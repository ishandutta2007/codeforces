#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define mp make_pair
#define MOD 1000000007
#define pii pair<ll, ll>
#define INF ((ll)1e+18)
typedef long long ll;
int Abs(int x) {
    return x>0?x:-x;
}

ll n, dp[105][105], a[105], dpm[105][105];
ll fnd(ll x, ll y) {
    if (x > y)
        return 0;
    return dp[x][y];
}
int main() {
    //freopen("input.txt", "r", stdin);
    /*ll sum = 0;
    for (int i = 0; i < 100; i++)
    for (int j = i; j < 100; j++) {
        for (int k = 0; k < (j-i+1); k++)
            sum += (j-i+1)*(j-i)/2;
    }
    cout << sum << endl;*/
    string s;
    cin >> n;
    cin >> s;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
        dp[i][i] = a[1];
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j + i <= n; j++) {
            int b[2];
            b[0] = b[1] = 0;
            for (int k = j; k < j+i; k++) {
                b[s[k]-'0']++;
            }
            ll ans = 0;
            for (int num = 0; num < 2; num++) {
                for (int am = 1; am <= b[num]; am++) {
                    for (int k = j; k < j+i; k++)
                        dpm[k][am] = -INF;
                }

                if (b[num] == 0)
                    continue;

                for (int k = j; k < j+i; k++)
                if (s[k] - '0' == num) {
                    dpm[k][1] = fnd(j, k-1);
                    ans = max(ans, dpm[k][1] + a[1] + fnd(k+1, j+i-1));
                }
                for (int am = 2; am <= b[num]; am++) {
                    for (int k = j; k < j+i; k++) {
                        if (s[k] - '0' != num)
                            continue;
                        for (int l = j; l < k; l++)
                            dpm[k][am] = max(dpm[k][am], dpm[l][am-1] + fnd(l+1, k-1));
                        ans = max(ans, dpm[k][am] + a[am] + fnd(k+1, j+i-1));
                    }

                }
            }
            dp[j][j+i-1] = ans;
            //cout << j << " " << j+i-1 << " " << ans << endl;
        }
    }
    cout << dp[0][n-1] << endl;
    return 0;
}