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
 
const int N = 3e5 + 5, md = 998244353;
 
inline int add(int x, int y) {
    x += y;
    if(x >= md) x -= md;
    return x;
}
 
inline int sub(int x, int y) {
    x -= y;
    if(x < 0) x += md;
    return x;
}
 
inline int mul(int x, int y) { return 1ll * x * y % md; }
 
struct ele {
    int x, y;
    ele (int a = 0, int b = 0) : x(a), y(b) {}
    bool operator < (const ele A) const {
        if(x == A.x) return y < A.y;
        return x < A.x;
    }
} a[N];
 
int t[N], fac[N];
int n, ans;
 
int solve() {
    int res = 1;
    sort(t + 1, t + n + 1);
    for(register int l = 1, r; l <= n; l = r + 1) {
        r = l;
        while(t[r + 1] == t[l]) ++r;
        res = mul(res, fac[r - l + 1]);
    }
    return res;
}
 
int main() {
    read(n); fac[0] = 1;
    for(register int i = 1; i <= n; i++) read(a[i].x), read(a[i].y), fac[i] = mul(fac[i - 1], i);
    ans = fac[n];
    for(register int i = 1; i <= n; i++) t[i] = a[i].x;
    ans = sub(ans, solve());
    for(register int i = 1; i <= n; i++) t[i] = a[i].y;
    ans = sub(ans, solve());
    sort(a + 1, a + n + 1);
    for(register int i = 1; i < n; i++) {
        if(a[i].y > a[i + 1].y) {
            print(ans, '\n');
            return 0;
        }
    }
    int res = 1;
    for(register int l = 1, r; l <= n; l = r + 1) {
        r = l;
        while(a[r + 1].x == a[l].x && a[r + 1].y == a[l].y) ++r;
        res = mul(res, fac[r - l + 1]);
    }
    print(add(ans, res), '\n');
    return 0;
}