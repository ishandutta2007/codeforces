#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 1e5 + 5;

int n;
vector<int> g[N];
map<pii, ll> ed;

void update(int u, int v, ll w) {
    if (u > v) swap(u, v);
    ed[make_pair(u, v)] = w;
}

ll get(int u, int v) {
    if (u > v) swap(u, v);
    return ed[make_pair(u, v)];
}

void add_path(int st, int fn, ll x) {
    vector<int> dist(n + 1, inf), from(n + 1, -1);
    dist[st] = 0;
    queue<int> que;
    que.push(st);
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (int to : g[v]) {
            if (dist[to] > dist[v] + 1) {
                dist[to] = dist[v] + 1;
                from[to] = v;
                que.push(to);
            }
        }
    }
    vector<int> path;
    for (int u = fn; u != st; u = from[u]) {
        path.push_back(u);
    }
    path.push_back(st);
    for (int i = 0; i + 1 < (int) path.size(); i++) {
        int u = path[i];
        int v = path[i + 1];
        update(u, v, get(u, v) + x);
    }
}

int get_leaf(int v, int par = -1) {
    for (int to : g[v]) {
        if (to == par) continue;
        return get_leaf(to, v);
    }
    return v;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int u, v, w, i = 1; i < n; i++) {
        cin >> u >> v >> w;
        g[u].push_back(v);
        g[v].push_back(u);
        update(u, v, w);
    }

    for (int v = 1; v <= n; v++) {
        if ((int) g[v].size() == 2) {
            cout << "NO\n";
            return 0;
        }
    }

    if (n == 2) {
        cout << "YES\n1\n1 2 " << get(1, 2) << "\n";
        return 0;
    }

    vector<tuple<int, int, ll>> res;
    vector<pii> edges;
    for (int u = 1; u <= n; u++) {
        for (int v : g[u]) {
            if (u < v)
                edges.emplace_back(u, v);
        }
    }

    for (pii edge : edges) {
        int u, v;
        tie(u, v) = edge;
        if (get(u, v) == 0) continue;
        if ((int) g[u].size() < (int) g[v].size()) swap(u, v);
        int A = -1, B = -1;
        for (int q : g[u]) {
            if (q == v) continue;
            if (A == -1) A = get_leaf(q, u);
            else B = get_leaf(q, u);
        }
        int x = get(u, v) / 2;
        if ((int) g[v].size() > 2) {
            int C = -1, D = -1;
            for (int q : g[v]) {
                if (q == u) continue;
                if (C == -1) C = get_leaf(q, v);
                else D = get_leaf(q, v);
            }
            res.emplace_back(A, C, x);
            res.emplace_back(B, A, -x);
            res.emplace_back(B, D, x);
            res.emplace_back(C, D, -x);
        } else {
            res.emplace_back(A, v, x);
            res.emplace_back(B, A, -x);
            res.emplace_back(B, v, x);
        }
    }

    cout << "YES\n" << (int) res.size() << "\n";

    for (auto el : res) {
        int u, v;
        ll x;
        tie(u, v, x) = el;
        cout << u << " " << v << " " << x << "\n";
    }

    return 0;
}