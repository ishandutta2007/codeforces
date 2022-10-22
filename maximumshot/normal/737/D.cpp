#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 4005;
int const K = 105;

int n;
int a[N];
int pr[N];
int dp[N / 2 + 5][K + K][K][2];
bool us[N / 2 + 5][K + K][K][2];

int rec(int l, int r, int k, int xod) {
    int res = -inf;
    if(l >= N / 2 + 5) return 0;
    if(us[l][K + l - (n + 1 - r)][k][xod]) return dp[l][K + l - (n + 1 - r)][k][xod];
    if(xod == 0) {
        if(l + k + 1 < r) {
            res = max(res, pr[l + k + 1] - pr[l] - rec(l + k + 1, r, k + 1, xod ^ 1));
        }
        if(l + k < r) {
            res = max(res, pr[l + k] - pr[l] - rec(l + k, r, k, xod ^ 1));
        }
    }else {
        if(r - k - 1 > l) {
            res = max(res, pr[r - 1] - pr[r - k - 2] - rec(l, r - k - 1, k + 1, xod ^ 1));
        }
        if(r - k > l) {
            res = max(res, pr[r - 1] - pr[r - k - 1] - rec(l, r - k, k, xod ^ 1));
        }
    }
    if(res == -inf)
        res = 0;
    us[l][K + l - (n + 1 - r)][k][xod] = 1;
    dp[l][K + l - (n + 1 - r)][k][xod] = res;
    return res;
}

int main() {

    scanf("%d", &n);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
        pr[i] = pr[i - 1] + a[i];
    }

    printf("%d\n", rec(0, n + 1, 1, 0));

    return 0;
}