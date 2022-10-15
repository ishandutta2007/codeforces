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
string getstr(void) {
    string s = "";
    char c = getch();
    while (c == ' ' || c == '\n' || c == '\r' || c == '\t') c = getch();
    while (!(c == ' ' || c == '\n' || c == '\r' || c == '\t')) s.push_back(c), c = getch();
    return s;
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
using io::getstr;
using io::putch;
using io::putstr;
using io::read;
using io::write;

#define maxn 50005
#define maxlgn 19
#define mod 1000000007

typedef pair<int, long long> pii;

const int prime[19] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};

long long power(long long a, long long x) {
    long long ans = 1;
    while (x) {
        if (x & 1) ans = ans * a % mod;
        a = a * a % mod;
        x >>= 1;
    }
    return ans;
}

long long rec[maxlgn];

void insert(long long val) {
    for (register int i = maxlgn - 1; ~i; i--)
        if (val >> i & 1) {
            if (rec[i]) {
                val ^= rec[i];
                if (!val) return;
            } else {
                rec[i] = val;
                break;
            }
        }
    return;
}

int main() {
    int n = read<int>();
    for (register int i = 1; i <= n; i++) {
        int a = read<int>(), statu = 0;
        for (register int j = 0; j < maxlgn; j++)
            while (a % prime[j] == 0) a /= prime[j], statu ^= 1 << j;
        insert(statu);
    }
    int cnt = 0;
    for (register int i = 0; i < maxlgn; i++)
        if (rec[i]) cnt++;
    write((power(2, n - cnt) + mod - 1) % mod), putch('\n');
    return 0;
}