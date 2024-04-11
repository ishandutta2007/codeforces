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

const double eps = 1e-10;
const ll INF = 0x7fffffffffffffff;
const int N = 3e5 + 5;

struct line {
    int k, b;
    line (int A = 0, int B = 0) : k(A), b(B) {}
};

bool operator < (const line A, const line B) {
    if(A.k == B.k) return A.b > B.b;
    return A.k < B.k;
}

vector <line> p[N << 2];
int opt[N], a[N], b[N], d[N];
int n;

void add(int u, int l, int r, int L, int R, line x) {
    if(l <= L && R <= r) {
        p[u].push_back(x);
        return;
    }
    int mid = (L + R) >> 1;
    if(mid >= l) add(u << 1, l, r, L, mid, x);
    if(mid + 1 <= r) add(u << 1 | 1, l, r, mid + 1, R, x);
}

double getx(line a, line b) { return (double)(b.b - a.b) / (a.k - b.k); }
ll gety(line a, int x) { return 1ll * x * a.k + a.b; }

vector <line> make_hull(vector <line> a) {
    vector <line> ans;
    int n = (int)a.size(), top = -1;
    sort(a.begin(), a.end());
    for(register int i = 0; i < n; i++) {
        if(i && a[i].k == a[i - 1].k) continue;
        while((int)ans.size() >= 2) {
            // if(getx(ans[top], a[i]) <= getx(ans[top - 1], ans[top]) + eps) --top, ans.pop_back();
            // else break;
            if(1ll * (a[i].b - ans[top].b) * (ans[top - 1].k - ans[top].k) <= 1ll * (ans[top].b - ans[top - 1].b) * (ans[top].k - a[i].k)) --top, ans.pop_back();
            else break;
        }
        ans.push_back(a[i]); ++top;
    }
    return ans;
}

void build(int u, int l, int r) {
    p[u] = make_hull(p[u]);
    if(l == r) return;
    int mid = (l + r) >> 1;
    build(u << 1, l, mid); build(u << 1 | 1, mid + 1, r);
}

ll query(int u, int l, int r, int x, int y) {
    ll ans = -INF;
    if(p[u].size()) {
        int l = 1, r = (int)p[u].size() - 1, res = 0;
        while(l <= r) {
            int mid = (l + r) >> 1;
//          if(gety(p[u][mid - 1], y) <= gety(p[u][mid], y)) res = mid, l = mid + 1;
//          else r = mid - 1;
            if(getx(p[u][mid - 1], p[u][mid]) - eps <= y) res = mid, l = mid + 1;
            else r = mid - 1;
        }
        ans = gety(p[u][res], y);
    }
    if(l == r) return ans;
    int mid = (l + r) >> 1;
    if(mid >= x) ans = max(ans, query(u << 1, l, mid, x, y));
    else ans = max(ans, query(u << 1 | 1, mid + 1, r, x, y));
    return ans;
}

int main() {
//    freopen("onepiece.in", "r", stdin);
//    freopen("onepiece.out", "w", stdout);
    read(n);
    for(register int i = 1; i <= n; i++) {
        read(opt[i]);
        if(opt[i] == 1) read(a[i]), read(b[i]);
        if(opt[i] == 2) {
            int x; read(x);
            d[x] = i;
        }
        if(opt[i] == 3) read(a[i]);
    }
    for(register int i = 1; i <= n; i++) {
        if(opt[i] == 1) {
            if(!d[i]) d[i] = n;
            add(1, i, d[i], 1, n, line(a[i], b[i]));
        }
    }
    build(1, 1, n);
    for(register int i = 1; i <= n; i++) {
        if(opt[i] == 3) {
            ll ans = query(1, 1, n, i, a[i]);
            if(ans == -INF) printf("EMPTY SET\n");
            else print(ans, '\n');
        }
    }
    return 0;
}