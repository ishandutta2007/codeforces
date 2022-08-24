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
int a[120];
int ba[120];
int bb[120];

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	reverse(a, a + n);
	ba[0] = 0;
	bb[0] = 0;
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		ba[i + 1] = max(ba[i], a[i] + (sum - bb[i]));
		bb[i + 1] = max(bb[i], a[i] + (sum - ba[i]));
		sum += a[i];
	}
	cout << sum - bb[n] << " " << bb[n] << "\n";
	return 0;
}