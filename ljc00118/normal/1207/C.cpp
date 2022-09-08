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
 
const ll INF = 0x7ffffffffffffff;
const int N = 2e5 + 5;
 
ll f[N][3];
char c[N];
int T, n, a, b;
 
int main() {
    read(T);
    while(T--) {
        read(n); read(a); read(b); scanf("%s", c + 1);
        f[1][1] = a + 2ll * b; f[1][2] = 2ll * a + 3ll * b;
        for(register int i = 2; i <= n; i++) {
            if(c[i] == '1') f[i][1] = INF, f[i][2] = f[i - 1][2] + a + 2 * b;
            else f[i][1] = min(f[i - 1][2] + 2 * a, f[i - 1][1] + a) + b, f[i][2] = min(f[i - 1][2] + a, f[i - 1][1] + 2 * a) + 2 * b;;
            // cout << f[i][1] << " " << f[i][2] << endl;
        }
        print(f[n][1], '\n');
    }
    return 0;
}