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

const int md = 998244353, G = 3, Gi = (md + 1) / G;

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

void ntt(int *a, int opt, int len) {
    static int r[1 << 19];
    int nbase = 0;
    while((1 << nbase) < len) ++nbase;
    for(register int i = 1; i < (1 << nbase); i++) {
        r[i] = (r[i >> 1] >> 1) | ((i & 1) << (nbase - 1));
        if(i < r[i]) swap(a[i], a[r[i]]);
    }
    for(register int mid = 1; mid < (1 << nbase); mid <<= 1) {
        int wn = fpow(opt == 1 ? G : Gi, (md - 1) / (mid << 1));
        for(register int i = 0; i < (1 << nbase); i += (mid << 1)) {
            int w = 1;
            for(register int j = 0; j < mid; j++, w = mul(w, wn)) {
                int x = a[i + j], y = mul(a[i + j + mid], w);
                a[i + j] = add(x, y); a[i + j + mid] = sub(x, y);
            }
        }
    }
    if(opt == -1) {
        int inv = fpow(1 << nbase, md - 2);
        for(register int i = 0; i < (1 << nbase); i++) a[i] = mul(a[i], inv);
    }
}

void inv(int *a, int *b, int len) {
    if(len == 1) {
        b[0] = fpow(a[0], md - 2);
        return;
    }
    static int F[1 << 19], G[1 << 19];
    inv(a, b, len >> 1);
    for(register int i = 0; i < len; i++) F[i] = a[i], G[i] = b[i];
    for(register int i = len; i < (len << 1); i++) F[i] = G[i] = 0;
    ntt(F, 1, len << 1); ntt(G, 1, len << 1);
    for(register int i = 0; i < (len << 1); i++) F[i] = mul(F[i], mul(G[i], G[i]));
    ntt(F, -1, len << 1);
    for(register int i = 0; i < len; i++) b[i] = sub(mul(2, b[i]), F[i]);
}

void qiudao(int *a, int *b, int len) {
    for(register int i = 0; i < len - 1; i++) b[i] = mul(a[i + 1], i + 1);
    b[len - 1] = 0;
}

void jifen(int *a, int *b, int len) {
    for(register int i = 0; i < len - 1; i++) b[i + 1] = mul(a[i], fpow(i + 1, md - 2));
    b[0] = 0;
}

void ln(int *a, int *b, int len) {
    static int F[1 << 19], G[1 << 19];
    qiudao(a, F, len); inv(a, G, len);
    ntt(F, 1, len << 1); ntt(G, 1, len << 1);
    for(register int i = 0; i < (len << 1); i++) F[i] = mul(F[i], G[i]);
    ntt(F, -1, len << 1); jifen(F, b, len);
    for(register int i = 0; i < (len << 1); i++) F[i] = G[i] = 0;
}

void exp(int *a, int *b, int len) {
    if(len == 1) {
        b[0] = 1;
        return;
    }
    static int F[1 << 19];
    exp(a, b, len >> 1); ln(b, F, len);
    F[0] = sub(add(1, a[0]), F[0]);
    for(register int i = 1; i < len; i++) F[i] = sub(a[i], F[i]);
    for(register int i = len; i < (len << 1); i++) F[i] = b[i] = 0;
    ntt(b, 1, len << 1); ntt(F, 1, len << 1);
    for(register int i = 0; i < (len << 1); i++) b[i] = mul(b[i], F[i]);
    ntt(b, -1, len << 1);
}

const int inv2 = (md + 1) / 2;
void sqrt(int *a, int *b, int len) {
    static int F[1 << 19];
    ln(a, F, len);
    for(register int i = 0; i < len; i++) F[i] = mul(F[i], inv2);
    exp(F, b, len);
}

int a[1 << 19], b[1 << 19], ans[1 << 19];
int n, m;

int main() {
	read(n); read(m);
	for(register int i = 1; i <= n; i++) {
		int x; read(x);
		++a[x];
	}
	int nbase = 0;
	while((1 << nbase) <= m) ++nbase;
	for(register int i = 0; i < (1 << nbase); i++) a[i] = sub(0, mul(a[i], 4));
	a[0] = add(1, a[0]);
	sqrt(a, b, 1 << nbase);
	b[0] = add(b[0], 1);
	inv(b, ans, 1 << nbase);
	for(register int i = 1; i <= m; i++) print(mul(ans[i], 2), '\n');
    return 0;
}