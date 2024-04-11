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

int n;
vec< vec< char > > ans;  

void rec(int xl, int xr, int yl, int yr) {
	if(xl == xr) {
		return;
	}
	int xm, ym;
	xm = (xl + xr) / 2;
	ym = (yl + yr) / 2;
	rec(xl, xm, yl, ym);
	rec(xl, xm, ym + 1, yr);
	rec(xm + 1, xr, yl, ym);
	rec(xm + 1, xr, ym + 1, yr);
	for(int i = xl;i <= xm;i++) {
		for(int j = yl;j <= ym;j++) {
			ans[i][j] ^= 1;		
		}
	}
}

bool solve() {
	
	cin >> n;

	n = 1 << n;

	ans.resize(n, vec< char >(n));

	rec(0, n - 1, 0, n - 1);

	for(auto i : ans) {
		for(auto j : i) cout << (j?"+" : "*");
		cout << "\n";
	}

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}