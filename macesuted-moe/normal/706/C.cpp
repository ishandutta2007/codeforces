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

#define maxn 100005

string str[2][maxn];
long long a[maxn], f[2][maxn];

int main() {
    int n = read<int>();
    for (register int i = 1; i <= n; i++) a[i] = read<int>();
    for (register int i = 1; i <= n; i++) {
        str[0][i].clear();
        char c = getch();
        while (c < 'a' || c > 'z') c = getch();
        while ('a' <= c && c <= 'z') {
            str[0][i].push_back(c);
            c = getch();
        }
        str[1][i] = str[0][i];
        reverse(str[1][i].begin(), str[1][i].end());
    }
    memset(f, 0x3f, sizeof(f));
    f[0][1] = 0, f[1][1] = a[1];
    for (register int i = 2; i <= n; i++) {
        for (register int thi = 0; thi <= 1; thi++)
            for (register int tha = 0; tha <= 1; tha++)
                if (str[thi][i] >= str[tha][i - 1])
                    f[thi][i] = min(f[thi][i], f[tha][i - 1] + thi * a[i]);
        if (min(f[0][i], f[1][i]) == 0x3f3f3f3f3f3f3f3f) {
            putstr("-1\n");
            return 0;
        }
    }
    write(min(f[0][n], f[1][n])), putch('\n');
    return 0;
}