#include <bits/stdc++.h>

using namespace std;

static constexpr int maxn = 200500;
static constexpr int inf = 2e9;

int dp[maxn];
int a[maxn];

void Solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int prev = i - a[i];
        if (prev >= 0) {
            dp[i] = 1 + dp[prev];
            ans = max(ans, dp[i]);
        }
    }
    cout << ans << endl;

    for (int i = 0; i <= n; ++i) {
        dp[i] = 0;
    }
}

int main() {
    srand(time(NULL));
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);

    int q;
    cin >> q;
    while (q--) {
        Solve();
    }
}