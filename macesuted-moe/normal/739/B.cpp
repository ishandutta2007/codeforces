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

#define maxn 200005
#define maxlgn 20

typedef pair<int, int> pii;

int a[maxn];
int fa[maxn][maxlgn], ans[maxn];
long long dist[maxn][maxlgn];

vector<vector<pii> > graph;

void dfs(int p, int pre) {
    for (register int i = 1; i < maxlgn; i++) fa[p][i] = fa[fa[p][i - 1]][i - 1], dist[p][i] = dist[p][i - 1] + dist[fa[p][i - 1]][i - 1];
    for (vector<pii>::iterator i = graph[p].begin(); i != graph[p].end(); i++)
        if (i->first != pre) fa[i->first][0] = p, dist[i->first][0] = i->second, dfs(i->first, p);
    return;
}
void dfs2(int p, int pre) {
    for (vector<pii>::iterator i = graph[p].begin(); i != graph[p].end(); i++)
        if (i->first != pre) dfs2(i->first, p), ans[p] += ans[i->first];
    return;
}

int main() {
    int n = read<int>();
    graph.resize(n + 1);
    for (register int i = 1; i <= n; i++) a[i] = read<int>();
    for (register int i = 2; i <= n; i++) {
        int from = read<int>(), dist = read<int>();
        graph[from].push_back((pii){i, dist}), graph[i].push_back((pii){from, dist});
    }
    dfs(1, 0);
    for (register int i = 1; i <= n; i++) {
        int top = i, dis = a[i];
        for (register int j = maxlgn - 1; ~j; j--)
            if (dist[top][j] <= dis) dis -= dist[top][j], top = fa[top][j];
        ans[fa[i][0]]++, ans[fa[top][0]]--;
    }
    dfs2(1, 0);
    for (register int i = 1; i <= n; i++) write(ans[i]), putch(" \n"[i == n]);
    return 0;
}