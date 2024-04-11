#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef pair< int, int > pii;
typedef long long ll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

bool solve() {

    int n, x, y;

    scanf("%d %d %d", &n, &x, &y);

    vec< ll > dp(n + 1, inf64);

    dp[0] = 0;

    for(int i = 1;i <= n;i++) {
        dp[i] = dp[i - 1] + x;
        if(i % 2) dp[i] = min(dp[i], dp[i / 2 + 1] + y + x);
        else dp[i] = min(dp[i], dp[i / 2] + y);
    }

    cout << dp[n] << '\n';

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}