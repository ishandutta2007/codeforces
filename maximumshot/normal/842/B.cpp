#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

inline int Sqr(int x) {
    return x * x;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int r, d;

    scanf("%d %d", &r, &d);

    int res = 0;

    int n;

    scanf("%d", &n);

    for(int i = 1;i <= n;i++) {
        int xi, yi, ri;
        scanf("%d %d %d", &xi, &yi, &ri);
        if(ri > r) continue;
        if(Sqr(xi) + Sqr(yi) >= Sqr(r - d + ri) &&
           Sqr(xi) + Sqr(yi) <= Sqr(r - ri)) {
            res++;
        }
    }

    printf("%d\n", res);

    return 0;
}