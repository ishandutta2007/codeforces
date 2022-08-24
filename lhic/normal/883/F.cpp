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

int main() {
	int n;
	cin >> n;
	set<string> kek;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		string t;
		for (char c : s) {
			if (c == 'h') {
				while (!t.empty() && t.back() == 'k') t.pop_back();
				t += 'h';
			} else if (c == 'u') {
				t += "oo";
			} else {
				t += c;
			}
		}
		kek.insert(t);
	}
	cout << kek.size() << endl;
	return 0;
}