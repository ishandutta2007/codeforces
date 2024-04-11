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
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
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

const int N = 2e5 + 5, md1 = 998244353, md2 = 98765431;

int a[N];
char c[N];
int n, m, q;

struct info {
    int v1, v2;
    info (int a = 0, int b = 0) : v1(a), v2(b) {}
} pw[N], f[2][N];

info operator + (const info a, const info b) {
    return info((a.v1 + b.v1) % md1, (a.v2 + b.v2) % md2);
}

info operator - (const info a, const info b) {
    return info((a.v1 - b.v1 + md1) % md1, (a.v2 - b.v2 + md2) % md2);
}

info operator * (const info a, const info b) {
    return info(1ll * a.v1 * b.v1 % md1, 1ll * a.v2 * b.v2 % md2);
}

bool operator == (const info a, const info b) {
    return a.v1 == b.v1 && a.v2 == b.v2;
}

info get(int l, int r) {
    if (l > a[m]) return 0;
    int _l = lower_bound(a + 1, a + m + 1, l) - a, _r = upper_bound(a + 1, a + m + 1, r) - a - 1;
    return f[l & 1][_r] - f[l & 1][_l - 1] * pw[_r - _l + 1];
}

int main() {
    read(n); scanf("%s", c + 1); read(q);
    pw[0] = info(1, 1); pw[1] = info(5, 7);
    for (int i = 2; i <= n; i++) pw[i] = pw[i - 1] * pw[1];
    for (int i = 1; i <= n; i++) {
        if (c[i] == '0') {
            a[++m] = i;
            f[0][m] = f[0][m - 1] * pw[1] + info(i % 2 + 1, i % 2 + 1);
            f[1][m] = f[1][m - 1] * pw[1] + info(2 - i % 2, 2 - i % 2);
        }
    }
    for (int i = 1; i <= q; i++) {
        int a, b, l;
        read(a); read(b); read(l);
        if (get(a, a + l - 1) == get(b, b + l - 1)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}