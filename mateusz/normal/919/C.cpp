#include <bits/stdc++.h>

using namespace std;

const int N = 2005;

int n, m, k;

char board[N][N];
int sumCol[N][N], sumRow[N][N];

int main() {
    
    scanf("%d %d %d", &n, &m, &k);
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%s", &board[i][1]);
        for (int j = 1; j <= m; j++) {
            sumCol[i][j] = sumCol[i][j - 1] + (board[i][j] == '*');
            sumRow[i][j] = sumRow[i - 1][j] + (board[i][j] == '*');
            if (j >= k && sumCol[i][j] - sumCol[i][j - k] == 0) {
                ans++;
            }
            if (i >= k && sumRow[i][j] - sumRow[i - k][j] == 0) {
                ans++;
            }
        }
    }
    
    if (k == 1) {
        ans /= 2;
    }
    
    printf("%d\n", ans);
    
    return 0;
}