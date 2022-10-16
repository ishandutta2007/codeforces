#include <stdlib.h>
#include <stdio.h>
#define swap(a, b) (a ^= b, b ^= a, a ^= b)

enum { N = (int)3e5 + 1, Q = (int)5e5, M = 2 * N - 2 };

char UnsafeInput_buf[1 << 23], *UnsafeInput_bufptr = UnsafeInput_buf;

void UnsafeInput_init() {
  fread(UnsafeInput_buf + 1, 1, sizeof UnsafeInput_buf - 1, stdin);
}

void UnsafeInput_read(unsigned* b, size_t n) {
  unsigned *e = b + n;
  while (b != e) {
    if (*++UnsafeInput_bufptr < '0') {
      ++b;
    } else {
      *b = *b * 10 + *UnsafeInput_bufptr - '0';
    }
  }
}

char UnsafeOutput_buf[1 << 21], *UnsafeOutput_bufptr = UnsafeOutput_buf;

void UnsafeOutput_YES() {
  *UnsafeOutput_bufptr++ = 'Y';
  *UnsafeOutput_bufptr++ = 'E';
  *UnsafeOutput_bufptr++ = 'S';
  *UnsafeOutput_bufptr++ = '\n';
}

void UnsafeOutput_NO() {
  *UnsafeOutput_bufptr++ = 'N';
  *UnsafeOutput_bufptr++ = 'O';
  *UnsafeOutput_bufptr++ = '\n';
}

void UnsafeOutput_write() {
  fwrite(UnsafeOutput_buf, 1, UnsafeOutput_bufptr - UnsafeOutput_buf, stdout);
}

int DSU_p[N], DSU_w[N];

int DSU_getp(int v) {
  return DSU_p[v]? DSU_p[v] = DSU_getp(DSU_p[v]): v;
}

void DSU_uni(int u, int v) {
  if (DSU_w[u = DSU_getp(u)] < DSU_w[v = DSU_getp(v)]) {
    swap(u, v);
  }
  DSU_w[u] += DSU_w[v] + 1;
  DSU_p[v] = u;
}

int FT_xo[M];

void FT_build() {
  for (int i = 0; i < M; ++i) if ((i | (i + 1)) < M) {
    FT_xo[i | (i + 1)] ^= FT_xo[i];
  }
}

void FT_update2lazy(int a, int b) {
  FT_xo[a] ^= 1;
  FT_xo[b] ^= 1;
}

void FT_update2(int a, int b) {
  static unsigned seed, src, ent;
  enum { K = 32 - __builtin_clz(RAND_MAX) };
  if (src >>= 1, !ent--) {
    src = rand();
    ent = K - 1;
  }
  int x = (seed = seed * 2 + src % 2) * 2;
  for (int i = 2; i; --i) {
    if (a > b) {
      swap(a, b);
    }
    while (a < b) {
      FT_xo[a] ^= x;
      a |= a + 1;
    }
  }
}

int FT_query2(int a, int b) {
  int res = 0;
  for (int i = 2; i; --i) {
    if (a < b) {
      swap(a, b);
    }
    while (a > b) {
      res ^= FT_xo[a];
      a = (a & (a + 1)) - 1;
    }
  }
  return res;
}

int p[N], tin[N], tout[N];

typedef struct {
  int a, b, x;
} Edge;
Edge edges[M], queries[Q], *nei[N];

int edgecmp(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int build_component(int t, int v, int x) {
  tin[v] = t++;
  for (Edge* ptr = nei[v]; ptr != nei[v - 1]; --ptr) if (ptr->b != p[v]) {
    p[ptr->b] = v;
    t = build_component(t, ptr->b, ptr->x);
  }
  tout[v] = t++;
  if (x) {
    FT_update2lazy(tin[v], tout[v]);
  }
  return t;
}

int main() {
  unsigned n = 0, q = 0;
  *nei = edges;
  UnsafeInput_init();
  UnsafeInput_read(&n, 1);
  UnsafeInput_read(&q, 1);
  UnsafeInput_read((unsigned*)queries, q * 3);
  for (Edge* e = queries; e < queries + q; ++e) {
    if (DSU_getp(e->a) != DSU_getp(e->b)) {
      DSU_uni(e->a, e->b);
      *++*nei = *e;
      swap(e->a, e->b);
      *++*nei = *e;
      e->a = -1;
    }
  }
  qsort(edges + 1, *nei - edges, sizeof *edges, edgecmp);
  nei[n] = *nei;
  for (Edge** ne = nei + n; ne != nei; --ne) {
    while ((*ne)->a > ne - nei) {
      --*ne;
    }
    *(ne - 1) = *ne;
  }
  *nei = edges;

  for (int i = 1, t = 0; i <= n; ++i) if (!p[i]) {
    t = build_component(t, i, 0);
  }
  FT_build();
  for (Edge* e = queries; e < queries + q; ++e) {
    if (e->a == -1) {
      UnsafeOutput_YES();
    } else if (FT_query2(tin[e->a], tin[e->b]) != !e->x) {
      UnsafeOutput_NO();
    } else {
      UnsafeOutput_YES();
      while (e->a != e->b) {
        if (tin[e->a] < tin[e->b]) {
          swap(e->a, e->b);
        }
        FT_update2(tin[e->a], tout[e->a]);
        e->a = p[e->a];
      }
    }
  }
  UnsafeOutput_write();
}