#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef pair< int, int > pii;
typedef long long ll;
typedef pair< ll, ll > pll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 100005;

inline int mul(int a, int b, int m) {
    return (1ll * a * b) % m;
}

inline int sum(int a, int b, int m) {
    return (a + b) % m;
}

inline int raz(int a, int b, int m) {
    return ((a - b) % m + m) % m;
}

int binpow(int n, int p, int m) {
    if(!p) return 1 % m;
    int q = binpow(n, p / 2, m);
    q = mul(q, q, m);
    if(p % 2) q = mul(q, n, m);
    return q;
}

int del(int a, int b, int m) {
    return mul(a, binpow(b, m - 2, m), m);
}

int m, n;
int a[N];

int main() {

    scanf("%d %d", &m, &n);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
    }

    sort(a + 1, a + n + 1);

    if(n == 1) {
        printf("%d %d\n", a[1], 0);
        return 0;
    }else if(n == 2) {
        printf("%d %d\n", a[1], a[2] - a[1]);
        return 0;
    }

    unordered_set< int > Q;

    for(int i = 1;i <= n;i++) Q.insert(a[i]);

    int S = 0;
    int sum_sqr = 0;

    for(int i = 1;i <= n;i++) {
        S = sum(S, a[i], m);
        sum_sqr = sum(sum_sqr, mul(a[i], a[i], m), m);
    }

    for(int T, d, i = 1;i <= n;i++) {
        d = del( mul(2 % m, S, m), n, m );
        d = raz(d, mul(2 % m, a[i], m), m);
        d = del(d, (n - 1) % m, m);
        if(!d) continue;

        T = mul(n, mul(a[i], a[i], m), m);
        T = sum(T, mul( mul(a[i], d, m), mul(n, n - 1, m), m ), m);
        T = sum(T, del(mul( mul(d, d, m), mul(n, mul(n - 1, (2 * n - 1) % m, m), m), m), 6, m), m);

        if(T != sum_sqr) continue;

        int ok = 1;
        for(int cur, j = 0;j < n;j++) {
            cur = sum( a[i], mul(j, d, m), m);
            if(!Q.count(cur)) {
                ok = 0;
                break;
            }
        }
        if(ok) {
            printf("%d %d\n", a[i], d);
            return 0;
        }
    }

    printf("-1");

    return 0;
}