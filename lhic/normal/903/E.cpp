#ifndef LOCAL
#pragma GCC optimize "-O3"
#endif
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

int k, n;
int fl;
int gc[100];
int cc[100];
string s[3000];

void check(const string &t) {
	for (int i = 0; i < k; ++i) {
		int cc = 0;
		for (int j = 0; j < n; ++j)
			cc += (t[j] != s[i][j]);
		if (!(cc == 2 || (cc == 0 && fl)))
			return;
	}
	cout << t << "\n";
	exit(0);
}

int main() {
	cin >> k >> n;
	for (int i = 0; i < k; ++i)
		cin >> s[i];
	sort(s, s + k);
	k = unique(s, s + k) - s;
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < 26; ++j)
			cc[j] = 0;
		for (int j = 0; j < n; ++j)
			++cc[s[i][j] - 'a'];
		if (i == 0) {
			for (int j = 0; j < 26; ++j) {
				gc[j] = cc[j];
				if (cc[j] > 1)
					fl = 1;
			}
		}
		else {
			for (int j = 0; j < 26; ++j) {
				if (cc[j] != gc[j]) {
					cout << -1 << "\n";
					return 0;
				}
			}
		}
	}
	if (k == 1) {
		swap(s[0][0], s[0][1]);
		cout << s[0] << "\n";
		return 0;
	}
	check(s[0]);
	vector<int> vv;
	for (int i = 0; i < n; ++i) {
		if (s[0][i] != s[1][i])
			vv.push_back(i);
	}
	string t = s[0];
	if (vv.size() == 2) {
		for (int i: vv) {
			for (int j = 0; j < n; ++j) {
				if (i == j)
					continue;
				swap(t[i], t[j]);
				check(t);
				swap(t[i], t[j]);
			}
		}
	}
	else {
		for (int i: vv) {
			for (int j: vv) {
				if (i >= j)
					continue;
				swap(t[i], t[j]);
				check(t);
				swap(t[i], t[j]);
			}
		}
	}
	cout << -1 << "\n";
	return 0;
}