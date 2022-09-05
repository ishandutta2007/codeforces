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

const int md = 998244353;

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

const int N = 1e6 + 5;

int f[N], g[N], tem[N], s[N];
int n;

int calc(int i) {
    int ans = 0;
    // addx(ans, f[i - 1]);
    addx(ans, mul(add(mul(f[i - 1], f[i - 1]), f[i - 1]), (md + 1) / 2));
    int sum = 0;
    addx(sum, mul(mul(f[i - 1], f[i - 1]), f[i - 1]));
    addx(sum, mul(3, mul(f[i - 1], f[i - 1])));
    addx(sum, mul(2, f[i - 1]));
    addx(ans, mul(sum, fpow(6, md - 2)));
    return ans;
}

int calc2(int i) {
    return mul(add(mul(f[i - 1], f[i - 1]), f[i - 1]), (md + 1) / 2);
}

int main() {
    read(n);
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        addx(f[i], f[i - 1]);
        addx(f[i], mul(add(mul(f[i - 1], f[i - 1]), f[i - 1]), (md + 1) / 2));
        // addx(f[i], f[i - 1]);
        addx(f[i], 1);
        // fprintf(stderr, "f[%d] = %d\n", i, f[i]);
    }
    for (int i = 1; i <= n; i++) tem[i] = calc2(i);
    for (int i = n; i >= 1; i--) tem[i] = sub(tem[i], tem[i - 1]);//, fprintf(stderr, "tem[%d] = %d\n", i, tem[i]);
    int ans = sub(calc(n), calc(n - 1));
    ans = mul(ans, 2); // tree
    ans = add(ans, 1); // lian
    for (int i = 1; i <= n - 1; i++) ans = add(ans, mul(tem[i], 2));
    // tree + lian
    for (int i = 1; i <= n; i++) s[i] = add(s[i - 1], tem[i]);
    for (int i = 1; i <= n - 1; i++) ans = add(ans, mul(1, mul(tem[i], s[n - i - 1])));
    // for (int i = 1; i <= (n - 1) / 2; i++) ans = sub(ans, mul(tem[i], tem[i]));
    // tree + lian + tree
    print(ans, '\n');
    return 0;
}