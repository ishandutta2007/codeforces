#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

const int MAXL = 700;

int n, k;
ld dp[2][MAXL], ans;

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> k;
    dp[0][1] = 1;

    for (int i=0; i<n; i++) {
        for (int j=1; j<MAXL; j++) {
            dp[1][j] = ld(k-1)/k*dp[0][j]+ld(1)/k*(dp[0][j-1]/j+dp[0][j]*j/(j+1));
            ans += dp[0][j]*(j*j+3*j)/(2*j+2);
        }
        for (int j=1; j<MAXL; j++) dp[0][j] = dp[1][j];
    }

    cout << fixed << setprecision(10) << ans << '\n';
    return 0;
}