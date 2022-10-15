/**
 * @author Macesuted
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <bits/stdc++.h>
using namespace std;

namespace io {

#define SIZE (1 << 20)

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

#define maxn 105

bool ans[maxn][maxn];

vector<int> pos;

bool ask1(int from, int to) {
    printf("1 %d %d\n", from, to);
    fflush(stdout);
    int ret;
    scanf("%d", &ret);
    return ret;
}
bool ask2(int from, vector<int>& vec, int p) {
    printf("2 %d %d", from, p + 1);
    for (register int i = 0; i <= p; i++) printf(" %d", vec[i]);
    puts("");
    fflush(stdout);
    int ret;
    scanf("%d", &ret);
    return ret;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        pos.clear();
        for (register int i = 0; i < n; i++) pos.push_back(i);
        stable_sort(pos.begin(), pos.end(), ask1);
        for (register int i = 0; i < n; i++)
            for (register int j = 0; j < n; j++)
                ans[i][j] = true;
        for (register int i = n - 1, p = n - 2; ~i; i--) {
            if (p == i) {
                for (register int x = 0; x <= p; x++)
                    for (register int y = p + 1; y < n; y++)
                        ans[pos[y]][pos[x]] = false;
                p--;
            }
            while (ask2(pos[i], pos, p)) p--;
        }
        puts("3");
        for (register int i = 0; i < n; i++) {
            for (register int j = 0; j < n; j++) putchar("01"[ans[i][j]]);
            puts("");
        }
        fflush(stdout);
        int ret;
        scanf("%d", &ret);
        if (ret == -1) return 0;
    }
    return 0;
}