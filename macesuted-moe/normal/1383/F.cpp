#include <bits/stdc++.h>
using namespace std;
const int Max_N = 1e4, Max_M = 1e4, Max_K = 10, Max_W = 25, Max_Q = 2e5, Inf = 25, INF = 1e9;
int n, m, K, q, Num = 1, Hd, Tl, w[15][Max_M * 2 + 5], flo[Max_N + 5], pre[Max_N + 5], prep[Max_N + 5], lin[Max_N + 5], Lin[Max_N + 5], f[1 << 10], g[1 << 10], vis[1 << 10], nw[Max_K + 5], dis[Max_N + 5], Bit[1 << 10], Q[Max_N + 5];
struct Edge {
    int Id, Next;
} e[Max_M * 2 + 5];
struct EDGE {
    int u, v, w;
} E[Max_M + 5];
namespace io {
#define SIZE (1 << 20)
char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55];
int f, qr;
inline void flush(void) { return fwrite(obuf, 1, oS - obuf, stdout), oS = obuf, void(); }
inline char getch(void) {
    return (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS++)) : *iS++);
}
void putch(char x) {
    *oS++ = x;
    if (oS == oT) flush();
    return;
}
string getstr(void) {
    string s = "";
    char c = getch();
    while (c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == EOF) c = getch();
    while (!(c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == EOF)) s.push_back(c), c = getch();
    return s;
}
void putstr(string str, int begin = 0, int end = -1) {
    if (end == -1) end = str.size();
    for (int i = begin; i < end; i++) putch(str[i]);
    return;
}
template <typename T>
T read() {
    T x = 0;
    for (f = 1, c = getch(); c < '0' || c > '9'; c = getch())
        if (c == '-') f = -1;
    for (x = 0; c <= '9' && c >= '0'; c = getch()) x = x * 10 + (c & 15);
    return x * f;
}
template <typename T>
void write(const T& t) {
    T x = t;
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

void Insert(int x, int y) {
    e[++Num].Next = lin[x];
    lin[x] = Num;
    e[Num].Id = y;
}
int bfs(int s) {
    for (int i = 1; i <= n; i++) Lin[i] = lin[i], flo[i] = 0, dis[i] = -1;
    dis[1] = 0;
    Q[Hd = Tl = 1] = 1, flo[1] = 0x7fffffff;
    for (; Hd <= Tl;) {
        int x = Q[Hd++];
        for (int i = lin[x]; i; i = e[i].Next)
            if (w[s][i] && dis[e[i].Id] == -1) {
                dis[e[i].Id] = dis[x] + 1, flo[e[i].Id] = min(flo[x], w[s][i]), pre[e[i].Id] = i, prep[e[i].Id] = x;
                if (e[i].Id == n) goto out;
                Q[++Tl] = e[i].Id;
            }
    }
    return 0;
out:
    int p = n;
    while (p != 1) w[s][pre[p]] -= flo[n], w[s][pre[p] ^ 1] += flo[n], p = prep[p];
    return flo[n];
}
void Solv(int num, int s) {
    if (num >= K) return;
    for (int j = 2; j <= Num; j++) w[num + 1][j] = w[num][j];
    Solv(num + 1, s);
    int ns = s | (1 << num);
    f[ns] = f[s];
    for (int j = 2; j <= Num; j++) w[num + 1][j] = w[num][j];
    w[num + 1][(num + 1) << 1] = 25;
    for (int p; p = bfs(num + 1);) f[ns] += p;
    Solv(num + 1, ns);
}
int main() {
    n = read<int>(), m = read<int>(), K = read<int>(), q = read<int>();
    for (int i = 1; i <= m; i++) {
        E[i].u = read<int>(), E[i].v = read<int>(), E[i].w = read<int>();
        Insert(E[i].u, E[i].v), Insert(E[i].v, E[i].u);
        w[0][i << 1] = E[i].w;
        w[0][(i << 1) | 1] = 0;
    }
    for (int i = 1; i <= K; i++) Bit[1 << (i - 1)] = i;
    for (int p; p = bfs(0);) f[0] += p;
    Solv(0, 0);
    for (int i = 1; i <= q; i++) {
        for (int j = 1; j <= K; j++) nw[j] = read<int>();
        for (int j = 0; j < 1 << K; j++)
            g[j] = g[j & (j - 1)] + nw[Bit[j & -j]];
        int ans = INF;
        for (int j = 0; j < 1 << K; j++)
            ans = min(ans, g[j] + f[((1 << K) - 1) ^ j]);
        write(ans), putch('\n');
    }
    return 0;
}