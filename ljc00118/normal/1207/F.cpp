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
 
const int N = 5e5 + 5, n = 5e5, B = 1005, sqr = 707;
 
int a[N], f[B][B];
int q, ans;
 
int main() {
    read(q); while(q--) {
        int opt, x, y;
        read(opt); read(x); read(y);
        if(opt == 1) {
            a[x] += y;
            for(register int i = 1; i <= sqr; i++) f[i][x % i] += y;
        }
        if(opt == 2) {
            if(x <= sqr) print(f[x][y], '\n');
            else {
                ans = 0;
                for(register int i = y; i <= n; i += x) ans += a[i];
                print(ans, '\n');
            }
        }
    }
    return 0;
}