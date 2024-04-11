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

double v[11][11];

int n, t;

void dfs(int i, int j, double x) {
	if(abs(v[i][j] - 1.0) > 1e-9 && v[i][j] + x <= 1.0) v[i][j] += x;
	else {
		if(i < n) {
			dfs(i + 1, j, x / 2.0);
			dfs(i + 1, j + 1, x / 2.0);
		}
	}
}

bool solve() {
	
	cin >> n >> t;

	for(int iter = 0;iter < t;iter++) {
		dfs(1, 1, 1);
	}

	int res = 0;

	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= i;j++) {
			if(abs(v[i][j] - 1.0) < 1e-9) res++;
		}
	}

	cout << res << '\n';

	return true;
}

int main() {
	
	//while(solve());
	solve();

	return 0;
}