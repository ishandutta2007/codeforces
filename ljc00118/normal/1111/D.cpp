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

const int N = 1e5 + 5, md = 1e9 + 7;

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

inline int mul(int x, int y) { return (ll)x * y % md; }

inline int fpow(int x, int y) {
    int ans = 1;
    while(y) {
        if(y & 1) ans = mul(ans, x);
        y >>= 1; x = mul(x, x);
    }
    return ans;
}

char c[N];
int f[N], fac[N], inv[N], cnt[52], ans[52][52];
int n, q, wxw, lim;

inline int calc(char c) {
    if(c >= 'a' && c <= 'z') return c - 'a';
    return c - 'A' + 26;
}

void add(int x) { if(!x) return; for(register int i = lim; i >= x; i--) f[i] = add(f[i], f[i - x]); }
void del(int x) { if(!x) return; for(register int i = x; i <= lim; i++) f[i] = sub(f[i], f[i - x]); }

int main() {
    scanf("%s", c + 1); n = strlen(c + 1); lim = n >> 1; read(q);
    fac[0] = 1;
    for(register int i = 1; i <= n; i++) fac[i] = mul(fac[i - 1], i);
    inv[n] = fpow(fac[n], md - 2);
    for(register int i = n; i >= 1; i--) inv[i - 1] = mul(inv[i], i);
    wxw = mul(mul(fac[lim], fac[lim]), 2);
    for(register int i = 1; i <= n; i++) ++cnt[calc(c[i])];
    for(register int i = 0; i <= 51; i++) wxw = mul(wxw, inv[cnt[i]]);
    f[0] = 1;
    for(register int i = 0; i <= 51; i++) add(cnt[i]);
    for(register int i = 0; i <= 51; i++) {
        del(cnt[i]);
        for(register int j = i; j <= 51; j++) {
            if(i != j) del(cnt[j]);
            ans[i][j] = mul(f[n >> 1], wxw);
            if(i != j) add(cnt[j]);
        }
        add(cnt[i]);
    }
    while(q--) {
        int x, y; read(x); read(y);
        x = calc(c[x]); y = calc(c[y]);
        if(x > y) swap(x, y);
        print(ans[x][y], '\n');
    }
    return 0;
}