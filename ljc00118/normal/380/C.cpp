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

const int N = 1e6 + 5;

int n, m;

struct ele {
    int ans, left, right;
    ele (int a = 0, int b = 0, int c = 0) : ans(a), left(b), right(c) {}
};

ele merge(ele a, ele b) {
    ele ans;
    int val = min(a.right, b.left);
    a.right -= val; b.left -= val;
    ans.ans = a.ans + b.ans + val;
    ans.left = a.left + b.left;
    ans.right = a.right + b.right;
    return ans;
}

struct node_t {
    int l, r;
    ele val;
} p[N << 2];

char c[N];
void build(int u, int l, int r) {
    p[u].l = l; p[u].r = r;
    if(l == r) {
        p[u].val = ele(0, c[l] == ')', c[l] == '(');
        return;
    }
    int mid = (l + r) >> 1;
    build(u << 1, l, mid); build(u << 1 | 1, mid + 1, r);
    p[u].val = merge(p[u << 1].val, p[u << 1 | 1].val);
}

ele query(int u, int l, int r) {
    if(l <= p[u].l && p[u].r <= r) return p[u].val;
    int mid = (p[u].l + p[u].r) >> 1; ele ans;
    if(mid >= l) ans = merge(ans, query(u << 1, l, r));
    if(mid + 1 <= r) ans = merge(ans, query(u << 1 | 1, l, r));
    return ans;
}

int main() {
    scanf("%s", c + 1); n = strlen(c + 1);
    build(1, 1, n);
    read(m); while(m--) {
        int l, r; read(l); read(r);
        print(query(1, l, r).ans << 1, '\n');
    }
    return 0;
} //