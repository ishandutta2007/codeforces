#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
const int INF = 1e9;
int n;
int a[nax];
bool dp[nax];

void solve_test_case() {
    cin >> n;
    dp[n + 1] = true;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
        dp[i] = false;
    }
    dp[0] = false;
    /**
        dp[x] whether we can construct valid sequences from x...
        a .....q
    */
    for (int i = n ; i >= 1 ; -- i) {
        int to = a[i] + i + 1;
        if (to <= n + 1) dp[i] |= dp[to];
        /**
            dp[i] |= dp[to] suppose that to... can be finished on its own
            dp[from]
        */
        int from = i - a[i];
        if (from >= 1) dp[from] |= dp[i + 1];
    }
    cout << ((dp[0] || dp[1]) ? "YES" : "NO") << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        solve_test_case();
    }
}