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

constexpr int INF = 1001001001;
ll op_sum(ll x, ll y) { return x + y; }
ll e_sum() { return 0; }
int op_min(int x, int y) { return min(x, y); }
int e_min() { return INF; }

} int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  VI a(n);
  rep(i, n) cin >> a[i], a[i]--;
  set<int> bounds{n};
  VVI rem_ev(n + 1);
  rep(i, n) {
    int x = min(-(a[i] - i), i + 1);
    if (0 < x) {
      rem_ev[min(i, x)].emplace_back(i);
      bounds.emplace(i);
    }
  }
  // cout << bounds.size() << endl;
  VI r1(n), r2(n);
  ll sc0 = 0;
  VI imn(n, -1), imx(n, -1);
  VL lens(n);
  rep(i, n) {
    for(int pos: rem_ev[i]) bounds.erase(pos);
    auto it = bounds.begin();
    int p = *it;
    r1[i] = p;
    if (p < n) {
      r2[i] = *next(it);
      if (imn[p] == -1) imn[p] = i;
      imx[p] = i;
    }
    lens[i] = r1[i] - i;
    sc0 += r1[i] - i;
  }
  VL gain(n);
  rep(i, n) gain[i] = r2[i] - r1[i];
  segtree<ll, op_sum, e_sum> seg0(lens);
  segtree<int, op_min, e_min> seg1(r1);
  segtree<ll, op_sum, e_sum> seg2(gain);
  // rep(i, n) cout << r1[i] << " \n"[i + 1 == n];
  int q;
  cin >> q;
  rep(_, q) {
    int p, x;
    cin >> p >> x;
    p--, x--;
    ll ans = sc0;
    int y = min(-(x - p), p + 1);
    if (x > a[p]) {
      if (imn[p] != -1) {
        ans += seg2.prod(max(y, imn[p]), imx[p] + 1);
      }
    } else if (x < a[p]) {
      if (0 < y) {
        int l = seg1.min_left(y, [&](int x) {
          return x > p;
        });
        ans -= seg0.prod(l, y);
        ans += ll(y - l) * p - ll(l + y - 1) * (y - l) / 2;
      }
    }
    cout <<  ans << '\n';
  }
}