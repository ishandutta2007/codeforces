#include <bits/stdc++.h>

using namespace std;

const int N = 705;

int dp[N][N][2];
int n;
int a[N];
bool edge[N][N];

bool good(int i, int j, int k) {
    if (i > j) {
        return true;
    }
    return dp[i][j][k];
}

int main() {
    
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            edge[i][j] = __gcd(a[i], a[j]) > 1;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        edge[0][i] = 1;
        edge[i][n + 1] = 1;
    }
    
    for (int i = n; i >= 1; i--) {
        for (int j = i; j <= n; j++) {
            
            for (int k = i; k <= j; k++) {
                if (edge[i - 1][k]) {
                    dp[i][j][0] |= good(i, k - 1, 1) && good(k + 1, j, 0);
                }
                if (edge[j + 1][k]) {
                    dp[i][j][1] |= good(i, k - 1, 1) && good(k + 1, j, 0);
                }
            }
            
        }
    }
    
    printf(dp[1][n][0] ? "Yes\n" : "No\n");
   
    return 0;
}