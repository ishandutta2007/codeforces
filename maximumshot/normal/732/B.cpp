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

    int n, k;

    scanf("%d %d", &n, &k);

    vec< int > a(n);

    for(int i = 0;i < n;i++) scanf("%d", &a[i]);

    int res = 0;

    for(int i = 0;i + 1 < n;i++) {
        if(a[i] + a[i + 1] < k) {
            int d = k - a[i] - a[i + 1];
            res += d;
            a[i + 1] += d;
        }
    }

    printf("%d\n", res);

    for(int i = 0;i < n;i++) {
        printf("%d ", a[i]);
    }

    printf("\n");

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