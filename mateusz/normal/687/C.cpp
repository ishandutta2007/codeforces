#include <bits/stdc++.h>
#define DEBUG(x) cerr << #x << " " << (x) << endl;
using namespace std;

const int N = 505;

int n, k;
int c[N];
int dp[N][N];

int main() {

    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
    }

    dp[0][0] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = k - c[i]; j >= 0; j--) {
            for (int l = k; l >= 0; l--) {
                dp[j + c[i]][l] |= dp[j][l];
                if (l + c[i] <= k) {
                    dp[j + c[i]][l + c[i]] |= dp[j][l];
                }
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i <= k; i++) {
        if (dp[k][i] == true) {
            cnt++;
        }
    }

    printf("%d\n", cnt);
    for (int i = 0; i <= k; i++) {
        if (dp[k][i]) {
            printf("%d ", i);
        }
    }

    return 0;
}