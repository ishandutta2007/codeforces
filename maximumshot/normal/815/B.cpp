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
    if(!p) return 1;
    int q = binpow(x, p / 2);
    q = Mul(q, q);
    if(p % 2) q = Mul(q, x);
    return q;
}

int const N = 2e5 + 5;

int n;
int a[N];
int fact[N];
int rfact[N];

inline int C(int nn, int kk) {
    if(nn < kk) return 0;
    return Mul(fact[nn], Mul(rfact[kk], rfact[nn - kk]));
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &n);

    for(int i = 0;i < n;i++) {
        scanf("%d", &a[i]);
    }

    if(n % 4 == 3) {
        int cur = 1;
        int ta[N];
        for(int i = 0;i + 1 < n;i++, cur ^= 1) {
            if(cur) {
                ta[i] = Sum(a[i], a[i + 1]);
            }else {
                ta[i] = Raz(a[i], a[i + 1]);
            }
        }
        memcpy(a, ta, sizeof(int) * (n - 1));
        n--;
    }

    fact[0] = 1;
    rfact[0] = 1;

    for(int i = 1;i < N;i++) {
        fact[i] = Mul(fact[i - 1], i);
        rfact[i] = Mul(rfact[i - 1], binpow(i, mod - 2));
    }

    int res = 0;

    if(n % 4 == 1) {
        int nn = (n - 1) / 2;
        int kk = 0;
        for(int i = 0;i < n;i++) {
            if(i % 2 == 0) {
                res = Sum(res, Mul(C(nn, kk), a[i]));
                kk++;
            }
        }
    }else if(n % 4 == 2) {
        int nn = (n - 2) / 2;
        int kk = 0;
        for(int i = 0;i < n;i += 2) {
            res = Sum(res, Mul(C(nn, kk), Sum(a[i], a[i + 1])));
            kk++;
        }
    }else if(n % 4 == 0) {
        int nn = n / 2 - 1;
        int kk = 0;
        for(int i = 0;i < n;i += 2) {
            res = Sum(res, Mul(C(nn, kk), Raz(a[i], a[i + 1])));
            kk++;
        }
    }else if(n % 4 == 3) {

    }

    printf("%d\n", res);

    return 0;
}