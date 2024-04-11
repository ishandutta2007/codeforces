#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 9;

int n, a, b, k;
string s;

int fpow(int x,int n) {
	int ans = 1;
	while(n) {
		if (n & 1) ans = ans * x % mod;
		x = x * x % mod;
		n >>= 1;
	}
	return ans;
}

signed main() {
	ios_base::sync_with_stdio(false);	cin.tie(0);
	cin >> n >> a >> b >> k >> s;
	int ans = 0;
	for (int i = 0;i < k;++i) {
		if (s[i] == '+') ans = (ans + fpow(b,i) * fpow(a,n - i)) % mod;
		else ans = ((ans - fpow(b, i) * fpow(a,n - i)) % mod + mod) % mod;
	}
	int tmp = fpow(b, k) * fpow(a, mod - 1 - k) % mod;
	int deg = (n + 1) / k;
	int mul;
	if (tmp == 1) mul = deg;
	else {
		int up = (fpow(tmp,deg) - 1 + mod) % mod;
		int down = tmp - 1;
		mul = up * fpow(down, mod - 2) % mod;
	} 
	ans = ans * mul % mod;
	cout << ans;
}