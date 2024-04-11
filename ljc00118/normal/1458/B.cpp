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

const int N = 105;

int a[N], b[N], f[N][N * N];
int n, sum;

int main() {
    memset(f, -1, sizeof(f));
    read(n);
    f[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        read(a[i]); read(b[i]);
        for (int j = i - 1; j >= 0; j--) {
            for (int k = sum; k >= 0; k--) {
                if (f[j][k] != -1) {
                    f[j + 1][k + a[i]] = max(f[j + 1][k + a[i]], f[j][k] + b[i]);
                }
            }
        }
        sum += a[i];
    }
    int all = 0;
    for (int i = 1; i <= n; i++) all += b[i];
    for (int i = 1; i <= n; i++) {
        double maxn = 0;
        for (int j = 0; j <= sum; j++) {
            if (f[i][j] != -1) {
                maxn = max(maxn, min((double)j, f[i][j] + (double)(all - f[i][j]) / 2));
            }
        }
        printf("%.1lf%c", maxn, i == n ? '\n' : ' ');
    }
    return 0;
}