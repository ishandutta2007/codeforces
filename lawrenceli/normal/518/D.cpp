#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2005;

int n, t;
double p;
double dp[MAXN];

int main() {
    cin >> n >> p >> t;
    dp[0] = 1;
    for (int i=0; i<t; i++)
        for (int j=n; j>=0; j--)
            dp[j] = p*(j==0 ? 0 : dp[j-1]) + (j==n ? 1 : 1-p)*dp[j];
    double ans = 0;
    for (int i=0; i<=n; i++) ans += dp[i]*i;
    cout << fixed << setprecision(10) << ans;
}