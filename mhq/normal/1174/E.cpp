#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = (int)1e6 + 100;
int f[maxN];
int n;
vector < vector < int > > all;
vector < int > divs[maxN];
void gen(int x, vector < int > p) {
    p.push_back(x);
    if (x == 1) {
        all.push_back(p);
        return;
    }
    for (int to : divs[x]) {
        if (f[x] == f[to] + 1) {
            gen(to, p);
        }
    }
}
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
int fact[maxN], invfact[maxN], inv[maxN];
int cnk(int a, int b) {
    if (a < b)  return 0;
    return mult(fact[a], mult(invfact[b], invfact[a - b]));
}
int dp[22][maxN];
int solve(vector < int > all) {
   // for (auto t : all) cout << t << " ";
   // cout << endl;
    int m = all.size();
    vector < int > cnts(m);
   // cout << "--------------- cntare" << endl;
    for (int i = 0; i < m; i++) {
        cnts[i] = (n / all[i]);
      //  cout << cnts[i] << " ";
        if (i > 0) {
            cnts[i] = sub(cnts[i], n / all[i - 1]);
        }
    }
   // cout << endl;
   // cout << "---------" << endl;
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;
    int sm = 0;
    for (int i = 0; i <= m; i++) {
        for (int j = sm; j >= 0; j--) {
            if (!dp[i][j]) continue;
            if (j > 0) {
                dp[i][j - 1] = sum(dp[i][j - 1], mult(dp[i][j], j));
            }
            if (i < m) {
                dp[i + 1][j + cnts[i] - 1] = sum(dp[i + 1][j + cnts[i] - 1], mult(dp[i][j], cnts[i]));
            }
        }
        sm += cnts[i];
    }
    return dp[m][0];
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    f[1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 2 * i; j <= n; j += i) {
            divs[j].push_back(i);
            if (f[j] < f[i] + 1) {
                f[j] = f[i] + 1;
            }
        }
    }
    int mx = 0;
    for (int i = 1; i <= n; i++) mx = max(mx, f[i]);
    for (int i = 1; i <= n; i++) {
        if (f[i] == mx) {
            vector < int > cur;
            gen(i, cur);
        }
    }
    int ans = 0;
    for (auto t : all) {
        ans = sum(ans, solve(t));
    }
    cout << ans;
    return 0;
}