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

const int N = 5e5 + 5;

struct node_t {
    int l, r, tag, multi, val, minn;
    ll sum;
} p[N << 2];

vector <pii> q[N];
int st1[N], st2[N], a[N];
ll ans[N];
int n, m, top1, top2;

void update(int u) {
    p[u].minn = min(p[u << 1].minn, p[u << 1 | 1].minn);
    p[u].sum = p[u << 1].sum + p[u << 1 | 1].sum;
    p[u].val = 0;
    if(p[u << 1].minn == p[u].minn) p[u].val += p[u << 1].val;
    if(p[u << 1 | 1].minn == p[u].minn) p[u].val += p[u << 1 | 1].val;
}

void add_tag(int u, int x) {
    p[u].tag += x;
    p[u].minn += x;
}

void add_multi(int u, int x) {
    // fprintf(stderr, "multi : u = %d, x = %d, val = %d\n", u, x, p[u].val);
    p[u].multi += x;
    p[u].sum += 1ll * x * p[u].val;
}

void pushdown(int u) {
    if(p[u].tag) {
        add_tag(u << 1, p[u].tag);
        add_tag(u << 1 | 1, p[u].tag);
        p[u].tag = 0;
    }
    if(p[u].multi) {
        if(p[u].minn == p[u << 1].minn) add_multi(u << 1, p[u].multi);
        if(p[u].minn == p[u << 1 | 1].minn) add_multi(u << 1 | 1, p[u].multi);
        p[u].multi = 0;
    }
}

void build(int u, int l, int r) {
    p[u].l = l; p[u].r = r;
    if(l == r) {
        p[u].minn = l; p[u].val = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(u << 1, l, mid); build(u << 1 | 1, mid + 1, r);
    update(u);
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

void add(int u, int l, int r) {
    if(l <= p[u].l && p[u].r <= r) {
        // fprintf(stderr, "i = %d, l = %d, r = %d, u = %d, val = %d, minn = %d\n", r, p[u].l, p[u].r, u, p[u].val, p[u].minn);
        if(p[u].minn == 0) add_multi(u, 1);
        return;
    }
    pushdown(u);
    int mid = (p[u].l + p[u].r) >> 1;
    if(mid >= l) add(u << 1, l, r);
    if(mid + 1 <= r) add(u << 1 | 1, l, r);
    update(u);
}

ll query(int u, int l, int r) {
    if(l <= p[u].l && p[u].r <= r) {
        // fprintf(stderr, "u = %d, l = %d, r = %d, sum = %I64d\n", u, p[u].l, p[u].r, p[u].sum);
        return p[u].sum;
    }
    pushdown(u);
    int mid = (p[u].l + p[u].r) >> 1; ll ans = 0;
    if(mid >= l) ans += query(u << 1, l, r);
    if(mid + 1 <= r) ans += query(u << 1 | 1, l, r);
    return ans;
}

int main() {
    read(n);
    for(register int i = 1; i <= n; i++) read(a[i]);
    build(1, 1, n);
    read(m);
    for(register int i = 1; i <= m; i++) {
        int l, r;
        read(l); read(r);
        q[r].push_back(make_pair(l, i));
    }
    for(register int i = 1; i <= n; i++) {
        while(top1 && a[st1[top1]] < a[i]) {
            // fprintf(stderr, "l = %d, r = %d, x = %d\n", st1[top1 - 1] + 1, st1[top1], a[i] - a[st1[top1]]);
            change(1, st1[top1 - 1] + 1, st1[top1], a[i] - a[st1[top1]]);
            --top1;
        }
        while(top2 && a[st2[top2]] > a[i]) {
            change(1, st2[top2 - 1] + 1, st2[top2], a[st2[top2]] - a[i]);
            --top2;
        }
        st1[++top1] = i; st2[++top2] = i;
        change(1, 1, n, -1);
        add(1, 1, i);
        for(register int j = 0; j < (int)q[i].size(); j++) {
            ans[q[i][j].second] = query(1, q[i][j].first, i);
        }
    }
    for(register int i = 1; i <= m; i++) print(ans[i], '\n');
    return 0;
}