#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 78;
int a[maxN], b[maxN];
const ll INF = (ll)1e18;
ll dp[maxN][maxN];
int prv[maxN][maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> a[i] >> b[i];
        }
        vector < int > inds(n);
        iota(inds.begin(), inds.end(), 1);
        sort(inds.begin(), inds.end(), [&](int x, int y) {
            return b[x] < b[y];
        });
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                dp[i][j] = -INF;
            }
        }
        dp[0][0] = 0;
        for (int i = 0; i < n; i++) {
            for (int cnt = 0; cnt <= k; cnt++) {
                if (dp[i + 1][cnt] < dp[i][cnt] + (k - 1) * (b[inds[i]])) {
                    prv[i + 1][cnt] = 0;
                    dp[i + 1][cnt] = dp[i][cnt] + (k - 1) * (b[inds[i]]);
                }
                if (cnt + 1 <= k) {
                    if (dp[i + 1][cnt + 1] < dp[i][cnt] + cnt * b[inds[i]] + a[inds[i]]) {
                        dp[i + 1][cnt + 1] = dp[i][cnt] + cnt * b[inds[i]] + a[inds[i]];
                        prv[i + 1][cnt + 1] = 1;
                    }
                }
            }
        }
//           cout << dp[n][k] << '\n';
        vector < int > opers;
        vector < int > bef;
        int cnt = k;
        for (int i = n; i > 0; i--) {
            if (prv[i][cnt] == 0) {
                opers.emplace_back(-inds[i - 1]);
                opers.emplace_back(inds[i - 1]);
            }
            else {
                bef.emplace_back(inds[i - 1]);
                cnt--;
            }
        }
        reverse(opers.begin(), opers.end());
        reverse(bef.begin(), bef.end());
        cout << opers.size() + bef.size() << '\n';
        for (int c = 0; c + 1 < k; c++) cout << bef[c] << " ";
        for (int v : opers) cout << v << " ";
        cout << bef.back();
        cout << '\n';

    }
    return 0;
}