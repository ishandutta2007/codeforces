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

const int N = 2e5 + 5;

ll a[N], b[N], d;
int n, m;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
    read(n); read(m);
    for (int i = 1; i <= n; i++) read(a[i]);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= m; i++) read(b[i]);
    for (int i = 2; i <= n; i++) d = gcd(d, a[i] - a[1]);
    for (int i = 1; i <= m; i++) print(gcd(d, a[1] + b[i]), i == m ? '\n' : ' ');
    return 0;
}