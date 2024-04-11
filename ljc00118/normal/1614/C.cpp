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

const int N = 2e5 + 5;

int s[30][N];
int T, n, m, ans;

int main() {
    read(T);
    while (T--) {
        read(n); read(m); ans = 0;
        for (int i = 0; i <= 29; i++) memset(s[i], 0, (n + 1) * 4);
        for (int i = 1; i <= m; i++) {
            int l, r, x;
            read(l); read(r); read(x);
            for (int j = 0; j <= 29; j++) {
                if (((x >> j) & 1) == 0) {
                    ++s[j][l]; --s[j][r + 1];
                }
            }
        }
        for (int i = 0; i <= 29; i++) {
            int cando = 0;
            for (int j = 1; j <= n; j++) {
                s[i][j] += s[i][j - 1];
                if (!s[i][j]) {
                    cando = 1;
                    break;
                }
            }
            if (cando) {
                ans = add(ans, mul(1 << i, fpow(2, n - 1)));
            }
        }
        print(ans, '\n');
    }
    return 0;
}