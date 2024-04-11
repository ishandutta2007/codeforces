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

#define maxn 505

int a[maxn][maxn];
bool vis[2][maxn];

int main() {
    int n = read<int>(), m = read<int>();
    for (register int i = 1; i <= n; i++)
        for (register int j = 1; j <= m; j++)
            a[i][j] = read<int>();
    for (register int t = 0; t < 10; t++) {
        bool only = true, ans = false;
        for (register int i = 1; i <= n; i++) {
            vis[0][i] = vis[1][i] = false;
            for (register int j = 1; j <= m; j++) vis[a[i][j] >> t & 1][i] = true;
            if (vis[0][i] && vis[1][i])
                only = false;
            else
                ans ^= vis[1][i];
        }
        if (only) {
            if (ans) {
                putstr("TAK\n");
                for (register int i = 1; i <= n; i++) write(1), putch(" \n"[i == n]);
                return 0;
            } else
                continue;
        }
        int spe = -1, pt = 0;
        ans = false;
        for (register int i = 1; i <= n; i++) ans ^= (a[i][1] >> t & 1);
        if (!ans)
            for (register int i = 1; i <= n; i++) {
                bool thi = (a[i][1] >> t & 1);
                if (!vis[!thi][i]) continue;
                for (register int j = 2; j <= m; j++)
                    if ((a[i][j] >> t & 1) != thi) {
                        spe = i, pt = j;
                        break;
                    }
                break;
            }
        if (!ans && spe == -1) continue;
        putstr("TAK\n");
        for (register int i = 1; i <= n; i++) write(i == spe ? pt : 1), putch(" \n"[i == n]);
        return 0;
    }
    putstr("NIE\n");
    return 0;
}