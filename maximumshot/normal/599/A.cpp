#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple 

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ll inf = 1000000000ll;
const ll inf64 = inf * inf;
const ll base = inf + 7;
const ld pi = acos(-1.0);

bool solve() {
	
	int d1, d2, d3;

	cin >> d1 >> d2 >> d3;

	int ans = inf;

	ans = min(ans, d1 + d2 + d3);
	ans = min(ans, d1 + d3 + d3 + d1);
	ans = min(ans, d2 + d3 + d3 + d2);
	ans = min(ans, d1 + d1 + d2 + d2);

	cout << ans << '\n';

	return true;
} 

int main() {
	
	//while(solve());
	solve();	

	return 0;
}