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

struct node_t {
    int tag;
    node_t *left, *right;
    node_t () { tag = 0; left = right = NULL; }
    node_t (int a, node_t *b, node_t *c) { tag = a; left = b; right = c; }
} *tr1, *tr2;

map < pair <int, int>, bool > wxw;
int n, m;

void change(node_t *&u, int l, int r, int L, int R, int x) {
    // fprintf(stderr, "l = %d, r = %d, L = %d, R = %d, x = %d\n", l, r, L, R, x);
    if(u == NULL) u = new node_t();
    if(l <= L && R <= r) {
        u -> tag = max(u -> tag, x);
        return;
    }
    int mid = (L + R) >> 1;
    if(mid >= l) change(u -> left, l, r, L, mid, x);
    if(mid + 1 <= r) change(u -> right, l, r, mid + 1, R, x);
}

int query(node_t *&u, int l, int r, int x) {
    // fprintf(stderr, "l = %d, r = %d, x = %d\n", l, r, x);
    if(u == NULL) return 0;
    if(l == r) return u -> tag;
    int mid = (l + r) >> 1;
    if(mid >= x) return max(query(u -> left, l, mid, x), u -> tag);
    return max(query(u -> right, mid + 1, r, x), u -> tag);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    while(m--) {
        int x, y; char c;
        cin >> x >> y >> c;
        if(wxw.count(make_pair(x, y))) {
            cout << 0 << endl;
            continue;
        }
        wxw[make_pair(x, y)] = 1;
        if(c == 'L') {
            int ed = query(tr1, 1, n, y);
            cout << x - ed << endl;
            change(tr2, ed + 1, x, 1, n, y);
        }
        if(c == 'U') {
            int ed = query(tr2, 1, n, x);
            cout << y - ed << endl;
            change(tr1, ed + 1, y, 1, n, x);
        }
    }
    return 0;
}