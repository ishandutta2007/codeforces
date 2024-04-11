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

int T, a, b, c, d;

inline ll getv(int n) {
    ll res = 1ll * a * (n + 1);
    int chao = min(n, c / d);
    res -= 1ll * (n - chao) * b * c;
    res -= 1ll * chao * (chao + 1) / 2 * d * b;
    return res;
}

int main() {
    read(T);
    while (T--) {
        read(a); read(b); read(c); read(d);
        if (a > 1ll * b * c) {
            printf("-1\n");
            continue;
        }
        int l = 1, r = 1000005, res = 0;
        while (l <= r) {
            // cout << l << " " << r << endl;
            int mid = (l + r) >> 1;
            if (getv(mid) > getv(mid - 1)) res = mid, l = mid + 1;
            else r = mid - 1;
        }
        print(getv(res), '\n');
    }
    return 0;
}