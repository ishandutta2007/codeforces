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

#define maxn 10005
#define maxlgn 15

typedef pair<int, int> pii;

vector<vector<pii> > graph;
int fa[maxn][maxlgn], dep[maxn], cnt[maxn], need;
bool vis[maxn];
vector<int> answer;

void dfs(int p, int pre) {
    vis[p] = true;
    dep[p] = dep[pre] + 1;
    fa[p][0] = pre;
    for (register int i = 1; i < maxlgn; i++) fa[p][i] = fa[fa[p][i - 1]][i - 1];
    for (vector<pii>::iterator i = graph[p].begin(); i != graph[p].end(); i++)
        if (!vis[i->first]) dfs(i->first, p);
    return;
}
int lca(int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);
    for (register int i = maxlgn - 1; ~i; i--)
        if (dep[fa[x][i]] >= dep[y]) x = fa[x][i];
    if (x == y) return x;
    for (register int i = maxlgn - 1; ~i; i--)
        if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
    return fa[x][0];
}
void dfs2(int p) {
    int edge = -1;
    for (vector<pii>::iterator i = graph[p].begin(); i != graph[p].end(); i++)
        if (fa[i->first][0] == p)
            dfs2(i->first), cnt[p] += cnt[i->first];
        else if (fa[p][0] == i->first)
            edge = i->second;
    if (fa[p][0] && cnt[p] == need) answer.push_back(edge);
    return;
}

int main() {
    int n = read<int>(), m = read<int>();
    graph.resize(n + 1);
    for (register int i = 1; i <= m; i++) {
        int from = read<int>(), to = read<int>();
        graph[from].push_back((pii){to, i}), graph[to].push_back((pii){from, i});
    }
    static vector<int> roots;
    roots.clear();
    for (register int i = 1; i <= n; i++)
        if (!vis[i]) roots.push_back(i), dfs(i, 0);
    need = 0;
    int lastedge = -1;
    for (register int i = 1; i <= n; i++)
        for (vector<pii>::iterator j = graph[i].begin(); j != graph[i].end(); j++)
            if (j->first < i) {
                if (fa[j->first][0] == i || fa[i][0] == j->first) continue;
                int LCA = lca(i, j->first), dist = dep[i] + dep[j->first] - 2 * dep[LCA];
                if (dist & 1)
                    cnt[i]--, cnt[j->first]--, cnt[LCA] += 2;
                else {
                    cnt[i]++, cnt[j->first]++, cnt[LCA] -= 2;
                    need++, lastedge = j->second;
                }
            }
    if (need == 0) {
        write(m), putch('\n');
        for (register int i = 1; i <= m; i++) write(i), putch(' ');
        putch('\n');
        return 0;
    }
    if (need == 1) answer.push_back(lastedge);
    for (vector<int>::iterator i = roots.begin(); i != roots.end(); i++) dfs2(*i);
    write(answer.size()), putch('\n');
    sort(answer.begin(), answer.end());
    for (vector<int>::iterator i = answer.begin(); i != answer.end(); i++) write(*i), putch(' ');
    putch('\n');
    return 0;
}