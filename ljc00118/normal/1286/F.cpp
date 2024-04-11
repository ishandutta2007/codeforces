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

const int N = 20;

ll a[N], sum[1 << N];
int f[1 << N];
int n, ans;

int main() {
    read(n);
    for (int i = 0; i < n; i++) {
        read(a[i]);
        if (!a[i]) { --i; --n; continue; }
    }
    for (int i = 1; i < (1 << n); i++) {
        int fir = 0, cnt = __builtin_popcount(i) - 1;
        for (int j = 0; j < n; j++) if ((i >> j) & 1) { fir = j; break; }
        sum[i] = sum[i ^ (1 << fir)] + a[fir];
        if ((sum[i] & 1) == (cnt & 1)) {
            for (int s = i ^ (1 << fir); s; s = (s - 1) & (i ^ (1 << fir))) {
                if (abs(sum[s] * 2 - sum[i]) <= cnt) {
                    f[i] = 1;
                    break;
                }
            }
        }
        for (int s = ((i ^ (1 << fir)) - 1) & (i ^ (1 << fir)); s; s = (s - 1) & (i ^ (1 << fir))) f[i] = max(f[i], f[s] + f[i ^ s]);
    }
    print(n - f[(1 << n) - 1], '\n');
    return 0;
}