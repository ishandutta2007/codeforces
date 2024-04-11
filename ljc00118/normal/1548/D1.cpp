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

const int N = 6005;

int x[N], y[N], cnt[2][2];
int n; ll ans;

int main() {
    read(n);
    for (int i = 1; i <= n; i++) {
        read(x[i]); read(y[i]);
        ++cnt[(x[i] / 2) & 1][(y[i] / 2) & 1];
    }
    rep(i0, 0, 1) rep(i1, 0, 1) rep(i2, 0, 1) rep(i3, 0, 1) rep(i4, 0, 1) rep(i5, 0, 1) {
        int tot = 0;
        if (i0 != i2 || i1 != i3) ++tot;
        if (i0 != i4 || i1 != i5) ++tot;
        if (i2 != i4 || i3 != i5) ++tot;
        if (tot % 2 == 0) {
            ll now = cnt[i0][i1];
            now *= (cnt[i2][i3] - ((i0 == i2) && (i1 == i3)));
            now *= (cnt[i4][i5] - ((i0 == i4) && (i1 == i5)) - ((i2 == i4) && (i3 == i5)));
            ans += now;
        }
    }
    print(ans / 6, '\n');
    return 0;
}