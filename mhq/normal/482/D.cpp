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
const int maxN = (int)1e5 + 10;
int n;
vector < int > g[maxN];
int dp[maxN][2];
void dfs(int v) {
    int t[] = {1, 0};
    int nxt[] = {0, 0};
    int coef[] = {1, 0};
    int nxt_coef[] = {0, 0};
    int all_zero = 1;
    for (int to : g[v]) {
        dfs(to);
        //cout << dp[to][0] << " " << dp[to][1] << endl;
        dp[to][0] = sum(dp[to][0], 1);
        all_zero = mult(all_zero, dp[to][0]);
        nxt[0] = nxt[1] = 0;
        nxt_coef[0] = nxt_coef[1] = 0;
        for (int cur = 0; cur < 2; cur++) {
            for (int res = 0; res < 2; res++) {
                nxt[(cur + res) & 1] = sum(nxt[(cur + res) & 1], mult(t[cur], dp[to][res]));
            }
        }
        for (int num = 0; num < 2; num++) {
            nxt_coef[num] = sum(nxt_coef[num], coef[num]);
            nxt_coef[num ^ 1] = sum(nxt_coef[num ^ 1], mult(coef[num], dp[to][1]));
        }
        for (int cur = 0; cur < 2; cur++) {
            t[cur] = nxt[cur];
            coef[cur] = nxt_coef[cur];
        }
    }
    int dif = sum(nxt_coef[0], all_zero);
    dp[v][1] = sum(all_zero, mult(2, sub(t[0], all_zero)));
    dp[v][0] = sum(nxt_coef[1], mult(2, sub(t[1], nxt_coef[1])));
    //cout << dp[v][0] << " " << dp[v][1] << " " << v << endl;
}
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        g[x].push_back(i);
    }
    dfs(1);
    cout << sum(dp[1][0], dp[1][1]);
    return 0;
}