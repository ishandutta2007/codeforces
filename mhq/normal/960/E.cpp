#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = (int)1e9 + 7;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
const int maxN = 2 * (int)1e5 + 10;
int V[maxN];
int n;
vector < int > g[maxN];
bool used[maxN];
int h_e;
int h_o;
int h[maxN];
int ans = 0;
void dfs1(int v) {
    used[v] = true;
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (used[to]) continue;
        h[to] = h[v] + 1;
        if (h[to] & 1) h_o++;
        else h_e++;
        dfs1(to);
    }
}
pair < int, int > dfs2(int v) {
    used[v] = true;
    int e, o;
    e = 0;
    o = 0;
    int cur = 0;
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (used[to]) continue;
        pair < int, int > q = dfs2(to);
        e += q.second;
        o += q.first;
        cur = sum(cur, mult(q.second, n - q.first - q.second));
        cur = sub(cur, mult(q.first, n - q.first - q.second));
    }
    //cout << v << " " << e << " " << o << endl;
    e += 1;
    //cout << v << " " << e << " " << o << endl;
    if ((h[v] & 1) == 0) {
        cur = sum(cur, mult((h_e - e), (n - (h_e - e) - (h_o - o))));
        cur = sub(cur, mult((h_o - o), (n - (h_e - e) - (h_o - o))));
    }
    else {
        //cout << v << endl;
        cur = sum(cur, mult(h_o - e, (n - (h_o - e) - (h_e - o))));
        cur = sub(cur, mult((h_e - o), (n - (h_o - e) - (h_e - o))));
    }
    cur = sum(cur, n);
    //cout << v << " " << cur << endl;
    ans = sum(ans, mult(cur, V[v]));
    //e += 1;
    return make_pair(e, o);
}
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> V[i];
        if (V[i] < 0) V[i] += mod;
        V[i] %= mod;
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(1);
    h_e++;
    //cout << h_e << " " << h_o << endl;
    memset(used, 0, sizeof used);
    dfs2(1);
    cout << ans;
    return 0;
}