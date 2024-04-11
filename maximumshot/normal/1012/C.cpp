#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

inline void relax(int &x, int y) {
    if(y < x) x = y;
}

const int N = 5005;

int n;
int a[N];
int dp[N][N][2];

int calc(int h1, int h2, int x) {
    int y = min(h1, h2) - 1;
    return max(x - y, 0);
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &n);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
    }

    a[0] = a[n + 1] = -inf;

    fill((int*)dp, (int*)dp + N * N * 2, inf);

    dp[0][0][0] = 0;
    dp[1][0][0] = 0;
    dp[1][1][1] = max(0, a[0] - a[1] - 1) + max(0, a[2] - a[1] + 1);

    for(int i = 2;i <= n;i++) {
        for(int j = 0;j <= n;j++) {
            dp[i][j][0] = min(dp[i - 1][j][0], dp[i - 1][j][1]);
            if(j == n) continue;
            relax(dp[i][j + 1][1], max(0, a[i + 1] - a[i] + 1) + max(0, a[i - 1] - a[i] + 1) + dp[i - 2][j][0]);
            if(dp[i - 2][j][1] != inf) {
                relax(
                    dp[i][j + 1][1],
                    max(0, a[i + 1] - a[i] + 1) + dp[i - 2][j][1] - max(0, a[i - 1] - a[i - 2] + 1) + calc(a[i - 2], a[i], a[i - 1]));
            }
        }
    }

    int kk = (n + 1) / 2;

    for(int k = 1;k <= kk;k++) {
        printf("%d ", min(dp[n][k][0], dp[n][k][1]));
    }

    printf("\n");

    return 0;
}