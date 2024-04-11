#include <bits/stdc++.h>
using namespace std;
const int maxN = 3005;
const int mod  = (int)1e9 + 7;
int n, d;
int val[maxN][maxN];
vector < int > g[maxN];
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
    for (int i = 0; i < g[v].size(); i++) {
        dfs(g[v][i]);
    }
    for (int i = 1; i <= n; i++) {
        val[v][i] = val[v][i - 1];
        int cur = 1;
        for (int j = 0; j < g[v].size(); j++) {
            cur = mult(cur, val[g[v][j]][i]);
        }
        val[v][i] = sum(val[v][i], cur);
    }
}
int f[maxN];
int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
}
int inv(int i) {
    return pw(i, mod - 2);
}
int iinv[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> d;
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        g[x].push_back(i);
    }
    dfs(1);
    for (int i = 1; i <= n; i++) {
        f[i] = val[1][i];
        iinv[i] = inv(i);
    }
    if (d <= n) {
        cout << f[d];
        return 0;
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        int cur = f[i];
        for (int j = 0; j <= n; j++) {
            if (j == i) continue;
            cur = mult(cur, d - j);
            cur = mult(cur, iinv[abs(i - j)]);
        }
        if ((n - i) % 2 == 0) ans = sum(ans, cur);
        else ans = sub(ans, cur);
    }
    cout << ans;
    return 0;
}