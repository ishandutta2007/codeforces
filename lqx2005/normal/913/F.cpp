#include <bits/stdc++.h>
#define pii pair<int, string>
#define par pair<pii, int>
#define x first
#define y second
#define eb emplace_back
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int N = 3e3 + 10, P = 998244353;
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
int n;
mint coef[N][N], f[N], g[N], h[N], s2[N], p0[N], p1[N];
int main() {
    cin >> n;
    initmath(n);
    s2[0] = 0;
    for(int i = 1; i <= n; i++) s2[i] = s2[i - 1] + i;
    int a, b;
    cin >> a >> b;
    mint p = mint(a) / mint(b);
    p0[0] = p1[0] = 1;
    for(int i = 1; i <= n; i++) p0[i] = p0[i - 1] * p, p1[i] = p1[i - 1] * (1 - p);
    coef[0][0] = 1;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            coef[i + 1][j] += coef[i][j] * p1[j];
            coef[i][j + 1] += coef[i][j] * p0[i];
        }
    }
    for(int i = 1; i <= n; i++) {
        f[i] = 1;
        for(int j = 1; j < i; j++) {
            f[i] -= f[j] * coef[j][i - j];
        }
    }
    h[1] = g[1] = 0;
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j < i; j++) {
            h[i] += (h[i - j] + g[j]) * coef[i - j][j] * f[j];
        }
        g[i] = h[i] + s2[i - 1];
        g[i] /= (1 - f[i]);
        h[i] += g[i] * f[i];
        // cout << g[i].x << endl;
    }
    cout << g[n].x << endl;
    return 0;
}