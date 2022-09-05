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

const int N = 3e5 + 5, md = 998244353;

int a[N];
int n, ans;

int fac(int n) {
    int ans = 1;
    for (int i = 1; i <= n; i++) ans = 1ll * ans * i % md;
    return ans;
}

int inv(int n) {
    int x = n, y = md - 2, ans = 1;
    while (y) {
        if (y & 1) ans = 1ll * ans * x % md;
        y >>= 1; x = 1ll * x * x % md;
    }
    return ans;
}

int main() {
    read(n); n *= 2;
    for (int i = 1; i <= n; i++) read(a[i]);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n / 2; i++) {
        a[i] %= md;
        ans = (ans - a[i] + md) % md;
    }
    for (int i = n / 2 + 1; i <= n; i++) {
        ans = (ans + a[i]) % md;
    }
    int tmp = inv(fac(n / 2));
    ans = 1ll * fac(n) * tmp % md * tmp % md * ans % md;
    print(ans, '\n');
    return 0;
}