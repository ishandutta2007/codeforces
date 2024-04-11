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

int q;

vector<int> vv;
map<int, int> mm;
vector<int> p;
vector<int> ad;
vector<int> sz;

int getcc(int x) {
	if (mm.count(x)) {
		return mm[x];
	}
	else {
		int cc = vv.size();
		vv.push_back(x);
		mm[x] = cc;
		p.push_back(cc);
		sz.push_back(1);
		ad.push_back(0);
		return cc;
	}
}

pair<int, int> get(int x) {
	if (p[x] == x)
		return {x, 0};
	auto a = get(p[x]);
	a.second ^= ad[x];
	return a;
}


int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> q;
	int last = 0;
	for (int i = 0; i < q; ++i) {
		int t;
		cin >> t;
		if (t == 1) {
			int l, r, x;
			cin >> l >> r >> x;
			l = l ^ last, r = r ^ last, x = x ^ last;
			if (l > r)
				swap(l, r);
			++r;
			l = getcc(l);
			r = getcc(r);
			auto a = get(l);
			auto b = get(r);
			if (a.first != b.first) {
				x = x ^ a.second ^ b.second;
				l = a.first;
				r = b.first;
				if (sz[l] > sz[r])
					swap(l, r);
				p[l] = r;
				ad[l] = x;
				sz[r] += sz[l];
			}
		}
		else {
			int l, r;
			cin >> l >> r;
			l ^= last;
			r ^= last;
			if (l > r)
				swap(l, r);
			++r;
			l = getcc(l);
			r = getcc(r);
			auto a = get(l);
			auto b = get(r);
			if (a.first != b.first) {
				cout << -1 << "\n";
				last = 1;
			}
			else {
				last = a.second ^ b.second;
				cout << last << "\n";
			}
		}
	}
	return 0;
}