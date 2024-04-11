#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const mod = inf + 7;

inline int Sum(int a, int b) {
    return (a + b) % mod;
}

inline int Raz(int a, int b) {
    return ((a - b) % mod + mod) % mod;
}

inline int Mul(int a, int b) {
    return (1ll * a * b) % mod;
}

int binpow(int x, int p) {
    if(p == 0) return 1 % mod;
    int q = binpow(x, p / 2);
    q = Mul(q, q);
    if(p % 2) {
        q = Mul(q, x);
    }
    return q;
}

int const N = 3e5 + 5;

int pw[N];
int rpw[N];
int n;
int a[N];

int main() {

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    pw[0] = 1;
    rpw[0] = 1;

    for(int i = 1;i < N;i++) {
        pw[i] = Mul(pw[i - 1], 2);
        rpw[i] = binpow(pw[i], mod - 2);
    }

    scanf("%d", &n);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
    }

    sort(a + 1, a + n + 1);

    int s1 = 0;
    int s2 = 0;
    int res = 0;

    for(int i = 1;i <= n;i++) {
        if(i > 1) {
            res = Sum(res, Mul(Mul(a[i], pw[i - 1]), s1));
            res = Raz(res, Mul(pw[i - 1], s2));
        }
        s1 = Sum(s1, rpw[i]);
        s2 = Sum(s2, Mul(a[i], rpw[i]));
    }

    printf("%d\n", res);

    return 0;
}