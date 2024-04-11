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

    S get(int p) {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) {
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

    S all_prod() { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) {
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

    template <bool (*f)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) {
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

constexpr int INF = 1001001001;

int op(int x, int y) {return min(x, y);}
int e() {return INF;}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n1, n2, n3, n4;
    cin >> n1 >> n2 >> n3 >> n4;
    VI a(n1), b(n2), c(n3), d(n4);
    rep(i, n1) cin >> a[i];
    rep(i, n2) cin >> b[i];
    rep(i, n3) cin >> c[i];
    rep(i, n4) cin >> d[i];
    VVI bad_a(n2), bad_b(n3), bad_c(n4);
    {
        int cnt;
        cin >> cnt;
        while(cnt--) {
            int x, y;
            cin >> x >> y, --x, --y;
            bad_a[y].push_back(x);
        }
    }
    {
        int cnt;
        cin >> cnt;
        while(cnt--) {
            int x, y;
            cin >> x >> y, --x, --y;
            bad_b[y].push_back(x);
        }
    }
    {
        int cnt;
        cin >> cnt;
        while(cnt--) {
            int x, y;
            cin >> x >> y, --x, --y;
            bad_c[y].push_back(x);
        }
    }
    {
        segtree<int, op, e> seg(a);
        rep(i, n2) {
            for(int x: bad_a[i]) seg.set(x, INF);
            int t = seg.all_prod();
            if (t == INF) b[i] = INF;
            else b[i] += t;
            for(int x: bad_a[i]) seg.set(x, a[x]);
        }
    }
    {
        segtree<int, op, e> seg(b);
        rep(i, n3) {
            for(int x: bad_b[i]) seg.set(x, INF);
            int t = seg.all_prod();
            if (t == INF) c[i] = INF;
            else c[i] += t;
            for(int x: bad_b[i]) seg.set(x, b[x]);
        }
    }
    {
        segtree<int, op, e> seg(c);
        rep(i, n4) {
            for(int x: bad_c[i]) seg.set(x, INF);
            int t = seg.all_prod();
            if (t == INF) d[i] = INF;
            else d[i] += t;
            for(int x: bad_c[i]) seg.set(x, c[x]);
        }
    }
    int ans = INF;
    rep(i, n4) chmin(ans, d[i]);
    if (ans == INF) ans = -1;
    cout << ans << endl;
}