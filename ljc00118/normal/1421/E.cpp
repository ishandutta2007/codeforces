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

const int N = 2e5 + 5;

ll f[N][3][2][2];
int a[N];
int n;

inline void addmax(ll &x, ll y) { x = max(x, y); }

int main() {
    memset(f, -0x3f, sizeof(f));
    read(n);
    for (int i = 1; i <= n; i++) read(a[i]);
    if (n == 1) {
        print(a[1], '\n');
        return 0;
    }
    f[1][1][0][1] = a[1]; f[1][2][0][0] = -a[1];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= 2; j++) {
            for (int k = 0; k <= 1; k++) {
                for (int t = 0; t <= 1; t++) {
                    for (int _ = 0; _ <= 1; _++) {
                        int go = (j + (_ == 1 ? 1 : 2)) % 3;
                        ll val = f[i][j][k][t] + (_ == 1 ? a[i + 1] : -a[i + 1]);
                        addmax(f[i + 1][go][k | (t == _)][_], val);
                    }
                }
            }
        }
    }
    print(max(f[n][1][1][0], f[n][1][1][1]), '\n');
    return 0;
}