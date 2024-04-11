#include<bits/stdc++.h>
namespace {
using namespace std;

#include <algorithm>
#include <cassert>
#include <vector>


#ifdef _MSC_VER
#include <intrin.h>
#endif

namespace atcoder {

namespace internal {

int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

constexpr int bsf_constexpr(unsigned int n) {
    int x = 0;
    while (!(n & (1 << x))) x++;
    return x;
}

int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

}  // namespace internal

}  // namespace atcoder


namespace atcoder {

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
  public:
    segtree() : segtree(0) {}
    explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}
    explicit segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) const {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() const { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) const {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) const {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*f)(S)> int min_left(int r) const {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) const {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

}  // namespace atcoder

using namespace atcoder;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(i,n) for(int i = (int)(n) - 1; i >= 0; i--)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
template<class T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }
template<class T> bool chmin(T& a, const T& b) { if (b < a) { a = b; return true; } else return false; }
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;


template<class T, T (*add)(T, T), T (*zero)(), T (*mul)(T, T), T (*one)(), int N>
struct Mat : array<array<T, N>, N> {
  using M = Mat<T, add, zero, mul, one, N>;
  void make_identity() {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        (*this)[i][j] = zero();
      }
    }
    for (int i = 0; i < N; i++) {
      (*this)[i][i] = one();
    }
  }
  M& operator+=(const M& rhs) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        (*this)[i][j] = add((*this)[i][j], rhs[i][j]);
      }
    }
    return *this;
  }
  M& operator*=(const M& rhs) {
    static M temp;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        temp[i][j] = zero();
      }
    }
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        for (int k = 0; k < N; k++) {
          temp[i][k] = add(temp[i][k], mul((*this)[i][j], rhs[j][k]));
        }
      }
    }
    *this = temp;
    return *this;
  }
  template <class I>
  void inplace_pow(I k) {
    assert(k >= 0);
    static M temp;
    temp = *this;
    make_identity();
    while (k) {
      if (k & 1) *this *= temp;
      k >>= 1;
      if (k) temp *= temp;
    }
  }
  friend ostream& operator<<(ostream& os, const M& A) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        os << A[i][j] << " \n"[j + 1 == N];
      }
    }
    return os;
  }
};

// tropical semiring
constexpr ll INF = 1002003004005006007;
ll add(ll x, ll y) { return min(x, y); }
ll zero() { return INF; }
ll mul(ll x, ll y) { return x + y; }
ll one() { return 0; }

using M = Mat<ll, add, zero, mul, one, 2>;

M op(M x, M y) { return x *= y; }
M e() {
  M m;
  m.make_identity();
  return m;
}

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  VI dv(n - 1), dh(n - 1);
  rep(i, n - 1) {
    int dvi, dvj, dhi, dhj;
    cin >> dvi >> dvj >> dhi >> dhj;
    dv[i] = dvj - 1;
    dh[i] = dhi - 1;
  }
  vector<M> init_vec(n - 2);
  rep(i, n - 2) {
    init_vec[i] = {
      array<ll, 2>{abs(dv[i+1] - dv[i]), 2 * (i + 1) - dv[i] - dh[i + 1]},
      array<ll, 2>{2 * (i + 1) - dh[i] - dv[i + 1], abs(dh[i+1] - dh[i])}
    };
  }
  segtree<M, op, e> seg(init_vec);
  int q;
  cin >> q;
  rep(i, q) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--, y1--, x2--, y2--;
    int l1 = max(x1, y1), l2 = max(x2, y2);
    if (l1 == l2) {
      cout << abs(x2 - x1) + abs(y2 - y1) << '\n';
      continue;
    }
    if (l1 > l2) {
      swap(l1, l2);
      swap(x1, x2);
      swap(y1, y2);
    }
    auto d = seg.prod(l1, l2 - 1);
    array<ll, 2> a{
      abs(l1 - x1) + abs(dv[l1] - y1), // (l1, dv[l1])
      abs(dh[l1] - x1) + abs(l1 - y1)  // (dh[l1], l1)
    };
    array<ll, 2> b{
      abs(l2 - x2) + abs(dv[l2-1] - y2), // (l2, dv[l2-1])
      abs(dh[l2-1] - x2) + abs(l2 - y2)  // (dh[l2-1], l2)
    };
    ll ans = INF;
    rep(i, 2) rep(j, 2) chmin(ans, a[i] + d[i][j] + b[j]);
    ans += l2 - l1;
    cout << ans << '\n';
  }
}