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

bool solve() {
	
	ll x;

	cin >> x;

	vec< pair< ll, ll > > ans; 

	for(ll n = 1;n <= 2000000;n++) {
		ll u = 6 * x - (n * n + n) * (1 - n);
		ll v = 3 * (n * n + n);
		if(u > 0 && u % v == 0) {
			ll m = u / v;
			if(m >= n) {
				ll value = n * (n + 1) * (1 - n + 3 * m);
				if(value % 6 == 0 && value / 6 == x) 
					ans.push_back(mp(n, m)), ans.push_back(mp(m, n));
			}
		}
	}

	sort(ALL(ans));
	ans.resize(unique(ALL(ans)) - ans.begin());

	cout << (int)ans.size() << '\n';

	for(int i = 0;i < (int)ans.size();i++) cout << ans[i].first << ' ' << ans[i].second << '\n';

	return true;
} 

int main() {
	
	//while(solve());
	solve();	

	return 0;
}