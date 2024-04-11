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

ll gcd(ll x, ll y) {
	return (x == 0?y : gcd(y % x, x));
}

ll lcm(ll x, ll y) {
	return (x / gcd(x, y)) * y;		
}

bool solve() {

	int n;
	cin >> n;

	ll l;

	vec< int > m(n), r(n);
	for(int i = 0;i < n;i++) cin >> m[i];
	for(int i = 0;i < n;i++) cin >> r[i];

	l = m[0];

	for(int i = 1;i < n;i++) l = lcm(l, m[i]);

	vec< char > used(l);

	for(int i = 0;i < n;i++) {
		for(int j = r[i];j < l;j += m[i]) used[j] = 1;
	}

	ll cnt = count(ALL(used), 1);

	ld res = (ld)cnt / (ld)l;

	cout.precision(10);
	cout << fixed << res << '\n';

	return true;
}

int main() {
		
	//while(solve());
	solve();

	return 0;
}