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

int T, x, y, a, b;

int main() {
    read(T);
    while (T--) {
        read(x); read(y); read(a); read(b);
        if (a > b) swap(a, b);
        int l = 0, r = x / a, ans = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            int cnt = mid;
            if (a != b) cnt = min(mid, (x - mid * a) / (b - a));
            if (1ll * cnt * a + 1ll * (mid - cnt) * b <= y) ans = mid, l = mid + 1;
            else r = mid - 1;
        }
        print(ans, '\n');
    }
    return 0;
}