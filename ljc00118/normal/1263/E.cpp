#include <bits/stdc++.h>
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

const int N = 1e6 + 5;

struct node_t { int l, r, maxn, minn, tag; } p[N << 2];

void update(int u) {
    p[u].maxn = max(p[u << 1].maxn, p[u << 1 | 1].maxn);
    p[u].minn = min(p[u << 1].minn, p[u << 1 | 1].minn);
}

void add_tag(int u, int x) {
    p[u].tag += x;
    p[u].maxn += x;
    p[u].minn += x;
}

void pushdown(int u) {
    if(p[u].tag) {
        add_tag(u << 1, p[u].tag);
        add_tag(u << 1 | 1, p[u].tag);
        p[u].tag = 0;
    }
}

void build(int u, int l, int r) {
    p[u].l = l; p[u].r = r;
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

int query(int u, int x) {
    if(p[u].l == p[u].r) return p[u].maxn;
    pushdown(u);
    int mid = (p[u].l + p[u].r) >> 1;
    if(mid >= x) return query(u << 1, x);
    return query(u << 1 | 1, x);
}

char c[N];
int a[N];
int n, now = 1;

int main() {
    read(n); scanf("%s", c + 1);
    build(1, 1, n);
    for(register int i = 1; i <= n; i++) {
        int val = 0;
        if(c[i] == 'L') { if(now != 1) { --now; } goto write; }
        if(c[i] == 'R') { ++now; goto write; }
        if(c[i] == '(') val = 1;
        if(c[i] == ')') val = -1;
        change(1, now, n, val - a[now]);
        a[now] = val;
        write:;
        if(p[1].minn < 0 || query(1, n) != 0) {
            print(-1, ' ');
        } else {
            print(p[1].maxn, ' ');
        }
    }
    putchar('\n');
    return 0;
}