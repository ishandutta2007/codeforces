#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 100010;
const int MOD = 1e9 + 7;

int n, k;
int a[MAXN], b[MAXN], cnt, rem, dp[MAXN], ret, fact[MAXN];

bool lucky(int x) {
    while (x > 0) {
        if (!(x%10 == 4 || x%10 == 7)) return 0;
        x /= 10;
    }
    return 1;
}

int exp(int x, int y) {
    if (y == 0) return 1;
    int z = exp(x, y/2);
    if (y%2 == 0) return ll(z) * z % MOD;
    return ll(z) * z % MOD * x % MOD;
}

int C(int x, int y) {
    if (x < y || y < 0) return 0;
    return ll(fact[x]) * exp(fact[y], MOD - 2) % MOD * exp(fact[x-y], MOD - 2) % MOD;
}

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d %d", &n, &k);
    for (int i=0; i<n; i++) scanf("%d", &a[i]);
    fact[0] = 1;
    for (int i=1; i<=n; i++) {
        fact[i] = ll(fact[i-1]) * i % MOD;
    }
    sort(a, a+n);
    for (int i=0; i<n;) {
        int j = i;
        for (; j<n && a[j] == a[i]; j++);
        if (lucky(a[i])) {
            b[cnt++] = j - i;
        } else rem += j - i;
        i = j;
    }
    dp[0] = 1;
    for (int i=0; i<cnt; i++) {
        for (int j=n; j>0; j--) {
            dp[j] = (ll(dp[j-1]) * b[i] + dp[j]) % MOD;
        }
    }
    for (int i=0; i<=cnt; i++) {
        ret = (ll(ret) + ll(dp[i]) * C(rem, k-i)) % MOD;
    }
    printf("%d\n", ret);
}