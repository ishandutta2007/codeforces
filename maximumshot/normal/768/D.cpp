#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef pair< int, int > pii;
typedef long long ll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

    int k, q;

    scanf("%d %d", &k, &q);

    vec< pii > a(q);
    vec< int > ans(q);

    for(int i = 0;i < q;i++) {
        scanf("%d", &a[i].first);
        a[i].second = i;
    }

    sort(ALL(a));

    vec< double > dp(k + 1, 0.0);
    vec< double > nx(k + 1, 0.0);

    dp[0] = 1.0;

    for(int t = 1, i = 0;i < q;t++) {
        nx.assign(k + 1, 0.0);
        for(int j = 0;j <= k;j++) {
            nx[j] = dp[j] * (1.0 * j / k);
            if(j > 0) nx[j] += dp[j - 1] * (1.0 * (k - j + 1) / k);
        }
        dp = nx;
        while( i < q && (a[i].first - 1e-7) / 2000.0 <= dp[k] ) {
            ans[ a[i].second ] = t;
            i++;
        }
    }

    for(int i = 0;i < q;i++) {
        printf("%d\n", ans[i]);
    }

    return 0;
}