#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = 2 * (int)1e5 + 100;
int dp[maxN][2];
int n;
vector < int > g[maxN];
const int mod = 998244353;
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
void dfs(int v) {
    int n = g[v].size();
    vector < int > pref(n + 1), suf(n + 1);
    for (int to : g[v]) dfs(to);
    pref[0] = 1;
    suf[n] = 1;
    for (int i = 0; i < g[v].size(); i++) {
        pref[i + 1] = mult(pref[i], dp[g[v][i]][0]);
    }
    for (int i = n - 1; i >= 0; i--) {
        suf[i] = mult(suf[i + 1], dp[g[v][i]][0]);
    }
    int all = 1;
    int all1 = 0;
    for (int i = 0; i < n; i++) {
        all = mult(all, sum(dp[g[v][i]][0], dp[g[v][i]][1]));
        all1 = sum(all1, mult(dp[g[v][i]][1], mult(pref[i], suf[i + 1])));

    }
    dp[v][0] = sub(all, all1);
    dp[v][1] = sub(all, pref[n]);
    if (n == 0) dp[v][1] = 1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        g[x].push_back(i);
    }
    dfs(1);
    cout << dp[1][0];
    return 0;
}