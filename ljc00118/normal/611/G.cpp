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

const int N = 1e6 + 5, md = 1e9 + 7;

inline int add(int x, int y) {
    x += y;
    if (x >= md) x -= md;
    return x;
}

inline int sub(int x, int y) {
    x -= y;
    if (x < 0) x += md;
    return x;
}

inline int mul(int x, int y) { return 1ll * x * y % md; }

inline int fpow(int x, int y) {
    int ans = 1;
    while (y) {
        if (y & 1) ans = mul(ans, x);
        y >>= 1; x = mul(x, x);
    }
    return ans;
}

struct point_t {
    int x, y;
    point_t (int a = 0, int b = 0) : x(a), y(b) {}
} a[N];

ll cross(int x, int y, int _x, int _y) {
    return 1ll * x * _y - 1ll * y * _x;
}

int sx[N], sy[N];
int n, ans, res;

inline int s(int x) { return (x % md + md) % md; }

int main() {
    read(n);
    for (int i = 1; i <= n; i++) read(a[i].x), read(a[i].y);
    reverse(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) a[i + n] = a[i];
    ll all = 0, sum = 0;
    for (int i = 2; i < n; i++) all += cross(a[i].x - a[1].x, a[i].y - a[1].y, a[i + 1].x - a[1].x, a[i + 1].y - a[1].y);
    for (int i = 1; i <= n * 2; i++) {
        sx[i] = add(sx[i - 1], s(a[i].x));
        sy[i] = add(sy[i - 1], s(a[i].y));
    }
    for (int i = 1, j = 1; i <= n; i++) {
        j = max(j, i + 1);
        while ((sum + cross(a[j].x - a[i].x, a[j].y - a[i].y, a[j + 1].x - a[i].x, a[j + 1].y - a[i].y)) <= all / 2) {
            sum += cross(a[j].x - a[i].x, a[j].y - a[i].y, a[j + 1].x - a[i].x, a[j + 1].y - a[i].y);
            res = (res + sum) % md;
            ++j;
        }
        ans = add(ans, mul(all % md, j - i - 1));
        ans = sub(ans, mul(res, 2));
        int x = sub(sub(sx[j], sx[i + 1]), mul(s(a[i].x), j - i - 1));
        int y = sub(sub(sy[j], sy[i + 1]), mul(s(a[i].y), j - i - 1));
        res = sub(res, sub(mul(s(a[i + 1].x - a[i].x), y), mul(s(a[i + 1].y - a[i].y), x)));
        sum -= cross(a[i + 1].x - a[i].x, a[i + 1].y - a[i].y, a[j].x - a[i].x, a[j].y - a[i].y);
    }
    print(ans, '\n');
    return 0;
}