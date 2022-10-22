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

int d, n, m;
vec< pii > a; 

// >= x
int bp(int x) {
	int bl, br, bm;
	bl = 0;
	br = m - 1;
	while(br - bl > 1) {
		bm = (bl + br) / 2;
		if(a[bm].first >= x) br = bm;
		else bl = bm + 1;
	}
	if(a[bl].first >= x) return bl;
	else if(a[br].first >= x) return br;
	else return m;
}

const int LOG = 21;

vec< pii > rmq[LOG];
vec< int > _log;

void build() {
	_log.resize(m + 1);
	int cur = 0;
	while((1 << cur) <= m) cur++; cur--;
	for(int i = m;i > 0;i--) {
		if((1 << cur) > i) cur--;
		_log[i] = cur;
	}
	for(int i = 0;i < LOG;i++) {
		rmq[i].resize(m, mp(inf + 10, -1));
	}
	for(int i = 0;i < m;i++) {
		rmq[0][i] = mp(a[i].second, i);
	}
	for(int i = 1;i < LOG;i++) {
		for(int j = 0;j + (1 << (i - 1)) < m;j++) {
			rmq[i][j] = min(rmq[i - 1][j], rmq[i - 1][j + (1 << (i - 1))]);
		}
	}
}

pii ask(int l, int r) {
	return min(rmq[ _log[r - l + 1] ][l], rmq[ _log[r - l + 1] ][r - (1 << _log[r - l + 1]) + 1]);
}

int nx(int i) {
	if(i + 1 == m) return -1;
	int bl, br, bm;
	bl = i + 1;
	br = m - 1;
	while(br - bl > 1) {
		bm = (bl + br) / 2;
		if(ask(i + 1, bm).first < a[i].second) br = bm;
		else bl = bm + 1;
	}
	if(ask(i + 1, bl).first < a[i].second) return bl;
	else if(ask(i + 1, br).first < a[i].second) return br;
	else return -1;
}

bool solve() {

	scanf("%d %d %d", &d, &n, &m);
	
	if(n == d) {
		cout << 0 << '\n';
		return true;
	}

	a.resize(m);
	for(int x, p, i = 0;i < m;i++) {
		scanf("%d %d", &x, &p);
		a[i] = mp(x, p);
	}

	m += 2;
	a.push_back(mp(0, 0));
	a.push_back(mp(d, 0));

	sort(ALL(a));
	build();

	ll ans = 0;
	int topl = n;

	for(int i = 1;i < m;i++) {
		topl -= (a[i].first - a[i - 1].first);
		if(topl < 0) {
			cout << -1 << '\n';
			return true;
		}
		int nxt = nx(i), delt;
		if(nxt == -1) delt = min(n, d - a[i].first);
		else delt = min(n, a[nxt].first - a[i].first);
		if(delt >= topl) {
			ans += (ll)(delt - topl) * (ll)a[i].second;
			topl = delt;
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