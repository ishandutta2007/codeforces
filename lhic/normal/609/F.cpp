#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef double ld;

using namespace std;

const int MAXN = 300000;

multiset<pair<ll, ll> > fr;
set<pair<ll, int> > ss;
int ans[MAXN];
ll t[MAXN];
ll x[MAXN];

int n, m;
vector<pair<ll, int> > vv;


void add(int a, ll l) {
	++ans[a];
	ll ol = x[a] + t[a];
	t[a] += l;
	ll nl = x[a] + t[a];
	ss.erase(make_pair(ol, a));
	while (true) {
		auto it = ss.lower_bound(make_pair(ol, 0));
		if (it == ss.end() || it->first > nl)
			break;
		ss.erase(it);
	}
	ss.insert(make_pair(nl, a));
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%lld%lld", x + i, t + i);
	for (int i = 0; i < n; ++i)
		vv.push_back(make_pair(x[i], i));
	sort(vv.begin(), vv.end());
	ll lst = -1;
	for (int i = 0; i < n; ++i) {
		int xx = vv[i].second;
		if (x[xx] + t[xx] <= lst)
			continue;
		ss.insert(make_pair(x[xx] + t[xx], xx));
		lst = x[xx] + t[xx];
	}
	for (int i = 0; i < m; ++i) {
		ll p, b;
		scanf("%lld%lld", &p, &b);
		auto it = ss.lower_bound(make_pair(p, 0));
		if (it == ss.end()) {
			fr.insert(make_pair(p, b));
			continue;
		}
		int xx = it->second;
		if (x[xx] > p) {
			fr.insert(make_pair(p, b));
			continue;
		}
		add(xx, b);
		while (true) {
			auto it = fr.lower_bound(make_pair(x[xx], 0));
			if (it == fr.end() || it->first > x[xx] + t[xx])
				break;
			add(xx, it->second);
			fr.erase(it);
		}
	}
	for (int i = 0; i < n; ++i) {
		printf("%d %lld\n", ans[i], t[i]);
	}
	return 0;
}