#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') fu = -1; c = getchar(); }
    while(c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 105;

double f[N][N * N], c[N][N], ans;
int a[N];
int n, x, sum;

int main() {
    read(n); read(x);
    f[0][0] = c[0][0] = 1;
    for(register int i = 1; i <= n; i++) {
        c[i][0] = 1;
        for(register int j = 1; j <= i; j++) {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }
    for(register int i = 1; i <= n; i++) {
        read(a[i]);
        for(register int j = i - 1; j >= 0; j--) {
            for(register int k = sum; k >= 0; k--) {
                f[j + 1][k + a[i]] += f[j][k];
            }
        }
        sum += a[i];
    }
    ans = sum;
    for(register int i = 1; i <= n; i++) {
        for(register int j = 0; j <= sum; j++) {
            double val = ((double)n / i - 1) * x / 2 + x, p = (double)j / i;
            if(val <= p) ans -= (p - val) / c[n][i] * f[i][j];
        }
    }
    printf("%.9lf\n", ans);
    return 0;
}