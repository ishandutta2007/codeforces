#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1000011, inf = 1000111222, max_a = 10;

int m[max_n];

int dp[max_a][max_a][max_a];
int dpp[max_a][max_a][max_a];
int c[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, MX;
    cin >> n >> MX;
    for (int i = 0; i < n; ++i) {
        //m[i] = rand() % MX;
        scanf("%d", m + i);
    }
    int ans = 0;
    sort(m, m + n);
    vector<int> v;
    int cnt = 1;
    for (int i = 1; i < n; ++i) {
        if (m[i] != m[i - 1]) {
            while (cnt > max_a - 1) {
                cnt -= 3;
                ++ans;
            }
            c[m[i - 1]] = cnt;
            cnt = 1;
        } else {
            ++cnt;
        }
    }
    ////////////
    while (cnt > max_a - 1) {
        cnt -= 3;
        ++ans;
    }
    c[m[n - 1]] = cnt;
    ////////////


    for (int i = 0; i < max_n; ++i) {
        int cim1 = (i - 1 >= 0 ? c[i - 1] : 0);
        int cim2 = (i - 2 >= 0 ? c[i - 2] : 0);
        int cim3 = i > 2 ? c[i - 3] : 0;
        for (int i = 0; i < max_a; ++i) {
            for (int j = 0; j < max_a; ++j) {
                for (int k = 0; k < max_a; ++k) {
                    dp[i][j][k] = 0;
                }
            }
        }

        for (int cc = 0; cc <= c[i]; ++cc) {
            for (int cp = 0; cp <= cim1; ++cp) {
                for (int cpp = 0; cpp <= cim2; ++cpp) {
                    int dpval = 0;
                    if (cc == 0) {
                        for (int j = 0; j <= cim3; ++j) {
                            dpval = max(dpval, dpp[cp][cpp][j]);
                        }
                    } else {
                        if (cc >= 3) {
                            dpval = max(dpval, dp[cc - 3][cp][cpp] + 1);
                        }
                        if (cp && cpp) {
                            dpval = max(dpval, dp[cc - 1][cp - 1][cpp - 1] + 1);
                        }
                    }
                    dp[cc][cp][cpp] = dpval;
                }
            }
        }
        for (int i = 0; i < max_a; ++i) {
            for (int j = 0; j < max_a; ++j) {
                for (int k = 0; k < max_a; ++k) {
                    dpp[i][j][k] = dp[i][j][k];
                }
            }
        }
    }
    int ans2 = -inf;
    for (int i = 0; i < max_a; ++i) {
        for (int j = 0; j < max_a; ++j) {
            for (int k = 0; k < max_a; ++k) {
                ans2 = max(ans2, dp[i][j][k]);
            }
        }
    }
    cout << ans + ans2 << endl;

    return 0;
}