#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef pair< int , int > pii;
typedef long long ll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

bool solve() {

    int n;

    scanf("%d", &n);

    vec< int > c(n);

    for(int i = 0;i < n;i++) scanf("%d", &c[i]);

    vec< string > a(n), b(n);

    char buff[100100];

    for(int i = 0;i < n;i++) {
        scanf("%s", &buff);
        a[i] = b[i] = buff;
        reverse(ALL(b[i]));
    }

    vec< ll > dp[2];

    dp[0] = dp[1] = vec< ll >(n, inf64);

    dp[0][0] = 0;
    dp[1][0] = c[0];

    for(int i = 1;i < n;i++) {
        if(a[i] >= a[i - 1])
            dp[0][i] = min(dp[0][i], dp[0][i - 1]);
        if(a[i] >= b[i - 1])
            dp[0][i] = min(dp[0][i], dp[1][i - 1]);
        if(b[i] >= a[i - 1])
            dp[1][i] = min(dp[1][i], dp[0][i - 1] + c[i]);
        if(b[i] >= b[i - 1])
            dp[1][i] = min(dp[1][i], dp[1][i - 1] + c[i]);
    }

    //for(int i = 0;i < n;i++) cout << dp[0][i] << ' ' << dp[1][i] << '\n';

    ll res = min(dp[0][n - 1], dp[1][n - 1]);

    if(res == inf64) cout << -1 << '\n';
    else cout << res << '\n';

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}