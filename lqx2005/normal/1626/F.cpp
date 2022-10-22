#include<bits/stdc++.h>

using namespace std;
const int P = 12252240, mod = 998244353;
int n, a[P], x, y, k, M;
int c0[P], c1[P];
int power(int a, int b, int c = 1) {
	for(; b; b >>= 1, a = 1ll * a * a % mod) if(b & 1) c = 1ll * c * a % mod;
	return c;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> a[0] >> x >> y >> k >> M;
	for(int i = 1; i < n; i++) a[i] = (1ll * a[i - 1] * x % M + y) % M;
	int ans = 0;
	int pn = power(n, k - 1);
	for(int i = 0; i < n; i++) (ans += 1ll * a[i] / P * P * pn % mod) %= mod;
	ans = 1ll * ans * k % mod;
	for(int i = 0; i < n; i++) c0[a[i] % P]++;
	for(int i = 1; i <= k; i++) {
		for(int j = 0; j < P; j++) {
			if(j % i) {
				(c0[j - j % i] += c0[j]) %= mod;
				(c1[j - j % i] += c1[j]) %= mod;
				(c1[j - j % i] += 1ll * c0[j] * j % mod) %= mod;
				c0[j] = 1ll * c0[j] * (n - 1) % mod;
				c1[j] = 1ll * c1[j] * (n - 1) % mod;
			} else {
				(c1[j] += 1ll * c1[j] * (n - 1) % mod) %= mod;
				(c1[j] += 1ll * c0[j] * j % mod) %= mod;
				(c0[j] += 1ll * c0[j] * (n - 1) % mod) %= mod;
			}
		}
	}
	for(int i = 0; i < P; i++) (ans += c1[i]) %= mod;
	cout << ans << endl;
	return 0;
}