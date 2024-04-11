#pragma GCC optimize(2)
#pragma GCC optimize(3)
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

const int N = 2005, md = 998244353;

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

char c[N];
int fac[N], inv[N], s1[N], s2[N], s3[N];
int n, ans;

inline int C(int n, int m) {
    if(n < 0 || m < 0 || n < m) return 0;
    return mul(fac[n], mul(inv[m], inv[n - m]));
}

int main() {
    scanf("%s", c + 1); n = strlen(c + 1);
    fac[0] = 1;
    for(register int i = 1; i <= n; i++) {
        s1[i] = s1[i - 1] + (c[i] == '(');
        s2[i] = s2[i - 1] + (c[i] == ')');
        s3[i] = s3[i - 1] + (c[i] == '?');
        fac[i] = mul(fac[i - 1], i);
    }
    inv[n] = fpow(fac[n], md - 2);
    for(register int i = n; i >= 1; i--) inv[i - 1] = mul(inv[i], i);
    for(register int cnt = 0; cnt <= n; cnt++) {
        for(register int res = 0; res <= n; res++) {
            ans = add(ans, 1ll * res * C(s3[n] - s3[cnt], (res - (s2[n] - s2[cnt]))) % md * C(s3[cnt], cnt - res - s2[cnt]) % md);
        }
    }
    print(ans, '\n');
    return 0;
}