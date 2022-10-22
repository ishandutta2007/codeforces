#include <iostream>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <iomanip>

#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <cstring>
#include <tuple>
#include <map>
#include <queue>
#include <bitset>
#include <list>
#include <stack>
#include <unordered_map>
#include <array>

#include <complex>
#include <time.h>
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

inline void no() {
	cout << "No\n";
	exit(0);
}

inline void yes() {
	cout << "Yes";
	exit(0);
}

bool solve() {
	
	int n;

	cin >> n;

	vec< string > a(n);

	int l, r, u, d;

	l = u = n;
	r = d = -1;

	for(int i = 0;i < n;i++) {
		cin >> a[i];
		for(int j = 0;j < n;j++) {
			if(a[i][j] > '0') {
				l = min(l, j);
				r = max(r, j);
				u = min(u, i);
				d = max(d, i);
			}
		}
	}

	if(l == n) yes();
	if(r - l + 1 < 3 || d - u + 1 < 3) no();

	if(a[u][l] != '1' || a[u][r] != '1' || a[d][l] != '1' || a[d][r] != '1') no();

	for(int i = u + 1;i < d;i++) {
		if(a[i][l] != '2' || a[i][r] != '2') no();
	}

	for(int j = l + 1;j < r;j++) {
		if(a[u][j] != '2' || a[d][j] != '2') no();
	}

	for(int i = u + 1;i < d;i++) {
		for(int j = l + 1;j < r;j++) {
			if(a[i][j] != '4') no();
		}
	}

	yes();

	return true;
}

int main() {
	
	//while(solve());
	solve();

	return 0;
}