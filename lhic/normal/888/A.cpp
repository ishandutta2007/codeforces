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
int a[1200];

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	int ans = 0;
	for (int i = 1; i < n - 1; ++i) {
		if (a[i] > a[i - 1] && a[i] > a[i + 1])
			++ans;
		if (a[i] < a[i - 1] && a[i] < a[i + 1])
			++ans;
	}
	cout << ans << "\n";
	return 0;
}