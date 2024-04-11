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

template <int mod, int base>
class Hash {
   private:
    int f[maxn], p[maxn];

   public:
    void init(string s, int n) {
        p[0] = 1;
        for (register int i = 1; i <= n; i++) {
            f[i] = (1LL * f[i - 1] * base + s[i] - 'a') % mod;
            p[i] = 1LL * p[i - 1] * base % mod;
        }
        return;
    }
    inline int get(int l, int r) { return ((f[r] - 1LL * f[l - 1] * p[r - l + 1]) % mod + mod) % mod; }
};

#define mod 1000000007

string S, T;
int f[maxn], g[maxn], pos[maxn];

Hash<1000000007, 31> hashs1, hasht1;
Hash<1000000009, 31> hashs2, hasht2;

int main() {
    ios::sync_with_stdio(false);
    cin >> S >> T;
    int n = S.size(), m = T.size();
    S = ' ' + S, T = ' ' + T;
    hashs1.init(S, n), hashs2.init(S, n);
    hasht1.init(T, m), hasht2.init(T, m);
    int hash1 = hasht1.get(1, m), hash2 = hasht2.get(1, m);
    for (register int i = 1; i <= n; i++)
        if (i >= m && hashs1.get(i - m + 1, i) == hash1 && hashs2.get(i - m + 1, i) == hash2)
            pos[i] = i - m + 1;
        else
            pos[i] = pos[i - 1];
    f[0] = g[0] = 1;
    for (register int i = 1; i <= n; i++) {
        f[i] = f[i - 1];
        if (pos[i]) f[i] = (f[i] + g[pos[i] - 1]) % mod;
        g[i] = (g[i - 1] + f[i]) % mod;
    }
    write((f[n] - 1 + mod) % mod), putch('\n');
    return 0;
}