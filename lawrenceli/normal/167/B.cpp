#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>
#include <iomanip>

using namespace std;

const int MAXN = 205;

int n, l, k;
double p[MAXN];
int a[MAXN];
double dp1[MAXN][2]; //# prizes
double dp2[MAXN][MAXN][2]; //#won, capacity

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> l >> k;
    for (int i=0; i<n; i++) {
        int _p; cin >> _p;
        p[i] = _p / 100.;
    }
    for (int i=0; i<n; i++)
        cin >> a[i];

    dp1[0][0] = 1;
    dp2[0][k][0] = 1;

    for (int i=0; i<n; i++) {
        if (a[i] == -1) {
            for (int j=0; j<MAXN-1; j++) {
                dp1[j+1][1] += dp1[j][0] * p[i];
                dp1[j][1] += dp1[j][0] * (1-p[i]);
            }

            for (int j=0; j<MAXN; j++)
                dp1[j][0] = dp1[j][1], dp1[j][1] = 0;
        } else {
            for (int j=0; j<MAXN; j++)
                for (int k=0; k<MAXN; k++) {
                    dp2[j+1][min(MAXN-1, k+a[i])][1] += dp2[j][k][0] * p[i];
                    dp2[j][k][1] += dp2[j][k][0] * (1-p[i]);
                }

            for (int j=0; j<MAXN; j++)
                for (int k=0; k<MAXN; k++)
                    dp2[j][k][0] = dp2[j][k][1], dp2[j][k][1] = 0;
        }
    }

    double ans = 0;
    for (int i=0; i<MAXN; i++)
        for (int j=0; j<MAXN; j++)
            for (int k=0; k<MAXN; k++) {
                int x = i + j;
                if (x < l) continue;
                if (i > k) continue;
                ans += dp1[i][0] * dp2[j][k][0];
            }

    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}