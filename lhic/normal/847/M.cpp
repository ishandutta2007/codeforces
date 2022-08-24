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
int t[1200];

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> t[i];
	int df = t[1] - t[0];
	for (int i = 0; i < n - 1; ++i) {
		if (t[i + 1] - t[i] != df) {
			cout << t[n - 1] << "\n";
			return 0;
		}
	}
	cout << t[n - 1] + df << "\n";
	return 0;
}