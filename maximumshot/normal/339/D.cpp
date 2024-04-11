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

vec< int > t, a;
vec< char > ty;

void build(int v, int tl, int tr) {
	if(tl == tr) t[v] = a[tl];
	else {
		int tm = (tl + tr) / 2;
		build(v << 1, tl, tm);
		build(v << 1 | 1, tm + 1, tr);
		if(ty[tr - tl + 1]) t[v] = t[v << 1] | t[v << 1 | 1];
		else t[v] = t[v << 1] ^ t[v << 1 | 1];
	}
}

void upd(int v, int tl, int tr, int p, int b) {
	if(tl == tr) t[v] = b;
	else {
		int tm = (tl + tr) / 2;
		if(p <= tm) upd(v << 1, tl, tm, p, b);
		else upd(v << 1 | 1, tm + 1, tr, p, b);
		if(ty[tr - tl + 1]) t[v] = t[v << 1] | t[v << 1 | 1];
		else t[v] = t[v << 1] ^ t[v << 1 | 1];
	}
}

bool solve() {

	ios_base :: sync_with_stdio(0);

	int n, m;

	cin >> n >> m;

	n = 1 << n;

	t.resize(4 * n);
	a.resize(n + 1);

	for(int i = 1;i <= n;i++) cin >> a[i];

	ty.resize(n + 1);
	for(int st = 0;(1 << st) <= n;st++) {
		ty[1 << st] = st % 2;
	}

	build(1, 1, n);

	for(int p, b;m;m--) {
		cin >> p >> b;
		upd(1, 1, n, p, b);
		cout << t[1] << '\n';
	}

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}