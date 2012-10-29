#ifndef CRYPTOHASH_WHIRLPOOL_H
#define CRYPTOHASH_WHIRLPOOL_H

#include <stdint.h>

/*
 * Whirlpool-specific definitions.
 */

#define DIGESTBYTES 64
#define DIGESTBITS  (8*DIGESTBYTES) /* 512 */

#define WBLOCKBYTES 64
#define WBLOCKBITS  (8*WBLOCKBYTES) /* 512 */

#define LENGTHBYTES 32
#define LENGTHBITS  (8*LENGTHBYTES) /* 256 */

typedef struct whirlpool_ctx {
	uint8_t  bitLength[LENGTHBYTES]; /* global number of hashed bits (256-bit counter) */
	uint8_t  buffer[WBLOCKBYTES];	/* buffer of data to hash */
	uint32_t bufferBits;		        /* current number of bits on the buffer */
	uint32_t bufferPos;		        /* current (possibly incomplete) byte slot on the buffer */
	uint64_t hash[DIGESTBYTES/8];    /* the hashing state */
} whirlpool_ctx;

void whirlpool_init(struct whirlpool_ctx * const structpointer);
void whirlpool_add(const unsigned char * const source,
               unsigned long sourceBits,
               struct whirlpool_ctx * const structpointer);
void whirlpool_finalize(struct whirlpool_ctx * const structpointer,
                    unsigned char * const result);

#endif