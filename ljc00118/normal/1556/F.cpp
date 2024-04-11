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
    while (c < '0' || c > '9') { if (c == '-') fu = -1; c = getchar(); }
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

const int md = 1e9 + 7;

inline int add(int x, int y) {
    if (x + y >= md) return x + y - md;
    return x + y;
}

inline void addx(int &x, int y) {
    x += y;
    if (x >= md) x -= md;
}

inline int sub(int x, int y) {
    if (x < y) return x - y + md;
    return x - y;
}

inline void subx(int &x, int y) {
    x -= y;
    if (x < 0) x += md;
}

inline int mul(int x, int y) { return 1ull * x * y % md; }

inline int fpow(int x, int y) {
    int ans = 1;
    while (y) {
        if (y & 1) ans = mul(ans, x);
        y >>= 1; x = mul(x, x);
    }
    return ans;
}

const int N = 14;

int f[1 << N], tem[N][1 << N], a[N], pre[1 << N];
int n, ans;

int main() {
    read(n);
    for (int i = 0; i < n; i++) read(a[i]);
    for (int i = 0; i < n; i++) {
        tem[i][0] = 1;
        for (int j = 0; j < (1 << n); j++) {
            if ((j >> i) & 1) continue;
            for (int k = 0; k < n; k++) {
                if (k == i || ((j >> k) & 1)) continue;
                tem[i][j | (1 << k)] = mul(tem[i][j], mul(a[i], fpow(a[i] + a[k], md - 2)));
            }
        }
    }
    for (int i = 0; i < n; i++) pre[1 << i] = i;
    for (int i = 0; i < n; i++) {
        memset(f, 0, sizeof(f));
        for (int j = 0; j < (1 << n); j++) {
            if (((j >> i) & 1) == 0) continue;
            int all = (j ^ (1 << i));
            f[j] = 1;
            for (int s = all; s; s = (s - 1) & all) {
                int coef = f[j ^ s];
                for (int k = 0; k < n; k++) {
                    if ((s >> k) & 1) {
                        coef = mul(coef, tem[k][j ^ s]);
                    }
                }
                f[j] = sub(f[j], coef);
            }
        }
        ans = add(ans, f[(1 << n) - 1]);
    }
    print(ans, '\n');
    return 0;
}