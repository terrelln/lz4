#include <lz4.h>
#include <stdlib.h>

#define CHECK(p) ((p) ? (void)0 : abort())

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
  size_t const out_size = 10 * size;
  uint8_t* out = malloc(out_size);
  CHECK(out);

  LZ4_decompress_safe((char*)data, (char const*)out, (int)size, (int)out_size);

  free(out);
}
