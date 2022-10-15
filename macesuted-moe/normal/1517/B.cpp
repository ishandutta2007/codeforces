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
using io::putch;
using io::putstr;
using io::read;
using io::write;

#define maxn 105

struct Rec {
    int val, line;
    inline bool operator<(const Rec& oth) const { return this->val < oth.val; }
};

multiset<int> a[maxn];
int ans[maxn][maxn];
vector<Rec> rec;

int main() {
    int _ = read<int>();
    while (_--) {
        int n = read<int>(), m = read<int>();
        rec.clear();
        for (register int i = 1; i <= n; i++) {
            a[i].clear();
            for (register int j = 1; j <= m; j++) {
                int t = read<int>();
                a[i].insert(t);
                rec.push_back((Rec){t, i});
            }
        }
        sort(rec.begin(), rec.end());
        memset(ans, 0, sizeof(ans));
        for (register int i = 1; i <= m; i++) {
            ans[rec[i - 1].line][i] = rec[i - 1].val;
            a[rec[i - 1].line].erase(a[rec[i - 1].line].lower_bound(rec[i - 1].val));
        }
        for (register int i = 1; i <= n; i++)
            for (register int j = 1; j <= m; j++)
                if (!ans[i][j]) ans[i][j] = *a[i].begin(), a[i].erase(a[i].begin());
        for (register int i = 1; i <= n; i++)
            for (register int j = 1; j <= m; j++) write(ans[i][j]), putch(" \n"[j == m]);
    }
    return 0;
}//awa