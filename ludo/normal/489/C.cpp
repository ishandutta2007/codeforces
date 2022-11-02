#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define MAXM 100
#define MAXS 900

typedef long long ll;
typedef pair<int, int> pii;

int m, s;
pair<int, int> dp[MAXM + 1][MAXS + 1] = {};

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL

    cin >> m >> s;

    for (int i = 0; i <= s; i++) {
        int v = (i < 10) ? i : -1;
        dp[0][i] = make_pair(v, v);
//        cerr << dp[0][i].first << "," << dp[0][i].second << " ";
    }
//    cerr << endl;

    for (int i = 1; i < m; i++) {
        for (int j = 0; j <= s; j++) {
            int bmin = -1, bmax = -1;
            for (int d = i == m-1; d < 10 && d <= j; d++) {
                // place this digit op place i

                if (dp[i - 1][j - d].first >= 0 && (bmin == -1 || d < bmin)) {
                    bmin = d;
                }
                if (dp[i - 1][j - d].second >= 0 && (bmax == -1 || d > bmax)) {
                    bmax = d;
                }
            }

            dp[i][j] = make_pair(bmin, bmax);
//            cerr << dp[i][j].first << "," << dp[i][j].second << " ";
        }
//        cerr << endl;
    }

    if (dp[m - 1][s].first == -1 || dp[m - 1][s].second == -1) {
        cout << "-1 -1" << endl;
    } else {
        bool lz; // if leading zeros, skip the printing. When finding a number > 0, lz = false
        int t;

        lz = true; t = s;
        for (int n = m - 1; n >= 0; n--) {
            if (!lz || dp[n][t].first != 0 || m == 1) {
                lz = false;
                cout << dp[n][t].first;
            }
            t -= dp[n][t].first;
        }

        cout << " ";

        lz = true; t = s;
        for (int n = m - 1; n >= 0; n--) {
            if (!lz || dp[n][t].second != 0 || m == 1) {
                lz = false;
                cout << dp[n][t].second;
            }
            t -= dp[n][t].second;
        }

        cout << endl;
    }
    return 0;
}