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

#define maxn 200005
#define mod 1000000007

typedef pair<int, int> pii;

pii a[maxn], point[maxn << 2];
long long fac[maxn], inv[maxn];

long long power(long long a, long long x) {
    long long ans = 1;
    while (x) {
        if (x & 1) ans = ans * a % mod;
        a = a * a % mod;
        x >>= 1;
    }
    return ans;
}

inline long long C(int n, int m) { return fac[n] * inv[m] % mod * inv[n - m] % mod; }

int times[maxn << 2];

int main() {
    fac[0] = inv[0] = 1;
    for (register int i = 1; i < maxn; i++) fac[i] = fac[i - 1] * i % mod;
    inv[maxn - 1] = power(fac[maxn - 1], mod - 2);
    for (register int i = maxn - 2; i; i--) inv[i] = inv[i + 1] * (i + 1) % mod;

    int n = read<int>(), k = read<int>();
    for (register int i = 1; i <= n; i++) a[i].first = read<int>(), a[i].second = read<int>();
    for (register int i = 1; i <= n; i++) point[i] = (pii){a[i].first, 1}, point[i + n] = (pii){a[i].second, 1};
    sort(point + 1, point + (n << 1) + 1);
    int nn = unique(point + 1, point + (n << 1) + 1) - point - 1;
    for (register int i = 1, lim = nn; i < lim; i++)
        if (point[i + 1].first - point[i].first > 1) point[++nn] = (pii){point[i].first + 1, point[i + 1].first - point[i].first - 1};
    sort(point + 1, point + nn + 1);
    for (register int i = 1; i <= n; i++) {
        int pl = lower_bound(point + 1, point + nn + 1, (pii){a[i].first, 1}) - point,
            pr = lower_bound(point + 1, point + nn + 1, (pii){a[i].second, 1}) - point;
        times[pl]++, times[pr + 1]--;
    }
    for (register int i = 1; i <= nn; i++) times[i] += times[i - 1];
    long long answer = 0;
    for (register int i = 1; i <= nn; i++)
        if (times[i] >= k) answer = (answer + point[i].second * C(times[i], k)) % mod;
    write(answer), putch('\n');
    return 0;
}