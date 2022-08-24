#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int mod = (int)1e9 + 7;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
const int maxN = (int)1e5 + 100;
int n, k;
vector < int > g[maxN];
const int maxK = 205;
int ans[maxK];
int s[maxK][maxK];
int sz[maxN];
int pw2[maxN];
int inv2[maxN];
int val[maxN];
int bad[maxK];
int ndp[maxK];
int dp[maxN][maxK];
void dfs(int v, int p) {
    for (int i = 0; i <= k; i++) {
        ndp[i] = 0;
    }
    vector < int > our_bad(k + 1);
    sz[v] = 1;
    dp[v][0] = 1;
    for (int to : g[v]) {
        if (to == p) continue;
        dfs(to, v);
        for (int x = 0; x <= min(k, sz[to]); x++) {
            our_bad[x] = sum(our_bad[x], dp[to][x]);
        }
        for (int x = 0; x <= min(sz[v] + sz[to], k); x++) {
            ndp[x] = 0;
        }
        for (int x = 0; x <= min(k, sz[v]); x++) {
            for (int y = 0; y <= sz[to] && x + y <= k; y++) {
                ndp[x + y] = sum(ndp[x + y], mult(dp[v][x], dp[to][y]));
            }
        }
        sz[v] += sz[to];
        for (int x = 0; x <= min(sz[v], k); x++) {
            dp[v][x] = ndp[x];
            ndp[x] = 0;
        }
    }
    // dp[v][i] - bad[i]
    for (int i = 0; i <= k; i++) {
        int need = sub(dp[v][i], our_bad[i]);
        ans[i] = sum(ans[i], need);
    }
    if (v == 1) return ;
    for (int x = 0; x <= k; x++) {
        ndp[x] = 0;
    }
    for (int x = 0; x + 1 <= k; x++) {
        if (x != 0) {
            ndp[x + 1] = dp[v][x];
        }
        else {
            ndp[x + 1] = val[sz[v]];
        }
        ans[x + 1] = sum(ans[x + 1], mult(ndp[x + 1], val[n - sz[v]]));
    }
    for (int x = 0; x <= k; x++) {
        dp[v][x] = sum(dp[v][x], ndp[x]);
    }
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    inv2[0] = 1;
    pw2[0] = 1;
    int inv = (mod + 1) / 2;
    for (int i = 1; i <= n; i++) {
        inv2[i] = mult(inv2[i - 1], inv);
        pw2[i] = mult(2, pw2[i - 1]);
        val[i] = sub(1, inv2[i]);
    }
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    s[0][0] = 1;
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= i; j++) {
            s[i][j] = sum(s[i - 1][j - 1], mult(j, s[i - 1][j]));
        }
    }
    dfs(1, -1);
    for (int i = 1; i <= k; i++) {
        ans[i] = mult(ans[i], pw2[n]);
    }
    int final_ans = 0;
    int fct = 1;
    for (int i = 1; i <= k; i++) {
        fct = mult(fct, i);
        final_ans = sum(final_ans, mult(s[k][i], mult(fct, ans[i])));
    }
    cout << final_ans;
    return 0;
}