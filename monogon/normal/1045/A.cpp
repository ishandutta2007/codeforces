
#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

const int N = 5005;
int n, m, ty[N];

struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap, long long flow) : v(v), u(u), cap(cap), flow(flow) {}
};

struct Dinic {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, long long cap) {
        edges.emplace_back(v, u, cap, 0);
        edges.emplace_back(u, v, cap, cap);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};

#define source (4 * m)
#define sink (5 * m + n + 1)
#define ship(i) (4 * m + (i))
#define weapon(i) (5 * m + (i))

int ans = 0;

void build(int i, int l, int r, Dinic &F) {
    if(l == r) {
        F.add_edge(i, ship(l), N);
        return;
    }
    int m = (l + r) / 2;
    F.add_edge(i, 2 * i + 1, N);
    F.add_edge(i, 2 * i + 2, N);
    build(2 * i + 1, l, m, F);
    build(2 * i + 2, m + 1, r, F);
}

void upd(int i, int l, int r, int L, int R, int w, Dinic &F) {
    if(r < L || R < l) return;
    if(L <= l && r <= R) {
        F.add_edge(weapon(w), i, 1);
        return;
    }
    int m = (l + r) / 2;
    upd(2 * i + 1, l, m, L, R, w, F);
    upd(2 * i + 2, m + 1, r, L, R, w, F);
}

bool used[N];
int cnt[N];

int assign(int u, Dinic &F) {
    if(u >= source) {
        return u - ship(0);
    }
    for(int i : F.adj[u]) {
        if(F.edges[i].u > u && F.edges[i].flow > 0) {
            F.edges[i].flow--;
            int x = assign(F.edges[i].u, F);
            if(x != -1) return x;
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    Dinic F = Dinic(sink + 1, source, sink);
    build(0, 1, m, F);
    rep(i, 1, n + 1) {
        cin >> ty[i];
        if(ty[i] == 0) {
            int k;
            cin >> k;
            while(k--) {
                int s;
                cin >> s;
                F.add_edge(weapon(i), ship(s), 1);
            }
            F.add_edge(source, weapon(i), 1);
        }else if(ty[i] == 1) {
            int l, r;
            cin >> l >> r;
            upd(0, 1, m, l, r, i, F);
            F.add_edge(source, weapon(i), 1);
        }else {
            int a, b, c;
            cin >> a >> b >> c;
            used[a] = used[b] = used[c] = true;
            ans += 2;
            F.add_edge(ship(a), weapon(i), 1);
            F.add_edge(ship(b), weapon(i), 1);
            F.add_edge(ship(c), weapon(i), 1);
            F.add_edge(weapon(i), sink, 1);
        }
    }
    rep(i, 1, m + 1) {
        if(!used[i]) {
            F.add_edge(ship(i), sink, 1);
        }
    }
    ans += F.flow();
    cout << ans << '\n';
    rep(w, 1, n + 1) {
        for(int i : F.adj[weapon(w)]) {
            int s = F.edges[i].u - ship(0);
            if(ty[w] == 1) {
                if(F.edges[i].u < source && F.edges[i].flow == 1) {
                    int sh = assign(F.edges[i].u, F);
                    assert(sh != -1);
                    cout << w << ' ' << sh << '\n';
                }
            }else if(s >= 1 && s <= m && F.edges[i].flow == 1) {
                if(ty[w] == 0 || cnt[w] < 2) {
                    cnt[w]++;
                    cout << w << ' ' << s << '\n';
                }
            }
        }
    }
}