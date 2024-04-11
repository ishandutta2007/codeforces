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

const int N = 1005;

int a[N][N], ans[N];
int n;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int calc(int pos) {
    int x, y;
    if(pos == 1) x = 2, y = 3;
    else if(pos == 2) x = 1, y = 3;
    else x = 1, y = 2;
    int _x = a[x][pos], _y = a[x][y], d = gcd(_x, _y);
    _x /= d, _y /= d;
    return floor(sqrt(a[pos][y] / _x / _y + 0.5)) * _x;
}

int main() {
    read(n);
    for(register int i = 1; i <= n; i++) {
        for(register int j = 1; j <= n; j++) {
            read(a[i][j]);
        }
    }
    for(register int i = 1; i <= n; i++) print(calc(i), i == n ? '\n' : ' ');
    return 0;
}