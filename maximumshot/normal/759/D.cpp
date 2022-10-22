#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const mod = inf + 7;

inline int sum(int a, int b) {
    return (a + b) % mod;
}

inline int raz(int a, int b) {
    return ((a - b) % mod + mod) % mod;
}

inline int mul(int a, int b) {
    return (1ll * a * b) % mod;
}

int binpow(int n, int p) {
    if(p == 0) return 1;
    int q = binpow(n, p / 2);
    q = mul(q, q);
    if(p % 2) q = mul(q, n);
    return q;
}

int const N = 5005;

int n;
char str[N];
int fact[N];
int rfact[N];

int C(int n, int k) {
    return n < k ? 0 : mul( fact[n], mul(rfact[n - k], rfact[k]) );
}

int dp[N][26];
int sm[N];

int main() {

    fact[0] = rfact[0] = 1;

    for(int i = 1;i < N;i++) {
        fact[i] = mul(fact[i - 1], i);
        rfact[i] = binpow(fact[i], mod - 2);
    }

    scanf("%d %s", &n, str);

    for(int x, i = 0;i < n;i++) {
        x = str[i] - 'a';
        for(int add, len = 1;len <= i + 1;len++) {
            sm[len] = raz(sm[len], dp[len][x]);
            add = raz(sm[len - 1], dp[len - 1][x]);
            dp[len][x] = sum(add, len == 1);
            sm[len] = sum(sm[len], dp[len][x]);
        }
    }

    int res = 0;

    for(int len = 1;len <= n;len++) {
        res = sum(res, mul(C(n - 1, len - 1), sm[len]));
    }

    printf("%d\n", res);

    return 0;
}