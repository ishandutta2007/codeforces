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

int c[7], T, x, y;

int main() {
    read(T);
    while (T--) {
        read(x); read(y);
        for (int i = 1; i <= 6; i++) read(c[i]);
        int cnt2 = y - x, cnt1 = y - cnt2;
        ll ans = 4e18;
        ans = min(ans, 1ll * (cnt1 < 0 ? c[4] : c[1]) * abs(cnt1) + 1ll * (cnt2 < 0 ? c[5] : c[2]) * abs(cnt2));
        cnt2 = x - y; cnt1 = x - cnt2;
        ans = min(ans, 1ll * (cnt1 < 0 ? c[4] : c[1]) * abs(cnt1) + 1ll * (cnt2 < 0 ? c[3] : c[6]) * abs(cnt2));
        cnt2 = x; cnt1 = y;
        ans = min(ans, 1ll * (cnt1 < 0 ? c[5] : c[2]) * abs(cnt1) + 1ll * (cnt2 < 0 ? c[3] : c[6]) * abs(cnt2));
        print(ans, '\n');
    }
    return 0;
}