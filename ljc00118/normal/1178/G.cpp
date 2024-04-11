#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;
typedef unsigned int i32;

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

const ll INF = 0x7fffffffffffffff;
const int N = 2e5 + 5, sqr = 450, ct = N / sqr;
const double eps = 1e-8;

struct ele {
    int a, b, id;
    ele (int aa = 0, int bb = 0, int c = 0) : a(aa), b(bb), id(c) {}
    bool operator < (const ele A) const { return b < A.b; }
} p[ct + 5][sqr + 5], p2[ct + 5][sqr + 5], st[ct + 5][sqr + 5], st2[ct + 5][sqr + 5];

vector <int> adj[N];
int a[N], b[N], fa[N], tops[N], pre[N], siz[N], B[N], l[N], r[N], tag[ct + 5], now[ct + 5], now2[ct + 5], top[ct + 5], top2[ct + 5];
int n, m, cnt;

void dfs1(int u) {
    tops[u] = ++cnt; pre[cnt] = u; siz[u] = 1;
    for(register int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        a[v] += a[u]; b[v] += b[u]; dfs1(v); siz[u] += siz[v];
    }
}

double slope(ele a, ele b) { return (double)(1ll * a.a * a.b - 1ll * b.a * b.b) / (b.b - a.b); }

void build(int id) {
    top[id] = 0;
    for(register int i = 1; i <= r[id] - l[id] + 1; i++) {
        p[id][i].a += tag[id];
        if(top[id] && st[id][top[id]].b == p[id][i].b) {
            if(1ll * st[id][top[id]].a * st[id][top[id]].b >= 1ll * p[id][i].a * p[id][i].b) continue;
            else --top[id];
        }
        while(top[id] && 1ll * st[id][top[id]].a * st[id][top[id]].b <= 1ll * p[id][i].a * p[id][i].b) --top[id];
        while(top[id] >= 2 && slope(st[id][top[id] - 1], st[id][top[id]]) + eps > slope(st[id][top[id]], p[id][i])) --top[id];
        st[id][++top[id]] = p[id][i];
    }
    now[id] = 1;
    top2[id] = 0;
    for(register int i = 1; i <= r[id] - l[id] + 1; i++) {
        p2[id][i].a += tag[id];
        if(top2[id] && st2[id][top2[id]].b == p2[id][i].b) {
            if(1ll * st2[id][top2[id]].a * st2[id][top2[id]].b >= 1ll * p2[id][i].a * p2[id][i].b) continue;
            else --top2[id];
        }
        while(top2[id] && 1ll * st2[id][top2[id]].a * st2[id][top2[id]].b <= 1ll * p2[id][i].a * p2[id][i].b) --top2[id];
        while(top2[id] >= 2 && slope(st2[id][top2[id] - 1], st2[id][top2[id]]) + eps > slope(st2[id][top2[id]], p2[id][i])) --top2[id];
        st2[id][++top2[id]] = p2[id][i];
    }
    // cout << id << " " << top2[id] << " " << st2[id][top2[id]].a << " " << st2[id][top2[id]].b << endl;
    tag[id] = 0; now2[id] = 1;
}

ll solve(int id) {
    while(now[id] < top[id] && 1ll * (st[id][now[id]].a + tag[id]) * st[id][now[id]].b <= 1ll * (st[id][now[id] + 1].a + tag[id]) * st[id][now[id] + 1].b) ++now[id];
    while(now2[id] < top2[id] && 1ll * (st2[id][now2[id]].a + tag[id]) * st2[id][now2[id]].b <= 1ll * (st2[id][now2[id] + 1].a + tag[id]) * st2[id][now2[id] + 1].b) ++now2[id];
    return max(1ll * (st[id][now[id]].a + tag[id]) * st[id][now[id]].b, 1ll * (st2[id][now2[id]].a + tag[id]) * st2[id][now2[id]].b);
}

void add(int l, int r, int x) {
    int b = B[l];
    for(register int i = 1; i <= ::r[b] - ::l[b] + 1; i++) {
        if(l <= p[b][i].id && p[b][i].id <= r) {
            p[b][i].a += x;
        }
        if(l <= p2[b][i].id && p2[b][i].id <= r) {
            p2[b][i].a += x;
        }
    }
    build(b);
}

ll qry(int l, int r) {
    ll ans = -INF, b = B[l];
    for(register int i = 1; i <= ::r[b] - ::l[b] + 1; i++) {
        // cout << p[b][i].id << " " << p2[b][i].id << endl;
        if(l <= p[b][i].id && p[b][i].id <= r) {
            ans = max(ans, 1ll * (p[b][i].a + tag[b]) * p[b][i].b);
        }
        if(l <= p2[b][i].id && p2[b][i].id <= r) {
            ans = max(ans, 1ll * (p2[b][i].a + tag[b]) * p2[b][i].b);
        }
    }
    // cout << l << " " << r << " " << ans << endl;
    return ans;
}

ll query(int l, int r) {
    if(B[l] == B[r]) return qry(l, r);
    ll ans = max(qry(l, ::r[B[l]]), qry(::l[B[r]], r));
    for(register int i = B[l] + 1; i <= B[r] - 1; i++) ans = max(ans, solve(i));
    // cout << l << " " << r << " " << ans << endl;
    return ans;
}

int main() {
    read(n); read(m);
    for(register int i = 2; i <= n; i++) read(fa[i]), adj[fa[i]].push_back(i);
    for(register int i = 1; i <= n; i++) read(a[i]);
    for(register int i = 1; i <= n; i++) read(b[i]);
    dfs1(1);
    // for(register int i = 1; i <= n; i++) fprintf(stderr, "%d%c", a[i], i == n ? '\n' : ' ');
    // for(register int i = 1; i <= n; i++) fprintf(stderr, "%d%c", b[i], i == n ? '\n' : ' ');
    for(register int i = 1; i <= n; i++) {
        int u = pre[i];
        B[i] = (i - 1) / sqr + 1;
        if(!l[B[i]]) l[B[i]] = i;
        r[B[i]] = i;
        p[B[i]][i - l[B[i]] + 1] = ele(a[u], b[u], i);
        p2[B[i]][i - l[B[i]] + 1] = ele(a[u], -b[u], i);
    }
    for(register int i = 1; i <= B[n]; i++) sort(p[i] + 1, p[i] + r[i] - l[i] + 1 + 1), sort(p2[i] + 1, p2[i] + r[i] - l[i] + 1 + 1), build(i);
    while(m--) {
        int opt; read(opt);
        if(opt == 1) {
            int x, y; read(x); read(y); int L = tops[x], R = tops[x] + siz[x] - 1;
            if(B[L] == B[R]) add(L, R, y);
            else {
                add(L, r[B[L]], y); add(l[B[R]], R, y);
                for(register int i = B[L] + 1; i <= B[R] - 1; i++) tag[i] += y;
            }
        }
        if(opt == 2) {
            int x; read(x);
            print(query(tops[x], tops[x] + siz[x] - 1), '\n');
        }
    }
    return 0;
}