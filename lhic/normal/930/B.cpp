#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

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
vector<int> go[5100];
int cc[26];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> s;
	for (int i = 0; i < s.size(); ++i) {
		go[s[i] - 'a'].push_back(i);
	}
	int n = s.size();
	s = s + s;
	int ans = 0;
	for (int i = 0; i < 26; ++i) {
		int mx = 0;
		for (int j = 0; j < n; ++j) {
			memset(cc, 0, sizeof(cc));
			for (int k: go[i]) {
				++cc[s[k + j] - 'a'];
			}
			int cur = 0;
			for (int i = 0; i < 26; ++i)
				if (cc[i] == 1)
					++cur;
			mx = max(mx, cur);
		}
		ans += mx;
	}
	cout.setf(ios::fixed);
	cout.precision(20);
	cout << ld(ans) / n << "\n";
	return 0;
}