#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') fu = -1; c = getchar(); }
    while(c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

template <typename T>
struct hash_map_t {
    vector <T> v, val, nxt;
    vector <int> head;
    int mod, tot, lastv;
    T lastans;
    bool have_ans;

    hash_map_t (int md = 0) {
        head.clear(); v.clear(); val.clear(); nxt.clear(); tot = 0; mod = md;
        nxt.resize(1); v.resize(1); val.resize(1); head.resize(mod);
        have_ans = 0;
    }

    bool count(int x) {
        int u = x % mod;
        for(register int i = head[u]; i; i = nxt[i]) {
            if(v[i] == x) {
                have_ans = 1;
                lastv = x;
                lastans = val[i];
                return 1;
            }
        }
        return 0;
    }

    void ins(int x, int y) {
        int u = x % mod;
        nxt.push_back(head[u]); head[u] = ++tot;
        v.push_back(x); val.push_back(y);
    }

    int qry(int x) {
        if(have_ans && lastv == x) return lastans;
        count(x);
        return lastans;
    }
};

const int N = 1500005;

struct sam_t {
    int ch[N][27], fa[N], len[N];
    int cnt, last;

    sam_t () { cnt = last = 1; }

    void extend(int x) {
        int p = last, np = last = ++cnt; len[np] = len[p] + 1;
        for(; p && !ch[p][x]; p = fa[p]) ch[p][x] = np;
        if(!p) fa[np] = 1;
        else {
            int q = ch[p][x];
            if(len[p] + 1 == len[q]) fa[np] = q;
            else {
                int nq = ++cnt; len[nq] = len[p] + 1;
                memcpy(ch[nq], ch[q], sizeof(ch[nq]));
                fa[nq] = fa[q]; fa[q] = fa[np] = nq;
                for(; ch[p][x] == q; p = fa[p]) ch[p][x] = nq;
            }
        }
    }
} sam;

pii val[N * 16], ans[N];
int lc[N * 16], rc[N * 16], tot;

void change(int &u, int l, int r, int x) {
    if(!u) u = ++tot;
    if(l == r) { ++val[u].first; val[u].second = -x; return; }
    int mid = (l + r) >> 1;
    if(mid >= x) change(lc[u], l, mid, x);
    else change(rc[u], mid + 1, r, x);
    val[u] = max(val[lc[u]], val[rc[u]]);
}

void merge(int &u, int v, int l, int r) {
    if(!u || !v) { u ^= v; return; }
    if(l == r) { val[u].first += val[v].first; return; }
    int mid = (l + r) >> 1;
    merge(lc[u], lc[v], l, mid);
    merge(rc[u], rc[v], mid + 1, r);
    val[u] = max(val[lc[u]], val[rc[u]]);
}

pii query(int u, int l, int r, int L, int R) {
    if(l <= L && R <= r) return u ? val[u] : make_pair(0, -l);
    int mid = (L + R) >> 1;
    if(mid >= l && mid + 1 <= r) return max(query(lc[u], l, r, L, mid), query(rc[u], l, r, mid + 1, R));
    if(mid >= l) { return query(lc[u], l, r, L, mid); } return query(rc[u], l, r, mid + 1, R);
}

vector <int> adj[N], Q[N];
int fa[N][22], wz[N], pre[N], rt[N], L[N], R[N];
char c[N], s[N];
int n, m, len, q;

void dfs1(int u) {
    for(register unsigned i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        dfs1(v);
        merge(rt[u], rt[v], 1, m);
    }
    for(register unsigned i = 0; i < Q[u].size(); i++) {
        int id = Q[u][i];
        ans[id] = query(rt[u], L[id], R[id], 1, m);
    }
}
    
int main() {
    scanf("%s", s + 1); n = len = strlen(s + 1);
    read(m);
    for(register int i = 1; i <= m; i++) {
        scanf("%s", c + 1);
        n = strlen(c + 1);
        s[++len] = 'z' + 1;
        for(register int j = 1; j <= n; j++) s[++len] = c[j], pre[len] = i;
    }
    // for(register int i = 1; i <= len; i++) putchar(s[i]);
    // fprintf(stderr, "len = %d\n", len);
    for(register int i = 1; i <= len; i++) wz[i] = sam.cnt + 1, sam.extend(s[i] - 'a');
    for(register int i = 1; i <= len; i++) if(pre[i]) change(rt[wz[i]], 1, m, pre[i]);
    // fprintf(stderr, "ok\n");
    for(register int i = 1; i <= sam.cnt; i++) {
        if(sam.fa[i]) adj[sam.fa[i]].push_back(i);
        fa[i][0] = sam.fa[i];
    }
    for(register int j = 1; j <= 21; j++) {
        for(register int i = 1; i <= sam.cnt; i++) {
            fa[i][j] = fa[fa[i][j - 1]][j - 1];
        }
    }
    read(q);
    for(register int i = 1; i <= q; i++) {
        int l, r, pl, pr;
        read(l); read(r); read(pl); read(pr);
        L[i] = l; R[i] = r;
        int now = wz[pr];
        for(register int j = 21; j >= 0; j--) {
            if(sam.len[fa[now][j]] >= pr - pl + 1) {
                // fprintf(stderr, "fa[%d][%d] = %d\n", now, j, fa[now][j]);
                now = fa[now][j];
            }
        }
        // fprintf(stderr, "now = %d\n", now);
        Q[now].push_back(i);
    }
    dfs1(1);
    for(register int i = 1; i <= q; i++) print(-ans[i].second, ' '), print(ans[i].first, '\n');
    return 0;   
}