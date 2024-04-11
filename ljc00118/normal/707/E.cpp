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

const int N = 2005, M = 1e6 + 5;

struct ele {
    int x, y, val;
    ele (int a, int b, int c) : x(a), y(b), val(c) {}
};

vector <ele> l[N];
ll f[N][N], ans[N][N]; char c[10];
int id[M], v[M], x[N], y[N], _x[N], _y[N], now[N];
int n, m, k, q, tot;

inline int lowbit(int x) { return x & -x; }

void add(int x, int y, int z) {
    for(register int i = x; i <= n; i += lowbit(i))
        for(register int j = y; j <= m; j += lowbit(j))
            f[i][j] += z;
    // fprintf(stderr, "f[1][1] = %I64d\n", f[1][1]);
}

ll query(int x, int y) {
    ll ans = 0;
    for(register int i = x; i; i -= lowbit(i))
        for(register int j = y; j; j -= lowbit(j))
            ans += f[i][j];
    return ans;
}

int main() {
    read(n); read(m); read(k);
    for(register int i = 1; i <= k; i++) {
        int len; read(len);
        while(len--) {
            int x, y, val;
            read(x); read(y); read(val);
            l[i].push_back(ele(x, y, val));
        }
    }
    read(q);
    for(register int i = 1; i <= q; i++) {
        scanf("%s", c + 1);
        if(c[1] == 'A') {
            int a, b, c, d;
            read(a); read(b); read(c); read(d);
            id[i] = ++tot; x[tot] = a; y[tot] = b; _x[tot] = c; _y[tot] = d;
        }
        if(c[1] == 'S') {
            int t; read(t);
            v[i] = t;
        }
    }
    for(register int i = 1; i <= k; i++) {
        for(register unsigned j = 0; j < l[i].size(); j++) add(l[i][j].x, l[i][j].y, l[i][j].val);
        for(register int j = 1; j <= tot; j++) {
            ans[i][j] = query(_x[j], _y[j]) - query(_x[j], y[j] - 1) - query(x[j] - 1, _y[j]) + query(x[j] - 1, y[j] - 1);
            // fprintf(stderr, "query(%d, %d) = %I64d\n", _x[j], _y[j], query(_x[j], _y[j]));
            // fprintf(stderr, "query(%d, %d) = %I64d\n", _x[j], y[j] - 1, query(_x[j], y[j] - 1));
            // fprintf(stderr, "query(%d, %d) = %I64d\n", x[j] - 1, _y[j], query(x[j] - 1, _y[j]));
            // fprintf(stderr, "query(%d, %d) = %I64d\n", x[j] - 1, y[j] - 1, query(x[j] - 1, y[j] - 1));
        }
        for(register unsigned j = 0; j < l[i].size(); j++) add(l[i][j].x, l[i][j].y, -l[i][j].val);
    }
    for(register int i = 1; i <= q; i++) {
        if(id[i] == 0) now[v[i]] ^= 1;
        else {
            ll ans = 0;
            for(register int j = 1; j <= k; j++) {
                if(!now[j]) {
                    ans += ::ans[j][id[i]];
                }
            }
            print(ans, '\n');
        }
    }
    return 0;
}