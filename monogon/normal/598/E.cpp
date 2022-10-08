
#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int INF = 1e9;
const int MAX_N = 35, MAX_K = 55;
int q, n, m, k;
int dp[MAX_N][MAX_N][MAX_K];

// dp on n, m, k
// INF is impossible (i.e. k > nm)
// otherwise, minimum cost to get exactly k

int main() {
    cin >> q;
    for(int i = 0; i <= 30; i++) {
        for(int j = 0; j <= 30; j++) {
            for(int K = 0; K <= 50; K++) {
                if(i > j) {
                    dp[i][j][K] = dp[j][i][K];
                }else if(K > i * j) {
                    dp[i][j][K] = INF;
                }else if(K == i * j || K == 0) {
                    dp[i][j][K] = 0;
                }else {
                    dp[i][j][K] = INF;
                    for(int l = 1; l < i; l++) {
                        for(int k2 = 0; 2 * k2 <= K; k2++) {
                            dp[i][j][K] = min(dp[i][j][K], j * j + dp[l][j][k2] + dp[i - l][j][K - k2]);
                        }
                    }
                    for(int l = 1; l < j; l++) {
                        for(int k2 = 0; 2 * k2 <= K; k2++) {
                            dp[i][j][K] = min(dp[i][j][K], i * i + dp[i][l][k2] + dp[i][j - l][K - k2]);
                        }
                    }
                }
            }
        }
    }
    while(q--) {
        cin >> n >> m >> k;
        cout << dp[n][m][k] << endl;
    }
}