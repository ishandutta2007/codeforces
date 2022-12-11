// =================================
//   author: memset0
//   date: 2019.02.26 19:21:05
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#define ll long long
namespace ringo {
template <class T>
inline void read(T &x) {
    x = 0;
    register char c = getchar();
    register bool f = 0;
    while (!isdigit(c)) f ^= c == '-', c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (f)
        x = -x;
}
template <class T>
inline void print(T x) {
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        print(x / 10);
    putchar('0' + x % 10);
}
template <class T>
inline void print(T x, char c) {
    print(x), putchar(c);
}

const int N = 2e5 + 10;
int n;
char s[N];

namespace seg {
const int M = N * 40;
int L, R, nod, rt[N << 1], lc[M], rc[M], cnt[M];
void build(int &u, int l = L, int r = R) {
    u = ++nod;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    build(lc[u], l, mid), build(rc[u], mid + 1, r);
}
void init(int l, int r) {
    L = l, R = r;
    build(rt[0]);
}
void modify(int &u, int v, int k, int l = L, int r = R) {
    u = ++nod, cnt[u] = cnt[v], lc[u] = lc[v], rc[u] = rc[v];
    if (l == r) {
        cnt[u]++;
        return;
    }
    int mid = (l + r) >> 1;
    if (k <= mid)
        modify(lc[u], lc[v], k, l, mid);
    else
        modify(rc[u], rc[v], k, mid + 1, r);
    cnt[u] = cnt[lc[u]] + cnt[rc[u]];
}
int query(int u, int v, int ql, int qr, int l = L, int r = R) {
    // if (ql > qr || !ql || !qr) return 0;
    // printf("query %d %d %d %d %d %d\n", u, v, ql, qr, l, r);
    // if (rand() % 4 == 0) exit(0);
    if (ql == l && qr == r)
        return cnt[v] - cnt[u];
    int mid = (l + r) >> 1;
    if (qr <= mid)
        return query(lc[u], lc[v], ql, qr, l, mid);
    if (ql > mid)
        return query(rc[u], rc[v], ql, qr, mid + 1, r);
    return query(lc[u], lc[v], ql, mid, l, mid) + query(rc[u], rc[v], mid + 1, qr, mid + 1, r);
}
}  // namespace seg
using seg::rt;

namespace sam {
const int M = N << 1;
int top, pos, nod = 1, lst = 1, cnt;
int fa[M], dfn[M], bln[M], stk[M], len[M], end[M], siz[M], ans[M], did[M], dep[M], ch[M][26];
std::vector<int> son[M];
void insert(int c) {
    // printf("insert %d\n", c);
    int f = lst, u = ++nod;
    lst = u, end[u] = len[u] = bln[u] = ++cnt;
    while (f && !ch[f][c]) ch[f][c] = u, f = fa[f];
    if (!f)
        return (void)(fa[u] = 1);
    int s = ch[f][c];
    if (len[s] == len[f] + 1)
        return (void)(fa[u] = s);
    int p = ++nod;
    end[p] = end[s], fa[p] = fa[s], len[p] = len[f] + 1, fa[s] = fa[u] = p;
    for (register int i = 0; i < 26; i++) ch[p][i] = ch[s][i];
    while (f && ch[f][c] == s) ch[f][c] = p, f = fa[f];
}
void build(int u) {
    dfn[u] = ++pos, did[dfn[u]] = u, siz[u] = 1;
    for (auto v : son[u]) dep[v] = dep[u] + 1, build(v), siz[u] += siz[v];
}
#define f ch
int jump(int u, int w) {
    // printf(">> jump %d %d\n", u, w);
    for (int i = 19; i >= 0; i--)
        if ((w >> i) & 1)
            u = f[u][i];
    return u;
}
void solve(int u) {
    // printf(">>> solve %d %d\n", u, ans[u]);
    if (u != 1) {
        ans[u] = 1;
        for (int f, l = 1, r = dep[u] - 1, mid, flag; mid = l + r >> 1, l <= r;) {
            f = jump(u, mid);
            // printf("[%d %d] => mid = %d f = %d | %d %d | %d %d %d %d \n", l, r, mid, f, rt[dfn[f] - 1],
            // rt[dfn[f] + siz[f] - 1], end[u] - len[u] + len[f], end[u] - 1);
            flag = seg::query(rt[dfn[f] - 1], rt[dfn[f] + siz[f] - 1], end[u] - len[u] + len[f], end[u] - 1);
            if (flag)
                ans[u] = std::max(ans[u], ans[f] + 1), r = mid - 1;
            else
                l = mid + 1;
        }
    }
    for (auto v : son[u]) solve(v);
}
int solve() {
    int ret = 0;
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= nod; i++) son[f[i][0] = fa[i]].push_back(i);
    for (int i = 1; i < 20; i++)
        for (int j = 1; j <= nod; j++) f[j][i] = f[f[j][i - 1]][i - 1];
    dep[1] = 1, build(1), seg::init(0, n);
    for (int i = 1; i <= nod; i++)
        if (bln[did[i]])
            seg::modify(rt[i], rt[i - 1], bln[did[i]]);
        else
            rt[i] = rt[i - 1];
    solve(1);
    // for (int i = 1; i <= nod; i++) print(bln[i], " \n"[i == nod]);
    // for (int i = 1; i <= nod; i++) print(len[i], " \n"[i == nod]);
    // for (int i = 1; i <= nod; i++) print(end[i], " \n"[i == nod]);
    // for (int i = 1; i <= nod; i++) print(ans[i], " \n"[i == nod]);
    for (int i = 1; i <= nod; i++) ret = std::max(ret, ans[i]);
    return ret;
}
#undef f
}  // namespace sam

void main() {
    int tmp; read(tmp);
    scanf("%s", s + 1), n = strlen(s + 1);
    for (int i = 1; i <= n; i++) sam::insert(s[i] - 'a');
    print(sam::solve(), '\n');
}

}  // namespace ringo
signed main() { return ringo::main(), 0; }