#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

bool solve() {

    int n;
    scanf("%d", &n);

    vec< ll > a(n);
    for(int x, i = 0;i < n;i++) {
        scanf("%d", &x);
        if(i > 0) a[i] = a[i - 1];
        a[i] += x;
    }

    vec< ll > dp(n), sf(n);
    dp[n - 1] = a[n - 1];
    sf[n - 1] = a[n - 1];

    for(int i = n - 2;i >= 0;i--) {
        dp[i] = sf[i + 1];
        sf[i] = max(sf[i + 1], a[i] - dp[i]);
    }
    
    printf("%I64d\n", dp[0]);

    return true;
}

int main() {

#ifdef MY
    while(solve());
#else
    solve();
#endif

    return 0;
}