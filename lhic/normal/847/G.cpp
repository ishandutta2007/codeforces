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
int cc[100];

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < 7; ++j) {
			if (s[j] == '1')
				++cc[j];
		}
	}
	int ans = 0;
	for (int i = 0; i < 7; ++i)
		ans = max(ans, cc[i]);
	cout << ans << "\n";
	return 0;
}