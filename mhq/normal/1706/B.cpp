#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n;
const int maxN = 1e5 + 10;
int dp[maxN];
int c[maxN];
int best[maxN];
vector<int> vals[maxN];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) vals[i].clear();
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        vals[c[i]].emplace_back(i);
    }
    for (int i = 1; i <= n; i++) {
        int f[2] = {0, 0};
        for (int x : vals[i]) {
            int clr = x % 2;
            f[clr] = max(f[clr], f[clr ^ 1] + 1);
        }
        cout << max(f[0], f[1]) << " ";
    }
//    for (int i = 1; i <= n; i++) {
//        dp[i] = 1;
//        if (i > 1 && c[i] == c[i - 1]) {
//            dp[i] = max(dp[i], dp[i - 1] + 1);
//        }
//        if (i > 2 && c[i] == c[i - 2]) {
//            dp[i] = max(dp[i], dp[i - 2] + 1);
//        }
//        best[c[i]] = max(best[c[i]], dp[i]);
//    }
//    for (int i = 1; i <= n; i++) cout << best[i] << " ";
    cout << '\n';

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int tst;
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}