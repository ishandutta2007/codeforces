#include <bits/stdc++.h>
using namespace std;

template <typename T>
T read(void) {
    T f = 1, num = 0;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') f = -f;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        num = (num << 3) + (num << 1) + (c ^ 48);
        c = getchar();
    }
    return f * num;
}

// const int maxn = 1e6 + 5;
const int maxn = 2e3 + 5;
const long long mod = 1e9 + 7;

long long fac[maxn], inv[maxn];
int c[maxn];

long long power(long long a, long long x) {
    long long ans = 1;
    while (x) {
        if (x & 1) ans = ans * a % mod;
        a = a * a % mod;
        x >>= 1;
    }
    return ans;
}
inline long long C(int n, int m) { return fac[n] * inv[m] % mod * inv[n - m] % mod; }

int main() {
    fac[0] = inv[0] = 1;
    for (int i = 1; i < maxn; i++) fac[i] = fac[i - 1] * i % mod;
    inv[maxn - 1] = power(fac[maxn - 1], mod - 2);
    for (int i = maxn - 2; i; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
    int k = read<int>();
    for (int i = 1; i <= k; i++) c[i] = read<int>();
    long long ans = 1, sum = 0;
    for (int i = 1; i <= k; i++) ans = ans * C((sum += c[i]) - 1, c[i] - 1) % mod;
    printf("%lld\n", ans);
    return 0;
}