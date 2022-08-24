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

string s;
int n;
vector<int> go[30];

int solve(int k) {
	int ans = go[k][0] + 1;
	for (int i = 1; i < go[k].size(); ++i) {
		ans = max(ans, go[k][i] - go[k][i - 1]);
	}
	ans = max(ans, n - go[k].back());
	return ans;
}

int main() {
	cin >> s;
	n = s.size();
	for (int i = 0; i < n; ++i) {
		go[s[i] - 'a'].push_back(i);
	}
	int ans = n;
	for (int i = 0; i < 26; ++i)
		if (!go[i].empty())
			ans = min(ans, solve(i));
	cout << ans << "\n";
	return 0;
}