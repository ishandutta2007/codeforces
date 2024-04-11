
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

template<typename C>
struct dinic {
    struct edge {
        int v;
        C cap, flow;
    };
    int n;
    vector<edge> e;
    vector<vector<int>> g;
    vector<int> level, p;
    dinic(int n) : g(n), p(n), level(n) {}
    void add_edge(int u, int v, C c) {
        int k = (int) e.size();
        e.push_back({v, c, 0});
        e.push_back({u, c, c});
        g[u].push_back(k);
        g[v].push_back(k ^ 1);
    }
    bool bfs(int s, int t) {
        fill(level.begin(), level.end(), -1);
        queue<int> Q;
        Q.push(s);
        level[s] = 0;
        while(!Q.empty()) {
            int x = Q.front(); Q.pop();
            for(int i : g[x]) {
                if(level[e[i].v] == -1 && e[i].flow < e[i].cap) {
                    level[e[i].v] = level[x] + 1;
                    Q.push(e[i].v);
                }
            }
        }
        return level[t] != -1;
    }
    C dfs(int x, int t, C amt) {
        if(x == t) return amt;
        for(int &i = p[x]; i < (int) g[x].size(); i++) {
            int idx = g[x][i];
            if(level[e[idx].v] == level[x] + 1 && e[idx].flow < e[idx].cap) {
                C a = dfs(e[idx].v, t, min(amt, e[idx].cap - e[idx].flow));
                if(a > 0) {
                    e[idx].flow += a;
                    e[idx ^ 1].flow -= a;
                    return a;
                }
            }
        }
        return 0;
    }
    C flow(int s, int t, C mx) {
        C f = 0;
        while(bfs(s, t)) {
            fill(p.begin(), p.end(), 0);
            while(true) {
                C d = dfs(s, t, mx - f);
                if(d == 0) break;
                f += d;
            }
        }
        return f;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<ll> d1(n), d2(n);
    rep(i, 0, n) cin >> d1[i];
    rep(i, 0, n) cin >> d2[i];
    sort(all(d1));
    sort(all(d2));
    // Assume p1 = 0
    // House 0 is at position -d1[0]
    // Assume p2 = -d1[0] +/- d2[i]
    vector<ll> positions;
    for(ll x : d1) {
        positions.push_back(x);
        positions.push_back(-x);
    }
    sort(all(positions));
    int p = sz(positions);
    positions.erase(unique(all(positions)), positions.end());
    for(ll d : d2) {
        for(ll p2 : {-d1[0] - d, -d1[0] + d}) {
            #define SOURCE 0
            #define SINK 1
            #define POS(x) (2 + (x))
            #define HOUSE1(x) (2 + p + (x))
            #define HOUSE2(x) (2 + p + n + (x))
            dinic<int> D(2 + p + n + n);
            rep(i, 0, n) {
                D.add_edge(SOURCE, HOUSE1(i), 1);
                D.add_edge(HOUSE2(i), SINK, 1);
            }
            rep(i, 0, n) {
                D.add_edge(HOUSE1(i), POS(lower_bound(all(positions), d1[i]) - positions.begin()), 1);
                D.add_edge(HOUSE1(i), POS(lower_bound(all(positions), -d1[i]) - positions.begin()), 1);
                int idx = lower_bound(all(positions), p2 - d2[i]) - positions.begin();
                if(idx < p && positions[idx] == p2 - d2[i]) {
                    D.add_edge(POS(idx), HOUSE2(i), 1);
                }
                idx = lower_bound(all(positions), p2 + d2[i]) - positions.begin();
                if(idx < p && positions[idx] == p2 + d2[i]) {
                    D.add_edge(POS(idx), HOUSE2(i), 1);
                }
            }
            int ans = D.flow(SOURCE, SINK, n);
            if(ans == n) {
                cout << "YES\n";
                vi h;
                rep(i, 0, n) {
                    for(int idx : D.g[HOUSE1(i)]) {
                        int v = D.e[idx].v;
                        if(v >= POS(0) && v <= POS(p - 1) && D.e[idx].flow == 1) {
                            h.push_back(positions[v - POS(0)]);
                            break;
                        }
                    }
                }
                const ll MX = 1e9;
                ll offset = max(0ll, -p2);
                for(ll x : h) {
                    offset = max(offset, -x);
                }
                for(ll x : h) {
                    cout << offset + x << ' ';
                }
                cout << '\n';
                cout << offset << ' ' << offset + p2 << '\n';
                return;
            }
        }
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}