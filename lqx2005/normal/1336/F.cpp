#include <bits/stdc++.h>
#define x first
#define y second
#define sz(a) int((a).size())
#define pb push_back
#define eb emplace_back
#define mid ((l + r) >> 1)
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef double db;
const int N = 3e5 + 10, K = 20, M = N * K, oo = 0x3f3f3f3f;
struct node {
    int l, r, suml, sumr;
    ll sum2;
    node() {l = r = suml = sumr = sum2 = 0; }
    node(int _l, int _r, int _suml, int _sumr, ll _sum2) {l = _l, r = _r, suml = _suml, sumr = _sumr, sum2 = _sum2; }
    friend node operator * (const node a, const node b) {
        if(a.sumr < 0) {
            if(b.sumr < 0) {
                return node(a.l, b.r, a.suml + b.suml, -1, a.sum2 + b.sum2 + 2ll * a.suml * b.suml);
            } else {
                return node(a.l, b.r, a.suml + b.suml, b.sumr, a.sum2 + b.sum2 + 2ll * a.suml * b.suml);
            }
        } else {
            if(b.sumr < 0) {
                return node(a.l, b.r, a.suml, b.suml + a.sumr, a.sum2 + b.sum2 + 2ll * a.sumr * b.suml);
            } else {
                return node(a.l, b.r, a.suml, b.sumr, a.sum2 + b.sum2 + 2ll * a.sumr * b.suml);
            }
        }
    }
    friend node operator + (const node a, const node b) {
        if(a.sumr < 0) {
            if(b.sumr < 0) {
                return node(a.l, b.r, a.suml, b.suml, a.sum2 + b.sum2);
            } else {
                return node(a.l, b.r, a.suml, b.sumr, a.sum2 + b.sum2);
            }
        } else {
            if(b.sumr < 0) {
                return node(a.l, b.r, a.suml, b.suml, a.sum2 + b.sum2);
            } else {
                return node(a.l, b.r, a.suml, b.sumr, a.sum2 + b.sum2);
            }
        }
    }
}t[M];
int rt[N], rt1[N], rt2[N];
int ls[M], rs[M], sum[M], tot = 0, mn[M], anc[M];
int nowdep;
int n, m, k;
vector<int> son[N];
vector<pair<int, int>> path[N];
map<pair<int, int>, vector<pair<int, int>>> mp;
int fa[N], siz[N], dep[N], top[N], dfn[N], id[N], dfc = 0, big[N], l[N], r[N];
ll ans = 0;
ll s2(ll x) {return x * x; }
void setdep(int u, int a, int k) {nowdep = k - dep[u] + dep[a] * 2; }
void dfs1(int u, int fa) {
    ::fa[u] = fa;
    dep[u] = dep[fa] + 1;
    siz[u] = 1;
    for(int v : son[u]) if(v != fa) {
        dfs1(v, u);
        siz[u] += siz[v];
        if(siz[v] > siz[big[u]]) big[u] = v;
    }
    return;
}
void dfs2(int u, int tp) {
    top[u] = tp;
    dfn[u] = ++dfc, id[dfc] = u;
    l[u] = dfc;
    if(big[u]) dfs2(big[u], tp);
    for(int v : son[u]) if(v != fa[u] && v != big[u]) {
        dfs2(v, v);
    }
    r[u] = dfc;
    return;
}
int lca(int u, int v) {
    for(; top[u] != top[v]; ) {
        if(dep[top[u]] < dep[top[v]]) swap(u, v);
        u = fa[top[u]];
    }
    if(dep[u] < dep[v]) swap(u, v);
    return v;
}
int jump(int u, int k) {
    for(; ; ) {
        if(dep[u] - dep[fa[top[u]]] > k) return id[dfn[u] - k];
        k -= dep[u] - dep[fa[top[u]]], u = fa[top[u]];
    }
}
namespace subtask2 {
	int newnode() {
		tot++;
		ls[tot] = rs[tot] = sum[tot] = 0;
		return tot;
	}
	void updata(int p) {
		sum[p] = sum[ls[p]] + sum[rs[p]];
	}
	void change(int &p, int l, int r, int x, int v) {
		if(!p) p = ++tot;
		if(l == r) return void(sum[p] += v);
		x <= mid ? change(ls[p], l, mid, x, v) : change(rs[p], mid + 1, r, x, v);
		updata(p);
	}
	int merge(int a, int b, int l, int r) {
		if(!a || !b) return a + b;
		if(l == r) {
			sum[a] += sum[b];
			return a;
		}
		ls[a] = merge(ls[a], ls[b], l, mid), rs[a] = merge(rs[a], rs[b], mid + 1, r);
		return updata(a), a;
	}
	int query(int p, int l, int r, int L, int R) {
		if(L > R || !p) return 0;
		if(L <= l && r <= R) return sum[p];
		int res = 0;
		if(L <= mid) res += query(ls[p], l, mid, L, R);
		if(R > mid) res += query(rs[p], mid + 1, r, L, R);
		return res;
	}

	void dfs3(int u, int fa) {
		for(int v : son[u]) if(v != fa) {
			dfs3(v, u);
			rt[u] = merge(rt[u], rt[v], 0, n);
		}
		ans += s2(query(rt[u], 0, n, 0, dep[u] - k));
		ans -= s2(query(rt[u], 0, n, 0, dep[u] - k - 1));
		// cout << u <<" "<< query(rt[u], 0, n, 0, dep[u] - k) <<" " << query(rt[u], 0, n, 0, dep[u] - k - 1) << endl;
		return;
	}
	void main(vector<pair<int, int>> p) {
		tot = 0;
		for(auto [u, v] : p) {
            // cout << u <<" " << v << endl;
			change(rt[u], 0, n, dep[v], 1);
		}
		dfs3(1, 0);
		return;
	}
}
namespace subtask1 {
	int newnode() {
		tot++;
		ls[tot] = rs[tot] = 0;
		t[tot] = node(0, 0, 0, 0, 0), mn[tot] = oo;
		return tot;
	}
	void updata(int p, int l, int r) {
		if(l == r) {
			if(dep[anc[p]] < nowdep) {
				t[p].suml = t[p].sumr = t[p].sum2 = anc[p] = 0;
			}
			if(t[p].suml || t[p].sumr) mn[p] = dep[id[l]], t[p].l = t[p].r = anc[p];
			else mn[p] = oo, t[p].l = t[p].r = 0;
		} else {
			mn[p] = min(mn[ls[p]], mn[rs[p]]);
			if(!t[ls[p]].r) t[p] = t[rs[p]];
			else if(!t[rs[p]].l) t[p] = t[ls[p]];
			else {
				if(!anc[p]) anc[p] = ::lca(t[ls[p]].r, t[rs[p]].l);
				if(dep[anc[p]] < nowdep) t[p] = t[ls[p]] + t[rs[p]];
				else t[p] = t[ls[p]] * t[rs[p]], mn[p] = min(mn[p], dep[anc[p]]);
			}
		}
        // cout << p <<" " << l <<" " << r <<" " << t[p].sum2 << endl;
		return;
	}
	void change(int &p, int l, int r, int x, int v) {
		if(!p) p = newnode();
		if(l == r) {
			t[p].suml += v, t[p].sumr = -1;
			t[p].sum2 = s2(t[p].suml);
			anc[p] = id[l];
			return updata(p, l, r);
		}
		x <= mid ? change(ls[p], l, mid, x, v) : change(rs[p], mid + 1, r, x, v);
		anc[p] = 0;
		updata(p, l, r);
	}
	int merge(int a, int b, int l, int r) {
		if(!a || !b) return a + b;
		if(l == r) {
			t[a] = t[a] * t[b];
			return updata(a, l, r), a;
		}
		ls[a] = merge(ls[a], ls[b], l, mid), rs[a] = merge(rs[a], rs[b], mid + 1, r);
		anc[a] = 0;
		return updata(a, l, r), a;
	}
	void clear(int p, int l, int r) {
		if(mn[p] >= nowdep) return;
		if(l == r) return updata(p, l, r);
		clear(ls[p], l, mid), clear(rs[p], mid + 1, r);
		return updata(p, l, r);
	}
	vector<int> build(vector<int> id) {
		sort(id.begin(), id.end(), [&](int x, int y) {
			return dfn[x] < dfn[y];
		});
		int n = sz(id);
		for(int i = 0; i < n; i++) id.push_back(lca(id[i], id[(i + 1) % n]));
		sort(id.begin(), id.end(), [&](int x, int y) {
			return dfn[x] < dfn[y];
		});
		id.erase(unique(id.begin(), id.end()), id.end());
		for(int u : id) son[u].clear();
		vector<int> stk;
		for(int u : id) {
			while(!stk.empty() && r[stk.back()] < dfn[u]) stk.pop_back();
			if(!stk.empty()) son[stk.back()].push_back(u);
			stk.push_back(u);
		}
		return id;
	}
    int range(int l, int r) {return max(0, r - l);}
	void dfs4(int u, int fa, int a) {
		for(int v : son[u]) {
			dfs4(v, u, a);
            setdep(u, a, k);
			rt1[u] = merge(rt1[u], rt1[v], 1, n);
            setdep(u, a, k + 1);
			rt2[u] = merge(rt2[u], rt2[v], 1, n);
		}
        if(!fa) return;
        // cout << t[rt1[u]].sum2 << endl;
        // cout << mn[rt[u]] << endl;
        int r = dep[u];
        while(k > dep[fa] + mn[rt1[u]] - dep[a] * 2) {
            int l = k - mn[rt1[u]] + dep[a] * 2 - 1;
            ans += t[rt1[u]].sum2 * range(l, min(r, dep[a] + k - 1));
            nowdep = mn[rt1[u]] + 1;
            clear(rt1[u], 1, n);
            r = l;
        }
        ans += range(dep[fa], min(r, dep[a] + k - 1)) * t[rt1[u]].sum2;
        r = dep[u];
        while(k + 1 > dep[fa] + mn[rt2[u]] - dep[a] * 2) {
            int l = k + 1 - mn[rt2[u]] + dep[a] * 2 - 1;
            ans -= t[rt2[u]].sum2 * range(l, min(r, dep[a] + k));
            nowdep = mn[rt2[u]] + 1;
            clear(rt2[u], 1, n);
            r = l;
        }
        ans -= range(dep[fa], min(r, dep[a] + k)) * t[rt1[u]].sum2;
		return;
	}
	void solve(int lca, vector<pair<int, int>> p) {
		tot = 0;
		vector<int> id;
		for(auto [u, v] : p) id.push_back(v);
        id.push_back(lca);
		id = build(id);
		for(int v : id) rt1[v] = rt2[v] = 0;
		for(auto [u, v] : p) {
			setdep(v, lca, k);
			change(rt1[v], 1, n, dfn[u], 1);
			setdep(v, lca, k + 1);
			change(rt2[v], 1, n, dfn[u], 1);
		}
		dfs4(lca, 0, lca);
		return;
	}
	void main(int lca, vector<pair<int, int>> p) {
		mp.clear();
		for(auto [u, v] : p) {
			int tu = jump(u, dep[u] - dep[lca] - 1), tv = jump(v, dep[v] - dep[lca] - 1);
			if(tu > tv) swap(tu, tv), swap(u, v);
			mp[{tu, tv}].eb(u, v);
		}
		for(auto [a, b] : mp) solve(lca, b);
		return;
	}
};
int main() {
    mn[0] = oo;
    cin >> n >> m >> k;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        son[u].push_back(v), son[v].push_back(u);
    }
    dep[0] = 0;
    dfs1(1, 0);
    dfs2(1, 1);
	vector<pair<int, int>> lis;
    for(int i = 1; i <= m; i++) {
        int s, t;
        cin >> s >> t;
        int lca = ::lca(s, t);
        if(lca != s && lca != t) path[lca].eb(s, t);
		if(dep[s] + dep[t] - dep[lca] * 2 >= k) ans--;
		lis.eb(s, lca), lis.eb(t, lca);
        // cout << s <<" " << lca <<" " << t <<" " << lca << endl;
    }
	subtask2::main(lis);
    for(int i = 1; i <= n; i++) {
        subtask1::main(i, path[i]);
    }
    cout << ans / 2 << endl;
	return 0;
}