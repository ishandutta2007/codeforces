#include<bits/stdc++.h>

#include <algorithm>
#include <cassert>
#include <iostream>
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

using namespace std;
using namespace atcoder;
#define rep(i,n)for (int i = 0; i < (n); ++i)
#define rrep(i,n)for (int i = (n)-1; i >= 0; --i)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;
struct HLD {
    std::vector<std::vector<int>> &to;
    int root, n;
    std::vector<int> sz, parent, depth, idx, ridx, head, inv;
    HLD(std::vector<std::vector<int>>& to, int root=0):
        to(to), root(root), n(to.size()),
        sz(n), parent(n), depth(n), idx(n), ridx(n), head(n), inv(n)
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
        inv[nxt] = u;
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

    int lca(int u, int v) {
        while(head[u] != head[v]) {
            if (depth[head[u]] > depth[head[v]]) u = parent[head[u]];
            else v = parent[head[v]];
        }
        return (depth[u] < depth[v] ? u : v);
    }
    // returns (paths upto lca from x (excluding lca), those from y, lca)
    std::tuple<std::vector<std::pair<int, int>>, std::vector<std::pair<int, int>>, int> paths(int x, int y) {
        std::tuple<std::vector<std::pair<int, int>>, std::vector<std::pair<int, int>>, int> ret;
        std::vector<std::pair<int, int>>& x_paths = get<0>(ret);
        std::vector<std::pair<int, int>>& y_paths = get<1>(ret);
        int& lca = get<2>(ret);
        while(head[x] != head[y]) {
            int xhead = head[x], yhead = head[y];
            if (depth[xhead] > depth[yhead]) {
                x_paths.emplace_back(x, xhead);
                x = parent[xhead];
            } else {
                y_paths.emplace_back(y, yhead);
                y = parent[yhead];
            }
        }
        if (depth[x] > depth[y]) {
            int ychild = inv[idx[y] + 1];
            x_paths.emplace_back(x, ychild);
            x = y;
        } else if (depth[x] < depth[y]) {
            int xchild = inv[idx[x] + 1];
            y_paths.emplace_back(y, xchild);
            y = x;
        }
        lca = x;
        return ret;
    }
};
bool op(bool x, bool y) {return false;}
bool e() {return false;}
int composition(int f, int g) {
    if (f == -1) return g;
    else return f;
}
int id() {return -1;}
bool mapping(int f, bool x) {
    if (f == -1) return x;
    return f;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    VI a(n);
    rep(i, n) cin >> a[i];
    VVI to(n);
    rep(_, n - 1) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    HLD d(to);
    map<int, vector<int>> mp;
    rep(i, n) {
        mp[a[i]].push_back(i);
    }
    lazy_segtree<bool,op,e,int,mapping,composition,id> seg(vector<bool>(n, true));
    for(auto [_, vs]: mp) {
        if (vs.size() <= 1) continue;
        sort(all(vs), [&](int u, int v) {return d.depth[u] < d.depth[v];});
        auto [xpath, ypath, lca] = d.paths(vs[0], vs[1]);
        set<int> st;
        rep(i, vs.size()) st.insert(d.idx[vs[i]]);
        if (lca == vs[0]) {
            int child = ypath.back().second, ic = d.idx[child], ric = d.ridx[child];
            seg.apply(0, ic, 0);
            seg.apply(ric, n, 0);
            for(int i = 1; i < vs.size(); ++i) {
                int u = vs[i], iu = d.idx[u], riu = d.ridx[u];
                if (!(ic <= iu && iu < ric)) {
                    cout << 0 << endl;
                    return 0;
                }
                seg.apply(iu, riu, 0);
                auto it = st.lower_bound(iu);
                it++;
                if (it != st.end() && *it < riu) {
                    cout << 0 << endl;
                    return 0;
                }
            }
        } else {
            for(int i = 0; i < vs.size(); ++i) {
                int u = vs[i], iu = d.idx[u], riu = d.ridx[u];
                seg.apply(iu, riu, 0);
                auto it = st.lower_bound(iu);
                it++;
                if (it != st.end() && *it < riu) {
                    cout << 0 << endl;
                    return 0;
                }
            }
        }
    }
    int ans = 0;
    rep(i, n) ans += seg.get(i);
    cout << ans << endl;
}