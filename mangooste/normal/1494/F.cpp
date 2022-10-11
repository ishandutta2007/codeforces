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

int n, m;
vec<vec<int>> g;
vec<pair<int, int>> edges;
vec<char> used;
vec<int> way, head;
vec<char> vis;

inline int another(int i, int v) {
    return edges[i].first ^ edges[i].second ^ v;
}

void dfs(int v) {
    for (; head[v] < len(g[v]); head[v]++) {
        int i = g[v][head[v]];
        if (used[i]) {
            continue;
        }
        int u = another(i, v);
        used[i] = 1;
        dfs(u);
    }
    way.push_back(v);
}

void dfs2(int v) {
    vis[v] = 1;
    for (auto i : g[v]) {
        if (used[i]) {
            continue;
        }
        int u = another(i, v);
        if (!vis[u]) {
            dfs2(u);
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> m;
    g.resize(n);
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        edges.emplace_back(v, u);
        g[v].push_back(i);
        g[u].push_back(i);
    }
    int tot = 0;
    for (int i = 0; i < n; i++) {
        tot += len(g[i]) % 2;
    }
    used.resize(m);
    head.resize(n);
    vis.resize(n);
    for (int c = 0; c < n; c++) {
        int cur_cnt = tot - len(g[c]) % 2;
        int good = 0;
        for (auto i : g[c]) {
            int v = another(i, c);
            if (len(g[v]) % 2) {
                cur_cnt--;
                good++;
            }
        }
        cur_cnt += (len(g[c]) - good) % 2;
        assert(cur_cnt % 2 == 0);
        auto try_solve = [&](int bad = -1) {
            fill(all(vis), 0);
            dfs2(c);
            for (auto i : g[c]) {
                int v = another(i, c);
                vis[v] = 1;
            }
            if (find(all(vis), 0) != vis.end()) {
                return;
            }
            way.clear();
            fill(all(head), 0);
            dfs(c);
            dbg(c, bad, way);
            way.push_back(-2);
            for (auto i : g[c]) {
                int v = another(i, c);
                if (len(g[v]) % 2 && v != bad) {
                    way.push_back(v);
                    way.push_back(c);
                }
            }
            if (find(all(used), 0) != used.end()) {
                return;
            }
            cout << len(way) << '\n';
            for (auto x : way) {
                cout << x + 1 << ' ';
            }
            cout << '\n';
            exit(0);
        };
        if (cur_cnt == 0 || (cur_cnt == 2 && (len(g[c]) - good) % 2)) {
            fill(all(used), 0);
            for (auto i : g[c]) {
                int v = another(i, c);
                if (len(g[v]) % 2) {
                    used[i] = 1;
                }
            }
            try_solve();
        }
        if (cur_cnt == 0) {
            for (auto i : g[c]) {
                int v = another(i, c);
                if (len(g[v]) % 2) {
                    dbg(v, c);
                    fill(all(used), 0);
                    for (auto j : g[c]) {
                        int w = another(j, c);
                        if (len(g[w]) % 2) {
                            used[j] = 1;
                        }
                    }
                    used[i] = 0;
                    try_solve(v);
                }
            }
        }
    }
    cout << 0 << '\n';
}