#include <bits/stdc++.h>
#include <Windows.h>
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

const int md = 998244353;

inline int add(int x, int y) {
    if (x + y >= md) return x + y - md;
    return x + y;
}

inline void addx(int &x, int y) {
    x += y;
    if (x >= md) x -= md;
}

inline int sub(int x, int y) {
    if (x < y) return x - y + md;
    return x - y;
}

inline void subx(int &x, int y) {
    x -= y;
    if (x < 0) x += md;
}

inline int mul(int x, int y) { return 1ull * x * y % md; }

inline int fpow(int x, int y) {
    int ans = 1;
    while (y) {
        if (y & 1) ans = mul(ans, x);
        y >>= 1; x = mul(x, x);
    }
    return ans;
}

const int N = 3e5 + 5;

int isp[N];
int n, ans, ret; ll m, now = 1;

int main() {
    read(n); read(m);
    for (int i = 2; i <= n; i++) {
        for (int j = i * 2; j <= n; j += i) isp[j] = 1;
    }
    ans = 0; ret = 1;
    for (int i = 1; i <= n; i++) {
        if (!isp[i]) {
            ll d = __gcd(now, (ll)i);
            if (m / now < i / d) break;
            now *= (i / d);
        }
        ret = mul(ret, (m / now) % md);
        ans = add(ans, ret);
    }
    ans = sub(0, ans);
    for (int i = 1; i <= n; i++) ans = add(ans, fpow(m % md, i));
    print(ans, '\n');
    return 0;
}