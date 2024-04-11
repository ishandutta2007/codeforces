#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple 

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ll inf = 1000000000ll;
const ll inf64 = inf * inf;
const ll base = inf + 7;
const ld pi = acos(-1.0);

const int LOG = 21;

vec< int > rmq[LOG];
vec< int > lg;
int n;

void build(const vec< int > & a) {
	lg.resize(n + 1);
	for(int i = 0;i < LOG;i++) {
		rmq[i].resize(n + 1);
	}
	rmq[0] = a;
	int q = 0;
	while((1 << q) <= n) q++;
	for(int i = n;i >= 1;i--) {
		if((1 << q) > i) q--;
		lg[i] = q;
	}
	for(int i = 1;i < LOG;i++) {
		for(int j = 1;j + (1 << (i - 1)) <= n;j++) {
			rmq[i][j] = max(
				rmq[i - 1][j], 
				rmq[i - 1][j + (1 << (i - 1))]
			);
		}
	}
}

int get_max(int l, int r) {
	return max(
		rmq[lg[r - l + 1]][l],
		rmq[lg[r - l + 1]][r - (1 << lg[r - l + 1]) + 1]
	);
}

bool solve() {
	
	int q;

	scanf("%d %d", &n, &q);

	vec< int > a(n + 1), b(n + 1);

	for(int i = 1;i <= n;i++) {
		scanf("%d", &a[i]);
		b[i] = abs(a[i] - a[i - 1]);
	}

	build(b);

	vec< int > _cur(n + 1);

	for(int i = 2;i <= n;i++) {
		int bl, br, bm;
		bl = 2, br = i;
		while(br - bl > 1) {
			bm = (bl + br) >> 1;
			if(b[i] >= get_max(bm, i)) br = bm;
			else bl = bm + 1;
		}
		_cur[i] = (b[i] >= get_max(bl, i)?bl : br);
	}

	ll ans;
	int _ll, _rr;
	vec< ll > dp(n + 1, 0);

	for(;q;q--) {
		scanf("%d %d", &_ll, &_rr);
		
		ans = 0;
		for(int i = _ll;i <= _rr;i++) dp[i] = 0;

		for(int r = _ll + 1;r <= _rr;r++) {
			int cur = max(_ll + 1, _cur[r]);
			dp[r] = (ll)(r - cur + 1) * (ll)abs(a[r] - a[r - 1]) + dp[cur - 1];
			ans += dp[r];
		}

		cout << ans << '\n';
	}

	return true;
} 

int main() {
	
	//while(solve());
	solve();	

	return 0;
}