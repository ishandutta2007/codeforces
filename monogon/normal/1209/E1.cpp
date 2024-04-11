
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 4, M = 105;
int t, n, m;
ll a[M][N];
ll dp[16][M];

int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> a[j][i];
            }
        }
        int N2 = ((1 << n) - 1);
        for(int i = 0; i <= N2; i++) {
            for(int j = 0; j <= m; j++) {
                dp[i][j] = 0;
            }
        }
        for(int i = 0; i < m; i++) { // column
            for(int j = 0; j <= N2; j++) { // subset of allowed rows
                for(int k = 0; k < n; k++) { // cyclic shift of this column
                    for(int j2 = 0; j2 <= N2; j2++) {
                        ll sumr = 0;
                        for(int l = 0; l < n; l++) {
                            bool b1 = (j2 >> l) & 1;
                            bool b2 = (j >> l) & 1;
                            if(!b1 && b2) {
                                sumr += a[i][(l + k) % n];
                            }
                            if(b1 && !b2) {
                                goto endloop;
                            }
                        }
                        dp[j][i + 1] = max(dp[j][i + 1], sumr + dp[j2][i]);
                        endloop:;
                    }
                }
            }
        }
        cout << dp[N2][m] << endl;
    }
}