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


int n, m;

set<int> ss;
set<int> a1[100], a2[100];

vector<pair<int, int> > v1, v2;

int cr(pair<int, int> a, pair<int, int> b) {
	if (a == b)
		return -1;
	if (a.first == b.first)
		return a.first;
	if (a.first == b.second)
		return a.first;
	if (a.second == b.first)
		return a.second;
	if (a.second == b.second)
		return a.second;
	return -1;
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		if (a > b)
			swap(a, b);
		v1.emplace_back(a, b);
	}
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		if (a > b)
			swap(a, b);
		v2.emplace_back(a, b);
	}
	for (int i = 0; i < v1.size(); ++i) {
		for (int j = 0; j < v2.size(); ++j) {
			int x = cr(v1[i], v2[j]);
			if (x == -1)
				continue;
			a1[i].insert(x);
			ss.insert(x);
		}
		if (a1[i].size() >= 2) {
			cout << -1 << "\n";
			return 0;
		}
	}
	for (int i = 0; i < v2.size(); ++i) {
		for (int j = 0; j < v1.size(); ++j) {
			int x = cr(v2[i], v1[j]);
			if (x == -1)
				continue;
			a2[i].insert(x);
		}
		if (a2[i].size() >= 2) {
			cout << -1 << "\n";
			return 0;
		}
	}
	if (ss.size() == 1) {
		cout << *ss.begin() << "\n";
	}
	else {
		cout << 0 << "\n";
	}
	return 0;
}