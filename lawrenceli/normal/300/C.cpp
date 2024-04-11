#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 1000010;
const ll MOD = 1e9 + 7;

int a, b, n;
ll fact[MAXN], tot;

bool perf(int n) {
    while (n > 0) {
        if (n%10 != a && n%10 != b) return 0;
        n /= 10;
    }
    return 1;
}

ll exp(ll b, ll e) {
    if (e==0) return 1;
    ll x = exp(b, e/2);
    if (e%2 == 0) return x * x % MOD;
    return (x * x % MOD) * b % MOD;
}

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d %d %d", &a, &b, &n);
    fact[0] = 1;
    for (int i=1; i<=n; i++) fact[i] = (fact[i-1] * i) % MOD;
    for (int i=0; i<=n; i++) {
        int sum = a * i + b * (n-i);
        if (perf(sum)) {
            tot = (tot + ((fact[n] * exp(fact[i], MOD - 2)) % MOD * exp(fact[n-i], MOD-2)) % MOD) % MOD;
        }
    }
    printf("%I64d\n", tot);
}