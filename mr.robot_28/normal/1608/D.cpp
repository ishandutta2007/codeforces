#include <bits/stdc++.h>
using namespace std;
#define x first
#define int long long
#define y second
#define sz(a) (int)a.size()
const int N = 3e5 + 100;
const int mod = 998244353;

int pow2[N];
int fact[N], ifact[N];

int power(int a, int b) {
	if (b == 0) {
		return 1;
	}
	if (b % 2 == 0) {
		int t = power(a, b / 2);
		return 1LL * t * t % mod;
	}
	return 1LL * a * power(a, b - 1) % mod;
} 

int cnk(int n, int k) {
	return 1LL * fact[n] * ifact[k] % mod * ifact[n - k] % mod; 
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	pow2[0] = 1;
	fact[0] = 1;
	for (int i = 1; i < N; i++) {
		fact[i] = 1LL * i * fact[i - 1] % mod;
		pow2[i] = 1LL * pow2[i - 1] * 2 % mod;
	}
	ifact[N - 1] = power(fact[N - 1], mod - 2);
	for (int i = N - 2; i >= 0; i--) {
		ifact[i] = 1LL * ifact[i + 1] * (i + 1) % mod;
	}
	int n;
	cin >> n;
	int fl1 = 1, fl2 = 1;
	int ans = 0;
	int pw = 1;
	int w = 0, b = 0;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s[0] == 'W') {
			w++;
		}
		else if (s[0] == 'B') {
			b++;
		}
		if (s[1] == 'W') {
			w++;
		}
		else if (s[1] == 'B') {
			b++;
		}
		if (s[0] == 'B' || s[1] == 'W') {
			fl1 = 0;
		}
		if (s[0] == 'W' || s[1] == 'B') {
			fl2 = 0;
		}
		int coun = 0;
		if ((s[0] == '?' || s[0] == 'W') && (s[1] == '?' || s[1] == 'B')) {
			coun++;
		}
		if ((s[0] == '?' || s[0] == 'B') && (s[1] == '?' || s[1] == 'W')) {
			coun++;
		}
		pw = 1LL * pw * coun % mod;
	}
	//cout << fl1 << " " << fl2 << " " << pw << "\n";
	ans = (ans + fl1 + fl2) % mod;
	ans = (ans + mod - pw) % mod;
	if (max(b, w) <= n) {
		ans = (ans + cnk(n * 2 - b - w, n - b)) % mod;
	}
	cout << ans;
	return 0;
}