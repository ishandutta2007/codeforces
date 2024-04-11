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

int const mod = inf + 7;

inline int Sum(int a, int b) {
    return (a + b) % mod;
}

inline int Mul(int a, int b) {
    return (1ll * a * b) % mod;
}

int const X = 5e6 + 5;

bool prime[X];
int a[X];
int f[X];

void prepare() {
    for(int i = 0;i < X;i++) {
        prime[i] = 1;
    }
    prime[0] = prime[1] = 0;
    for(int x = 2;x * x < X;x++) {
        if(!prime[x]) continue;
        for(int y = x * x;y < X;y += x) {
            prime[y] = 0;
        }
    }
    for(int x = X - 1;x >= 0;x--) {
        if(!prime[x]) continue;
        for(int y = x;y < X;y += x) a[y] = x;
    }
    for(int p, pp, i = 2;i < X;i++) {
        p = a[i];
        if(p % 2) pp = Mul(p, (p - 1) / 2);
        else pp = Mul(p / 2, p - 1);
        f[i] = Sum(f[i / p], Mul(i / p, pp));
    }
}

int main() {

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    prepare();

    int t, l, r;

    scanf("%d %d %d", &t, &l, &r);

    int cur = 1;
    int res = 0;

    for(int i = l;i <= r;i++) {
        res = Sum(res, Mul(cur, f[i]));
        cur = Mul(cur, t);
    }

    printf("%d\n", res);

    return 0;
}