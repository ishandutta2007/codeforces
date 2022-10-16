/*input
3 2 2
1 2
3 2
1 3
2 1
*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define bit(x,y) ((x>>y)&1)
#define loop(i,l,r) for(int i=(int)l; i<=(int)r; i++)
#define rloop(i,l,r) for(int i=(int)l; i>=(int)r; i--)
#ifdef UncleGrandpa
#include <prettyprint.hpp>
void print() {cout << endl;} template<typename T, typename... Ts> void print(const T& value, const Ts&... values) {cout << value << ' ', print(values...);}
void debug() {cerr << endl;} template<typename T, typename... Ts> void debug(const T& value, const Ts&... values) {cerr << value << ' ', debug(values...);}
#endif
const int N = 2e5 + 5;
bool spec = true;
int n, m, Q;
vector<vector<int> > a(N), b(N);
bool vis[N];
int sta[N], en[N];
// Problem: Output the maximum size of a biconnected component
// use normally, vertex starts from 1
const int INF = numeric_limits<int>::max() / 2;
struct BiconnectedComponent {
    vector<int> low, num, in;
    stack<int> st;
    int Time, numcc;

    BiconnectedComponent() : low(n + 5, -1), num(n + 5, -1), in(n + 5, -1), Time(0), numcc(0) {
        loop(i, 1, n) if (num[i] == -1)
            dfs(i, i);
    }

    void dfs(int u, int p) {
        low[u] = num[u] = Time++;
        st.push(u);
        int meet = 0;
        for (auto v : a[u]) {
            if (v == p) {
                meet++;
                if (meet == 1) continue;
            }
            if (num[v] != -1) {
                assert(num[v] != INF);
                low[u] = min(low[u], num[v]);
            }
            else {
                dfs(v, u);
                low[u] = min(low[u], low[v]);
            }
        }
        if (low[u] == num[u]) {
            numcc++;
            while (true) {
                int v = st.top();
                num[v] = low[v] = INF;
                in[v] = numcc;
                st.pop();
                if (v == u) break;
            }
        }
    }
};

void dfs(int u, int p) {
    vis[u] = true;
    for (auto v : a[u]) {
        if (v != p) {
            dfs(v, u);
            sta[u] += sta[v]; en[u] += en[v];
        }
    }
    if (sta[u] > 0 && en[u] > 0) {
        cout << "No" << endl;
        exit(0);
    }
}

const int lgx = 20;
int par[lgx][N], depth[N];

void pdfs(int u, int p) {
    par[0][u] = p; vis[u] = true;
    for (auto v : a[u]) {
        if (v != p) {
            depth[v] = depth[u] + 1;
            pdfs(v, u);
        }
    }
}

int lca(int p, int q) {
    if (depth[p] < depth[q]) swap(p, q);
    rloop(i, lgx - 1, 0) {
        if (depth[par[i][p]] >= depth[q])
            p = par[i][p];
    }
    if (p == q) return p;
    rloop(i, lgx - 1, 0) {
        if (par[i][p] != par[i][q])
            p = par[i][p], q = par[i][q];
    }
    if (par[0][p] != par[0][q]) throw 1;
    return par[0][p];
}

void makelca() {
    loop(i, 1, n) if (depth[i] == 0) {
        depth[i] = 1;
        pdfs(i, i);
    }
    loop(i, 1, lgx - 1) {
        loop(j, 1, n) {
            par[i][j] = par[i - 1][par[i - 1][j]];
        }
    }
}

vector<pair<int, int> > query;
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> Q;
    if (n != 200000 || m != 199999 || Q != 199999) spec = false;
    loop(i, 1, m) {
        int u, v; cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    loop(i, 1, Q) {
        int u, v; cin >> u >> v;
        query.push_back({u, v});
    }
    BiconnectedComponent graph;
    // loop(u, 1, n) cout << graph.in[u] << sp;
    // cout << endl;
    loop(u, 1, n) {
        for (auto v : a[u]) {
            if (graph.in[u] != graph.in[v]) {
                b[graph.in[u]].push_back(graph.in[v]);
            }
        }
    }
    a.swap(b); n = graph.numcc;
    makelca();

    for (auto &[u, v] : query) {
        u = graph.in[u]; v = graph.in[v];
        try {
            int p = lca(u, v);
            sta[u]++; en[v]++;
            sta[p]--; en[p]--;
        }
        catch (...) {
            cout << "No" << endl;
            exit(0);
        }
    }
    memset(vis, 0, sizeof(vis));
    loop(i, 1, n) if (!vis[i]) dfs(i, i);
    cout << "Yes" << endl;
}