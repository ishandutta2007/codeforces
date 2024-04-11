#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 9;
const int maxn = 1e6 + 5;

long long f[maxn];

long long power(long long a, long long x) {
    long long ans = 1;
    while (x) {
        if (x & 1) (ans *= a) %= mod;
        (a *= a) %= mod;
        x >>= 1;
    }
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);
    f[1] = 1;
    for (int i = 2; i <= n; i++) f[i] = (f[i - 1] * (power(2, i) - 3)) % mod;
    long long s = 0;
    for (int i = 2; i <= n >> 1; i++) (s += f[i] << 2) %= mod;
    printf("%lld\n", (10LL + (s << 3) + (power(s, 2) << 1)) % mod);
    return 0;
}