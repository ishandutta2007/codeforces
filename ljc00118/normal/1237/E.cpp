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

// const int N = 1e6 + 5, INF = 0x7fffffff, md = 998244353;

// inline void add(int &x, int y) {
//     x += y;
//     if(x >= md) x -= md;
// }

// inline int mul(int x, int y) { return 1ll * x * y % md; }

// ll dep[N][2][2], mdep[N];
// int f[N][2][2];
// int n, ans;

int n, a, b;

int main() {
    // memset(dep, 0x3f, sizeof(dep));
    // read(n); f[1][1][1] = f[1][0][0] = 1; dep[1][1][1] = dep[1][0][0] = 0;
    // for(register int i = 2; i <= n; i++) {
    //     mdep[i] = mdep[i / 2] + mdep[i - i / 2 - 1] + i - 1;
    //     for(register int j = 0; j <= 1; j++) {
    //         for(register int k = 0; k <= 1; k++) {
    //             int low = (j == 0) ? 2 : 1;
    //             for(register int t = low; t <= low + i - 1; t++) {
    //                 if((t & 1) == k) {
    //                     ll sum = i - 1; int val = 1;
    //                     if(t != low) sum += dep[t - low][j][k ^ 1], val = mul(val, f[t - low][j][k ^ 1]);
    //                     if(t != low + i - 1) sum += dep[low + i - 1 - t][k ^ 1][k], val = mul(val, f[low + i - 1 - t][k ^ 1][k]);
    //                     dep[i][j][k] = min(dep[i][j][k], sum);
    //                     if(sum == mdep[i]) add(f[i][j][k], val);
    //                 }
    //             }
    //         }
    //     }
    //     if(f[i][1][0] || f[i][1][1]) {
    //         printf("%d : %d\n", i, f[i][1][0] + f[i][1][1]);
    //     }
    // }
    // add(ans, f[n][1][0]); add(ans, f[n][1][1]); print(ans, '\n');
    read(n); a = 1; b = 2;
    while(a <= n) {
        if(n == a || n == b) { print(1, '\n'); return 0; }
        if(b & 1) {
            a = b * 2 - 1; b = b * 2;
        } else {
            a = b * 2; b = b * 2 + 1;
        }
    }
    print(0, '\n');
    return 0;
}