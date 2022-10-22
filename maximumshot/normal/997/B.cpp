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

int solve(int n) {
    int maxs = n * 50;

    vec< vec< int > > dp(2, vec< int >(maxs + 1));

    dp[0][0] = 1;

    for(int i = 1;i <= n;i++) {
        dp[i & 1].assign(maxs + 1, 0);
        auto &prv = dp[(i - 1) & 1];
        auto &nxt = dp[i & 1];
        for(int j = 0;j <= maxs;j++) {
            if(!prv[j]) continue;
            if(j + 1 <= maxs) nxt[j + 1] = 1;
            if(j + 5 <= maxs) nxt[j + 5] = 1;
            if(j + 10 <= maxs) nxt[j + 10] = 1;
            if(j + 50 <= maxs) nxt[j + 50] = 1;
        }
    }

    return count(ALL(dp[n & 1]), 1);
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n;

    cin >> n;

    if(n <= 50) {
        cout << solve(n) << "\n";
    }else {
        cout << solve(50) + 49ll * (n - 50) << "\n";
    }

    return 0;
}