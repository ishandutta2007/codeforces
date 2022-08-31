#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 103, inf = 1000111222;

int dp[2][max_n][max_n * max_n];

int n;
int a[max_n];
int b[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    int sumw = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        sumw += b[i];
    }
    for (int i = 0; i <= n + 1; ++i) {
        for (int j = 0; j <= sumw; ++j) {
            dp[0][i][j] = -inf;
        }
    }
    dp[0][0][0] = 0;
    int cur = 0;
    int prev = 1;
    for (int i = 0; i < n; ++i) {
        swap(cur, prev);
        for (int j = 0; j <= n + 1; ++j) {
            for (int k = 0; k <= sumw; ++k) {
                dp[cur][j][k] = -inf;
            }
        }
        dp[cur][0][0] = 0;
        for (int took = 1; took <= i + 1; ++took) {
            for (int have = 0; have <= min(100 * took, sumw); ++have) {
                //dp[cur][took][have] = -inf;
                dp[cur][took][have] = max(dp[cur][took][have], dp[prev][took][have]);
                //cout << "$ " << have << ' ' << b[i] << endl;
                if (have >= b[i]) {
                  /*  if (took == 1 && have == 5) {
                        cout << "$$$" << endl;
                    }*/
                    dp[cur][took][have] = max(dp[cur][took][have], dp[prev][took - 1][have - b[i]] + a[i]);
                }
            }
        }
      //  cout << "$ " << dp[cur][1][5] << endl;
    }
    //cout << "$ " << dp[cur][1][5] << endl;
    for (int k = 1; k <= n; ++k) {
        ld ans = 0;
        for (int have = 0; have <= sumw; ++have) {
            ld other = sumw - have;
            int space = dp[cur][k][have];
            if (space < 0) {
                continue;
            }
            //cout << have << ' ' << other << ' ' << space << endl;
            ans = max<ld>(ans, have + min<ld>(other / 2, space - have));
        }
        printf("%.10f ", double(ans));
    }


    return 0;
}