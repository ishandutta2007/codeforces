#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int r, n;
    cin >> r >> n;

    vector<int> dp(n + 1, -inf), pr(n + 1, -inf);;
    vector<int> t(n + 1), x(n + 1), y(n + 1);
    t[0] = 0;
    x[0] = y[0] = 1;

    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> x[i] >> y[i];
    }

    dp[0] = pr[0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (t[i] - t[j] >= 2 * r) {
                dp[i] = max(dp[i], pr[j] + 1);
                break;
            }
            int dist = abs(x[i] - x[j]) + abs(y[i] - y[j]);
            if (dist <= t[i] - t[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        pr[i] = max(pr[i - 1], dp[i]);
    }

    cout << pr[n] << "\n";

    return 0;
}