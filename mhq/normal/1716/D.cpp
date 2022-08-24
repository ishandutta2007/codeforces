#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
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
int n, k;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    cin >> n >> k;
    vector<int> dp(n + 1);
    int tot = 0;
    dp[0] = 1;
    int ss = 0;
    vector<int> fin_ans(n + 1);
    for (int i = 0; ; i++) {
        ss += (k + i);
        if (ss > n) break;
        vector<int> ndp(n + 1);
        int T = k + i;
        for (int x = 0; x <= n; x++) {
            if (x >= T) {
                ndp[x] = sum(ndp[x - T], dp[x - T]);
            }
        }
        for (int p = 0; p <= n; p++) {
            fin_ans[p] = sum(fin_ans[p], ndp[p]);
            dp[p] = ndp[p];
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << fin_ans[i] << " ";
    }
    return 0;
}