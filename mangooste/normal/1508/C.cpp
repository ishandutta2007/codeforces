#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vec vector
#define ar array

#define all(a) (a).begin(), (a).end()
#define len(a) ((int)((a).size()))

template<typename A, typename B>
ostream& operator<<(ostream &out, pair<A, B> p) { return out << '(' << p.first << ", " << p.second << ')'; }

template<typename A, typename B = typename enable_if<!is_same<A, string>::value, typename A::value_type>::type>
ostream& operator<<(ostream &out, A vec) { out << '{'; string sep; for (B x : vec) out << sep << x, sep = ", "; return out << '}'; }

void dbg_print() { cerr << endl; }
template<typename A, typename... B> void dbg_print(A a, B... b) { cerr << ' ' << a; dbg_print(b...); }

#ifdef LOCAL
    #define dbg(...) cerr << '#' << __LINE__ << " [" << #__VA_ARGS__ << "]:", dbg_print(__VA_ARGS__)
#else
    #define dbg(...)
#endif

struct DSU {
    vec<int> par, sz;

    DSU() {}
    DSU(int n) : par(n), sz(n, 1) {
        iota(all(par), 0);
    }

    int get_par(int v) {
        return par[v] == v ? v : par[v] = get_par(par[v]);
    }

    bool unite(int v, int u) {
        v = get_par(v), u = get_par(u);
        if (v == u) {
            return false;
        }
        if (sz[v] < sz[u]) {
            swap(v, u);
        }
        sz[v] += sz[u];
        par[u] = v;
        return true;
    }
};

int n, m;
vec<vec<pair<int, int>>> g;
vec<ar<int, 3>> edges;
ll cnt;
set<int> vers;
DSU dsu1, dsu2;

void dfs(int v) {
    vers.erase(v);
    sort(all(g[v]));
    for (int i = 0; i <= len(g[v]); i++) {
        int prev = (i ? g[v][i - 1].first : -1);
        int cur = (i == len(g[v]) ? n : g[v][i].first);
        while (1) {
            auto it = vers.lower_bound(prev + 1);
            if (it == vers.end()) {
                break;
            }
            int u = *it;
            if (u < cur) {
                cnt--;
                dsu1.unite(v, u);
                dfs(u);
            } else {
                break;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> m;
    g.resize(n);
    int xor_all = 0;
    for (int i = 0; i < m; i++) {
        int v, u, w;
        cin >> v >> u >> w;
        v--, u--;
        xor_all ^= w;
        g[v].emplace_back(u, w);
        g[u].emplace_back(v, w);
        edges.push_back({v, u, w});
    }
    for (int i = 0; i < n; i++) {
        vers.insert(i);
    }
    cnt = 1ll * n * (n - 1) / 2 - m;
    dsu1 = dsu2 = DSU(n);
    for (int i = 0; i < n; i++) {
        if (vers.count(i)) {
            dfs(i);
        }
    }
    sort(all(edges), [&](auto a, auto b) {
        return a[2] < b[2];
    });
    int mn = (cnt == 0 ? xor_all : 0);
    ll ans = 0;
    for (auto [a, b, c] : edges) {
        if (dsu1.unite(a, b)) {
            ans += c;
            dsu2.unite(a, b);
        } else if (dsu2.get_par(a) != dsu2.get_par(b)) {
            mn = min(mn, c);
        }
    }
    cout << ans + mn << '\n';
}