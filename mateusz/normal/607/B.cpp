#include <bits/stdc++.h>

using namespace std;

const int N = 505;
int n;
int tab[N], dp[N][N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tab[i]);
    }
    
    for (int i = 1; i <= n; i++) {
        dp[i][i] = 1;
        dp[i + 1][i] = 1;
    }
    dp[1][0] = 1;
    
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j + i - 1 <= n; j++) {
            dp[j][j + i - 1] = 1e9;
            if (tab[j] == tab[j + i - 1]) {
                dp[j][j + i - 1] = dp[j + 1][i + j - 2];
            }
            for (int k = j; k <= j + i - 2; k++) {
                dp[j][j + i - 1] = min(dp[j][j + i - 1], dp[j][k] + dp[k + 1][j + i - 1]);
            }        
        }
    }
    
    printf("%d\n", dp[1][n]);
    
    return 0;
}