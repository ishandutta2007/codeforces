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

const int base = 16, N = 1 << base, md = 998244353, G = 3, Gi = (md + 1) / G;

inline int add(int x, int y) {
    x += y;
    if(x >= md) x -= md;
    return x;
}

inline int sub(int x, int y) {
    x -= y;
    if(x < 0) x += md;
    return x;
}

inline int mul(int x, int y) { return 1ll * x * y % md; }

inline int fpow(int x, int y) {
    int ans = 1;
    while(y) {
        if(y & 1) ans = mul(ans, x);
        y >>= 1; x = mul(x, x);
    }
    return ans;
}

int roots[N], root[N], rev[N], n, k;

void init_ntt() {
    for(register int i = 1; i < N; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (base - 1));
    for(register int mid = 1; mid < N; mid <<= 1) {
        int wn = fpow(G, (md - 1) / (mid << 1));
        int wn2 = fpow(Gi, (md - 1) / (mid << 1));
        for(register int i = 0; i < N; i += (mid << 1)) {
            int w = 1, w2 = 1;
            for(register int j = 0; j < mid; j++, w = mul(w, wn), w2 = mul(w2, wn2)) {
                roots[mid + j] = w;
                root[mid + j] = w2;
            }
        }
    }
}

void ntt(int *a, int opt) {
    for(register int i = 1; i < N; i++) if(i < rev[i]) swap(a[i], a[rev[i]]);
    for(register int mid = 1; mid < N; mid <<= 1) {
        for(register int i = 0; i < N; i += (mid << 1)) {
            for(register int j = 0; j < mid; j++) {
                int w = opt == 1 ? roots[mid + j] : root[mid + j];
                int x = a[i + j], y = mul(a[i + j + mid], w);
                a[i + j] = add(x, y); a[i + j + mid] = sub(x, y);
            }
        }
    }
    if(opt == -1) {
        int inv = fpow(N, md - 2);
        for(register int i = 0; i < N; i++) a[i] = mul(a[i], inv);
    }
}

int a[3][N], b[3][N], c[3][N];
void update() {
    for(register int i = 0; i < 3; i++) ntt(a[i], 1);
    for(register int i = 0; i < 3; i++) {
        for(register int j = 0; j < N; j++) {
            b[i][j] = mul(a[i / 2][j], a[i - i / 2][j]);
            c[i][j] = mul(a[i / 2 + 1][j], a[i - i / 2 + 1][j]);
        }
    }
    for(register int i = 0; i < 3; i++) {
        ntt(b[i], -1); ntt(c[i], -1);
        for(register int j = 0; j < (1 << 15); j++) {
            a[i][j] = b[i][j];
            if(j) a[i][j] = add(a[i][j], c[i][j - 1]);
        }
        for(register int j = (1 << 15); j < N; j++) a[i][j] = 0;
    }
}

void update2() {
    memcpy(a[2], a[1], sizeof(a[2]));
    memcpy(a[1], a[0], sizeof(a[1]));
    for(register int i = 1; i < (1 << 15); i++) a[0][i] = add(a[1][i], add(a[1][i - 1], a[2][i - 1]));
}

int main() {
    init_ntt();
    read(n); read(k);
    a[0][0] = 1;
    for(register int i = 30; i >= 0; i--) {
        // cout << i << endl;
        update();
        if(n & (1 << i)) update2();
    }
    for(register int i = 1; i <= k; i++) print(a[0][i], i == k ? '\n' : ' ');
    return 0;
}