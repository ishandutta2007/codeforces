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
 
ll a, b, c, d;
int n;
 
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
 
int main() {
    read(n); read(a); read(b); read(c); read(d);
    if (!a && !c) {
        printf("NO\n");
        return 0;
    }
    if (!b && !d) {
        printf("NO\n");
        return 0;
    }
    if (!a && !b) {
        printf("NO\n");
        return 0;   
    }
    if (!c && !d) {
        printf("NO\n");
        return 0;
    }
    ll x, y;
    if (!a) {
        y = abs(b);
    } else if (!c) {
        y = abs(d);
    } else {
        ll tmp = 1ll * abs(a) * abs(c) / gcd(abs(a), abs(c));
        y = abs(b * tmp / a - d * tmp / c);
    }
    if (!b) {
        x = abs(a);
    } else if (!d) {
        x = abs(c);
    } else {
        ll tmp = 1ll * abs(b) * abs(d) / gcd(abs(b), abs(d));
        x = abs(a * tmp / b - c * tmp / d);
    }
    if (!x || !y) {
        printf("NO\n");
        return 0;
    }
    x = gcd(abs(a), abs(c));
    if (x > n || y > n || x * y != n) {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            print(i, ' '); print(j, '\n');
        }
    }
    return 0;
}