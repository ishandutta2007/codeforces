#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1005;
const int MOD = 1e9 + 7;

int n, c[MAXN], C[MAXN][MAXN];
int dp[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=0; i<n; i++) cin >> c[i];

    for (int i=0; i<MAXN; i++) {
        C[i][0] = 1;
        for (int j=1; j<=i; j++)
            C[i][j] = (C[i-1][j]+C[i-1][j-1])%MOD;
    }

    int p = 0;
    for (int i=0; i<n; i++) {
        if (i == 0) dp[i] = 1;
        else {
            for (int j=0; j<c[i]; j++)
                dp[i] = (dp[i] + ll(dp[i-1])*C[p-1+c[i]-1-j][p-1]%MOD)%MOD;
        }
        p += c[i];
    }

    cout << dp[n-1] << '\n';
}