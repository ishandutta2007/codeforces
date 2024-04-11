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

int x[N], y[N], cnt[4][4][4];
int n; ll ans, ans3;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
    read(n);
    for (int i = 1; i <= n; i++) {
        read(x[i]); read(y[i]);
    }
    for (int i = 1; i <= n; i++) {
        memset(cnt, 0, sizeof(cnt));
        for (int j = 1; j <= n; j++) {
            if (i != j) {
                int d = gcd(abs(x[j] - x[i]), abs(y[j] - y[i]));
                ++cnt[x[j] % 4][y[j] % 4][d % 4];
                // fprintf(stderr, "%d %d %d\n", x[j] % 4, y[j] % 4, d % 4);
            }
        }
        rep(i0, 0, 3) rep(i1, 0, 3) rep(i2, 0, 3) rep(i3, 0, 3) rep(i4, 0, 3) rep(i5, 0, 3) {
            if (i0 % 2 != i3 % 2 || i1 % 2 != i4 % 2) continue;
            int d = (i0 == i3 && i1 == i4) ? 4 : 2;
            int same = (i0 == i3 && i1 == i4 && i2 == i5);
            int S = (i0 - x[i] % 4) * (i4 - y[i] % 4) - (i1 - y[i] % 4) * (i3 - x[i] % 4);
            S = (S / 2 % 2 + 2) % 2;
            int b = (i2 + i5 + d) / 2 % 2;
            if (b == S) {
                ll now = 0;
                if (same) now += cnt[i0][i1][i2] * (cnt[i0][i1][i2] - 1);
                else now += cnt[i0][i1][i2] * cnt[i3][i4][i5];
                if (i0 % 2 == x[i] % 2 && i1 % 2 == y[i] % 2) ans3 += now;
                else ans += now;
            }
        }
    }
    // fprintf(stderr, "ans = %lld, ans3 = %lld\n", ans, ans3);
    print(ans / 2 + ans3 / 6, '\n');
    return 0;
}