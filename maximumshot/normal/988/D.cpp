#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
//#include "optimization.h"

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

const int module = 1e6 + 3;

int value[module];

int get_pos(ll x) {
    ll xx = x;
    x = (x % module + module) % module;
    while(value[x] != xx && value[x] != INT_MAX) if(++x == module) x = 0;
    return x;
}

void add(ll val) {
    int p = get_pos(val);
    value[p] = val;
}

bool have(ll val) {
    int p = get_pos(val);
    return value[p] == val;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    fill(value, value + module, INT_MAX);

    int n;

    scanf("%d", &n);

    vec< ll > x(n);

    for(int val, i = 0;i < n;i++) {
        scanf("%d", &val);
        x[i] = val;
        add(val);
    }

    sort(ALL(x));

    for(int i = 1;i + 1 < n;i++) {
        for(int j = 0;j <= 31;j++) {
            ll xl = x[i] - (1ll << j);
            ll xr = x[i] + (1ll << j);
            if(xl < -inf || xl > inf) continue;
            if(xr < -inf || xr > inf) continue;
            if(have(xl) && have(xr)) {
                printf("3\n%lld %lld %lld\n", xl, x[i], xr);
                return 0;
            }
        }
    }

    for(int i = 0;i + 1 < n;i++) {
        for(int j = 0;j <= 31;j++) {
            ll xr = x[i] + (1ll << j);
            if(xr < -inf || xr > inf) continue;
            if(have(xr)) {
                printf("2\n%lld %lld\n", x[i], xr);
                return 0;
            }
        }
    }

    printf("1\n%lld\n", x[0]);

    return 0;
}