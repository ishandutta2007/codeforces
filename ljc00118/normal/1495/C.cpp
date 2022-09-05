#pragma GCC optimize(2)
#pragma GCC optimize(3)
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

char c[N][N];
int T, n, m;

int main() {
    read(T);
    while (T--) {
        read(n); read(m);
        for (int i = 1; i <= n; i++) scanf("%s", c[i] + 1);
        int fir = (n % 3 == 1 ? 1 : 2);
        for (int i = fir; i <= n; i += 3) {
            for (int j = 1; j <= m; j++) c[i][j] = 'X';
        }
        for (int i = fir; i + 3 <= n; i += 3) {
            if (c[i + 1][2] == 'X' || c[i + 2][2] == 'X') c[i + 1][2] = c[i + 2][2] = 'X';
            else c[i + 1][1] = c[i + 2][1] = 'X';
        }
        for (int i = 1; i <= n; i++) printf("%s\n", c[i] + 1);
    }
    return 0;
}