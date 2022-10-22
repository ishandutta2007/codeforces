#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;
const int MX = 5e5;

int n, s;
int fact[MX], ifact[MX];
int dp[MX];

// mod
int modpow(int x, int y) {
	if (y == 1) return x;
	if (y == 0) return 1;
	int z = modpow(x, y/2);
	z = z*z%mod;
	if (y&1) z = z*x%mod;
	return z;
}
int inv(int x) {
	return modpow(x, mod-2);
}

// fft
const int root = 646;
const int root_1 = 208611436;
const int root_pw = 1<<20;
void fft(vector<int>& a, bool invert) {
	int n = a.size();
	for (int i=1, j=0; i<n; ++i) {
		int bit = n >> 1;
		for (; j>=bit; bit>>=1)
			j -= bit;
		j += bit;
		if (i < j)
			swap (a[i], a[j]);
	}
	for (int len=1; len<=n; len<<=1) {
		int wlen = invert ? root_1 : root;
		for (int i=len; i<root_pw; i<<=1)
			wlen = wlen * wlen % mod;
		for (int i=0; i<n; i+=len) {
			int w = 1;
			for (int j=0; j<len/2; ++j) {
				int u = a[i+j], v = a[i+j+len/2] * w % mod;
				a[i+j] = u+v < mod ? u+v : u+v-mod;
				a[i+j+len/2] = u-v >= 0 ? u-v : u-v+mod;
				w = w * wlen % mod;
			}
		}
	}
	if (invert) {
		int nrev = inv(n);
		for (int i=0; i<n; ++i)
			a[i] = a[i] * nrev % mod;
	}
}
vector<int> poly_mult(vector<int> a, vector<int> b) {
	int l = 1;
	int sa = a.size(), sb = b.size();
	while (l < sa+sb+1)
		l <<= 1;
	a.resize(l,0); b.resize(l,0);
	fft(a,0); fft(b,0);
	vector<int> c(l,0);
	for (int i=0; i<l; i++)
		c[i] = a[i] * b[i] % mod;
	fft(c, true);
	return c;
}

signed main() {
	fact[0] = 1;
	for (int i=1; i<MX; i++) 
		fact[i] = fact[i-1] * i % mod;
	ifact[MX-1] = inv(fact[MX-1]);
	for (int i=MX-1; i>0; i--)
		ifact[i-1] = ifact[i] * i % mod;
	cin >> n;
	s = (n+1)/2;

	// fft
	vector<int> a(s+1,0);
	for (int i=0; i<s-1; i++)
		a[i] = fact[i];
	vector<int> b(s+1,0);
	for (int i=0; i<s-1; i++)
		b[s-i] = ifact[i];
	vector<int> c = poly_mult(a,b);

	int dpsum = 0;
	for (int i=s; i>=1; i--) {
		dp[i] = 0;
		if (i == 1) {
			dp[i] = fact[n-1];
		} else {
			// sum of j from s to n-i of fact[n - j - 2] / ifact[n - i - j]
			// (n - j - 2) - (n - i - j) + s = s + i - 2
			dp[i] = c[s + i - 2];
			int constFact = fact[n-i] * (i-1) % mod;
			dp[i] = dp[i] * constFact % mod;
		}
		dp[i] = (dp[i] - dpsum * inv(i) % mod + mod) % mod;
		dpsum = (dpsum + dp[i]) % mod;
	}

	for (int i=1; i<=n; i++)
		cout << dp[i] << (i == n ? "" : " ");
	cout << endl;
}