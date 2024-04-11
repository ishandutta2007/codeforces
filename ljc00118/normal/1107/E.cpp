#include <bits/stdc++.h>
#define int long long
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> " << endl;
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

char c[N];
int f[N][N][N];
int sum[N], v[N];
int n;

#undef int
int main() {
#define int long long
    read(n); scanf("%s", c + 1);
    for(register int i = 1; i <= n; i++) read(v[i]);
    for(register int i = 2; i <= n; i++) {
        for(register int j = 1; j < i; j++) v[i] = max(v[i], v[j] + v[i - j]);
    }
    for(register int i = 1; i <= n; i++) {
        for(register int j = i + 1; j <= n; j++) sum[i] += (c[i] == c[j]);
    }
    for(register int i = n; i >= 1; i--) {
        for(register int j = i; j <= n; j++) {
            for(register int k = i; k < j; k++) {
                if(c[j] == c[k]) {
                    for(register int t = 0; t <= sum[j]; t++) {
                        f[i][j][t] = max(f[i][j][t], f[k + 1][j - 1][0] + f[i][k][t + 1]);
                    }
                }
            }
            for(register int k = 0; k <= sum[j]; k++) f[i][j][k] = max(f[i][j][k], f[i][j - 1][0] + v[k + 1]);
        }
    }
    cout << f[1][n][0] << endl;
    return 0;
}