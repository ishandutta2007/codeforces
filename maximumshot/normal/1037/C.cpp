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

const int N = 1e6 + 5;

int n;
char a[N];
char b[N];
int dp[N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &n);
    scanf("%s %s", a + 1, b + 1);

    fill(dp, dp + N, inf);

    dp[0] = 0;

    for(int i = 1;i <= n;i++) {
        if(a[i] == b[i]) {
            dp[i] = min(dp[i], dp[i - 1]);
        }
        if(a[i] != b[i]) {
            dp[i] = min(dp[i], dp[i - 1] + 1);
        }
        if(i > 1 && a[i] == b[i - 1] && a[i - 1] == b[i]) {
            dp[i] = min(dp[i], dp[i - 2] + 1);
        }
    }

    printf("%d\n", dp[n]);

    return 0;
}