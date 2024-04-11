#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long double, long double > pdd;
typedef pair< long long, long long > pll;

#define vec vector
#define ALL(x) begin(x), end(x)

void solve() {
    int n;
    cin >> n;

    ld C, T;

    cin >> C >> T;

    vec< pair< ld, int > > a(n + 1);

    int sum = 0;

    for(int i = 1;i <= n;i++) {
        cin >> a[i].first >> a[i].second;
        sum += a[i].second;
    }

    vec< vec< ld > > dp(n + 1, vec< ld >(sum + 1, 1e18));

    sort(a.begin() + 1, a.end());

    dp[1][a[1].second] = a[1].first / 0.9;
    dp[0][0] = 0;

    for(int i = 2;i <= n;i++) {
        for(int k = i;k >= 1;k--) {
            for(int b = sum;b >= a[i].second;b--) {
                dp[k][b] = min(dp[k][b], dp[k - 1][b - a[i].second] * (1 / 0.9) + a[i].first / 0.9);
            }
        }
    }

    int res = 0;

    for(int k = 1;k <= n;k++) {
        for(int b = 0;b <= sum;b++) {
            ld f = dp[k][b];
            ld t0 = max(ld(0), (sqrt(f * C) - 1) / C);
            ld tt = t0 + 10 * k + f / (1 + C * t0);
            if(tt <= T) {
                res = max(res, b);
            }
        }
    }

    printf("%d\n", res);
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);

    int tc;

    cin >> tc;

    while(tc--) solve();

    return 0;
}