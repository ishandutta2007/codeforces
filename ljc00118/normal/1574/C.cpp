#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename T>
inline void read(T &f) {
    f = 0; T fu = 1; char c = getchar();
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

const int N = 2e5 + 5;

ll a[N], sum;
int n, m;

int main() {
    read(n);
    for (int i = 1; i <= n; i++) read(a[i]), sum += a[i];
    sort(a + 1, a + n + 1);
    read(m);
    for (int i = 1; i <= m; i++) {
        ll x, y, ans = 4e18;
        read(x); read(y);
        int pos = lower_bound(a + 1, a + n + 1, x) - a;
        if (pos <= n) ans = min(ans, max(0ll, y - (sum - a[pos])));
        if (pos > 1) ans = min(ans, max(0ll, y - (sum - a[pos - 1])) + x - a[pos - 1]);
        print(ans, '\n');
    }
    return 0;
}