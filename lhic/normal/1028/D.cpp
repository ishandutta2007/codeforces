#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO
#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

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

const ll MOD = 1e9 + 7;

int n;
set<int> ss;

set<int> buy;
set<int> sell;

void no() {
	cout << 0 << "\n";
	exit(0);
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	ll ans = 1;
	for (int i = 0; i < n; ++i) {
		string s;
		int p;
		cin >> s >> p;
		if (s.size() == 3) {
			if (!buy.empty() && *buy.rbegin() >= p) {
				buy.insert(p);
			}
			else if (!sell.empty() && *sell.begin() <= p) {
				sell.insert(p);
			}
			else {
				ss.insert(p);
			}
		}
		else {
			if (!buy.empty() && *buy.rbegin() > p)
				no();
			if (!sell.empty() && *sell.begin() < p)
				no();
			if (buy.count(p)) {
				buy.erase(p);
				for (int x: ss)
					sell.insert(x);
				ss.clear();
			}
			else if (sell.count(p)) {
				sell.erase(p);
				for (int x: ss)
					buy.insert(x);
				ss.clear();
			}
			else {
				ss.erase(p);
				ans = (ans * 2) % MOD;
				for (int x: ss) {
					if (x < p)
						buy.insert(x);
					else
						sell.insert(x);
				}
				ss.clear();
			}
		}
	}
	ans = (ans * (ss.size() + 1)) % MOD;
	cout << ans << "\n";
	return 0;
}