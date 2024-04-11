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

const int N = 1e5 + 5;

struct node_t {
    int l, r, tag, rev;
} p[N << 2];

int a[N];
int n, q;

void pushdown(int u) {
    if(p[u].tag != -1) {
        p[u << 1].tag = p[u].tag;
        p[u << 1 | 1].tag = p[u].tag;
        p[u << 1].rev = 0;
        p[u << 1 | 1].rev = 0;
        p[u].tag = -1;
    }
    if(p[u].rev) {
        p[u << 1].rev ^= 1;
        p[u << 1 | 1].rev ^= 1;
        p[u].rev = 0;
    }
}

void build(int u, int l, int r) {
    p[u].l = l; p[u].r = r; p[u].tag = -1; p[u].rev = 0;
    if(l == r) return;
    int mid = (l + r) >> 1;
    build(u << 1, l, mid); build(u << 1 | 1, mid + 1, r);
}

void change(int u, int l, int r, int x) {
    if(l > r) return;
    if(l <= p[u].l && p[u].r <= r) {
        p[u].tag = x; p[u].rev = 0;
        return;
    }
    pushdown(u);
    int mid = (p[u].l + p[u].r) >> 1;
    if(mid >= l) change(u << 1, l, r, x);
    if(mid + 1 <= r) change(u << 1 | 1, l, r, x);
}

void modify(int u, int l, int r) {
    if(l <= p[u].l && p[u].r <= r) {
        p[u].rev ^= 1;
        return;
    }
    pushdown(u);
    int mid = (p[u].l + p[u].r) >> 1;
    if(mid >= l) modify(u << 1, l, r);
    if(mid + 1 <= r) modify(u << 1 | 1, l, r);
}

pii query(int u, int x) {
    if(p[u].l == p[u].r) return make_pair(p[u].tag, p[u].rev);
    pushdown(u);
    int mid = (p[u].l + p[u].r) >> 1;
    if(mid >= x) return query(u << 1, x);
    return query(u << 1 | 1, x);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> q;
    for(register int i = 1; i <= n; i++) cin >> a[i];
    build(1, 0, 1e5);
    while(q--) {
        char c; int x;
        cin >> c >> x;
        if(c == '<') {
            if(x <= 0) change(1, -x + 1, 1e5, 1);
            else change(1, x, 1e5, 1), modify(1, 1, x - 1);
        } else {
            if(x >= 0) change(1, x + 1, 1e5, 0);
            else change(1, -x, 1e5, 0), modify(1, 1, -x - 1);
        }
    }
    for(register int i = 1; i <= n; i++) {
        pii now = query(1, (int)abs(a[i]));
        int val = a[i];
        if(now.first == 0 && a[i] > 0) val = -val;
        if(now.first == 1 && a[i] < 0) val = -val;
        if(now.second) val = -val;
        cout << val << " ";
    }
    cout << endl;
    return 0;   
}