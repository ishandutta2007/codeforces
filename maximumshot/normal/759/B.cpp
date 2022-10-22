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

int const N = 100005;

int n;
int t[N];
int dp[N];

int main() {

    scanf("%d", &n);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &t[i]);
        dp[i] = inf;
    }

    dp[1] = 20;

    for(int i = 2;i <= n;i++) {
        dp[i] = min(dp[i], dp[i - 1] + 20);
        for(int j = i;j >= 1 && t[j] + 89 >= t[i];j--) {
            dp[i] = min(dp[i], dp[j - 1] + 50);
        }
        for(int j = i;j >= 1 && t[j] + 1439 >= t[i];j--) {
            dp[i] = min(dp[i], dp[j - 1] + 120);
        }
    }

    for(int i = 1;i <= n;i++) {
        printf("%d\n", dp[i] - dp[i - 1]);
    }

    return 0;
}