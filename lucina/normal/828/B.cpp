#include<bits/stdc++.h>
using namespace std;
const int nax = 105;
char s[nax][nax];
int n, m;
int all_black = 0;
int sum[nax][nax];

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%s", s[i] + 1);
        for (int j = 1 ; j <= m ; ++ j) {
            if (s[i][j] == 'B') all_black += 1;
            sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + (s[i][j] == 'B');
        }
    }

    int ans = 128 * 128;

    for (int bar = 1 ; bar <= min(n, m) ; ++ bar) {

        for (int i = 1 ; i + bar - 1 <= n ; ++ i) {
            for (int j = 1 ; j + bar - 1 <= m ; ++ j) {
                int ct_b = sum[i + bar - 1][j + bar - 1] - sum[i - 1][j + bar - 1] - sum[i + bar - 1][j - 1] + sum[i - 1][j - 1];
                if (ct_b == all_black) ans = min(ans, bar * bar - ct_b);
            }
        }
    }

    printf("%d\n", ans == 128 * 128 ? -1 : ans);
}