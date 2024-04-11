#include <bits/stdc++.h>
using namespace std;
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
int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
}
const int maxN = 4005;
const int maxK = 80;
int c[maxK][maxK];
int n, copn, k;
vector < int > g[maxN];
int f[maxK], t[maxK];
vector < int > dp[maxN][maxK];
bool used[maxN];
map < int, int > s[maxN];
int all[maxN][maxK];
void init() {
    for (int i = 1; i <= n; i++) {
        g[i].clear();
        for (int cyc = 0; cyc <= k; cyc++) {
            dp[i][cyc].clear();
            all[i][cyc] = 0;
        }
    }
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
        s[x][y] = g[x].size() - 1;
        s[y][x] = g[y].size() - 1;
    }
    for (int cyc = 0; cyc <= k; cyc++) f[cyc] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            if (j != 0) dp[i][j].resize(g[i].size() + 1, 0);
            else dp[i][j].resize(g[i].size() + 1, 1);
        }
        all[i][0] = 0;
    }
}
// cycle of length k, with no
void dfs(int v, int iter) {
    used[v] = true;
    if (iter >= 2) {
        for (int i = 0; i < g[v].size(); i++) {
            int to = g[v][i];
            int pos = s[to][v];
            all[v][iter] = sum(all[v][iter], dp[to][iter - 2][pos]);
        }
    }
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        int pos = s[to][v];
        if (!used[to]) dfs(to, iter);
        for (int cyc = 2; cyc <= iter; cyc++) {
            int res = sub(all[v][cyc], dp[to][cyc - 2][pos]);
            dp[v][iter][i] = sum(dp[v][iter][i], mult(res, dp[v][iter - cyc][i]));
        }
    }
    for (int cyc = 2; cyc <= iter; cyc++) {
        dp[v][iter].back() = sum(dp[v][iter].back(), mult(all[v][cyc], dp[v][iter - cyc].back()));
        //if (v == 1 && iter == 4 && cyc == 4) cout << "EHRE " << all[1][4] << endl;
        //if (v == 1 && iter == 4 && cyc == 4) cout << "EHRE " << dp[1][4].back() << endl;
    }
    //if (v == 1 && iter == 4) cout << dp[1][4].back() << " GO" << endl;
}
void go() {
    init();
    for (int iter = 1; iter <= k; iter++) {
        memset(used, 0, sizeof used);
        dfs(1, iter);
    }
    for (int j = 1; j <= n; j++) {
        for (int cyc = 0; cyc <= k; cyc++) f[cyc] = sum(f[cyc], dp[j][cyc].back());
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> copn >> k;
    c[0][0] = 1;
    for (int i = 1; i <= k; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= k; j++) {
            c[i][j] = sum(c[i - 1][j], c[i - 1][j - 1]);
        }
    }
    go();
    n = copn;
    for (int i = 0; i <= k; i++) t[i] = f[i];
    go();
    int ans = 0;
    for (int i = 0; i <= k; i++) ans = sum(ans, mult(c[k][i], mult(f[i], t[k - i])));
    cout << ans;
	return 0;
}