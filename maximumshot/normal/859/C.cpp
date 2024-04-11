#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>
//#include "optimization.h"

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 55;

int dp[N][2];
int a[N];
int n;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    cin >> n;

    int tot = 0;

    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        tot += a[i];
    }

    dp[n][0] = +a[n];
    dp[n][1] = +a[n];

    for(int i = n - 1;i >= 1;i--) {
        dp[i][0] = max(a[i] - dp[i + 1][1], -a[i] + dp[i + 1][0]);
        dp[i][1] = max(a[i] - dp[i + 1][0], -a[i] + dp[i + 1][1]);
    }

    int bob = (dp[1][1] + tot) / 2;
    int alice = tot - bob;

    cout << alice << " " << bob << "\n";

    return 0;
}