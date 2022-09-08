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

const int N = 1e5 + 5;

struct fenwick {
    int f[N << 2], n;

    inline int lowbit(int x) { return x & -x; }

    inline void add(int x, int y) {
        for(register int i = x; i <= n; i += lowbit(i))
            f[i] += y;
    }

    inline int query(int x) {
        int ans = 0;
        for(register int i = x; i; i -= lowbit(i))
            ans += f[i];
        return ans;
    }
} tr[2];

struct ele {
    int x, y, opt, v;
    bool operator < (const ele A) const { return make_pair(x, opt) < make_pair(A.x, A.opt); }
} q[N * 6];

int pre[N << 2], big;
int p[N], s[N], b[N], inc[N], pref[N], ans[N];
int n, m, tot;

int main() {
    read(n); read(m);
    tr[0].n = tr[1].n = (n + m) << 1;
    for(register int i = 1; i <= n; i++) read(p[i]);
    for(register int i = 1; i <= n; i++) read(s[i]);
    for(register int i = 1; i <= n; i++) read(b[i]);
    for(register int i = 1; i <= m; i++) read(inc[i]);
    for(register int i = 1; i <= m; i++) read(pref[i]);
    for(register int i = 1; i <= n; i++) {
        q[++tot] = (ele) {p[i], b[i] + p[i], 0, 1};
        q[++tot] = (ele) {p[i], b[i] - p[i] + 1, 1, -1};
        q[++tot] = (ele) {s[i] + 1, b[i] + p[i], 0, -1};
        q[++tot] = (ele) {s[i] + 1, b[i] - p[i] + 1, 1, 1};
        pre[++big] = b[i] + p[i]; pre[++big] = b[i] - p[i] + 1;
    }
    for(register int i = 1; i <= m; i++) {
        q[++tot] = (ele) {inc[i], inc[i] + pref[i], 2, i};
        q[++tot] = (ele) {inc[i], pref[i] - inc[i], 3, i};
        pre[++big] = inc[i] + pref[i]; pre[++big] = pref[i] - inc[i];
    }
    sort(pre + 1, pre + big + 1); big = unique(pre + 1, pre + big + 1) - pre - 1;
    for(register int i = 1; i <= tot; i++) q[i].y = lower_bound(pre + 1, pre + big + 1, q[i].y) - pre;
    sort(q + 1, q + tot + 1);
    for(register int i = 1; i <= tot; i++) {
        // fprintf(stderr, "%d %d %d %d\n", q[i].x, q[i].y, q[i].opt, q[i].v);
        if(q[i].opt & 2) ans[q[i].v] += tr[q[i].opt & 1].query(q[i].y);
        else tr[q[i].opt].add(q[i].y, q[i].v);
    }
    for(register int i = 1; i <= m; i++) print(ans[i], i == m ? '\n' : ' ');
    return 0;
} //