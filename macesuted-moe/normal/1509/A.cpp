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

#define maxn 3005

queue<int> que[2];

int main() {
    int _ = read<int>();
    while (_--) {
        int n = read<int>();
        for (register int i = 1; i <= n; i++) {
            int t = read<int>();
            que[t & 1].push(t);
        }
        while (!que[0].empty()) write(que[0].front()), putch(' '), que[0].pop();
        while (!que[1].empty()) write(que[1].front()), putch(' '), que[1].pop();
        putch('\n');
    }
    return 0;
}
//awa