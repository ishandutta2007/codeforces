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

#define maxn 505
#define mod 1000000007

long long f[maxn][maxn];
int dfn[maxn];

long long dfs(int l, int r) {
    if (l == r) return 1;
    if (f[l][r]) return f[l][r];
    for (register int i = l + 1; i < r; i++)
        if (dfn[l + 1] <= dfn[i + 1]) f[l][r] = (f[l][r] + dfs(l + 1, i) * dfs(i, r) % mod) % mod;
    return f[l][r] = (f[l][r] + dfs(l + 1, r)) % mod;
}
int main() {
    int n = read<int>();
    for (register int i = 1; i <= n; i++) dfn[i] = read<int>();
    printf("%lld\n", dfs(1, n));
    return 0;
}