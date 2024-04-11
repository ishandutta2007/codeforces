#include <iostream>

using namespace std;


struct Vertex {
  int x, y, offset;
  Vertex *l, *r;
};
using Ptr = Vertex*;

constexpr int max_size = 2e5, mod = 998244353, p = mod - 2;
Vertex storage[max_size];
int allocated;

void shift(Ptr t, int offset) {
  if (t) {
    t->offset += offset;
  }
}

bool push(Ptr t) {
  if (t && t->offset) {
    shift(t->l, t->offset);
    shift(t->r, t->offset);
    t->x += t->offset;
    t->offset = 0;
  }
  return t;
}

bool split(Ptr t, Ptr& l, Ptr& r, int x) {
  bool splitting = 0;
  if (!push(t)) {
    l = r = 0;
    splitting = 1;
  } else if (t->x >= x) {
    if (splitting = t->x != x && split(t->l, l, t->l, x)) {
      r = t;
    }
    t->x += 1;
    shift(t->r, 1);
  } else {
    if (splitting = split(t->r, t->r, r, x)) {
      l = t;
    }
  }
  return splitting;
}

void add(Ptr& t, int x, int y) {
  if (!push(t) || t->y > y) {
    Ptr el = storage + allocated;
    *el = Vertex{x, y};
    if (split(t, el->l, el->r, el->x)) {
      ++allocated;
      el->x += 1;
      t = el;
    }
  } else if (t->x >= x) {
    if (t->x != x) {
      add(t->l, x, y);
    }
    t->x += 1;
    shift(t->r, 1);
  } else {
    add(t->r, x, y);
  }
}

uint32_t fmulc(uint32_t a, uint32_t b) {
  uint64_t x = (uint64_t)a * b;
  asm(
    "divl %4; \n\t"
    : "=a" (a), "=d" (b)
    : "d" ((uint32_t) (x >> 32)), "a" ((uint32_t) x), "r" (mod)
  );
  return b;
}

void fmulm(uint32_t& a, uint32_t b) {
  a = fmulc(a, b);
}

uint32_t fact(uint32_t n) {
  static uint32_t maxn = 0, fact[2 * max_size]{1};
  while (maxn < n) {
    ++maxn;
    fact[maxn] = fmulc(fact[maxn - 1], maxn);
  }
  return fact[n];
}

uint32_t fpow(uint32_t x, int p = mod - 2) {
  uint32_t res = 1;
  while (p) {
    if (p & 1) {
      fmulm(res, x);
    }
    fmulm(x, x);
    p >>= 1;
  }
  return res;
}

uint32_t nfact(uint32_t n) {
  static uint32_t maxn = 2, nfact[max_size + 2]{1, 1, 499122177}, inv[max_size + 2]{0, 1, 499122177};
  while (maxn < n) {
    ++maxn;
    inv[maxn] = fpow(maxn);
    nfact[maxn] = fmulc(nfact[maxn - 1], inv[maxn]);
    ++maxn;
    inv[maxn] = fmulc(inv[maxn / 2], inv[2]);
    nfact[maxn] = fmulc(nfact[maxn - 1], inv[maxn]);
  }
  return nfact[n];
}

uint32_t cnk(uint32_t n, uint32_t k) {
  return fmulc(fact(n), fmulc(nfact(k), nfact(n - k)));
}

int main()
{
  cin.tie(0), ios::sync_with_stdio(0);
  uint32_t t, n, m, x, r;
  cin >> t;
  while (t--) {
    Ptr root{};
    allocated = 0;
    cin >> n >> m;
    while (m--) {
      cin >> x >> x;
      add(root, x, r = r * (RAND_MAX + 1) + rand());
    }
    cout << cnk(2 * n - allocated - 1, n) << '\n';
  }
  return 0;
}