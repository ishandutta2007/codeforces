#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <tuple>
#include <fstream>
#include <stdio.h>
#include <cstring>
#include <map>
#include <queue>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;

const int inf = 1000000000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);

bool solve() {

	ll n;
	cin >> n;

	for(ll pos = 1, value = 1;;) {
		// pos .. pos + value - 1
		if(pos <= n && n <= pos + value - 1) {
			cout << n - pos + 1 << '\n';
			return true;
		}
		pos += value;
		value++;
	}

	return true;	
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}