
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

// assign edges to vertices such that:
// a vertex is assigned at most min(k, floor(deg / 2)) edges
// an edge is assigned an adjacent vertex
// we want maximum matching
// we want to assign it deg - k "copy" edges

const int N = 605;
int n, m, k, u[N], v[N];

struct edge {
    int u, v, rev;
    ll cap, flow;
};
vector<edge> e;
vi adj[2 * N];

void add_edge(int u, int v, ll w) {
    int k = sz(e);
    e.push_back({u, v, k + 1, w, 0});
    e.push_back({v, u, k, w, w});
    adj[u].push_back(k);
    adj[v].push_back(k + 1);
}

ll ans = 0;
ll f[2 * N];
int par[2 * N];
bool vis[2 * N];

bool send_flow(int s, int t) {
    fill(vis, vis + t + 1, false);
    f[s] = LLONG_MAX;
    vis[s] = true;
    queue<int> Q;
    Q.push(s);
    while(!Q.empty()) {
        int x = Q.front(); Q.pop();
        if(x == t) {
            ans += f[t];
            while(x != s) {
                e[par[x]].flow += f[t];
                e[e[par[x]].rev].flow -= f[t];
                x = e[par[x]].u;
            }
            return true;
        }
        for(int i : adj[x]) {
            if(!vis[e[i].v] && e[i].flow < e[i].cap) {
                f[e[i].v] = min(f[x], e[i].cap - e[i].flow);
                vis[e[i].v] = true;
                par[e[i].v] = i;
                Q.push(e[i].v);
            }
        }
    }
    return false;
}

int deg[N], c[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m >> k;
        e.clear();
        rep(i, 0, n + m + 2) adj[i].clear();
        fill(deg + 1, deg + n + 1, 0);
        // 0 = source
        // i = vertex
        // n + i + 1 = edge
        // n + m + 1 = sink
        rep(i, 0, m) {
            cin >> u[i] >> v[i];
            add_edge(u[i], n + i + 1, 1);
            add_edge(v[i], n + i + 1, 1);
            add_edge(n + i + 1, n + m + 1, 1);
            deg[u[i]]++;
            deg[v[i]]++;
        }
        bool flag = false;
        ll sum = 0;
        rep(i, 1, n + 1) {
            if(deg[i] > 2 * k) flag = true;
            add_edge(0, i, max(0, 2 * (deg[i] - k)));
            sum += max(0, 2 * (deg[i] - k));
        }
        if(flag) {
            rep(i, 0, m) {
                cout << "0 ";
            }
            cout << '\n';
            continue;
        }

        ans = 0;
        while(send_flow(0, n + m + 1));
        if(ans != sum) {
            rep(i, 0, m) {
                cout << "0 ";
            }
            cout << '\n';
            continue;
        }
        rep(i, 0, m) c[i] = i + 1;
        rep(i, 1, n + 1) {
            vi ve;
            for(int j : adj[i]) {
                int k = e[j].v - n - 1;
                if(k >= 0 && k < m && e[j].flow == 1) {
                    ve.push_back(k);
                }
            }
            assert(sz(ve) % 2 == 0);
            while(!ve.empty()) {
                int x = ve.back(); ve.pop_back();
                int y = ve.back(); ve.pop_back();
                c[y] = c[x];
            }
        }
        rep(i, 0, m) {
            cout << c[i] << ' ';
        }
        cout << '\n';
    }
}