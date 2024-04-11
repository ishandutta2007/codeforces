#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    int n;

    scanf("%d", &n);

    int r1 = inf + 10;
    int l1 = -inf - 10;
    int r2 = inf + 10;
    int l2 = -inf - 10;

    for(int l, r, i = 0;i < n;i++) {
        scanf("%d %d", &l, &r);
        r1 = min(r1, r);
        l1 = max(l1, l);
    }

    int m;

    scanf("%d", &m);

    for(int l, r, i = 0;i < m;i++) {
        scanf("%d %d", &l, &r);
        r2 = min(r2, r);
        l2 = max(l2, l);
    }

    int res = 0;

    if(r1 < l2) {
        res = max(res, l2 - r1);
    }

    if(r2 < l1) {
        res = max(res, l1 - r2);
    }

    printf("%d\n", res);

    return 0;
}