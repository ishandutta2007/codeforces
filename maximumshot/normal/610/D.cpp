#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <set>
#include <string>
#include <tuple>
#include <fstream>
#include <stdio.h>
#include <cstring>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;

const int inf = 1000000000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);

vec< pii > f(vec< pii > a) {
	sort(ALL(a));
	
	int l, r;
	tie(l, r) = a[0];

	vec< pii > ans;

	for(int i = 1;i < (int)a.size();i++) {
		if(a[i].first <= r) r = max(r, a[i].second);
		else ans.push_back(mp(l, r)), tie(l, r) = a[i];
	}

	ans.push_back(mp(l, r));

	return ans;
}

struct fen {
	int n;
	vec< int > t;

	fen() {
		n = 0;
		t.clear();
	}

	fen(int _n) {
		n = _n;
		t.resize(n);
	}

	void add(int l, int r) {
		for(int i = l;i < n;i = i | (i + 1)) t[i]++;
		for(int i = r + 1;i < n;i = i | (i + 1)) t[i]--;
	}

	int get(int p) {
		int ans = 0;
		for(int i = p;i >= 0;i = (i & (i + 1)) - 1) ans += t[i];
		return ans;
	}
};

bool solve() {

	int n;

	cin >> n;

	vec< pair< pii, pii > > _ver, _hor;
	vec< vec< pii > > ver, hor, points;
	vec< int > crd;

	for(int i = 0;i < n;i++) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		crd.push_back(x1);
		crd.push_back(y1);
		crd.push_back(x2);
		crd.push_back(y2);
		if(x1 == x2) {
			if(y1 > y2) swap(y1, y2);
			_ver.push_back(mp(mp(x1, y1), mp(x2, y2)));
		}else { // y1 == y2
			if(x1 > x2) swap(x1, x2);
			_hor.push_back(mp(mp(x1, y1), mp(x2, y2)));
		}
	}

	sort(ALL(crd));
	crd.resize(unique(ALL(crd)) - crd.begin());
	int sz = (int)crd.size();

	fen F(sz);

	hor.resize(sz);
	ver.resize(sz);
	points.resize(sz);

	for(auto i : _hor) {
		int p = lower_bound(ALL(crd), i.first.second) - crd.begin();
		hor[p].push_back(mp(i.first.first, i.second.first));
	}
	
	for(auto i : _ver) {
		int p = lower_bound(ALL(crd), i.first.first) - crd.begin();
		ver[p].push_back(mp(i.first.second, i.second.second));
	}
	
	ll ans = 0;

	for(int i = 0;i < sz;i++) {
		if(!hor[i].empty()) hor[i] = f(hor[i]);
		if(!ver[i].empty()) ver[i] = f(ver[i]);

		for(auto j : hor[i]) {
			ans += j.second - j.first + 1;
		}
		for(auto j : ver[i]) {
			ans += j.second - j.first + 1;
		}
	}

	for(int j = 0;j < sz;j++) {
		for(auto i : ver[j]) { 
			int p;
			p = lower_bound(ALL(crd), i.first) - crd.begin();
			points[p].push_back(mp(j, 1));
			p = lower_bound(ALL(crd), i.second) - crd.begin();
			points[p].push_back(mp(j, -1));
		}
	}

	for(int i = 0;i < sz;i++) {
		for(auto j : points[i]) {
			if(j.second == -1) continue;
			int x = j.first;
			ans += F.get(x);
		}
		for(auto j : hor[i]) {
			int l, r;
			tie(l, r) = j;
			l = lower_bound(ALL(crd), l) - crd.begin();
			r = lower_bound(ALL(crd), r) - crd.begin();
			F.add(l, r);
		}
		for(auto j : points[i]) {
			if(j.second == 1) continue;
			int x = j.first;
			ans -= F.get(x);
		}
	}

	cout << ans << '\n';

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}