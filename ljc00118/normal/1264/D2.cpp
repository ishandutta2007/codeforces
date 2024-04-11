#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') fu = -1; c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 1e6 + 5, md = 998244353;

inline int add(int x, int y) {
    x += y;
    if (x >= md) x -= md;
    return x;
}

inline int sub(int x, int y) {
    x -= y;
    if (x < 0) x += md;
    return x;
}

inline int mul(int x, int y) { return 1ll * x * y % md; }

inline int fpow(int x, int y) {
    int ans = 1;
    while (y) {
        if (y & 1) ans = mul(ans, x);
        y >>= 1; x = mul(x, x);
    }
    return ans;
}

char c[N];
int s1[N], s2[N], s3[N], s4[N], s5[N], fac[N], inv[N];
int n, ans;

inline int C(int n, int m) {
    if (n < 0 || m < 0 || n < m) return 0;
    return mul(fac[n], mul(inv[m], inv[n - m]));
}

int main() {
    scanf("%s", c + 1); n = strlen(c + 1);
    fac[0] = 1;
    for (int i = 1; i <= n; i++) {
        s1[i] = s1[i - 1] + (c[i] == '(');
        s2[i] = s2[i - 1] + (c[i] == ')');
        s3[i] = s3[i - 1] + (c[i] == '?');
        fac[i] = mul(fac[i - 1], i);
    }
    inv[n] = fpow(fac[n], md - 2);
    for (int i = n; i >= 1; i--) inv[i - 1] = mul(inv[i], i);
    for (int i = 0; i <= s3[n]; i++) {
        s4[i] = C(s3[n], i);
        s5[i] = C(s3[n] - 1, i);
        if (i) {
            s4[i] = add(s4[i], s4[i - 1]);
            s5[i] = add(s5[i], s5[i - 1]);    
        }
    }
    for (int i = 1; i <= n; i++) {
        int qwq = s2[n] - s2[i] + s3[n] - s3[i] - s1[i - 1] - 1;
        if (c[i] == '(') if (qwq >= 0) ans = add(ans, s4[min(qwq, s3[n])]);
        if (c[i] == '?') if (qwq >= 0) ans = add(ans, s5[min(qwq, s3[n])]);
    }
    print(ans, '\n');
    return 0;
}