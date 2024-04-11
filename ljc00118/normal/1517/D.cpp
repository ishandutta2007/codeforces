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

inline void addmin(int &x, int y) { x = min(x, y); }

const int N = 505;

int r[N][N], d[N][N], f[N][N][11];
int n, m, k;

int main() {
    memset(r, 0x3f, sizeof(r));
    memset(d, 0x3f, sizeof(d));
    read(n); read(m); read(k);
    if (k & 1) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                print(-1, j == m ? '\n' : ' ');
            }
        }
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < m; j++) read(r[i][j]);
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= m; j++) read(d[i][j]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int t = 0; t <= k / 2; t++) {
                f[i][j][t] = min(min(r[i][j], r[i][j - 1]), min(d[i][j], d[i - 1][j])) * t * 2;
            }
        }
    }
    for (int t = 0; t < k / 2; t++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (i != 1) addmin(f[i - 1][j][t + 1], f[i][j][t] + d[i - 1][j] * 2);
                if (i != n) addmin(f[i + 1][j][t + 1], f[i][j][t] + d[i][j] * 2);
                if (j != 1) addmin(f[i][j - 1][t + 1], f[i][j][t] + r[i][j - 1] * 2);
                if (j != m) addmin(f[i][j + 1][t + 1], f[i][j][t] + r[i][j] * 2);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            print(f[i][j][k / 2], j == m ? '\n' : ' ');
        }
    }
    return 0;
}