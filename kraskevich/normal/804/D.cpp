#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int N = 100 * 1000 + 10;

vector<int> g[N];
int max_dist[N];
int diam[N];
int comp[N];
int h[N];
vector<int> at[N];
vector<int> d_at[N];
vector<ll> sd[N];
bool was[N];
map<pii, double> mem;
int curc;

int dfs1(int v, int par) {
    comp[v] = curc;
    at[curc].push_back(v);
    for (int to : g[v]) {
        if (to == par)
            continue;
        h[v] = max(h[v], dfs1(to, v) + 1);
    }
    return h[v];
}

void dfs2(int v, int par, int low) {
    max_dist[v] = max(low, h[v]);
    d_at[comp[v]].push_back(max_dist[v]);
    vector<int> kids(1);
    for (int to : g[v])
        if (to != par)
            kids.push_back(h[to] + 1);
    sort(kids.rbegin(), kids.rend());
    for (int to : g[v])
        if (to != par) {
            int kh = (kids[0] == h[to] + 1) ? kids[1] : kids[0];
            dfs2(to, v, max(low, kh) + 1);
        } 
}

int dist[N];

void bfs(int st, int c) {
    for (int v : at[c])
        dist[v] = N;
    dist[st] = 0;
    queue<int> q;
    q.push(st);
    while (q.size()) {
        int v = q.front();
        q.pop();
        for (int to : g[v])
            if (dist[to] > dist[v] + 1) {
                dist[to] = dist[v] + 1;
                q.push(to);
            }
    }
}

void pre(int c) {
    int v = at[c][0];
    for (int rep = 0; rep < 2; rep++) {
        bfs(v, c);
        int x = v;
        for (int y : at[c])
            if (dist[y] > dist[x])
                x = y;
        v = x;
    }
    for (int y : at[c])
        diam[y] = dist[v];
    sort(d_at[c].begin(), d_at[c].end());
    ll curs = 0;
    for (int d : d_at[c]) {
        curs += d;
        sd[c].push_back(curs);
    }
}

double solve(int a, int b) {
    ll dd = max(diam[a], diam[b]);
    a = comp[a];
    b = comp[b];
    if (at[a].size() > at[b].size())
        swap(a, b);
    if (mem.count(pii(a, b)))
        return mem[pii(a, b)];
    ll cnt = at[a].size() * 1ll * at[b].size();
    ll sum = 0;
    for (int d : d_at[a]) {
        int x = d + 1;
        int l = lower_bound(d_at[b].begin(), d_at[b].end(), dd - x) - d_at[b].begin();
        sum += l * dd;
        sum += x * ((int)d_at[b].size() - l) + sd[b].back() - (l == 0 ? 0 : sd[b][l - 1]);
    }
    return mem[pii(a, b)] = (sum * 1.0 / cnt);
}

    
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    fill(comp, comp + n, -1);
    for (int i = 0; i < n; i++) 
        if (comp[i] == -1) {
            dfs1(i, i);
            curc++;
            dfs2(i, i, 0);
            pre(curc - 1);
        }
    /*
    for (int i = 0; i < n; i++)
        cout << diam[i] << " ";
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << max_dist[i] << " ";
    cout << endl;
    */
    while (q--) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        if (comp[a] == comp[b])
            cout << -1 << "\n";
        else
            cout << solve(a, b) << "\n";
    }
}