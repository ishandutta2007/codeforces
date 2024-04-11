#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 300111, max_d = 10;
const ll inf = 5e18;

ll dp[max_n][max_d];
int n;
ll a[max_n];
ll b[max_n];

ll solve() {
    if (n == 1) {
        return 0;
    }
    for (int i = 0; i < max_d; ++i) {
        dp[0][i] = 1LL * b[0] * i;
    }
    for (int i = 1; i < n; ++i) {
        for (int ca = 0; ca < max_d; ++ca) {
            dp[i][ca] = inf;
            int ch = a[i] + ca;
            for (int pa = 0; pa < max_d; ++pa) {
                int ph = a[i - 1] + pa;
                if (ph != ch) {
                    dp[i][ca] = min(dp[i][ca], dp[i - 1][pa] + 1LL * b[i] * ca);
                }
            }
        }
    }
    ll ans = inf;
    for (int i = 0; i < max_d; ++i) {
        ans = min(ans, dp[n - 1][i]);
    }
    return ans;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int q;
    cin >> q;
    while (q--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%I64d %I64d", a + i, b + i);
        }
        printf("%I64d\n", solve());
    }

    return 0;
}