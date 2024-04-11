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

char str[maxn];

int main() {
    int n = read<int>(), m = read<int>();
    for (register int i = 1; i <= n; i++)
        while (str[i] != 'a' && str[i] != 'b') str[i] = getch();
    int answer = 0;
    int cnt = 0;
    for (register int l = 1, r = 0; l <= n; str[l++] != 'a' ? cnt-- : 0) {
        while (r < n && (str[r + 1] == 'a' || cnt < m)) cnt += (str[++r] != 'a');
        answer = max(answer, r - l + 1);
    }
    cnt = 0;
    for (register int l = 1, r = 0; l <= n; str[l++] != 'b' ? cnt-- : 0) {
        while (r < n && (str[r + 1] == 'b' || cnt < m)) cnt += (str[++r] != 'b');
        answer = max(answer, r - l + 1);
    }
    write(answer), putch('\n');
    return 0;
}