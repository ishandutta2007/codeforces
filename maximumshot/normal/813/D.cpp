#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 5005;
int const X = 1e5 + 5;

int n;
int a[N];
int f7[N];
int f1[N];
int f2[N];
int dp[N][N];

int md[7];
int vl[X];

int main() {

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &n);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
    }

    for(int i = 1;i <= n;i++) {
        for(int j = i - 1;j >= 1;j--) {
            if(f7[i] == 0 && a[i] % 7 == a[j] % 7) {
                f7[i] = j;
            }
            if(f1[i] == 0 && a[i] - 1 == a[j]) {
                f1[i] = j;
            }
            if(f2[i] == 0 && a[i] + 1 == a[j]) {
                f2[i] = j;
            }
        }
    }

    for(int i = 1;i <= n;i++) {
        dp[0][i] = 1;
        for(int j = i - 1;j >= 1;j--) {
            if(abs(a[i] - a[j]) == 1 || a[i] % 7 == a[j] % 7) {
                dp[0][i] = max(dp[0][i], dp[0][j] + 1);
            }
        }
    }

    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            vl[a[j]] = 0;
            md[a[j] % 7] = 0;
        }
        for(int j = 1;j < i;j++) {
            md[a[j] % 7] = max(md[a[j] % 7], dp[j][i]);
            vl[a[j]] = max(vl[a[j]], dp[j][i]);
        }
        for(int p, j = i + 1;j <= n;j++) {
            dp[i][j] = 2;
            dp[i][j] = max(dp[i][j], dp[0][i] + 1);
            dp[i][j] = max(dp[i][j], md[a[j] % 7] + 1);
            dp[i][j] = max(dp[i][j], vl[a[j] - 1] + 1);
            dp[i][j] = max(dp[i][j], vl[a[j] + 1] + 1);
            md[a[j] % 7] = max(md[a[j] % 7], dp[i][j]);
            vl[a[j]] = max(vl[a[j]], dp[i][j]);
        }
    }

    int res = 0;

    for(int i = 1;i <= n;i++) {
        for(int j = i + 1;j <= n;j++) {
            res = max(res, dp[i][j]);
        }
    }

    printf("%d\n", res);

    return 0;
}