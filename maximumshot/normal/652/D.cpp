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
#include <bitset>
#include <list>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;
typedef pair< double, double > pdd;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);

bool solve() {

	int n;
	scanf("%d", &n);

	vec< int > crd;
	vec< pii > seg;

	for(int l, r, i = 0;i < n;i++) {
		scanf("%d %d", &l, &r);
		seg.push_back(mp(l, r));
		crd.push_back(l);
		crd.push_back(r);
	}

	sort(ALL(crd));
	crd.resize(unique(ALL(crd)) - crd.begin());

	int sz = (int)crd.size();

	vec< vec< pii > > add(sz);

	for(int i = 0;i < n;i++) {
		seg[i].first = lower_bound(ALL(crd), seg[i].first) - crd.begin();
		seg[i].second = lower_bound(ALL(crd), seg[i].second) - crd.begin();
		add[seg[i].first].push_back(mp(seg[i].second, i));
	}

	vec< int > f(sz);
	vec< int > ans(n);

	for(int i = sz - 1;i >= 0;i--) {
		for(auto cur : add[i]) {
			int r, id;
			r = cur.first;
			id = cur.second;
			for(int j = r - 1;j >= 0;j = (j & (j + 1)) - 1) ans[id] += f[j];
			for(int j = r;j < sz;j |= (j + 1)) f[j]++;
		}
	}

	for(int i = 0;i < n;i++) {
		printf("%d\n", ans[i]);
	}

	return true;
}

int main() {
		
	//while(solve());
	solve();

	return 0;
}