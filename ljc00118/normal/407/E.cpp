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

const int N = 2e5 + 5, INF = 0x7fffffff;

struct node_t {
    int l, r, minn, tag;
} p[N << 2];

void update(int u) { p[u].minn = min(p[u << 1].minn, p[u << 1 | 1].minn); }

inline void add_tag(int u, int x) { p[u].minn += x; p[u].tag += x; }

void pushdown(int u) {
    if(p[u].tag) {
        add_tag(u << 1, p[u].tag);
        add_tag(u << 1 | 1, p[u].tag);
        p[u].tag = 0;
    }
}

void build(int u, int l, int r) {
    p[u].l = l; p[u].r = r; p[u].minn = 0;
    if(l == r) return;
    int mid = (l + r) >> 1;
    build(u << 1, l, mid); build(u << 1 | 1, mid + 1, r);
}

void change(int u, int l, int r, int x) {
    if(l <= p[u].l && p[u].r <= r) {
        add_tag(u, x);
        return;
    }
    pushdown(u);
    int mid = (p[u].l + p[u].r) >> 1;
    if(mid >= l) change(u << 1, l, r, x);
    if(mid + 1 <= r) change(u << 1 | 1, l, r, x);
    update(u);
}

int query(int u, int l, int r, int x) {
    if(p[u].minn > x) return 0;
    if(p[u].l == p[u].r) return p[u].l;
    pushdown(u);
    int mid = (p[u].l + p[u].r) >> 1;
    if(mid >= l && mid + 1 <= r) {
        int ans = query(u << 1 | 1, l, r, x);
        if(ans) return ans;
        return query(u << 1, l, r, x);
    } else if(mid >= l) return query(u << 1, l, r, x);
    return query(u << 1 | 1, l, r, x);
}

map <int, int> pre;
int a[N], v[N], st1[N], st2[N], top1, top2;
int n, k, d, maxn, ansl, ansr, minn = INF, maxr;

int main() {
    read(n); read(k); read(d);
    for(register int i = 1; i <= n; i++) read(a[i]);
    if(d == 0) {
        int now = 1, last = 1;
        maxn = ansl = ansr = 1;
        for(register int i = 2; i <= n; i++) {
            if(a[i] == a[i - 1]) {
                ++now;
                if(now > maxn) {
                    maxn = now;
                    ansl = last;
                    ansr = i;
                }
            } else now = 1, last = i;
        }
        print(ansl, ' '); print(ansr, '\n');
        return 0;
    }
    build(1, 1, n);
    for(register int i = 1; i <= n; i++) minn = min(minn, a[i]);
    for(register int i = 1; i <= n; i++) v[i] = (a[i] - minn) / d;
    for(register int r = n, l; r >= 1; r = l - 1) {
        l = r;
        while(l - 1 && (a[l - 1] % d + d) % d == (a[r] % d + d) % d) --l;
        pre.clear(); top1 = top2 = 0; st1[0] = st2[0] = r + 1; maxr = r;
        for(register int i = r; i >= l; i--) {
            while(top1 && v[i] >= v[st1[top1]]) {
                change(1, st1[top1], st1[top1 - 1] - 1, v[i] - v[st1[top1]]);
                --top1;
            }
            while(top2 && v[i] <= v[st2[top2]]) {
                change(1, st2[top2], st2[top2 - 1] - 1, v[st2[top2]] - v[i]);
                --top2;
            }
            st1[++top1] = st2[++top2] = i;
            change(1, i, i, -i);
            if(pre.count(a[i])) maxr = min(maxr, pre[a[i]] - 1);
            int ans = query(1, i, maxr, k - i);
            if(ans - i + 1 >= maxn) {
                maxn = ans - i + 1;
                ansl = i;
                ansr = ans;
            }
            pre[a[i]] = i;
        }
    }
    print(ansl, ' '); print(ansr, '\n');
    return 0;
}