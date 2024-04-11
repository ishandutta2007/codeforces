#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename T>
inline void read(T &f) {
    f = 0; T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 1e6 + 5;

int ch[N][26], fa[N], len[N];
int las = 1, cnt = 1;

void extend(int x) {
    int p = las, np = las = ++cnt; len[np] = len[p] + 1;
    for (; p && !ch[p][x]; p = fa[p]) ch[p][x] = np;
    if (!p) fa[np] = 1;
    else {
        int q = ch[p][x];
        if (len[q] == len[p] + 1) fa[np] = q;
        else {
            int nq = ++cnt; len[nq] = len[p] + 1;
            memcpy(ch[nq], ch[q], sizeof(ch[q]));
            fa[nq] = fa[q]; fa[q] = fa[np] = nq;
            for (; ch[p][x] == q; p = fa[p]) ch[p][x] = nq;
        }
    }
}

vector <int> adj[N];
char c[N];
int id[N], tops[N], siz[N];
int n, dfnt;

void dfs1(int u) {
    tops[u] = ++dfnt; siz[u] = 1;
    for (auto v : adj[u]) {
        dfs1(v);
        siz[u] += siz[v];
    }
}

int mx[N << 2];

void modify(int u, int l, int r, int x, int y) {
    mx[u] = max(mx[u], y);
    if (l == r) return;
    int mid = (l + r) >> 1;
    if (mid >= x) modify(u << 1, l, mid, x, y);
    else modify(u << 1 | 1, mid + 1, r, x, y);
}

int query(int u, int L, int R, int l, int r) {
    if (l <= L && R <= r) return mx[u];
    int mid = (L + R) >> 1, ans = 0;
    if (mid >= l) ans = max(ans, query(u << 1, L, mid, l, r));
    if (mid + 1 <= r) ans = max(ans, query(u << 1 | 1, mid + 1, R, l, r));
    return ans;
}

int ret[N], ans = 1;

int main() {
    read(n); scanf("%s", c + 1); reverse(c + 1, c + n + 1);
    for (int i = 1; i <= n; i++) extend(c[i] - 'a'), id[i] = las;
    for (int i = 2; i <= cnt; i++) adj[fa[i]].push_back(i);
    dfs1(1);
    ret[1] = 1;
    int now = 1;
    for (int i = 2; i <= n; i++) {
        ret[i] = ret[i - 1];
        if (ret[i] < i) {
            ret[i] = i;
            now = ch[now][c[i] - 'a'];
        }
        modify(1, 1, cnt, tops[id[i - 1]], i - 1);
        while (ret[i] < n) {
            int cando = 0;
            // check [i, ret[i]]
            int pos = query(1, 1, cnt, tops[now], tops[now] + siz[now] - 1);
            if (pos && ret[pos - (ret[i] - i)] >= pos) cando = 1;
            // check [i + 1, ret[i] + 1]
            int go = ch[now][c[ret[i] + 1] - 'a'];
            if (len[fa[go]] == ret[i] - i + 1) go = fa[go];
            if (!cando) {
                int pos = query(1, 1, cnt, tops[go], tops[go] + siz[go] - 1);
                if (pos && ret[pos - (ret[i] - i)] >= pos) cando = 1;
            }
            if (cando) now = ch[now][c[ret[i] + 1] - 'a'], ++ret[i];
            else break;
        }
        ans = max(ans, ret[i] - i + 1);
        if (len[fa[now]] == ret[i] - i) now = fa[now];
    }
    print(ans, '\n');
    return 0;
}