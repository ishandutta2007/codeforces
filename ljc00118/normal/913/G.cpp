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

int T, n; ll a;

ll mul(ll x, ll y, ll md) {
    ll ans = 0;
    while (y) {
        if (y & 1) ans = (ans + x) % md;
        y >>= 1; x = (x + x) % md;
    }
    return ans;
}

ll fpow(ll x, ll y, ll md) {
    ll ans = 1;
    while (y) {
        if (y & 1) ans = mul(ans, x, md);
        y >>= 1; x = mul(x, x, md);
    }
    return ans;
}

int main() {
    read(T);
    while (T--) {
        read(a);
        ll tmp = a;
        n = 0;
        while (tmp) tmp /= 10, ++n;
        for (ll m = 1, pw = 10; ; ++m, pw *= 10) {
            ll md = 1ll << (n + m);
            ll b = (md - a * pw % md) % md;
            if (b % 5 == 0) b += md;
            if (b >= pw) continue;
            ll x = (a * pw + b) / md, mi = 0, phi = 4, pw5 = 5;
            for (int i = 0; i <= 4; i++) {
                if (fpow(2, i, 5) == x % 5) {
                    mi = i;
                    break;
                }
            }
            for (int i = 2; i <= n + m; i++) {
                if (i != 2) phi *= 5;
                pw5 *= 5;
                for (int j = 0; j <= 4; j++) {
                    if (fpow(2, mi + phi * j, pw5) == x % pw5) {
                        mi += phi * j;
                        break;
                    }
                }
            }
            print(mi + n + m, '\n');
            break;
        }
    }
    return 0;
}