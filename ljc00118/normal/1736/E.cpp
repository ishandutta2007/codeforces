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

const int N = 505;

int a[N], dp[2][N][N];
int n;

inline void upd(int &x, int y) { x = max(x, y); }

int main() {
    memset(dp[0], -1, sizeof(dp[0]));
    read(n);
    for (int i = 1; i <= n; i++) read(a[i]);
    dp[0][0][0] = 0;
    for (int i = 1, cur = 0; i <= n; i++, cur ^= 1) {
        memset(dp[cur ^ 1], -1, sizeof(dp[cur ^ 1]));
        for (int j = 0; j < i; j++) {
            for (int k = max(0, i - (j + 1) - 1); k <= j; k++) {
                if (dp[cur][j][k] == -1) continue;
                upd(dp[cur ^ 1][j + 1][k - (i - (j + 1) - 1)], dp[cur][j][k] + a[i]);
            }
        }
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k <= j; k++) {
                if (dp[cur ^ 1][j - 1][k] != -1) {
                    upd(dp[cur ^ 1][j][k], dp[cur ^ 1][j - 1][k] + a[i]);
                }
            }
        }
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= j; k++) {
                upd(dp[cur ^ 1][j][k], dp[cur][j][k]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) upd(ans, dp[n & 1][n][i]);
    print(ans, '\n');
    return 0;
}