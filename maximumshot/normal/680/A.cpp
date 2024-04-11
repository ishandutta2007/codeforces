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

bool solve() {

	vec< int > a(5);
	int res = 0, sum = 0;

	for(int i = 0;i < 5;i++) cin >> a[i], res += a[i], sum += a[i];

	sort(ALL(a));

	for(int i = 0;i < 5;i++) {
		if(i + 2 < 5 && a[i] == a[i + 1] && a[i] == a[i + 2]) {
			res = min(res, sum - a[i] - a[i + 1] - a[i + 2]);
		}
		if(i + 1 < 5 && a[i] == a[i + 1]) {
			res = min(res, sum - a[i] - a[i + 1]);
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