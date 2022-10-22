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

const int mod = inf + 7;
const int K = 5005;

inline int _sum(int a, int b) {
    return a + b < mod ? a + b : a + b - mod;
}

inline int _sub(int a, int b) {
    return a >= b ? a - b : a - b + mod;
}

inline int _mul(int a, int b) {
    return (1ll * a * b) % mod;
}

inline void _add(int &x, int y) {
    if((x += y) >= mod) x -= mod;
}

inline int _binpow(int x, int p) {
    int res = 1;
    int tmp = x;
    while(p > 0) {
        if(p & 1) {
            res = _mul(res, tmp);
        }
        tmp = _mul(tmp, tmp);
        p >>= 1;
    }
    return res;
}

vec< int > rec(int n, int k) { // f[0], f[1], ..., f[k]
    vec< int > f(k + 1);
    f[0] = _sub(_binpow(2, n), 1);
    if(!k) return f;
    if(n == 1) {
        f.assign(k + 1, 1);
        return f;
    }
    vec< int > g = rec(n - 1, k - 1);
    for(int cur = 1, kk = 0;kk < k;kk++) {
        f[kk + 1] = _mul(n, _sub(f[kk], _sum(g[kk], cur)));
        cur = _mul(cur, n);
        _add(f[kk + 1], cur);
    }
    return f;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n, k;

    cin >> n >> k;
    cout << rec(n, k)[k] << "\n";

    return 0;
}