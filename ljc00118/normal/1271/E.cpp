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

ll n, m;

ll calc(ll n, ll m) {
    ll ans = 0;
    for (ll bit = 1; m <= n; bit <<= 1, m <<= 1) ans += min(bit, n - m + 1);
    return ans;
}

int main() {
    read(n); read(m);
    ll l = 1, r = n / 2, ans = -1;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        if (calc(n, mid * 2) + calc(n, mid * 2 + 1) >= m) ans = mid * 2, l = mid + 1;
        else r = mid - 1;
    }
    l = 1, r = (n + 1) / 2;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        if (calc(n, mid * 2 - 1) >= m) ans = max(ans, mid * 2 - 1), l = mid + 1;
        else r = mid - 1;
    }
    print(ans, '\n');
    return 0;
}