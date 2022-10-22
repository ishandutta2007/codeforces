#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n, k;

    scanf("%d %d", &n, &k);

    vec< int > a(n + 1);

    ll tot = 0;
    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
        tot += a[i];
    }

    vec< ll > dp(n + 1);
    multiset< int > q;

    for(int i = 1;i <= n;i++) {
        q.insert(a[i]);
        if(i > k) q.erase(q.lower_bound(a[i - k]));
        dp[i] = dp[i - 1];
        if(i >= k) {
            dp[i] = max(dp[i], dp[i - k] + *q.begin());
        }
    }

    cout << tot - dp[n] << "\n";

    return 0;
}