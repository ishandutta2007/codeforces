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

const int mod = inf + 9;
const int N = 1e5 + 5;

inline int _sum(int a, int b) {
    return (a + b < mod ? a + b : a + b - mod);
}

inline int _sub(int a, int b) {
    return a >= b ? a - b : a - b + mod;
}

inline int _mul(int a, int b) {
    return (1ll * a * b) % mod;
}

inline int _binpow(int x, int p) {
    int res = 1;
    int tmp = x % mod;
    if(tmp < 0) tmp += mod;
    while(p > 0) {
        if(p & 1) {
            res = _mul(res, tmp);
        }
        p >>= 1;
        tmp = _mul(tmp, tmp);
    }
    return res;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n, a, b, k;
    char s[N];

    scanf("%d %d %d %d", &n, &a, &b, &k);

    scanf("%s", s);

    int x = _mul(b, _binpow(a, mod - 2));
    int tmp = 0;

    for(int cur = 1, i = 0;i < k;i++, cur = _mul(cur, x)) {
        if(s[i] == '+') {
            tmp = _sum(tmp, cur);
        }else {
            tmp = _sub(tmp, cur);
        }
    }

    int pw = n / k;
    int res = _mul(_binpow(a, n), tmp);

    x = _binpow(x, k);

    if(x == 1) {
        res = _mul(res, pw + 1);
    }else {
        res = _mul(res, _sub(_binpow(x, pw + 1), 1));
        res = _mul(res, _binpow(_sub(x, 1), mod - 2));
    }

    printf("%d\n", res);

    return 0;
}