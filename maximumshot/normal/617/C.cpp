#include <iostream>
#include <math.h>
#include <vector>
#include <tuple>
#include <string>
#include <stdio.h>
#include <set>
#include <map>
#include <fstream>
#include <algorithm>
#include <deque>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple
#define vec vector

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair< int, int > pii;

const int inf = 1000000000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);

ll sqr(int x) {
	return 1ll * x * x;
}

bool solve() {

	int n, x1, y1, x2, y2;

	cin >> n;
	cin >> x1 >> y1;
	cin >> x2 >> y2;

	vec< pair< ll, ll > > a;
 
	for(int i = 0;i < n;i++) {
		int x, y;
		cin >> x >> y;
		ll d1 = sqr(x - x1) + sqr(y - y1);
		ll d2 = sqr(x - x2) + sqr(y - y2);
		a.push_back(mp(d1, d2));
	}

	sort(ALL(a));

	ll mx = 0;
	ll ans = inf64;

	for(int i = n - 1;i >= 0;i--) {
		// [0 .. i]
		ans = min(ans, a[i].first + mx);
		mx = max(mx, a[i].second);
		if(i == 0) ans = min(ans, mx);
	}

	cout << ans << '\n';

	return true;
}

int main() {

	//while(solve());
	solve();

	return 0;
}