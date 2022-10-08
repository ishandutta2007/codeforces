
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

string dirs = "LRUD";
map<char, int> ma = {{'L', 0}, {'R', 1}, {'U', 2}, {'D', 3}};
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int n, m;

bool ins(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

const int INF = 1e9;

struct edge {
    int v, flow, cap;
};

struct dinic {
    vector<edge> e;
    vector<vi> g;
    vi lvl, p;
    int n;
    dinic(int n) : n(n) {
        g.resize(n);
        lvl.resize(n);
        p.resize(n);
    }
    void add_edge(int u, int v, int w) {
        int k = sz(e);
        e.push_back({v, 0, w});
        e.push_back({u, w, w});
        g[u].push_back(k);
        g[v].push_back(k + 1);
    }
    int dfs(int x, int t, int amt) {
        if(x == t) return amt;
        for(int &idx = p[x]; idx < sz(g[x]); idx++) {
            int i = g[x][idx];
            if(e[i].flow < e[i].cap && lvl[x] + 1 == lvl[e[i].v]) {
                int val = dfs(e[i].v, t, min(amt, e[i].cap - e[i].flow));
                if(val > 0) {
                    e[i].flow += val;
                    e[i ^ 1].flow -= val;
                    return val;
                }
            }
        }
        return 0;
    }
    bool bfs(int s, int t) {
        fill(all(lvl), -1);
        lvl[s] = 0;
        queue<int> Q;
        Q.push(s);
        while(!Q.empty()) {
            int x = Q.front(); Q.pop();
            for(int i : g[x]) {
                if(lvl[e[i].v] == -1 && e[i].flow < e[i].cap) {
                    lvl[e[i].v] = lvl[x] + 1;
                    Q.push(e[i].v);
                }
            }
        }
        return lvl[t] != -1;
    }
    int flow(int s, int t) {
        int ans = 0;
        while(bfs(s, t)) {
            fill(all(p), 0);
            int val = 0;
            while((val = dfs(s, t, INF)) > 0) {
                ans += val;
            }
        }
        return ans;
    }
};

void solve() {
    cin >> n >> m;
    vector<vi> a(n);
    vector<string> dir(n, string(m, '?'));
    rep(i, 0, n) {
        a[i].assign(m, 0);
        rep(j, 0, m) {
            cin >> a[i][j];
        }
    }
    rep(i, 0, n) {
        rep(j, 0, m) {
            rep(d, 0, 4) {
                int x = i + dx[d];
                int y = j + dy[d];
                if(ins(x, y) && a[i][j] > a[x][y]) {
                    dir[i][j] = dirs[d];
                }
            }
        }
    }
    int s = n * m, t = n * m + 1;
    int snew = n * m + 2, tnew = n * m + 3;
    dinic F(n * m + 4);
    int w1 = 0, w2 = 0;
    rep(i, 0, n) {
        rep(j, 0, m) {
            if((i + j) % 2 == 0) {
                if(dir[i][j] == '?') {
                    w1++;
                    F.add_edge(snew, i * m + j, 1);
                }else {
                    F.add_edge(s, i * m + j, 1);
                }
                rep(d, 0, 4) {
                    int x = i + dx[d];
                    int y = j + dy[d];
                    if(ins(x, y) && a[x][y] == a[i][j]) {
                        F.add_edge(i * m + j, x * m + y, 1);
                    }
                }
            }else {
                if(dir[i][j] == '?') {
                    w2++;
                    F.add_edge(i * m + j, tnew, 1);
                }else {
                    F.add_edge(i * m + j, t, 1);
                }
            }
        }
    }
    F.add_edge(t, s, INF);
    F.add_edge(snew, t, w2);
    F.add_edge(s, tnew, w1);
    F.flow(snew, tnew);
    rep(i, 0, n) {
        rep(j, 0, m) {
            if((i + j) % 2 == 0) {
                for(int idx : F.g[i * m + j]) {
                    int pos = F.e[idx].v;
                    if(F.e[idx].flow == F.e[idx].cap && pos < n * m) {
                        int x = pos / m, y = pos % m;
                        rep(d, 0, 4) {
                            if(x == i + dx[d] && y == j + dy[d]) {
                                dir[i][j] = dirs[d];
                                dir[x][y] = dirs[d ^ 1];
                            }
                        }
                    }
                }
            }
        }
    }
    rep(i, 0, n) rep(j, 0, m) {
        if(dir[i][j] == '?') {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    rep(i, 0, n) {
        rep(j, 0, m) {
            int d = ma[dir[i][j]];
            int x = i + dx[d];
            int y = j + dy[d];
            if(a[i][j] == a[x][y]) {
                cout << ((i + j) % 2 == 0 ? a[i][j] - 1 : 1) << ' ';
            }else {
                cout << a[i][j] - a[x][y] << ' ';
            }
        }
        cout << '\n';
    }
    rep(i, 0, n) {
        rep(j, 0, m) {
            cout << dir[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        solve();
    }
}