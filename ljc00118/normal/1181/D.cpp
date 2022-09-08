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

    void clear() { *this = hash_map_t(mod); }

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

const int N = 5e5 + 5, INF = 0x7fffffff;

struct node_t {
    int size, value;
    node_t *left, *right;
    node_t () {}
    node_t (int a, int b, node_t *c, node_t *d) : size(a), value(b), left(c), right(d) {}
} *root, *null, *st[N << 1], t[N << 1];

struct ele {
    int id; ll val;
    bool operator < (const ele A) const { return val < A.val; }
} a[N], Q[N];

int s[N], ans[N], A[N];
int n, m, q, cnt, now = 1, lastnow = 1;

#define update(u) if(u -> left -> size) u -> size = u -> left -> size + u -> right -> size, u -> value = u -> right -> value
#define new_node(a, b, c, d) (&(*st[cnt++] = node_t(a, b, c, d)))
#define merge(a, b) new_node(a -> size + b -> size, b -> value, a, b)
#define ratio 4

void maintain(node_t *u) {
    if(u -> left -> size > u -> right -> size * ratio) u -> right = merge(u -> left -> right, u -> right), st[--cnt] = u -> left, u -> left = u -> left -> left;
    else if(u -> right -> size > u -> left -> size * ratio) u -> left = merge(u -> left, u -> right -> left), st[--cnt] = u -> right, u -> right = u -> right -> right;
}

void ins(node_t *u, int x) {
    if(u -> size == 1) u -> left = new_node(1, min(u -> value, x), null, null), u -> right = new_node(1, max(u -> value, x), null, null);
    else ins(x > u -> left -> value ? u -> right : u -> left, x); update(u); maintain(u);
}

int find(node_t *u, int x) {
    if(u -> size == 1) return u -> value;
    return x > u -> left -> size ? find(u -> right, x - u -> left -> size) : find(u -> left, x);
}

ll calc(int x) { return 1ll * x * a[x].val - s[x]; }

int main() {
    read(n); read(m); read(q);
    null = new node_t(0, 0, 0, 0);
    root = new node_t(1, INF, null, null);
    for(register int i = 0; i <= m * 2; i++) st[i] = &t[i];
    for(register int i = 1; i <= m; i++) a[i].id = i, a[i].val = 0;
    for(register int i = 1; i <= n; i++) read(A[i]), ++a[A[i]].val;
    sort(a + 1, a + m + 1);
    for(register int i = 1; i <= m; i++) s[i] = s[i - 1] + a[i].val;
    for(register int i = 1; i <= q; i++) read(Q[i].val), Q[i].id = i;
    sort(Q + 1, Q + q + 1);
    for(register int i = 1; i <= q; i++) {
        if(Q[i].val <= n) ans[Q[i].id] = A[Q[i].val];
        else {
            Q[i].val -= n;
            while(now <= m && calc(now) < Q[i].val) {
                ins(root, a[now].id);
                ++now;
            }
            int index = (Q[i].val - calc(now - 1)) % (now - 1);
            // fprintf(stderr, "k = %I64d, now = %d, index = %d\n", Q[i].val, now, index);
            if(index == 0) index = now - 1;
            ans[Q[i].id] = find(root, index);
        }
    }
    for(register int i = 1; i <= q; i++) print(ans[i], '\n');
    return 0;
}