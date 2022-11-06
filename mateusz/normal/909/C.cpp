#include <bits/stdc++.h>

using namespace std;

const int N = 5005, M = 1e9 + 7;

int n;
char type[N];
int dp[2][N][2], suf[2][N][2];

void add(int &w, int u) {
    w += u;
    if (w >= M) {
        w -= M;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf(" %c", &type[i]);
    }
    
    dp[0][0][0] = 1;
    suf[0][0][0] = 1;
    
    for (int i = 1; i <= n; i++) {
        int ii = i % 2;
        for (int j = n; j >= 0; j--) {
            suf[ii][j][0] = dp[ii][j][0] = suf[ii][j][1] = dp[ii][j][1] = 0;
            if (type[i] == 'f' && j > 0) {
                add(dp[ii][j][1], suf[ii ^ 1][j - 1][0]);
                add(dp[ii][j][1], dp[ii ^ 1][j - 1][1]);
            } else if (type[i] == 's'){
                add(dp[ii][j][0], suf[ii ^ 1][j][0]);
                add(dp[ii][j][0], dp[ii ^ 1][j][1]);
            }
            add(suf[ii][j][0], suf[ii][j + 1][0]);
            add(suf[ii][j][0], dp[ii][j][0]);
            add(suf[ii][j][1], suf[ii][j + 1][1]);
            add(suf[ii][j][1], dp[ii][j][1]);
        }
    }
    printf("%d\n", (suf[n % 2][0][1] + suf[n % 2][0][0]) % M);
    return 0;
}