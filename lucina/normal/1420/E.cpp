#include<bits/stdc++.h>
using namespace std;
int const nax = 82;
const int INF = 1061109567;
int n;
int a[nax];
int dp[nax][nax][40 * nax][2];
int ans[nax * nax];

inline void upd_min(int &a, int b) {
    a = min(a, b);
}

int p[nax];

int main() {

    scanf("%d", &n);
    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%1d", a + i);
    }
    int zero = count(a + 1, a + 1 + n, 0);

    int cur = 0;
    int top = 0;
    for (int i = 1 ; i <= n ; ++ i) {
        if (a[i] == 1) {
            p[++ top] = cur;
            cur = 0;
        } else cur += 1;
    }
    p[++ top] = cur;


    memset(dp, 0x3f, sizeof(dp));
    const int LIM = n * (n - 1) / 2;

    dp[0][0][0][0] = 0;

    for (int j = 0 ; j < top ; ++ j) {
        int x = p[j + 1];
        for (int c = 0 ; c <= n ; ++ c)
            for (int t = 0 ; t <= LIM ; ++ t)
            for (int y = 0 ; y < 2 ; ++ y) {
                int now = dp[j][c][t][y];
                if (now == INF) continue;

                for (int b = 0 ; b <= n ; ++ b) {
                    int has = (y == 0) ? c : -c;
                    int dif = x - b;
                    has -= dif;
                    if (abs(has) > n) continue;
                    if (has >= 0) {
                        upd_min(dp[j + 1][has][t + has][0], now + b * b);
                    } else {
                        upd_min(dp[j + 1][abs(has)][t + abs(has)][1], now + b * b);
                    }
                }
        }
    }


    for (int t = 0, f = INF ; t <= LIM ; ++ t) {
        f = min(f, dp[top][0][t][0]);
        printf("%d ", (zero * zero  - f) / 2);
    }




}