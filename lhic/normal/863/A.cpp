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

void check(ll x) {
	vector<int> vv;
	while (x) {
		vv.push_back(x % 10);
		x /= 10;
	}
	auto tmp = vv;
	reverse(tmp.begin(), tmp.end());
	if (vv == tmp) {
		cout << "YES\n";
		exit(0);
	}
}

int main() {
	ll x;
	cin >> x;
	check(x);
	while (x % 10 == 0) {
		x /= 10;
		check(x);
	}
	cout << "NO\n";
	return 0;
}