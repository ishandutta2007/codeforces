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

ll a[105]; int b[105];
int n, m; ll ans1, ans2;
// ans1 : , ans2 : 

int main() {
    read(n); read(m);
    for (int i = 1; i <= n; i++) read(a[i]);
    for (int s = 2; s <= m * 2; s++) {
        for (int i = 1; i <= n; i++) b[i] = a[i] % s;
        sort(b + 1, b + n + 1);

        int x = s / 2, y = s - x;
        if (x == y) {
            int cnt = 0;
            for (int i = 1; i <= n; i++) cnt += (b[i] >= x);
            if (cnt % 2 == 0) ++ans1;
            else ++ans2;
            --x; ++y;
        }
        int pos = 0;
        for (int i = 1; i <= n; i++) {
            if (b[i] < x) {
                pos = i;
            }
        }
        if ((n - pos) % 2 == 0) {
            // x > b[pos], s - x <= b[pos + 1]
            // 2x > b[n]
            // int lim = max(max(b[pos] + 1, b[n] / 2 + 1), s - b[pos + 1]);
            int lim = max(s - m, b[n] / 2 + 1);
            if (pos != 0) lim = max(lim, b[pos] + 1);
            if (pos != n) lim = max(lim, s - b[pos + 1]);
            // [lim, x], x 
            if (lim <= x) ans1 += (x - lim + 1) * 2;
        }
        // x 
        if ((n - pos) % 2 == 1) {
            int lim = max(s - m, b[n - 1] / 2 + 1);
            if (pos != 0) lim = max(lim, b[pos] + 1);
            if (pos != n) lim = max(lim, s - b[pos + 1]);
            if (lim <= x) ans2 += (x - lim + 1) * 2;
        }
    }
    ll ans = 1ll * m * m - ans1 - ans2;
    print(ans / 2, ' '); print(ans / 2, ' '); print(ans2, ' '); print(ans1, '\n');
    return 0;
}