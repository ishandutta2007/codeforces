#include <bits/stdc++.h>
#define par pair<int, int>
#define x first
#define y second
#define mp make_pair
#define sz(a) int((a).size())
using namespace std;
typedef double db;
typedef long long i64;
const int N = 1e7 + 10, P = 998244353;
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
	friend void operator += (mint &a, const mint b) {a = a + b; }
	friend void operator -= (mint &a, const mint b) {a = a - b; }
	friend void operator *= (mint &a, const mint b) {a = a * b; }
	friend void operator /= (mint &a, const mint b) {a = a / b; }
} p2[N], fac[N], ifac[N], inv[N];
void initmath(int n) {
	p2[0] = 1;
	for(int i = 1; i <= n + 1; i++) p2[i] = p2[i - 1] * 2;
	fac[0] = 1;
	for(int i = 1; i <= n + 1; i++) fac[i] = fac[i - 1] * (p2[i] - 1);
	ifac[n + 1] = fac[n + 1] ^ (P - 2);
	for(int i = n; i >= 0; i--) ifac[i] = ifac[i + 1] * (p2[i + 1] - 1);
	for(int i = 1; i <= n; i++) inv[i] = ifac[i] * fac[i - 1];
	return;
}
mint qbinom(int n, int m) {
	if(n < m || m < 0) return 0;
	return fac[n] * ifac[m] * ifac[n - m]; 
}

void solve() {
	int n, k, x;
	cin >> n >> k >> x;
	if(x == 0) {
		if(n > k) {
			cout << 0 << endl;
			return;
		}
		mint ans = 1;
		for(int i = 1; i <= n; i++) ans = ans * (p2[k] - p2[i - 1]);
		cout << ans.x << endl;
		return;
	}
	mint ans = 0, prod = 1, b = 1, p = mint(2) ^ n, inv2 = mint(2) ^ (P - 2);
	for(int i = 0; i <= k; i++) {
		if(i) prod = prod * (p2[k] - p2[i]);
		ans += b * prod;
		b = b * (p - 1) * inv[i + 1];
		p = p * inv2;
	}
	cout << ans.x << endl;
	return;
}

int main() {
	initmath(N - 10);
	int t;
	for(cin >> t; t--; solve());
	return 0;
}