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

const int N = 1e6 + 5;
const int mod = 998244353;

int _mul() { return 1; }

template< typename ... Args >
int _mul(int x, Args ... rest) {
    return (1ll * x * _mul(rest...)) % mod;
}

int _sum() { return 1; }

template< typename ... Args >
int _sum(int x, Args ... rest) {
    int y = _sum(rest...);
    return x + y < mod ? x + y : x + y - mod;
}

inline void _add(int &x, int y) {
    if((x += y) >= mod) x -= mod;
}

inline int _sub(int x, int y) {
    return x >= y ? x - y : x - y + mod;
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

int fact[N];
int rfact[N];

inline int CNK(int n, int k) {
    if(n < k) return 0;
    return _mul(fact[n], rfact[k], rfact[n - k]);
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    fact[0] = rfact[0] = 1;

    for(int i = 1;i < N;i++) {
        fact[i] = _mul(fact[i - 1], i);
    }

    {
        int hlp = _binpow(fact[N - 1], mod - 2);
        for(int i = N - 1;i >= 0;i--) {
            rfact[i] = hlp;
            hlp = _mul(hlp, i);
        }
    }

    int n;

    cin >> n;

    vec< int > pw3(n + 1), pw3n(n + 1);

    pw3[0] = pw3n[0] = 1;

    for(int i = 1;i <= n;i++) {
        pw3[i] = _mul(pw3[i - 1], 3);
    }

    for(int i = 1;i <= n;i++) {
        pw3n[i] = _mul(pw3n[i - 1], pw3[n]);
    }

    int s1 = 0;

    for(int i = 1;i <= n;i++) {
        _add(s1, _mul(CNK(n, i), (i & 1 ? 1 : mod - 1), pw3[i], pw3n[n - i]));
    }

    int s2 = s1;
    int s3 = 0;

    for(int i = 1;i <= n;i++) {
        int ai = _sub(pw3[n - i], 1);
        ai = _binpow(ai, n);
        ai = _sub(ai, pw3n[n - i]);
        _add(s3, _mul(ai, CNK(n, i), i & 1 ? 1 : mod - 1));
    }

    cout << _sub(_sum(s1, s2, _mul(3, s3)), 1) << "\n";

    return 0;
}