/**
     * @author Macesuted
     * @date 2021-02-03
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
    char c = getchar();
    T f = 1, num = 0;
    while (c < '0' || c > '9') {
        if (c == '-') f = -f;
        c = getchar();
    }
    while ('0' <= c && c <= '9') {
        num = (num << 3) + (num << 1) + (c ^ 48);
        c = getchar();
    }
    return f * num;
}

#define maxn 100005

int fa[maxn], siz[maxn];
inline int getfa(int p) { return fa[p] == p ? p : fa[p] = getfa(fa[p]); }

long long power(long long a, long long x, long long p) {
    long long ans = 1;
    while (x) {
        if (x & 1) ans = ans * a % p;
        a = a * a % p;
        x >>= 1;
    }
    return ans;
}

int main() {
    int n = read<int>(), m = read<int>(), p = read<int>();
    for (register int i = 1; i <= n; i++) fa[i] = i, siz[i] = 1;
    for (register int i = 1, from, to; i <= m; i++) {
        from = getfa(read<int>()), to = getfa(read<int>());
        if (from == to) continue;
        siz[to] += siz[from], fa[from] = to;
    }
    long long ans = 1;
    int k = 0;
    for (register int i = 1; i <= n; i++)
        if (fa[i] == i) ans = ans * siz[i] % p, k++;
    printf("%lld\n", k <= 1 ? 1 % p : ans * power(n, k - 2, p) % p);
    return 0;
}