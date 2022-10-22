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

bool solve() {
	
	int n, m;
	
	cin >> n >> m;

	if(n == 0) {
		cout << 3 * m << '\n';
		return true;
	}

	if(m == 0) {
		cout << 2 * n << '\n';
		return true;
	}

	int bl, br, bm;
	int h, c2, c3, c6, ost;

	bl = 3;
	br = inf;

	while(br - bl > 1) {
		bm = (bl + br) / 2;
		
		h = bm;
		c2 = h / 2;
		c3 = h / 3;
		c6 = h / 6;

		if(c3 < m) { bl = bm + 1; continue; }

		ost = max(0, m - (c3 - c6));

		if(c2 >= n + ost) br = bm;
		else bl = bm + 1;
	}

	h = bl;
	c2 = h / 2;
	c3 = h / 3;
	c6 = h / 6;

	if(c3 < m) cout << br << '\n';
	else {
		ost = max(0, m - (c3 - c6));

		if(c2 >= n + ost) cout << bl << '\n';
		else cout << br << '\n';
	}

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}