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

	int n;

	scanf("%d", &n);

	ll s = 0;

	map< ll, int > c;

	for(int x, i = 0;i < n;i++) {
		scanf("%d", &x);
		s += x;
		c[s]++;
	}

	int res = 0;

	for(auto cur : c) res = max(res, cur.second);

	printf("%d\n", n - res);

	return true;
}

int main() {
	
	//while(solve());
	solve();

	return 0;
}