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
set<string> ss;

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		if (ss.count(s))
			cout << "YES\n";
		else
			cout << "NO\n";
		ss.insert(s);
	}
	return 0;
}