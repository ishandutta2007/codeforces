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

const int MAXN = 510000;

char ch[MAXN];
ll x[MAXN];

vector<pair<ll, int>> vv;

int gg[MAXN];
int q;

ll fv[MAXN];

void add(int x, ll y) {
	for (; x < vv.size(); x |= (x + 1))
		fv[x] += y;
}

ll get(int x) {
	ll ans = 0;
	for (; x >= 0; x = (x & (x + 1)) - 1)
		ans += fv[x];
	return ans;
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> q;
	for (int i = 0; i < q; ++i) {
		cin >> ch[i] >> x[i];
		if (ch[i] == '+')
			vv.emplace_back(x[i], i);
	}
	sort(vv.begin(), vv.end());
	set<pair<ll, int>> ss;
	set<int> m2;
	for (int i = 0; i < q; ++i) {
		if (ch[i] == '+') {
			int p = lower_bound(ALL(vv), make_pair(x[i], i)) - vv.begin();
			gg[i] = p;
			add(p, x[i]);
			auto it = ss.emplace(x[i], i).first;
			if (it != ss.begin()) {
				if (prev(it)->first * 2 < x[i])
					m2.insert(p);
			}
			auto it2 = next(it);
			if (it2 != ss.end()) {
				if (x[i] * 2 < it2->first) {
					m2.emplace(gg[it2->second]);
				}
				else {
					m2.erase(gg[it2->second]);
				}
			}
		}
		else {
			auto it = ss.lower_bound(make_pair(x[i], 0));
			int p = gg[it->second];
			add(p, -x[i]);
			m2.erase(p);
			ss.erase(it++);
			if (it != ss.end()) {
				if (it != ss.begin() && prev(it)->first * 2 < it->first)
					m2.insert(gg[it->second]);
				else
					m2.erase(gg[it->second]);
			}
		}
		int now = (int)ss.size();
		if (now == 0) {
			cout << 0 << "\n";
			continue;
		}
		--now;
		for (auto p: m2) {
			if (vv[p].first > 2 * get(p - 1))
				--now;
		}
		cout << now << "\n";
	}
	return 0;
}