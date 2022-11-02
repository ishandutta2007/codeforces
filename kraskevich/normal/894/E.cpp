#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

const int N = 1000 * 1000 + 10;

ll val[N];
ll sum[N];

void init() {
    for (int i = 1; i < N; i++) {
        val[i] = val[i - 1] + i;
        sum[i] = sum[i - 1] + val[i];
    }
}

ll get_tot(ll x) {
    if (x == 0)
        return 0;
    int pos = lower_bound(val, val + N, x) - val;
    return x * pos - sum[pos - 1]; 
}

vector<int> g[N];
vector<int> w[N];
vector<int> gr[N];

vector<int> gc[N];
vector<ll> wc[N];
ll size[N];
ll dp[N];
bool was[N];
int cur;
int comp[N];
vector<int> od;

void dfs(int v) {
    was[v] = true;
    for (int to : g[v])
        if (!was[to])
            dfs(to);
    od.push_back(v);
}

void dfs_comp(int v) {
    was[v] = true;
    comp[v] = cur;
    for (int to : gr[v])
        if (!was[to])
            dfs_comp(to);
}

ll calc_dp(int v) {
    if (was[v])
        return dp[v];
    was[v] = true;
    for (int i = 0; i < (int)gc[v].size(); i++) {
        int to = gc[v][i];
        ll len = wc[v][i];
        dp[v] = max(dp[v], len + calc_dp(to));
    }
    dp[v] += size[v];
    return dp[v];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    init();

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, ww;
        cin >> a >> b >> ww;
        --a;
        --b;
        g[a].push_back(b);
        w[a].push_back(ww);
        gr[b].push_back(a);
    }
    for (int i = 0; i < n; i++)
        if (!was[i])
            dfs(i);
    reverse(od.begin(), od.end());
    fill(was, was + n, false);
    for (int i : od)
        if (!was[i]) {
            dfs_comp(i);
            cur++;
        }

    fill(was, was + n, false);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < (int)g[i].size(); j++) {
            int to = g[i][j];
            ll len = w[i][j];
            if (comp[i] == comp[to])
                size[comp[i]] += get_tot(len);
            else {
                gc[comp[i]].push_back(comp[to]);
                wc[comp[i]].push_back(len);
            }
        }

    int s;
    cin >> s;
    --s;
    cout << calc_dp(comp[s]) << "\n";
}