#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> " << endl;
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

const int N = 6e5 + 5;

int lc[N * 30], rc[N * 30], rt[N], tot;

void change(int &u, int l, int r, int x) {
    if(!u) u = ++tot;
    if(l == r) return;
    int mid = (l + r) >> 1;
    if(mid >= x) change(lc[u], l, mid, x);
    else change(rc[u], mid + 1, r, x);
}

int query(int u, int l, int r, int L, int R) {
    if(!u) return 0;
    if(l <= L && R <= r) return 1;
    int mid = (L + R) >> 1, ans = 0;
    if(mid >= l) ans |= query(lc[u], l, r, L, mid);
    if(mid + 1 <= r) ans |= query(rc[u], l, r, mid + 1, R);
    return ans;
}

int merge(int u1, int u2, int l, int r) {
    if(!u1 || !u2) return u1 ^ u2;
    int mid = (l + r) >> 1, now = ++tot;
    lc[now] = merge(lc[u1], lc[u2], l, mid);
    rc[now] = merge(rc[u1], rc[u2], mid + 1, r);
    return now;
}

int ch[N][26], fa[N], len[N], endpos[N];
int last = 1, cnt = 1;

void extend(int x, int pos) {
    int p = last, np = last = ++cnt; len[np] = len[p] + 1;
    for(; p && !ch[p][x]; p = fa[p]) ch[p][x] = np;
    if(!p) fa[np] = 1;
    else {
        int q = ch[p][x];
        if(len[q] == len[p] + 1) fa[np] = q;
        else {
            int nq = ++cnt; len[nq] = len[p] + 1; endpos[nq] = pos;
            memcpy(ch[nq], ch[q], sizeof(ch[nq]));
            fa[nq] = fa[q]; fa[q] = fa[np] = nq;
            for(; ch[p][x] == q; p = fa[p]) ch[p][x] = nq;
        }
    }
    endpos[np] = pos;
}

int tax[N], a[N];
void topsort() {
    // for(register int i = 1; i <= cnt; i++) fprintf(stderr, "len[%d] = %d\n", i, len[i]);
    for(register int i = 1; i <= cnt; i++) ++tax[len[i]];
    for(register int i = 1; i <= cnt; i++) tax[i] += tax[i - 1];
    for(register int i = 1; i <= cnt; i++) a[tax[len[i]]--] = i;
}

char c[N]; int f[N], id[N], n, ans;

int main() {
    scanf("%d%s", &n, c + 1);
    for(register int i = 1; i <= n; i++) extend(c[i] - 'a', i);
    topsort();
    for(register int i = cnt; i >= 2; i--) {
        int u = a[i];
        change(rt[u], 1, n, endpos[u]);
    }
    for(register int i = cnt; i >= 2; i--) {
        int u = a[i];
        rt[fa[u]] = merge(rt[fa[u]], rt[u], 1, n);
    }
    for(register int i = 2; i <= cnt; i++) {
        int u = a[i];
        // fprintf(stderr, "a[%d] = %d\n", i, a[i]);
        // fprintf(stderr, "query(%d, %d, %d, %d, %d) = %d\n", rt[id[fa[u]]], endpos[u] - len[u] + len[id[fa[u]]], endpos[u] - 1, 1, n, query(rt[id[fa[u]]], endpos[u] - len[u] + len[id[fa[u]]], endpos[u] - 1, 1, n));
        if(fa[u] == 1) f[u] = 1, id[u] = u;
        else if(query(rt[id[fa[u]]], endpos[u] - len[u] + len[id[fa[u]]], endpos[u] - 1, 1, n)) f[u] = f[id[fa[u]]] + 1, id[u] = u;
        else f[u] = f[id[fa[u]]], id[u] = id[fa[u]];
        // fprintf(stderr, "f[%d] = %d\n", u, f[u]);
        ans = max(ans, f[u]);
    }
    cout << ans << endl;
    return 0;
}