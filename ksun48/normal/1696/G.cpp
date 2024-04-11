#include <bits/stdc++.h>
using namespace std;
 
namespace atcoder {
 
namespace internal {
 
// @param n `0 <= n`
// @return minimum non-negative `x` s.t. `n <= 2**x`
int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}
 
// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
constexpr int bsf_constexpr(unsigned int n) {
    int x = 0;
    while (!(n & (1 << x))) x++;
    return x;
}
 
// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
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
 
using ll = int64_t;
using ld = double;
 
ld P, Q;
 
using S = array<array<ld, 3>, 3>;
 
ld INF = 1e18;
 
S op(S x, S y){
    S ret;
    ret.fill({INF, INF, INF});
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                ret[i][j] = min(ret[i][j], x[i][k] + y[k][j]);
            }
        }
    }
    return ret;
}
 
S get(ld val){
    return {array<ld, 3>{val / P, 0, val}, {val / P, INF, INF}, {val / P, INF, val}};
}
 
S id{array<ld, 3>{0, INF, INF}, {INF, 0, INF}, {INF, INF, 0}};
S e(){
    return id;
}
 
void pr(S ret){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cerr << ret[i][j] << ' ';
        }
        cerr << '\n';
    }
}
 
ll ll_op(ll x, ll y){
    return x + y;
}
ll ll_e(){ return 0; }
 
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    ll _x, _y;
    cin >> _x >> _y;
    if(_x > _y) swap(_x, _y);
    P = ld(_x) / ld(_x + _y);
    Q = ld(_y) / ld(_x + _y);
 
    vector<ll> b(n);
    vector<S> vals(n);
    for(int i = 0; i < n; i++){
        cin >> b[i];
        vals[i] = get(ld(b[i]));
    }
    using seg = atcoder::segtree<S, op, e>;
    using fseg = atcoder::segtree<ll, ll_op, ll_e>;
    seg segtree(vals);
    fseg fsegtree(b);
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int k;
            ll v;
            cin >> k >> v;
            k--;
            fsegtree.set(k, v);
            segtree.set(k, get(v));
        } else if(type == 2){
            int l, r;
            cin >> l >> r;
            l--;
            S ret = segtree.prod(l, r);
            ld ans = INF;
            for(int i = 0; i < 3; i++){
                ans = min(ans, ret[0][i]);
            }
            ld rest = ld(fsegtree.prod(l, r)) - ans;
            ld cost = (ans + (rest / Q)) / (_x + _y);
            cout << fixed << setprecision(10);
            cout << cost << '\n';
        } else {
            assert(false);
        }
    }
}