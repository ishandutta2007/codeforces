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

	ld d, L, v1, v2;
	
	cin >> d >> L >> v1 >> v2;

	ld l, r, m;
	l = 0;
	r = 1e6;

	for(int k = 0;k < 228;k++) {
		m = (l + r) / 2.0;
		ld x = v1 * m;	
		ld s = L - x - d;
		if(s < m * v2) r = m;
		else l = m;
	}

	cout.precision(10);
	cout << fixed;
	cout << l << '\n';

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}