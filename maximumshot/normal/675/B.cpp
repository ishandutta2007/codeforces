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

bool solve() {
	
	int n, a, b, c, d;

	cin >> n >> a >> b >> c >> d;

	ll res = 0;

	for(int v = 1;v <= n;v++) {
		int x, y, z, w;

		x = b + v - c;
		z = a + v - d;
		w = a + x - d;

		if(x < 1 || x > n || z < 1 || z > n || w < 1 || w > n) continue;
		if(a + v + b != d + w + c) continue;
		if(a + x + c != b + z + d) continue;

		res += n;
	}

	cout << res << '\n';

	return true;
}

int main() {
	
	//while(solve());
	solve();

	return 0;
}