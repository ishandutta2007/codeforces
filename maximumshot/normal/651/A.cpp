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

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);

bool solve() {
	
	int a1, a2;

	cin >> a1 >> a2;

	int ans = 0;
	
	while(1) {
		if(a1 == 0 || a2 == 0) break;
		if(a1 == 1 && a2 == 1) break;
		ans++;
		if(a1 < a2) a1++, a2 -= 2;
		else a2++, a1 -= 2;
	}

	cout << ans << '\n';

	return true;
}

int main() {

	//while(solve());
	solve();	
	
	return 0;
}