#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 55;
int x[maxN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        string s;
        cin >> s;
        vector<int> dp(4, 1e9);
        dp[0] = 0;
        for (int i = 0; i < s.size(); i++) {
            vector<int> ndp(4, 1e9);
            for (int prv_mask = 0; prv_mask < 4; prv_mask++) {
                for (int ch = 0; ch < 2; ch++) {
                    if (!ch && i >= 2 && prv_mask % 2 == 0 && s[i] == s[i - 2]) continue;
                    if (!ch && i >= 1 && prv_mask < 2 && s[i] == s[i - 1]) continue;
                    ndp[prv_mask / 2 + 2 * ch] = min(ndp[prv_mask / 2 + 2 * ch], dp[prv_mask] + ch);
                }
            }
            dp = ndp;
        }
        cout << *min_element(dp.begin(), dp.end()) << '\n';
    }
    return 0;
}