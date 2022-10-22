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
#include <stack>
#include <math.h>
#include <unordered_map>
#include <array>

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

ld dist(int x1, int y1, int x2, int y2) {
	ll val = 1ll * (x1 - x2) * (x1 - x2) + 1ll * (y1 - y2) * (y1 - y2);
	return sqrt(ld(val));
}

bool solve() {
	
	int ax, ay, bx, by, tx, ty;

	cin >> ax >> ay;
	cin >> bx >> by;
	cin >> tx >> ty;

	int n;

	cin >> n;

	vec< pii > a(n);

	for(int x, y, i = 0;i < n;i++) {
		scanf("%d %d", &x, &y);
		a[i] = mp(x, y);
	}

	cout.precision(10);
	cout << fixed;

	if(n == 1) {
		cout << min(dist(ax, ay, a[0].first, a[0].second), dist(bx, by, a[0].first, a[0].second)) + 
			dist(a[0].first, a[0].second, tx, ty) << '\n';
		return true;
	}

	ld res = 1e18;
	ld sum = 0.0;

	for(int i = 0;i < n;i++) {
		sum += dist(a[i].first, a[i].second, tx, ty);
	}

	sum = sum + sum;

	for(int i = 0;i < n;i++) {
		res = min(res, sum - dist(a[i].first, a[i].second, tx, ty) + dist(a[i].first, a[i].second, ax, ay));
		res = min(res, sum - dist(a[i].first, a[i].second, tx, ty) + dist(a[i].first, a[i].second, bx, by));
	}

	vec< ld > pr(n), sf(n);
	
	for(int i = 0;i < n;i++) {
		pr[i] = sum - dist(a[i].first, a[i].second, tx, ty) + dist(a[i].first, a[i].second, ax, ay);
		if(i > 0 && pr[i - 1] < pr[i]) pr[i] = pr[i - 1];
	}

	for(int i = n - 1;i >= 0;i--) {
		sf[i] = sum - dist(a[i].first, a[i].second, tx, ty) + dist(a[i].first, a[i].second, ax, ay);
		if(i + 1 < n && sf[i + 1] < sf[i]) sf[i] = sf[i + 1];
	}

	for(int i = 0;i < n;i++) {
		ld tmp = 1e18;

		if(i > 0 && pr[i - 1] < tmp) tmp = pr[i - 1];
		if(i + 1 < n && sf[i + 1] < tmp) tmp = sf[i + 1];

		res = min(res, tmp - dist(a[i].first, a[i].second, tx, ty) + dist(a[i].first, a[i].second, bx, by));
	}

	cout << res << '\n';

	return true;
}

int main() {
	
	//while(solve());
	solve();

	return 0;
}