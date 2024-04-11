#include <bits/stdc++.h>
#define x first
#define y second
#define sz(a) int((a).size())
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
using namespace std;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef long long ll;
typedef double db;
const int N = 1e6 + 10, P = 1e9 + 7;
int t, n, m, k;
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
}fac[N], ifac[N], inv[N];
void initmath(int n) {
    inv[1] = fac[0] = ifac[0] = 1;
    for(int i = 2; i <= n; i++) inv[i] = inv[P % i] * (P - P / i);
    for(int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i, ifac[i] = ifac[i - 1] * inv[i];
    return;
}
mint binom(int n, int m) {return n < m || m < 0 ? 0 : fac[n] * ifac[m] * ifac[n - m]; }
void solve() {
	cin >> n >> m >> k;
	mint ans = 0;
	for(int i = 1; i <= m; i++) ans += binom(n - i - 1, n - m - 1) * k * i / (mint(2) ^ (n - i));
	if(n == m) ans += mint(k) * m;
	cout << ans.x << endl;
	return;
}
int main() {
	initmath(N - 10);
	cin >> t;
	for(; t--; solve());
	return 0;
}