/**
 * @author Macesuted
 * @date 2021-02-25
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

#define maxn 10000005

long long f[maxn];

int main() {
    int n = read<int>(), x = read<int>(), y = read<int>();
    for (register int i = 1; i <= n; i++) f[i] = min(f[i - 1] + x, f[(i + 1) >> 1] + y + x * (i & 1));
    printf("%lld\n", f[n]);
    return 0;
}