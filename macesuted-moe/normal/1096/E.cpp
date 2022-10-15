/**
 * @author Macesuted
 * @date 2021-01-03
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <bits/stdc++.h>
using namespace std;

#define bufferSiz (1 << 18)
char Buff[bufferSiz], *_S = Buff, *_T = Buff;
#define getchar() (_S == _T && (_T = (_S = Buff) + fread(Buff, 1, bufferSiz, stdin), _S == _T) ? EOF : *_S++)

template <typename T>
T read(void) {
    T f = 1, num = 0;
    char c = getchar();
    while (!isdigit(c)) {
        if (c == '-')
            f = -f;
        c = getchar();
    }
    while (isdigit(c)) {
        num = (num << 3) + (num << 1) + (c ^ 48);
        c = getchar();
    }
    return f * num;
}

#define maxn 5105
#define mod 998244353

long long fac[maxn], inv[maxn];

long long power(long long a, long long x) {
    long long ans = 1;
    while (x) {
        if (x & 1) ans = ans * a % mod;
        a = a * a % mod;
        x >>= 1;
    }
    return ans;
}

inline long long C(int n, int m) { return n < m || n < 0 || m < 0 ? 0 : fac[n] * inv[m] % mod * inv[n - m] % mod; }

long long solve(int n, int m, int lim) {
    if (n == 0) return 1;
    long long sum = 0;
    for (register int i = 0; i <= m; i++) sum = (sum + ((i & 1) ? -1 : 1) * C(m, i) % mod * C(n - i * lim + m - 1, m - 1) % mod) % mod;
    return (sum % mod + mod) % mod;
}

int main() {
    fac[0] = inv[0] = 1;
    for (register int i = 1; i < maxn; i++) fac[i] = fac[i - 1] * i % mod;
    inv[maxn - 1] = power(fac[maxn - 1], mod - 2);
    for (register int i = maxn - 2; i; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
    int p = read<int>(), s = read<int>(), r = read<int>();
    long long answer = 0;
    for (register int x = r; x <= s; x++)
        for (register int i = 1; i <= p; i++)
            if (i * x + (p - i) * (x - 1) >= s && i * x <= s)
                answer = (answer + solve(s - i * x, p - i, x) * C(p - 1, i - 1) % mod * power(i, mod - 2)) % mod;
    printf("%lld\n", answer * power(C(s - r + p - 1, p - 1), mod - 2) % mod);
    return 0;
}