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

	cin >> n;

	int mn, mx;

	for(int x, i = 1;i <= n;i++) {
		cin >> x;
		if(x == 1) mn = i;
		if(x == n) mx = i;
	}

	int res = abs(mn - mx);

	res = max(res, abs(mn - 1));
	res = max(res, abs(mx - 1));
	res = max(res, abs(n - mn));
	res = max(res, abs(n - mx));

	cout << res << '\n';

	return true;
}

int main() {
	
	//while(solve());
	solve();

	return 0;
}