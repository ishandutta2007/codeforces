/**
 * @author Macesuted (macesuted@qq.com)
 * @copyright Copyright (c) 2021
 */

#include <bits/stdc++.h>
using namespace std;

namespace io {
#define SIZE (1 << 20)
char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55];
int f, qr;
inline void flush(void) { return fwrite(obuf, 1, oS - obuf, stdout), oS = obuf, void(); }
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
    return x * f;
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

#define maxn 505

int f[21][maxn][maxn], rig[maxn][maxn], down[maxn][maxn];

int main() {
    int n = read<int>(), m = read<int>(), k = read<int>();
    memset(rig, 0x3f, sizeof(rig)), memset(down, 0x3f, sizeof(down));
    for (register int i = 1; i <= n; i++)
        for (register int j = 1; j < m; j++)
            rig[i][j] = read<int>();
    for (register int i = 1; i < n; i++)
        for (register int j = 1; j <= m; j++)
            down[i][j] = read<int>();
    if (k & 1) {
        for (register int i = 1; i <= n; i++)
            for (register int j = 1; j <= m; j++)
                write(-1), putch(" \n"[j == m]);
        return 0;
    }
    k >>= 1;
    for (register int t = 1; t <= k; t++)
        for (register int i = 1; i <= n; i++)
            for (register int j = 1; j <= m; j++)
                f[t][i][j] = min(min(f[t - 1][i - 1][j] + down[i - 1][j], f[t - 1][i][j - 1] + rig[i][j - 1]),
                                 min(f[t - 1][i + 1][j] + down[i][j], f[t - 1][i][j + 1] + rig[i][j]));
    for (register int i = 1; i <= n; i++)
        for (register int j = 1; j <= m; j++)
            write(f[k][i][j] << 1), putch(" \n"[j == m]);
    return 0;
}//awa