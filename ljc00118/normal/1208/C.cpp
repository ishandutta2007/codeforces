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

const int N = 2005;

int a[N][N];
int n, tot = -1;

int main() {
    read(n);
    for(register int i = 1; i <= n; i += 4) {
        for(register int j = 1; j <= n; j += 4) {
            for(register int x = i; x <= i + 3; x++) {
                for(register int y = j; y <= j + 3; y++) {
                    a[x][y] = ++tot;
                }
            }
        }
    }
    for(register int i = 1; i <= n; i++) {
        for(register int j = 1; j <= n; j++) {
            print(a[i][j], j == n ? '\n' : ' ');
        }
    }
    // for(register int i = 1; i <= n; i++) {
    //     int sum = 0;
    //     for(register int j = 1; j <= n; j++) {
    //         sum ^= a[i][j];
    //     }
    //     if(sum) {
    //         fprintf(stderr, "%d\n", sum);
    //     }
    //     sum = 0;
    //     for(register int j = 1; j <= n; j++) {
    //         sum ^= a[j][i];
    //     }
    //     if(sum) {
    //         fprintf(stderr, "%d\n", sum);
    //     }
    // }
    return 0;
}