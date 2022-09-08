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

const int md = 998244353;

inline int fpow(int x, int y) {
    int ans = 1;
    while (y) {
        if (y & 1) ans = 1ll * ans * x % md;
        y >>= 1; x = 1ll * x * x % md;
    }
    return ans;
}

vector <ll> primes;
ll D;
int fac[65], inv[65];
int q;

// inline int C(int n, int m) { return 1ll * fac[n] * inv[m] % md * inv[n - m] % md; }

int main() {
    fac[0] = 1;
    for (int i = 1; i <= 60; i++) fac[i] = 1ll * fac[i - 1] * i % md;
    inv[60] = fpow(fac[60], md - 2);
    for (int i = 60; i >= 1; i--) inv[i - 1] = 1ll * inv[i] * i % md;
    read(D);
    for (int i = 2; 1ll * i * i <= D; i++) {
        if (D % i == 0) {
            primes.push_back(i);
            while (D % i == 0) D /= i;
        }
    }
    if (D != 1) primes.push_back(D);
    read(q);
    while (q--) {
        ll u, v;
        read(u); read(v);
        if (u == v) {
            print(1, '\n');
            continue;
        }
        if (u > v) swap(u, v);
        int ans = 1, sum1 = 0, sum2 = 0;
        for (int i = 0; i < (int)primes.size(); i++) {
            int now1 = 0, now2 = 0;
            while (u % primes[i] == 0) u /= primes[i], ++now1;
            while (v % primes[i] == 0) v /= primes[i], ++now2;
            if (now1 > now2) {
                sum1 += (now1 - now2);
                ans = 1ll * ans * inv[now1 - now2] % md;
            } else if (now1 < now2) {
                sum2 += (now2 - now1);
                ans = 1ll * ans * inv[now2 - now1] % md;
            }
        }
        ans = 1ll * ans * fac[sum1] % md * fac[sum2] % md;
        print(ans, '\n');
    }
    return 0;
}