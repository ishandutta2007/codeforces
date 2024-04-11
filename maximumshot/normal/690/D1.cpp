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

int r, c;
vec< string > a;
vec< vec< char > > used;

void dfs(int i, int j) {
	used[i][j] = 1;
	for(int di = -1;di <= 1;di++) {
		for(int dj = -1;dj <= 1;dj++) {
			if(di == 0 && dj == 0 || di != 0 && dj != 0) continue;
			int I, J;
			I = i + di;
			J = j + dj;
			if(I < 0 || I >= r || J < 0 || J >= c) continue;
			if(a[I][J] == '.' || used[I][J]) continue;
			dfs(I, J);
		}
	}
}

bool solve() {
	
	cin >> r >> c;

	a.resize(r);

	for(int i = 0;i < r;i++) cin >> a[i];

	used.resize(r, vec< char >(c));

	int res = 0;

	for(int i = 0;i < r;i++) {
		for(int j = 0;j < c;j++) {
			if(a[i][j] == '.' || used[i][j]) continue;
			dfs(i, j);
			res++;
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