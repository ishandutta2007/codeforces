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

const int N = 1e5 + 5, INF = 1e9;

char c[N];
int f[N][2][2];
int T, n;

inline void addmin(int &x, int y) { x = min(x, y); }

int main() {
    read(T);
    while (T--) {
        scanf("%s", c + 1); n = strlen(c + 1);
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j <= 1; j++) {
                for (int k = 0; k <= 1; k++) f[i][j][k] = INF;
            }
        }
        f[1][0][0] = 0; f[1][0][1] = 1; f[1][1][0] = 0; f[1][1][1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j <= 1; j++) {
                for (int k = 0; k <= 1; k++) {
                    for (int t = 0; t <= 1; t++) {
                        if (t == 1) {
                            addmin(f[i][k][t], f[i - 1][j][k] + 1);
                            continue;
                        }
                        if (!k && c[i - 1] == c[i]) continue;
                        if (!j && c[i - 2] == c[i]) continue;
                        addmin(f[i][k][t], f[i - 1][j][k]);
                    }
                }
            }
        }
        int ans = INF;
        for (int i = 0; i <= 1; i++) {
            for (int j = 0; j <= 1; j++) addmin(ans, f[n][i][j]);
        }
        print(ans, '\n');
    }
    return 0;
}