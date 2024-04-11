#include <bits/stdc++.h>
 
typedef long long ll;
typedef long long llong;
typedef long double ld;
typedef unsigned long long ull;
 
using namespace std;
 
/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/
 
int n;
 
ll a[1200][10];
 
int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 5; ++j)
			cin >> a[i][j];
	}
	if (n > 100) {
		cout << 0 << "\n";
		return 0;
	}
	vector<int> ans;
	for (int i = 0; i < n; ++i) {
		int fl = 0;
		for (int j = 0; j < n; ++j)
			for (int k = 0; k < n; ++k) {
				if (j == i || k == i || k == j)
					continue;
				ll sum = 0;
				for (int l = 0; l < 5; ++l)
					sum += (a[j][l] - a[i][l]) * (a[k][l] - a[i][l]);
				if (sum > 0)
					fl = 1;
			}
		if (!fl)
			ans.push_back(i);
	}
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i] + 1 << " ";
	cout << "\n";
	return 0;
}