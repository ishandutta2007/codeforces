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

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n;

    scanf("%d", &n);

    vec< int > x(n);
    vec< int > y(n);
    vec< int > perm(n);
    ll sx = 0, sy = 0;

    for(int i = 0;i < n;i++) {
        scanf("%d %d", &x[i], &y[i]);
        sx -= x[i];
        sy -= y[i];
        perm[i] = i;
    }

    mt19937 rnd(42);

    const ll CAN = 1500000ll * 1500000ll;

    while(1) {
        shuffle(ALL(perm), rnd);
        ll tx = sx, ty = sy;
        for(int i = 0;i <= n;i++) {
            if((tx >= 0 ? tx : -tx) <= 1e7 && (ty >= 0 ? ty : -ty) <= 1e7 && tx * tx + ty * ty <= CAN) {
                vec< int > res(n);
                for(int j = 0;j < i;j++) {
                    res[perm[j]] = 1;
                }
                for(int j = i;j < n;j++) {
                    res[perm[j]] = -1;
                }
                for(int x : res) printf("%d ", x);
                printf("\n");
                return 0;
            }
            if(i < n) {
                tx += 2ll * x[perm[i]];
                ty += 2ll * y[perm[i]];
            }
        }
    }

    return 0;
}