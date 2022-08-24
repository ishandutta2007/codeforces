#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = (int)1e6 + 10;
vector < pair < char, int > > g[maxN];
int n;
bool can[maxN];
int dp[maxN];
const int INF = (int)1e9;
int bal[maxN];
int k;
bool used[maxN];
int a[maxN];
void dfs(int v, int& cur) {
    bal[v] = cur;
    if (used[v]) {
        cur++;
    }
    sort(g[v].begin(), g[v].end());
    for (auto it : g[v]) {
        dfs(it.second, cur);
    }
}
int h[maxN];
void calc(int v, int val, int sec) {
    dp[v] = min(dp[v], val + h[v]);
    if (used[v]) {
        dp[v] = min(dp[v], sec + bal[v] + 1);
    }
    for (auto it : g[v]) {
        h[it.second] = h[v] + 1;
        calc(it.second, min(val, dp[v] - h[v]), min(sec, dp[v] - bal[v]));
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int p;
        char c;
        cin >> p >> c;
        g[p].emplace_back(c, i);
    }
    cin >> k;
    for (int i = 0; i <= n; i++) {
        dp[i] = INF;
    }
    for (int i = 1; i <= k; i++) {
        cin >> a[i];
        used[a[i]] = true;
    }
    dp[0] = 0;
    int p = 1;
    dfs(0, p);
    calc(0, INF, INF);
    for (int i = 1; i <= k; i++) cout << dp[a[i]] << " ";
    cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst = 1;
//    cin >> tst;
    while (tst--) solve();
    return 0;
}