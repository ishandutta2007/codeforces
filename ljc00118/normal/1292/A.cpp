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

const int N = 1e5 + 5;

int a[4][N];
int n, q, ans;

int main() {
    read(n); read(q);
    for (int i = 1; i <= q; i++) {
        int x, y; read(x); read(y);
        ans -= (a[x][y] & a[x - 1][y - 1]);
        ans -= (a[x][y] & a[x - 1][y]);
        ans -= (a[x][y] & a[x - 1][y + 1]);
        ans -= (a[x][y] & a[x + 1][y - 1]);
        ans -= (a[x][y] & a[x + 1][y]);
        ans -= (a[x][y] & a[x + 1][y + 1]);
        a[x][y] ^= 1;
        ans += (a[x][y] & a[x - 1][y - 1]);
        ans += (a[x][y] & a[x - 1][y]);
        ans += (a[x][y] & a[x - 1][y + 1]);
        ans += (a[x][y] & a[x + 1][y - 1]);
        ans += (a[x][y] & a[x + 1][y]);
        ans += (a[x][y] & a[x + 1][y + 1]);
        if (ans) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}