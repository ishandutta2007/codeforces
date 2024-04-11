#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
bool dp[15][15][15][15][5];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        vector<int>v(n);
        int mx = 0;
        int sm = 0;
        for (int& c : v) {
            cin >> c;
            mx = max(mx, c);
            sm += c;
        }
        if (sm % 2 == 1 || 2 * mx > sm) {
            cout << "T\n";
        }
        else {
            cout << "HL\n";
        }
    }
    return 0;
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            for (int k = 0; k < 15; k++) {
                for (int t = 0; t < 15; t++) {
                    for (int where = 0; where <= 4; where++) {
                        dp[i][j][k][t][where] = false;
                        if (i > 0 && where != 0) dp[i][j][k][t][where] |= !dp[i - 1][j][k][t][0];
                        if (j > 0 && where != 1) dp[i][j][k][t][where] |= !dp[i][j - 1][k][t][1];
                        if (k > 0 && where != 2) dp[i][j][k][t][where] |= !dp[i][j][k - 1][t][2];
                        if (t > 0 && where != 3) dp[i][j][k][t][where] |= !dp[i][j][k][t - 1][3];
                        if (where == 4) {
                            if ((i + j + k + t) % 2 == 1) {
                                assert(dp[i][j][k][t][where] == true);
                            } else {
                                if (2 * max({i, j, k, t}) > i + j + k + t) {
                                    assert(dp[i][j][k][t][where] == true);
                                } else {
                                    assert(dp[i][j][k][t][where] == false);
                                }
                            }
//                        assert(dp[i][j][k][where])
                        }
//                    if (where == 3 && dp[i][j][k][where] == true && ((i + j + k) % 2 != 1) && 2 * max({i, j, k}) <= i + j + k) {
//                        cout << " HI " << i << " " << j << " " << k << endl;
//                    }
                    }
                }
            }
        }
    }
    return 0;
}