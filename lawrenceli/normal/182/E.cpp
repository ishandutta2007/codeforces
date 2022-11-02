#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>

using namespace std;

const int MAXN = 105;
const int MAXL = 3005;
const int MOD = 1e9 + 7;

int n, l, a[MAXN], b[MAXN];
int dp[MAXL][MAXN][2];

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> l;
    for (int i=0; i<n; i++) {
        cin >> a[i] >> b[i];
        dp[a[i]][i][0] ++;
        if (a[i] != b[i]) dp[b[i]][i][1] ++;
    }

    for (int i=1; i<=l; i++) {
        for (int j=0; j<n; j++)
            for (int k=0; k<2; k++) {
                int a0 = a[j], b0 = b[j];
                if (k) swap(a0, b0);
                for (int j1=0; j1<n; j1++)
                    for (int k1=0; k1<2; k1++) {
                        if (j == j1) continue;
                        if (a[j1] == b[j1] && k1 == 1) continue;
                        int a1 = a[j1], b1 = b[j1];
                        if (k1) swap(a1, b1);
                        if (b0 != a1) continue;
                        int i1 = i+a1;
                        if (i1 <= l)
                            dp[i1][j1][k1] = (dp[i1][j1][k1] + dp[i][j][k]) % MOD;
                    }
            }
    }

    int res = 0;
    for (int j=0; j<n; j++)
        for (int k=0; k<2; k++)
            res = (res + dp[l][j][k]) % MOD;

    cout << res << '\n';
    return 0;
}