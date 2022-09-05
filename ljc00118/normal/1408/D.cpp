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

const int N = 2005, MAXN = 1e6 + 5;

int a[N], b[N], c[N], d[N], mx[MAXN];
int n, m, ans = MAXN;

int main() {
    read(n); read(m);
    for (int i = 1; i <= n; i++) read(a[i]), read(b[i]);
    for (int i = 1; i <= m; i++) read(c[i]), read(d[i]);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (c[j] >= a[i] && d[j] >= b[i]) {
                mx[c[j] - a[i]] = max(mx[c[j] - a[i]], d[j] - b[i] + 1);
            }
        }

    }
    for (int i = 1000001; i >= 0; i--) {
        mx[i] = max(mx[i], mx[i + 1]);
        ans = min(ans, mx[i] + i);
    }
    print(ans, '\n');
    return 0;
}