#include <bits/stdc++.h>
//#include "optimization.h"

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef pair< double, double > pdd;
typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;

const int inf = 1e9;
const ll inf64 = 1ll * inf * inf;

const int mod = inf + 7;

inline int _sum(int a, int b) {
    return (a + b < mod ? a + b : a + b - mod);
}

inline int _mul(int a, int b) {
    return (1ll * a * b) % mod;
}

inline int _sub(int a, int b) {
    return (a >= b ? a - b : a - b + mod);
}

int binpow(int a, int p) {
    int r = 1;
    int t = a;
    while(p > 0) {
        if(p & 1) {
            r = _mul(r, t);
        }
        t = _mul(t, t);
        p >>= 1;
    }
    return r;
}

const int N = 2e6 + 5;

int d[N];
int p[N];
int n, k;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &k);

    for(int j = 1;j <= k;j++) {
        p[j] = _sum(p[j], p[j - 1]);
        d[j] = p[j];
        d[j] = _sum(d[j], binpow(j, n));
        for(int x = 2;j * x <= k;x++) {
//            for(int r = 0;r < x && j * x + r <= k;r++) {
//                d[x * j + r] = _sub(d[x * j + r], d[j]);
//            }
            int le = x * j;
            int ri = min(k, x * j + x - 1);
            p[le] = _sub(p[le], d[j]);
            if(ri < k) {
                p[ri + 1] = _sum(p[ri + 1], d[j]);
            }
        }
    }

//    for(int i = 2;i <= k;i++) {
//        d[i] = binpow(i, n);
//        for(int x = 2;x <= i;x++) {
//            d[i] = _sub(d[i], d[i / x]);
//        }
//    }

//    for(int i = 1;i <= k;i++) {
//        cout << i << " : " << d[i] << "\n";
//    }

    int res = 0;

    for(int i = 1;i <= k;i++) {
        res = _sum(res, ((d[i] ^ i) % mod + mod) % mod);
    }

    printf("%d\n", res);

    return 0;
}