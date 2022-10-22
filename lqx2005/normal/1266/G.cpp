#include <bits/stdc++.h>
#define x first
#define y second
#define eb emplace_back
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int N = 2e6 + 10, P = 998244353;
int n;
struct mint {
    int x;
    mint() {x = 0; }
    mint(int _x) {x = _x; }
    friend mint operator + (const mint a, const mint b) {return (a.x + b.x) % P; }
    friend mint operator - (const mint a, const mint b) {return (a.x - b.x + P) % P; }
    friend mint operator * (const mint a, const mint b) {return 1ll * a.x * b.x % P; }
    friend mint operator ^ (mint a, int b) {
        mint c(1);
        for(; b; b >>= 1, a = a * a) if(b & 1) c = c * a;
        return c;
    }
    friend mint operator / (mint a, mint b) {return a * (b ^ (P - 2)); }
    friend mint &operator += (mint &a, const mint b) {return a = a + b; }
    friend mint &operator -= (mint &a, const mint b) {return a = a - b; }
    friend mint &operator *= (mint &a, const mint b) {return a = a * b; }
    friend mint &operator /= (mint &a, const mint b) {return a = a / b; }
} fac[N], ifac[N], inv[N];
void initmath(int n) {
    inv[1] = fac[0] = ifac[0] = 1;
    for(int i = 2; i <= n; i++) inv[i] = inv[P % i] * (P - P / i);
    for(int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i, ifac[i] = ifac[i - 1] * inv[i];
    return;
}
mint binom(int n, int m) {return n < m || m < 0 ? 0 : fac[n] * ifac[m] * ifac[n - m]; }
mint c[N];
int main() {
    cin >> n;
    initmath(n);
    mint p = 1;
    for(int i = 1; i <= n; i++) p = p * i;
    p *= n;
    mint ans = p * (p + 1) / 2;
    c[0] = n;
    for(int i = 1; i < n; i++) c[i] = fac[n] * ifac[n - i + 1] * (mint(n - i) * (n - i) + 1);
    for(int i = n; i < 2 * n; i++) c[i] = fac[n] - c[i - n];
    for(int i = 1; i < 2 * n; i++) ans -= c[i] * i;
    // for(int i = 0; i < 2 * n; i++) cout << c[i].x << endl;
    cout << ans.x << endl;
    return 0;
}