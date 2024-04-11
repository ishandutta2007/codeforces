#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define vec vector
#define ar array

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
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

const int N = 3e5 + 4;

struct Tree {
    vec<int> g[N];
    int dist[N];

    Tree() {}

    void add(int v, int u) {
        g[v].push_back(u);
        g[u].push_back(v);
    }

    void make_unique() {
        for (int i = 0; i < N; i++) {
            sort(all(g[i]));
            g[i].resize(unique(all(g[i])) - g[i].begin());
        }
    }

    pair<int, int> bfs(int start) {
        fill(all(dist), N);
        dist[start] = 0;

        vec<int> que{start};
        for (int st = 0; st < len(que); st++) {
            int v = que[st];
            for (auto u : g[v])
                if (dist[u] > dist[v] + 1) {
                    dist[u] = dist[v] + 1;
                    que.push_back(u);
                }
        }

        return { dist[que.back()], que.back() };
    }

    int solve() {
        make_unique();
        return bfs(bfs(0).second).first;
    }
};

int n, m;
int edges[N][2];
vec<int> g[N];

int tin[N], tup[N], timer;
bool used[N];
bool bridge[N];

int which[N], current;
Tree tree;

int another(int i, int v) {
    return edges[i][0] ^ edges[i][1] ^ v;
}

void dfs(int v, int par) {
    used[v] = true;
    tin[v] = tup[v] = timer++;

    for (auto i : g[v]) {
        if (i == par)
            continue;

        int u = another(i, v);
        if (used[u]) {
            tup[v] = min(tup[v], tin[u]);
            continue;
        }

        dfs(u, i);

        tup[v] = min(tup[v], tup[u]);
        if (tup[u] > tin[v])
            bridge[i] = true;
    }
}

void dfs2(int v) {
    used[v] = true;
    which[v] = current;

    for (auto i : g[v]) {
        if (bridge[i])
            continue;

        int u = another(i, v);
        if (!used[u])
            dfs2(u);
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1];
        edges[i][0]--, edges[i][1]--;

        g[edges[i][0]].push_back(i);
        g[edges[i][1]].push_back(i);
    }

    dfs(0, -1);

    fill(all(used), false);
    for (int i = 0; i < n; i++)
        if (!used[i]) {
            dfs2(i);
            current++;
        }

    for (int i = 0; i < m; i++) {
        int v = edges[i][0];
        int u = edges[i][1];
        if (which[v] == which[u])
            continue;

        tree.add(which[v], which[u]);
    }

    cout << tree.solve() << '\n';
}