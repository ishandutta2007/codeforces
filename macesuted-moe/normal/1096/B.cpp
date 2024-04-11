/**
 * @author Macesuted
 * @date 2021-03-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <bits/stdc++.h>
using namespace std;

#define bufferSiz (1 << 18)
char Buff[bufferSiz], *_S = Buff, *_T = Buff;
#define getchar() (_S == _T && (_T = (_S = Buff) + fread(Buff, 1, bufferSiz, stdin), _S == _T) ? EOF : *_S++)

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

#define maxn 200005
#define mod 998244353

char str[maxn];

int main() {
    int n = read<int>();
    for (register int i = 1; i <= n; i++)
        while (str[i] < 'a' || str[i] > 'z') str[i] = getch();
    int l = 1, r = n;
    while (str[l] == str[l + 1]) l++;
    while (str[r - 1] == str[r]) r--;
    if (l > r)
        printf("%lld\n", 1LL * n * n % mod);
    else
        printf("%lld\n", (1 + l + (n - r + 1) + (str[l] == str[r] ? 1LL * l * (n - r + 1) : 0)) % mod);
    return 0;
}