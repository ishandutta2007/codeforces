#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 105;

ll dp[N][N][N];
int c[N];
int p[N][N];
int n, m, k;

bool solve() {

    cin >> n >> m >> k;

    for(int i = 1;i <= n;i++) cin >> c[i];

    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++)
            cin >> p[i][j];
    }

    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= k;j++)
            for(int cl = 1;cl <= m;cl++)
                dp[j][i][cl] = inf64;

    for(int last = -1, i = 1;i <= n;i++) {
        if(c[i] > 0) {
            if(last != -1 && last != c[i]) break;
            else last = c[i];
        }
        if(last == -1) {
            for(int cl = 1;cl <= m;cl++) {
                dp[1][i][cl] = 0;
                for(int j = 1;j <= i;j++) {
                    if(c[j] == 0)
                        dp[1][i][cl] += p[j][cl];
                }
            }
        }else {
            dp[1][i][last] = 0;
            for(int j = 1;j <= i;j++)
                if(c[j] == 0)
                    dp[1][i][last] += p[j][last];
        }
    }

    for(int kk = 2;kk <= k;kk++) {
        for(int i = kk;i <= n;i++) {
            vec< ll > preff(m + 1, inf64), suff(m + 2, inf64);
            for(int cl = 1;cl <= m;cl++) {
                preff[cl] = min(preff[cl - 1], dp[kk - 1][i - 1][cl]);
            }
            for(int cl = m;cl >= 1;cl--) {
                suff[cl] = min(suff[cl + 1], dp[kk - 1][i - 1][cl]);
            }
            if(c[i] > 0) {
                int cl = c[i];
                dp[kk][i][cl] = min(
                        dp[kk][i - 1][cl],
                        min(preff[cl - 1], suff[cl + 1])
                );
            }else {
                for(int cl = 1;cl <= m;cl++) {
                    dp[kk][i][cl] = min(
                            dp[kk][i - 1][cl],
                            min(preff[cl - 1], suff[cl + 1])
                    ) + p[i][cl];
                }
            }
        }
    }

    /*cout << "\n";
    for(int kk = 1;kk <= k;kk++) {
        for(int i = 1;i <= n;i++) {
            for(int cl = 1;cl <= m;cl++)
                cout << dp[kk][i][cl] << ' ';
            cout << "\n";
        }
        cout << "\n\n";
    }*/

    ll res = inf64;

    for(int cl = 1;cl <= m;cl++) {
        res = min(res, dp[k][n][cl]);
    }

    cout << (res == inf64?-1 : res) << '\n';

    return true;
}

int main() {

#ifdef MY
    while(solve());
#else
    solve();
#endif

    return 0;
}