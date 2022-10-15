/**
 * @author Macesuted Kysic
 * @date 2021-03-08
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <bits/stdc++.h>
using namespace std;

bool beg;

namespace io {

#define SIZE (1 << 18)

char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55];
int f, qr;

inline void flush(void) {
    fwrite(obuf, 1, oS - obuf, stdout);
    oS = obuf;
}

inline char getch(void) { return (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS++)) : *iS++); }
inline void putch(char x) {
    *oS++ = x;
    if (oS == oT) flush();
    return;
}
template <typename I>
inline I read() {
    register I x = 0;
    for (f = 1, c = getch(); c < '0' || c > '9'; c = getch())
        if (c == '-') f = -1;
    for (x = 0; c <= '9' && c >= '0'; c = getch()) x = x * 10 + (c & 15);
    x *= f;
    return x;
}
template <typename I>
inline void write(const I& t) {
    register I x = t;
    if (!x) putch('0');
    if (x < 0) putch('-'), x = -x;
    while (x) qu[++qr] = x % 10 + '0', x /= 10;
    while (qr) putch(qu[qr--]);
}
struct Flusher_ {
    ~Flusher_() { flush(); }
} io_flusher_;
}  // namespace io
using io::getch;
using io::putch;
using io::read;
using io::write;

#define maxlenn 21

long long buc[maxlenn];

bool en;

int main() {
    long long n = read<long long>();
    for (register int i = 1, t; i <= n; i++) {
        t = read<int>();
        for (register int j = 0; j < maxlenn; j++) buc[j] += (t >> j) & 1;
    }
    long long ans = 0;
    for (register long long i = 1, tmp = 0; i <= n; i++, ans += tmp * tmp, tmp = 0)
        for (int j = 0; j < maxlenn; j++)
            if (buc[j]) buc[j]--, tmp += 1 << j;
    write(ans), putch('\n');
    return 0;
}