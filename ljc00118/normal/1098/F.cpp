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

const int N = 4e5 + 5;

struct sam_t {
    int ch[N][26], len[N], fa[N];
    int las, cnt;

    void reset() { las = cnt = 1; }

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
} sam;

bool cmp(int i, int j) {
    return sam.len[i] < sam.len[j];
}

struct dag_t {
    ll s1[N], s2[N];
    int w1[N], w2[N], wson[N], id[N], tops[N], pre[N], ed[N];
    int dfnt;

    void build() {
        for (int i = 1; i <= sam.cnt; i++) id[i] = i;
        sort(id + 1, id + sam.cnt + 1, cmp);
        s1[1] = 1;
        for (int i = 1; i <= sam.cnt; i++) {
            int u = id[i];
            for (int j = 0; j < 26; j++) {
                if (sam.ch[u][j]) {
                    s1[sam.ch[u][j]] += s1[u];
                }
            }
        }
        for (int i = sam.cnt; i >= 1; i--) {
            int u = id[i]; s2[u] = 1;
            for (int j = 0; j < 26; j++) {
                if (sam.ch[u][j]) {
                    s2[u] += s2[sam.ch[u][j]];
                    if (s2[sam.ch[u][j]] > s2[w2[u]]) w2[u] = sam.ch[u][j];
                    if (s1[u] > s1[w1[sam.ch[u][j]]]) w1[sam.ch[u][j]] = u;
                }
            }
        }
        for (int i = 1; i <= sam.cnt; i++) {
            int u = id[i];
            for (int j = 0; j < 26; j++) {
                if (sam.ch[u][j]) {
                    if (w2[u] == sam.ch[u][j] && w1[sam.ch[u][j]] == u) {
                        wson[u] = sam.ch[u][j];
                    }
                }
            }
        }
        for (int i = 1; i <= sam.cnt; i++) {
            int u = id[i];
            if (tops[u]) continue;
            for (int tmp = u; tmp; tmp = wson[tmp]) {
                tops[tmp] = ++dfnt;
                pre[dfnt] = tmp;
            }
            for (; u; u = wson[u]) ed[u] = dfnt;
        }
    }
} dag;

struct fenwick {
    ll f[N];

    void add(int x, ll y) {
        while (x <= sam.cnt) {
            f[x] += y;
            x += (x & -x);
        }
    }

    void add(int l, int r, ll x) {
        add(l, x);
        add(r + 1, -x);
    }

    ll query(int x) {
        ll ans = 0;
        while (x) {
            ans += f[x];
            x &= (x - 1);
        }
        return ans;
    }
} tr[4];

char c[N];
int pos[N], id[N];
int n, q;

vector <int> adj[N];
int tops[N], wson[N], siz[N], fa[N], top[N];
int tot;

void dfs1(int u) {
    siz[u] = 1;
    for (auto v : adj[u]) {
        fa[v] = u; dfs1(v); siz[u] += siz[v];
        if (siz[v] > siz[wson[u]]) wson[u] = v;
    }
}

void dfs2(int u, int tp) {
    tops[u] = ++tot; top[u] = tp;
    if (wson[u]) dfs2(wson[u], tp);
    for (auto v : adj[u]) {
        if (v == wson[u]) continue;
        dfs2(v, v);
    }
}

ll sum[N], val[N];
int bel[N], seq[N], s[N], lc[N], rc[N], sz[N], w[N], sumw[N], tag[N], rt;
int tbuild(int l, int r) {
    if (l > r) return 0;
    int L = l + 1, R = r, ret = l;
    while (L <= R) {
        int mid = (L + R) >> 1;
        if (s[r] - s[mid - 1] >= s[mid - 1] - s[l - 1]) ret = mid, L = mid + 1;
        else R = mid - 1;
    }
    int u = seq[ret];
    if (!rt) rt = u;
    bel[u] = rt;
    sz[u] = r - l + 1;
    lc[u] = tbuild(l, ret - 1);
    rc[u] = tbuild(ret + 1, r);
    sumw[u] = w[u] + sumw[lc[u]] + sumw[rc[u]];
    return u;
}

void build(int u) {
    int len = 0;
    seq[len = 1] = u;
    while (wson[seq[len]]) {
        seq[len + 1] = wson[seq[len]];
        ++len;
    }
    for (int i = 1; i <= len; i++) s[i] = s[i - 1] + siz[seq[i]] - siz[wson[seq[i]]];
    rt = 0; tbuild(1, len);
    while (u) {
        for (auto v : adj[u]) {
            if (v == wson[u]) continue;
            build(v);
        }
        u = wson[u];
    }
}

void add(int u, int l, int r) {
    if (l <= 1 && sz[u] <= r) {
        ++tag[u];
        sum[u] += sumw[u];
        return;
    }
    int mid = sz[lc[u]];
    if (lc[u] && mid >= l) add(lc[u], l, r);
    if (rc[u] && mid + 1 < r) add(rc[u], l - mid - 1, r - mid - 1);
    if (mid + 1 >= l && mid + 1 <= r) val[u] += w[u];
    sum[u] = val[u] + sum[lc[u]] + sum[rc[u]] + 1ll * sumw[u] * tag[u];
}

ll query(int u, int l, int r, int tg) {
    if (l <= 1 && sz[u] <= r) return sum[u] + 1ll * sumw[u] * tg;
    int mid = sz[lc[u]]; ll ans = 0; tg += tag[u];
    if (lc[u] && mid >= l) ans += query(lc[u], l, r, tg);
    if (rc[u] && mid + 1 < r) ans += query(rc[u], l - mid - 1, r - mid - 1, tg);
    if (mid + 1 >= l && mid + 1 <= r) ans += val[u] + 1ll * w[u] * tg;
    return ans;
}

struct atom {
    int u, id, c;
    atom (int a = 0, int b = 0, int d = 0) : u(a), id(b), c(d) {}
};

vector <atom> qry[N];
ll ans[N];

int main() {
    sam.reset();
    scanf("%s", c + 1); n = strlen(c + 1); read(q);
    reverse(c + 1, c + n + 1);
    for (int i = 1; i <= n; i++) {
        sam.extend(c[i] - 'a');
        pos[i] = sam.las;
    }
    dag.build();
    for (int i = 2; i <= sam.cnt; i++) {
        adj[sam.fa[i]].push_back(i);
    }
    dfs1(1); dfs2(1, 1);
    for (int i = 1; i <= q; i++) {
        int l, r;
        read(l); read(r);
        l = n - l + 1; r = n - r + 1; swap(l, r);
        int len = 0, u = 1;
        while (l <= r) {
            u = sam.ch[u][c[l] - 'a'];
            int L = dag.tops[u] + 1, R = min(L - 1 + r - l, dag.ed[u]), res = dag.tops[u];
            while (L <= R) {
                int mid = (L + R) >> 1, v = dag.pre[mid];
                if (sam.len[sam.fa[v]] < len + mid - dag.tops[u] + 1 && len + mid - dag.tops[u] + 1 <= sam.len[v] && tops[v] <= tops[pos[l + mid - dag.tops[u]]] && tops[pos[l + mid - dag.tops[u]]] <= tops[v] + siz[v] - 1) res = mid, L = mid + 1;
                else R = mid - 1;
            }
            qry[dag.tops[u] - 1].push_back(atom(pos[r], -i, len + 1 - dag.tops[u]));
            qry[res].push_back(atom(pos[r], i, len + 1 - dag.tops[u]));
            l += res - dag.tops[u] + 1; len += res - dag.tops[u] + 1; u = dag.pre[res];
        }
    }
    for (int i = 2; i <= sam.cnt; i++) w[i] = sam.len[i] - sam.len[fa[i]];
    build(1);
    for (int i = 1; i <= sam.cnt; i++) {
        int u = dag.pre[i];
        tr[2].add(tops[u], tops[u] + siz[u] - 1, 1);
        tr[3].add(tops[u], tops[u] + siz[u] - 1, dag.tops[u] - sam.len[u]);
        while (u) {
            int l = tops[top[u]], r = tops[u];
            r = r - l + 1; l = 1;
            add(bel[u], l, r);
            u = fa[top[u]];
        }
        for (auto j : qry[i]) {
            int u = j.u;
            ll ret = tr[2].query(tops[u]) * j.c + tr[3].query(tops[u]);
            while (u) {
                int l = tops[top[u]], r = tops[u];
                r = r - l + 1; l = 1;
                ret += query(bel[u], l, r, 0);
                u = fa[top[u]];
            }
            if (j.id > 0) ans[j.id] += ret;
            else ans[-j.id] -= ret;
        }
    }
    for (int i = 1; i <= q; i++) print(ans[i], '\n');
    return 0;
}