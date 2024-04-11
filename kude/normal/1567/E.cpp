#include<bits/stdc++.h>

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

using namespace std;
using namespace atcoder;
#define rep(i,n) for(int i = 0; i < int(n); ++i)
#define rrep(i,n) for(int i = int(n)-1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template<class T> void chmax(T& a, const T& b) {a = max(a, b);}
template<class T> void chmin(T& a, const T& b) {a = min(a, b);}
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

ll op(ll x, ll y) {
    return x + y;
}

ll e() { return 0; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    VI a(n + 3);
    constexpr int INF = 1001001001;
    a[0] = INF;
    a[n + 1] = -1, a[n + 2] = -2;
    for(int i = 1; i <= n; i++) cin >> a[i];
    n += 3;
    set<int> starts{0};
    rep(i, n - 1) if (a[i] > a[i + 1]) starts.insert(i + 1);
    segtree<ll, op, e> seg(n);
    auto comb2 = [](ll x) {
        return x * (x - 1) / 2;
    };
    for(auto it = starts.begin(); next(it) != starts.end(); it++) {
        int i = *it;
        int j = *next(it);
        seg.set(i, comb2(j - i + 1));
    }

    auto calc = [&](int i) {
        int j = *starts.upper_bound(i);
        seg.set(i, comb2(j - i + 1));
    };

    auto mrg = [&](int i, int j) {
        seg.set(i, 0), seg.set(j, 0);
        if (a[j - 1] > a[j]) {
            calc(i), calc(j);
            return j;
        }
        starts.erase(j);
        calc(i);
        return i;
    };

    while(q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int i, x;
            cin >> i >> x;
            starts.insert(i), starts.insert(i + 1);
            a[i] = x;
            auto it = starts.find(i);
            int j = *prev(it);
            int k = *next(it);
            i = mrg(j, i);
            mrg(i, k);
        } else {
            int l, r;
            cin >> l >> r;
            r++;
            int l_ub = *starts.upper_bound(l);
            if (r <= l_ub) {
                cout << comb2(r - l + 1) << '\n';
                continue;
            }
            int r_lb = *prev(starts.lower_bound(r));
            ll ans = comb2(l_ub - l + 1) + comb2(r - r_lb + 1) + seg.prod(l_ub, r_lb);
            cout << ans << '\n';
        }
        // rep(i, n) cout << a[i] << " \n"[i + 1 == n];
        // for(int x: starts) cout << x << ' ';
        // cout << endl;
    }
}