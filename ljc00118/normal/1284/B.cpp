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

const int N = 1e5 + 5;

int minn[N], maxn[N];
int n; ll ans;

int main() {
    read(n);
    for (int i = 1; i <= n; i++) {
        int m, minn = 1000000, maxn = 0, ok = 0; read(m);
        for (int j = 1; j <= m; j++) {
            int x; read(x);
            if (x > minn) ok = 1;
            minn = min(minn, x);
            maxn = max(maxn, x);
        }
        if (ok) {
            ans += (n * 2 - 1);
            --i; --n; continue;
        }
        ::minn[i] = minn; ::maxn[i] = maxn;
    }
    sort(maxn + 1, maxn + n + 1);
    for (int i = 1; i <= n; i++) ans += n - (upper_bound(maxn + 1, maxn + n + 1, minn[i]) - maxn) + 1;
    print(ans, '\n');
    return 0;
}