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

const int N = 105;

int a[N], b[N], c[N], ans[N];
int T, n;

int main() {
    read(T);
    while (T--) {
        read(n);
        for (int i = 1; i <= n; i++) read(a[i]);
        for (int i = 1; i <= n; i++) read(b[i]);
        for (int i = 1; i <= n; i++) read(c[i]);
        ans[1] = a[1];
        for (int i = 2; i < n; i++) {
            if (a[i] != ans[i - 1]) ans[i] = a[i];
            else ans[i] = b[i];
        }
        if (a[n] != ans[n - 1] && a[n] != ans[1]) ans[n] = a[n];
        if (b[n] != ans[n - 1] && b[n] != ans[1]) ans[n] = b[n];
        if (c[n] != ans[n - 1] && c[n] != ans[1]) ans[n] = c[n];
        for (int i = 1; i <= n; i++) print(ans[i], i == n ? '\n' : ' ');
    }
    return 0;
}