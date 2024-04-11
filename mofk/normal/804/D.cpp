#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;
typedef pair <int, int> ii;

const int big = 1000;
int N, M, Q;
vi adj[100005];
int f[100005];
int g[100005];
int g2[100005];
int mx[100005];
int dad[100005];
int id[100005];
vi val[100005];
vi ssum[100005];
int root;
map <ii, double> answer;

void dfs_down(int u) {
    id[u] = root;
    val[root].pb(u);
    g[u] = 1;
    ff(i, 0, (int)adj[u].size() - 1) {
        int v = adj[u][i];
        if (v == dad[u]) continue;
        dad[v] = u;
        dfs_down(v);
        if (g[u] < g[v] + 1) g2[u] = g[u], g[u] = g[v] + 1;
        else g2[u] = max(g2[u], g[v] + 1);
    }
}

void dfs_up(int u) {
    ff(i, 0, (int)adj[u].size() - 1) {
        int v = adj[u][i];
        if (v == dad[u]) continue;
        f[v] = f[u] + 1;
        if (g[u] == g[v] + 1) f[v] = max(f[v], g2[u] + 1);
        else f[v] = max(f[v], g[u] + 1);
        dfs_up(v);
    }
}

void go(int u) {
    root = u;
    dfs_down(u);
    dfs_up(u);
    ff(i, 0, (int)val[u].size() - 1) {
        int tmp = val[u][i];
        val[u][i] = max(f[tmp], g[tmp]);
        mx[u] = max(mx[u], val[u][i]);
    }
    sort(val[u].begin(), val[u].end());
    ssum[u].assign(val[u].size() + 1, 0);
    fb(i, (int)val[u].size() - 1, 0) ssum[u][i] = ssum[u][i+1] + val[u][i];
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(12);
    cin >> N >> M >> Q;
    int u, v;
    ff(i, 1, M) cin >> u >> v, adj[u].pb(v), adj[v].pb(u);
    ff(i, 1, N) if (!dad[i]) go(i);
    ff(i, 1, Q) {
        cin >> u >> v;
        if (id[u] == id[v]) {
            cout << -1 << '\n';
            continue;
        }
        u = id[u], v = id[v];
        if (val[u].size() > val[v].size()) swap(u, v);
        if (answer.find(ii(u, v)) != answer.end()) {
            cout << fixed << answer[ii(u, v)] << '\n';
            continue;
        }
        int thres = max(mx[u], mx[v]);
        ll ans = 0;
        ff(i, 0, (int)val[u].size() - 1) {
            int pos = lower_bound(val[v].begin(), val[v].end(), thres - val[u][i]) - val[v].begin();
            ans += 1ll * thres * pos + 1ll * val[u][i] * (val[v].size() - pos) + ssum[v][pos];
        }
        double real_ans = (double)ans / (1ll * val[u].size() * val[v].size()) - 1;
        answer[ii(u, v)] = real_ans;
        cout << fixed << real_ans << '\n';
    }
    return 0;
}