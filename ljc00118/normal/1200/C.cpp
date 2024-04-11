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
 
ll n, m, d;
int q;
 
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
 
int main() {
    read(n); read(m); read(q); d = gcd(n, m); n /= d; m /= d;
    while(q--) {
        ll a, b, c, d;
        read(a); read(b); read(c); read(d);
        ll A = (a == 1 ? (b - 1) / n + 1 : (b - 1) / m + 1);
        ll B = (c == 1 ? (d - 1) / n + 1 : (d - 1) / m + 1);
        if(A == B) printf("YES\n"); else printf("NO\n");
    }
    return 0;
}