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
    int mod, tot, lastv, last_id;
    T lastans;
    bool have_ans;

    hash_map_t (int md = 0) {
        head.clear(); v.clear(); val.clear(); nxt.clear(); tot = 0; mod = md;
        nxt.resize(1); v.resize(1); val.resize(1); head.resize(mod);
        have_ans = 0;
    }

    void clear() {
        for(register int i = 1; i <= tot; i++) head[v[i] % mod] = 0;
        tot = 0;
        v.clear(); val.clear(); nxt.clear();
        v.resize(1); val.resize(1); nxt.resize(1);
        have_ans = 0;
    }

    bool count(int x) {
        int u = x % mod;
        for(register int i = head[u]; i; i = nxt[i]) {
            if(v[i] == x) {
                have_ans = 1;
                lastv = x;
                last_id = i;
                lastans = val[i];
                return 1;
            }
        }
        return 0;
    }

    void ins(int x, int y) {
        // fprintf(stderr, "debug %d %d\n", x, y);
        if(count(x)) {
            val[last_id] = y;
            lastans = y;
            return;
        }
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

const int N = 2e5 + 5;

struct node_t { int ans, minn, maxn, x, y, tag; } p[N << 2];

void add_tag(int u, int x) {
    p[u].minn += x; p[u].maxn += x; p[u].tag += x;
    p[u].x -= x; p[u].y -= x;
}

void update(int u) {
    p[u].ans = max(max(p[u << 1].ans, p[u << 1 | 1].ans), max(p[u << 1].maxn + p[u << 1 | 1].y, p[u << 1 | 1].maxn + p[u << 1].x));
    p[u].minn = min(p[u << 1].minn, p[u << 1 | 1].minn);
    p[u].maxn = max(p[u << 1].maxn, p[u << 1 | 1].maxn);
    p[u].x = max(max(p[u << 1].x, p[u << 1 | 1].x), p[u << 1].maxn - p[u << 1 | 1].minn * 2);
    p[u].y = max(max(p[u << 1].y, p[u << 1 | 1].y), p[u << 1 | 1].maxn - p[u << 1].minn * 2);
}

void pushdown(int u) {
    if(p[u].tag) {
        add_tag(u << 1, p[u].tag);
        add_tag(u << 1 | 1, p[u].tag);
        p[u].tag = 0;
    }
}

char c[N];
int d[N];
int n, m;

void build(int u, int l, int r) {
    if(l == r) {
        p[u].ans = 1;
        p[u].maxn = p[u].minn = d[l];
        p[u].x = p[u].y = -d[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(u << 1, l, mid); build(u << 1 | 1, mid + 1, r);
    update(u);
}

void change(int u, int l, int r, int L, int R, int x) {
    if(l <= L && R <= r) {
        add_tag(u, x);
        return;
    }
    pushdown(u);
    int mid = (L + R) >> 1;
    if(mid >= l) change(u << 1, l, r, L, mid, x);
    if(mid + 1 <= r) change(u << 1 | 1, l, r, mid + 1, R, x);
    update(u);
}

int main() {
    read(n); read(m); scanf("%s", c + 1);
    n = n * 2 - 2;
    for(register int i = 1; i <= n; i++) d[i] = d[i - 1] + (c[i] == '(' ? 1 : -1);
    build(1, 1, n);
    print(p[1].ans, '\n');
    for(register int i = 1; i <= m; i++) {
        int x, y; read(x); read(y);
        change(1, x, n, 1, n, c[x] == '(' ? -2 : 2);
        change(1, y, n, 1, n, c[y] == '(' ? -2 : 2);
        swap(c[x], c[y]);
        print(p[1].ans, '\n');
    }
    return 0;
}