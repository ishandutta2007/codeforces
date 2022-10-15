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

int f[maxn], g[maxn], a[maxn];

int main() {
    int n = read<int>();
    for (register int i = 1; i <= n; i++) a[i] = read<int>();
    for (register int i = 1; i <= n; i++) {
        f[i] = 1;
        if (i > 1 && a[i] > a[i - 1]) f[i] += f[i - 1];
    }
    for (register int i = n; i; i--) {
        g[i] = 1;
        if (i < n && a[i] < a[i + 1]) g[i] += g[i + 1];
    }
    int answer = 1;
    for (register int i = 1; i < n; i++) answer = max(answer, f[i] + 1);
    for (register int i = 2; i <= n; i++) answer = max(answer, 1 + g[i]);
    for (register int i = 2; i < n; i++)
        if (a[i - 1] + 1 < a[i + 1]) answer = max(answer, f[i - 1] + 1 + g[i + 1]);
    write(answer), putch('\n');
    return 0;
}