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
#include <time.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ll inf = 1000000000ll;
const ll inf64 = inf * inf;
const ll base = inf + 7;

bool solve() 
{
	ll t, s, q;
	ll ans = 0;
	
	cin >> t >> s >> q;

	while(s < t) ans ++, s *= q;

	cout << ans << '\n';

	return true;
}

int main() {

	//while(solve());
	solve();    

	return 0;
}