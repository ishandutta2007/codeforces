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
#include <map>
#include <queue>

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

struct segment_tree {
	int n;
	vec< int > t;

	segment_tree(int _n) {
		n = _n;
		t.resize(4 * n, -1);
	}

	void upd(int v, int tl, int tr, int pos, int value) {
		if(tl == tr) t[v] = max(t[v], value);
		else {
			int tm = (tl + tr) / 2;
			if(pos <= tm) upd(v * 2 + 1, tl, tm, pos, value);
			else upd(v * 2 + 2, tm + 1, tr, pos, value);
			t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
		}
	}

	void upd(int pos, int value) {
		upd(0, 0, n - 1, pos, value);
	}

	int get(int v, int tl, int tr, int l, int r) {
		if(l <= tl && tr <= r) return t[v];
		else {
			int tm = (tl + tr) / 2, ans = -1;
			if(l <= tm) ans = max(ans, get(v * 2 + 1, tl, tm, l, r));
			if(r > tm) ans = max(ans, get(v * 2 + 2, tm + 1, tr, l, r));
			t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
			return ans;
		}
	}

	int get(int l, int r) {
		return get(0, 0, n - 1, l, r);
	}
};

int bp(const vec< int > & a, int x) {
	if(a.empty()) return -1;
	int bl, br, bm;
	bl = 0, br = (int)a.size() - 1;
	while(br - bl > 1) {
		bm = (bl + br) / 2;
		if(a[bm] >= x) br = bm;
		else bl = bm + 1;
	}
	return (a[bl] == x?bl : (a[br] == x?br : -1));
}

bool solve() {

	int n, k;

	scanf("%d %d", &n, &k);

	vec< int > crd;
	vec< pii > a(n);
	vec< int > age(n), otv(n);

	for(int i = 0;i < n;i++) scanf("%d", &a[i].first), otv[i] = a[i].first;
	for(int i = 0;i < n;i++) scanf("%d", &a[i].second), crd.push_back(a[i].second), age[i] = a[i].second;

	sort(ALL(crd));
	crd.resize(unique(ALL(crd)) - crd.begin());
	int sz = (int)crd.size();

	sort(ALL(a));

	vec< int > boss(n), c(sz);

	for(int i = 0;i < n;i++) {
	
		int it = i;
		while(it < n && a[i].first == a[it].first) it++; it--;
		
		for(int j = i;j <= it;j++) {
			for(int jj = bp(crd, a[j].second);jj < sz;jj |= (jj + 1)) c[jj]++;
		}

		for(int j = i;j <= it;j++) {
			int l, r;
			l = lower_bound(ALL(crd), a[j].second - k) - crd.begin();
			r = upper_bound(ALL(crd), a[j].second + k) - crd.begin() - 1;
			for(int jj = r;jj >= 0;jj = (jj & (jj + 1)) - 1) boss[j] += c[jj];
			for(int jj = l - 1;jj >= 0;jj = (jj & (jj + 1)) - 1) boss[j] -= c[jj];
		}

		i = it;
	}

	int q;
	scanf("%d", &q);

	vec< pair< int, tuple< int, int, int > > > b;
	vec< int > ans(q);

	for(int i = 0;i < q;i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		x--, y--;
		b.push_back(mp(max(otv[x], otv[y]), mt(i, x, y)));
	}

	sort(ALL(b));
	
	int i, j;
	i = n - 1;
	j = q - 1;

	segment_tree st(sz);

	while(j >= 0) {
		while(i >= 0 && a[i].first >= b[j].first) {
			// add to a[i].second : boss[i]
			st.upd(bp(crd, a[i].second), boss[i]);
			i--;
		}

		int id, x, y;
		tie(id, x, y) = b[j].second;
		int l, r;
		l = max(age[x], age[y]) - k;
		r = min(age[x], age[y]) + k;
		if(l > r) ans[id] = -1;
		else {
			l = lower_bound(ALL(crd), l) - crd.begin();
			r = upper_bound(ALL(crd), r) - crd.begin() - 1;
			
			if(l > r) ans[id] = -1;
			else ans[id] = st.get(l, r);
		}
		j--;
	}

	for(int i = 0;i < q;i++) printf("%d\n", ans[i]);

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}