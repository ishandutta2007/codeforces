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

const int N = 2505;
const long double eps = 1e-20, PI = acos(-1.0);

long double d[N];
int x[N], y[N];
int n, tot;
ll ans;

inline int L(int x) {
    if (x == 1) return tot;
    return x - 1;
}

inline int R(int x) {
    if (x == tot) return 1;
    return x + 1;
}

inline long double calc(int i, int j) {
    if (i <= j) return d[j] - d[i];
    return d[j] + 360 - d[i];
}

int main() {
    read(n);
    for (int i = 1; i <= n; i++) read(x[i]), read(y[i]);
    for (int i = 1; i <= n; i++) {
        tot = 0;
        for (int j = 1; j <= n; j++) {
            if (i != j) {
                int _x = x[j] - x[i], _y = y[j] - y[i];
                if (!_x && !_y) continue;
                if (!_x) {
                    if (_y > 0) d[++tot] = 0;
                    else d[++tot] = 180;
                    // fprintf(stderr, "i = %d, j = %d, jiaodu = %.8lf\n", i, j, d[tot]);
                    continue;
                }
                if (!_y) {
                    if (_x > 0) d[++tot] = 90;
                    else d[++tot] = 270;
                    // fprintf(stderr, "i = %d, j = %d, jiaodu = %.8lf\n", i, j, d[tot]);
                    continue;
                }
                long double now = asin(fabs((long double)_x / sqrt(1ll * _x * _x + 1ll * _y * _y))) / PI * 180;
                if (_x > 0 && _y > 0) d[++tot] = now;
                if (_x > 0 && _y < 0) d[++tot] = 180 - now;
                if (_x < 0 && _y < 0) d[++tot] = 180 + now;
                if (_x < 0 && _y > 0) d[++tot] = 360 - now;
                // fprintf(stderr, "i = %d, j = %d, jiaodu = %.8lf\n", i, j, d[tot]);
            }
        }
        if (tot <= 3) continue;
        sort(d + 1, d + tot + 1);
        int pos = 1; ans += 1ll * tot * (tot - 1) * (tot - 2) * (tot - 3) / 24;
        for (int j = 1; j <= tot; j++) {
            while (R(pos) != j && calc(j, R(pos)) - eps <= 180) pos = R(pos);
            int cnt = (j <= pos ? pos - j + 1 : tot - j + 1 + pos);
            // fprintf(stderr, "j = %d, pos = %d, cnt = %d\n", j, pos, cnt);
            if (cnt >= 4) ans -= 1ll * (cnt - 1) * (cnt - 2) * (cnt - 3) / 6; 
        }
    }
    print(ans, '\n');
    return 0;
}