/**
 * @author Macesuted Kysic
 * @date 2021-03-11
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

#define maxn 500005
#define maxlgn 63
#define mod 1000000007

long long a[maxn];
int cnt[maxlgn];

bool en;

int main() {
    int T = read<int>();
    while (T--) {
        int n = read<int>();
        memset(cnt, 0, sizeof(cnt));
        for (register int i = 1; i <= n; i++) {
            a[i] = read<long long>();
            for (register int j = 0; j < maxlgn; j++) cnt[j] += ((a[i] >> j) & 1);
        }
        long long answer = 0;
        for (register int i = 1; i <= n; i++) {
            long long an = 0, o = 0;
            for (register int j = 0; j < maxlgn; j++)
                an = (an + (((a[i] >> j) & 1) ? cnt[j] : 0) % mod * ((1LL << j) % mod) % mod) % mod,
                o = (o + (((a[i] >> j) & 1) ? n : cnt[j]) % mod * ((1LL << j) % mod) % mod) % mod;
            answer = (answer + an * o % mod) % mod;
        }
        write(answer), putch('\n');
    }
    return 0;
}