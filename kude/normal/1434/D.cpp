#include <bits/stdc++.h>

#include <algorithm>

#ifdef _MSC_VER
#include <intrin.h>
#endif

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

#include <cassert>
#include <iostream>
#include <vector>
namespace atcoder {

template <class S,
          S (*op)(S, S),
          S (*e)(),
          class F,
          S (*mapping)(F, S),
          F (*composition)(F, F),
          F (*id)()>
struct lazy_segtree {
  public:
    lazy_segtree() : lazy_segtree(0) {}
    lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
    lazy_segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        lz = std::vector<F>(size, id());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return e();

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push(r >> i);
        }

        S sml = e(), smr = e();
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }

        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    void apply(int p, F f) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = mapping(f, d[p]);
        for (int i = 1; i <= log; i++) update(p >> i);
    }
    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return;

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, f);
                if (r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }

        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    template <bool (*g)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return g(x); });
    }
    template <class G> int max_right(int l, G g) {
        assert(0 <= l && l <= _n);
        assert(g(e()));
        if (l == _n) return _n;
        l += size;
        for (int i = log; i >= 1; i--) push(l >> i);
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!g(op(sm, d[l]))) {
                while (l < size) {
                    push(l);
                    l = (2 * l);
                    if (g(op(sm, d[l]))) {
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

    template <bool (*g)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return g(x); });
    }
    template <class G> int min_left(int r, G g) {
        assert(0 <= r && r <= _n);
        assert(g(e()));
        if (r == 0) return 0;
        r += size;
        for (int i = log; i >= 1; i--) push((r - 1) >> i);
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!g(op(d[r], sm))) {
                while (r < size) {
                    push(r);
                    r = (2 * r + 1);
                    if (g(op(d[r], sm))) {
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
    std::vector<F> lz;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
    void all_apply(int k, F f) {
        d[k] = mapping(f, d[k]);
        if (k < size) lz[k] = composition(f, lz[k]);
    }
    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = id();
    }
};

}  // namespace atcoder

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for (int i = (n)-1; i >= 0; --i)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;

struct HLD {
    std::vector<std::vector<int>> &to;
    int root, n;
    std::vector<int> sz, parent, depth, idx, ridx, head;
    HLD(std::vector<std::vector<int>>& to, int root=0):
        to(to), root(root), n(to.size()),
        sz(n), parent(n), depth(n), idx(n), ridx(n), head(n)
    {
        init_tree_data(root);
        int x = 0;
        assign_idx(root, root, x);
    }
    void init_tree_data(int u, int p=-1, int d=0) {
        parent[u] = p;
        depth[u] = d;
        int s = 1;
        for(int v: to[u]) {
            if (v == p) continue;
            init_tree_data(v, u, d+1);
            s += sz[v];
        }
        sz[u] = s;
    }
    void assign_idx(int u, int h, int &nxt, int p=-1) {
        head[u] = h;
        idx[u] = nxt++;
        if (sz[u] == 1) {
            ridx[u] = nxt;
            return;
        }
        int mxsize = 0;
        int mi;
        for(int v: to[u]) {
            if (v == p) continue;
            if (sz[v] > mxsize) {
                mxsize = sz[v];
                mi = v;
            }
        }
        assign_idx(mi, h, nxt, u);
        for(int v: to[u]) {
            if (v == p || v == mi) continue;
            assign_idx(v, v, nxt, u);
        }
        ridx[u] = nxt;
    }
};

struct S {
    int even, odd;
};

S op(S x, S y) {return {max(x.even, y.even), max(x.odd, y.odd)};}
S e() {return {-1, -1};}
S mapping(bool f, S x) {
    if (f) return {x.odd, x.even};
    else return x;
}
bool composition(bool f, bool g) {return f^g;}
bool id() {return false;}

struct E {
    int u, v, state;
};


VVI to;
P dfs(int u, int p=-1, int depth=0) {
    P ret = {u, depth};
    for(int v: to[u]) {
        if (v == p) continue;
        P r = dfs(v, u, depth+1);
        if (r.second > ret.second) ret = r;
    }
    return ret;
}

int main() {
    cin.tie(0);
    int n;
    cin >> n;
    to.resize(n);
    vector<E> es(n-1);
    rep(i, n-1) {
        int u, v, t;
        cin >> u >> v >> t;
        --u, --v;
        es[i] = {u, v, t};
        to[u].push_back(v);
        to[v].push_back(u);
    }
    int m;
    cin >> m;
    VI query(m);
    rep(i, m) {
        cin >> query[i];
        query[i]--;
    }
    VI ab(2);
    ab[0] = dfs(0).first;
    ab[1] = dfs(ab[0]).first;
    VVI ans(2, VI(m));
    rep(tt, 2) {
        int a = ab[tt];
        HLD hld(to, a);
        VI is_odd(n);
        rep(i, n-1) {
            int u = es[i].u, v = es[i].v, s = es[i].state;
            if (hld.parent[u] == v) {
                swap(u, v);
                swap(es[i].u, es[i].v);
            }
            is_odd[v] = s;
        }
        queue<int> que;
        que.push(a);
        while(!que.empty()) {
            int u = que.front(); que.pop();
            for(int v: to[u]) {
                if (v == hld.parent[u]) continue;
                is_odd[v] ^= is_odd[u];
                que.push(v);
            }
        }

        vector<S> init_vec(n);
        rep(i, n) {
            if (is_odd[i]) {
                init_vec[hld.idx[i]] = {-1, hld.depth[i]};
            } else {
                init_vec[hld.idx[i]] = {hld.depth[i], -1};
            }
        }
        lazy_segtree<S,op,e,bool,mapping,composition,id> seg(init_vec);
        rep(i, m) {
            int ei = query[i];
            int v = es[ei].v;
            int vin = hld.idx[v], vout = hld.ridx[v];
            seg.apply(vin, vout, true);
            ans[tt][i] = seg.all_prod().even;
        }
    }
    rep(i, m) cout << max(ans[0][i], ans[1][i]) << '\n';
}