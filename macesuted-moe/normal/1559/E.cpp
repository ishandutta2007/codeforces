#include <bits/stdc++.h>

const int N = 1e5 + 10, mod = 998244353;

inline int read()
{
    int x = 0, f = 0;
    char ch = getchar();
    while (!isdigit(ch))
        f |= ch == '-', ch = getchar();
    while ( isdigit(ch))
        x = x * 10 + ch - '0', ch = getchar();
    return f ? -x : x;
}

int f[N], g[N], l[N], r[N], L[N], R[N], mu[N];

int main()
{
    int n = read(), m = read(), ans = 0;
    for (int i = 1; i <= n; ++i)
        l[i] = read(), r[i] = read();
    mu[1] = 1;
    for (int i = 1; i <= m; ++i)
        for (int j = i + i; j <= m; j += i)
            mu[j] -= mu[i];
    // for (int i = 1; i <= 20; ++i)
        // printf("%d ", mu[i]);
    // puts("");
    for (int i = 1; i <= m; ++i)
        if (mu[i] != 0) {
            for (int j = 1; j <= n; ++j)
                L[j] = (l[j] - 1) / i + 1, R[j] = r[j] / i;
            int M = m / i;
            for (int i = 1; i <= n; ++i)
                M -= L[i], R[i] -= L[i];
            f[0] = g[0] = 1;
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= M; ++j)
                    g[j] = (f[j] + g[j - 1]) % mod;
                for (int j = 1; j <= M; ++j)
                    f[j] = g[j] - (j - R[i] - 1 >= 0 ? g[j - R[i] - 1] : 0);
                for (int j = 1; j <= M; ++j)
                    f[j] = (f[j] + mod) % mod;
            }
            int res = 0;
            for (int i = 0; i <= M; ++i)
                (res += f[i]) %= mod;
            for (int i = 1; i <= M; ++i) f[i] = g[i] = 0;
            if (mu[i] == -1)
                res = mod - res;
            ans = (ans + res) % mod;
        }
    std::cout << ans << std::endl;
    return 0;
}