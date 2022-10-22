#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

const int mod = 998244353;
const int N = 2e5 + 5;

int _mul(int a, int b) {
    return (1ll * a * b) % mod;
}

int n;
vector<int> g[N];
int dp[N];
int fact[N];

void dfs(int v, int par = -1) {
    dp[v] = 1;
    int cn = 0;
    for (int to : g[v]) {
        if (to == par) continue;
        dfs(to, v);
        dp[v] = _mul(dp[v], dp[to]);
        cn++;
    }
    dp[v] = _mul(dp[v], fact[cn + 1]);
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = _mul(fact[i - 1], i);
    }

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int u, v, i = 1; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);

    int res = _mul(n, fact[(int)g[1].size()]);
    for (int to : g[1]) {
        res = _mul(res, dp[to]);
    }

    cout << res << "\n";

    return 0;
}