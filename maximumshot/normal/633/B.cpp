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

ll c(ll x, ll y) {
	ll ans = 0;
	while(x % y == 0) ans++, x /= y;
	return ans;
}

bool solve() {

	ll m;
	cin >> m;

	vec< ll > ans;

	for(ll t, c2 = 0, c5 = 0, x = 1;;x++) {
		c2 += c(x, 2ll);
		c5 += c(x, 5ll);
		t = min(c2, c5);
		if(t == m) ans.push_back(x);
		if(t > m) break;
	}

	cout << (int)ans.size() << '\n';
	for(auto i : ans) cout << i << ' ';
	cout << '\n';

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}