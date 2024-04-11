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

const int LOG = 21;

int n, k;
vec< int > mn[LOG], mx[LOG], v, c, _log;

void build() {
	for(int i = 0;i < LOG;i++) {
		mn[i].resize(n, +inf + 10);
		mx[i].resize(n, -inf - 10);
	}
	mn[0] = c;
	mx[0] = v;
	for(int i = 1;i < LOG;i++) {
		for(int j = 0;j + (1 << (i - 1)) < n;j++) {
			mn[i][j] = min(mn[i - 1][j], mn[i - 1][j + (1 << (i - 1))]);
			mx[i][j] = max(mx[i - 1][j], mx[i - 1][j + (1 << (i - 1))]);
		}
	}
	_log.resize(n + 1);
	int cur = 0;
	while((1 << cur) <= n) cur++;
	for(int i = n;i >= 1;i--) {
		if((1 << cur) > i) cur--;
		_log[i] = cur;
	}
}

int ask(int l, int r) {
	return min(
		min(mn[ _log[r - l + 1] ][l], mn[ _log[r - l + 1] ][r - (1 << _log[r - l + 1]) + 1]),
		max(mx[ _log[r - l + 1] ][l], mx[ _log[r - l + 1] ][r - (1 << _log[r - l + 1]) + 1])
	);
}

int get_max(int l, int r) {
	return max(mx[ _log[r - l + 1] ][l], mx[ _log[r - l + 1] ][r - (1 << _log[r - l + 1]) + 1]);
}

int get_min(int l, int r) {
	return min(mn[ _log[r - l + 1] ][l], mn[ _log[r - l + 1] ][r - (1 << _log[r - l + 1]) + 1]);
}

bool solve() {

	scanf("%d %d", &n, &k);

	v.resize(n);
	c.resize(n);

	for(int i = 0;i < n;i++) {
		scanf("%d", &v[i]);
		v[i] *= 100;
	}

	for(int i = 0;i < n;i++) {
		scanf("%d", &c[i]);
	}

	build();

	vec< int > mas;

	for(int i = 0;i < n;i++) {
		int l, r, m1, m2, t;
		l = i;
		r = n - 1;
		while(r - l > 2) {
			m1 = l + (r - l) / 3;
			m2 = r - (r - l) / 3;
			if(get_max(i, m1) < get_min(i, m2)) l = m1;
			else r = m2;
		}
		t = -inf;
		for(int j = max(i, l - 5);j <= min(n - 1, r + 5);j++) {
			t = max(t, ask(i, j));
		}
		mas.push_back(t);
	}

	sort(ALL(mas));

	ld ans = 0.0, p = (ld)k / (ld)n;

	for(int i = 0;i + k - 1 < n;i++) {
		ans += (ld)mas[i] * p;
		if(k > 1) p *= (ld)(n - k - i) / (ld)(n - i - 1);
	}

	cout.precision(10);
	cout << fixed << ans << '\n';

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}