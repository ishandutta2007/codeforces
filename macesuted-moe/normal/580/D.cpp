/**
 * @author Macesuted
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <bits/stdc++.h>
using namespace std;

namespace io {

#define SIZE (1 << 18)

char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55];
int f, qr;

inline void flush(void) {
    fwrite(obuf, 1, oS - obuf, stdout);
    oS = obuf;
    return;
}

inline char getch(void) { return (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS++)) : *iS++); }
inline void putch(char x) {
    *oS++ = x;
    if (oS == oT) flush();
    return;
}

void putstr(string str, int begin = 0, int end = -1) {
    if (end == -1) end = str.size();
    for (register int i = begin; i < end; i++) putch(str[i]);
    return;
}

template <typename T>
inline T read() {
    register T x = 0;
    for (f = 1, c = getch(); c < '0' || c > '9'; c = getch())
        if (c == '-') f = -1;
    for (x = 0; c <= '9' && c >= '0'; c = getch()) x = x * 10 + (c & 15);
    x *= f;
    return x;
}
template <typename T>
inline void write(const T& t) {
    register T x = t;
    if (!x) putch('0');
    if (x < 0) putch('-'), x = -x;
    while (x) qu[++qr] = x % 10 + '0', x /= 10;
    while (qr) putch(qu[qr--]);
    return;
}
struct Flusher_ {
    ~Flusher_() { flush(); }
} io_flusher_;
}  // namespace io
using io::getch;
using io::putch;
using io::putstr;
using io::read;
using io::write;

#define maxn 18

long long f[1 << maxn][maxn];
int a[maxn], c[maxn][maxn], cnt[1 << maxn];

int main() {
    int n = read<int>(), m = read<int>(), k = read<int>(), maxS = 1 << n;
    for (register int i = 0; i < n; i++) a[i] = read<int>();
    for (register int i = 1; i < maxS; i++) cnt[i] = cnt[i >> 1] + (i & 1);
    for (register int i = 1; i <= k; i++) {
        int from = read<int>(), to = read<int>();
        c[from - 1][to - 1] = read<int>();
    }
    for (register int i = 0; i < n; i++) f[1 << i][i] = a[i];
    for (register int S = 1; S < maxS; S++)
        for (register int i = 0; i < n; i++)
            if (S >> i & 1)
                for (register int j = 0; j < n; j++)
                    if (!(S >> j & 1))
                        f[S | (1 << j)][j] = max(f[S | (1 << j)][j], f[S][i] + c[i][j] + a[j]);
    long long answer = 0;
    for (register int S = 0; S < maxS; S++)
        if (cnt[S] == m)
            for (register int j = 0; j < n; j++)
                if (S >> j & 1)
                    answer = max(answer, f[S][j]);
    write(answer), putch('\n');
    return 0;
}