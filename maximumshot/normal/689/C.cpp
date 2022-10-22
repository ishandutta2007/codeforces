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
#include <complex>

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

ll f(ll n) {
	ll res = 0;

	for(ll k = 2;k * k * k <= n;k++) {
		res += n / (k * k * k);
	}

	return res;
}

bool solve() {

	ll m, bl, br, bm;
	cin >> m;

	bl = 1;
	br = inf64;

	while(br - bl > 1) {
		bm = (bl + br) / 2;
		if(f(bm) < m) bl = bm + 1;
		else br = bm;
	}

	if(f(bl) == m) cout << bl << '\n';
	else if(f(br) == m) cout << br << '\n';
	else cout << -1 << '\n';

	return true;
}

int main() {
	
	//while(solve());
	solve();

	return 0;
}