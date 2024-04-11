#include <cstdio>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

const int MAXN = 300;

int x, n, p;
double dp[2][2][1<<8][MAXN];

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);
    cin >> x >> n >> p;
    int cnt = 0;
    for (int i=9; 1; i++) {
        if (bool(x&1<<i) == bool(x&1<<8)) cnt++;
        else break;
    }
    dp[0][bool(x&1<<8)][x&(1<<8)-1][cnt] = 1;
    for (int i=0; i<n; i++) {
        for (int j=0; j<2; j++)
            for (int k=0; k<1<<8; k++)
                for (int l=0; l<MAXN; l++)
                    if (dp[0][j][k][l] > 0) {
                        double val = dp[0][j][k][l];
                        if (k != (1<<8)-1)
                            dp[1][j][k+1][l] += val*(100.-p)/100;
                        else if (!j)
                            dp[1][1][0][0] += val*(100.-p)/100;
                        else
                            dp[1][0][0][l] += val*(100.-p)/100;

                        int b = bool(k&1<<7);
                        if (b == j)
                            dp[1][b][(k<<1)&(1<<8)-1][l+1] += val*p/100.;
                        else
                            dp[1][b][(k<<1)&(1<<8)-1][0] += val*p/100.;
                    }
        for (int j=0; j<2; j++)
            for (int k=0; k<1<<8; k++)
                for (int l=0; l<MAXN; l++)
                    dp[0][j][k][l] = dp[1][j][k][l], dp[1][j][k][l] = 0;
    }
    double ans = 0;
    for (int j=0; j<2; j++)
        for (int k=0; k<1<<8; k++)
            for (int l=0; l<MAXN; l++)
                if (dp[0][j][k][l] > 0) {
                    if (k == 0) {
                        cnt = 8;
                        if (!j) cnt += l+1;
                    } else cnt = __builtin_ctz(k);
                    ans += cnt*dp[0][j][k][l];
                }
    cout << setprecision(10) << ans << '\n';
    return 0;
}