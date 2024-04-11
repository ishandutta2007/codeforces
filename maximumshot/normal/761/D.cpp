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

int main() {

    int n, l, r;

    scanf("%d %d %d", &n, &l, &r);

    vec< int > a(n + 1), c(n + 1);

    for(int i = 1;i <= n;i++) scanf("%d", &a[i]);

    vec< pii > b(n + 1);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &b[i].first);
        b[i].second = i;
    }

    sort(ALL(b));

    int mx = -inf - 1;

    for(int bl, br, bm, ql, qr, i, iter = 1;iter <= n;iter++) {
        i = b[iter].second;
        ql = l - a[i];
        qr = r - a[i];

        ql = max(ql, mx + 1);

        if(ql > qr) {
            puts("-1");
            return 0;
        }

        c[i] = ql;

        mx = ql;
    }

    for(int i = 1;i <= n;i++) {
        printf("%d ", c[i] + a[i]);
    }
    printf("\n");

    return 0;
}