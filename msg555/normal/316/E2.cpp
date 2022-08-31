#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstddef>
#include <cassert>

using namespace std;

#define MOD 1000000000

int FSHFT[200010][2][2];
int RSHFT[200010][2][2];
int FSUM[200010];

void shift(int* ff, int nm) {
  int A[2][2];
  memcpy(A, nm < 0 ? RSHFT[-nm][0] : FSHFT[nm][0], sizeof(A));

  int nf[2];
  nf[0] = ((long long)ff[0] * A[0][0] + (long long)ff[1] * A[0][1]) % MOD;
  nf[1] = ((long long)ff[0] * A[1][0] + (long long)ff[1] * A[1][1]) % MOD;
  memcpy(ff, nf, sizeof(nf));
}

template<class T>
struct segtree {
  segtree(size_t N) { 
    this->N = N = 1 << (32 - __builtin_clz(N - 1));
    V.resize(2 * N);

    for(size_t i = 0; i < N; i++) {
      V[N + i].set_size(1);
    }
    refresh();
  }

  T& get(int x) {
    return V[N + x];
  }

  void refresh() {
    for(size_t i = N - 1; i; i--) {
      V[i] = V[2 * i].pull_into(V[2 * i + 1]);
    }
  }

  void zip(size_t x, size_t dep) {
    for(; dep; dep--) {
      x = x >> 1;
      V[x] = V[2 * x].pull_into(V[2 * x + 1]);
    }
  }

  template<bool doupdate, class TT>
  T work(const TT& v, size_t a, size_t b, size_t x, size_t A, size_t B) {
    for(size_t dep = 0; ; dep++) {
      size_t c1 = 2 * x;
      size_t c2 = 2 * x + 1;
      size_t M = A + ((B - A) >> 1);

      if(a <= A && B <= b) {
        if(doupdate) {
          V[x].update(v);
          zip(x, dep);
        }
        return V[x];
      }

      V[x].push(V[c1], V[c2]);
      if(b <= M) {
        x = c1;
        B = M;
      } else if(M <= a) {
        x = c2;
        A = M;
      } else {
        T ret = work<doupdate>(v, a, b, c1, A, M).pull_into(
                           work<doupdate>(v, a, b, c2, M, B));
        if(doupdate) {
          V[x] = V[c1].pull_into(V[c2]);
          zip(c1, dep + 1);
        }
        return ret;
      }
    }
  }

  template<class TT>
  void update(const TT& v, size_t a, size_t b) {
    work<true>(v, a, b, 1, 0, N);
  }

  T query(size_t a, size_t b) {
    return work<false, void*>(NULL, a, b, 1, 0, N);
  }

  size_t N;
  vector<T> V;
};

struct agg {
  agg() : fadd(0), sz(0) {
    fs[0] = fs[1] = 0;
  }

  void set_size(size_t sz) {
    this->sz = sz;
  }

  agg pull_into(const agg& x) {
    agg r = *this;
    r.fadd = 0;
    r.fs[0] = (r.fs[0] + (long long)FSUM[sz - 1] * fadd) % MOD;
    r.fs[1] = (r.fs[1] + (long long)FSUM[sz] * fadd) % MOD;
    r.sz = sz + x.sz;

    int ff[2];
    memcpy(ff, x.fs, sizeof(ff));
    ff[0] = (ff[0] + (long long)FSUM[x.sz - 1] * x.fadd) % MOD;
    ff[1] = (ff[1] + (long long)FSUM[x.sz] * x.fadd) % MOD;

    shift(ff, sz);
    r.fs[0] = (r.fs[0] + ff[0]) % MOD;
    r.fs[1] = (r.fs[1] + ff[1]) % MOD;
    return r;
  }

  void update(int v) {
    fadd = (fadd + v) % MOD;
  }

  void update(unsigned int v) {
    fadd = 0;
    fs[1] = v;
  }

  void update(void* v) {
  }

  void push(agg& lft, agg& rht) {
    if(fadd) {
      fs[1] = (fs[1] + fadd) % MOD;
      lft.fadd = (lft.fadd + fadd) % MOD;
      rht.fadd = (rht.fadd + fadd) % MOD;
      fadd = 0;
    }
  }

  int fadd;
  int fs[2];
  size_t sz;
};

int main() {
  FSHFT[0][0][0] = RSHFT[0][0][0] = 1;
  FSHFT[0][1][1] = RSHFT[0][1][1] = 1;
  FSHFT[1][0][0] = 0; FSHFT[1][0][1] = 1;
  FSHFT[1][1][0] = 1; FSHFT[1][1][1] = 1;
  RSHFT[1][0][0] = MOD - 1; RSHFT[1][0][1] = 1;
  RSHFT[1][1][0] = 1; RSHFT[1][1][1] = 0;
  FSUM[0] = 0;
  for(int i = 2; i < 200010; i++) {
    for(int j = 0; j < 2; j++) {
      for(int k = 0; k < 2; k++) {
        for(int a = 0; a < 2; a++) {
          FSHFT[i][j][k] = (FSHFT[i][j][k] + (long long)FSHFT[i - 1][j][a] * FSHFT[1][a][k]) % MOD;
          RSHFT[i][j][k] = (RSHFT[i][j][k] + (long long)RSHFT[i - 1][j][a] * RSHFT[1][a][k]) % MOD;
        }
      }
    }
    FSUM[i - 1] = FSUM[i - 2] + FSHFT[i][0][0];
  }

  int N, M;
  scanf("%d%d", &N, &M);

  segtree<agg> seg(N);
  for(int i = 0; i < N; i++) {
    scanf("%d", seg.get(i).fs + 1);
  }
  seg.refresh();

  for(int i = 0; i < M; i++) {
    int c; scanf("%d", &c);
    if(c == 1) {
      int j, v;
      scanf("%d%d", &j, &v);
      seg.update<unsigned int>(v, j - 1, j);
    } else if(c == 2) {
      int lf, rh;
      scanf("%d%d", &lf, &rh);

      agg r = seg.query(lf - 1, rh);
      printf("%d\n", (int)(
            (r.fs[1] + (long long)FSUM[rh - lf + 1] * r.fadd) % MOD));
    } else if(c == 3) {
      int lf, rh, d;
      scanf("%d%d%d", &lf, &rh, &d);
      seg.update(d, lf - 1, rh);
    }
  }
  return 0;
}