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

const int inf = 1000000000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);

bool solve() {

	ll s, x;
	cin >> s >> x;

	if(s < x) {
		cout << "0\n";
		return true;
	}

	ll y = s - x;

	if(y % 2) {
		cout << "0\n";
		return true;
	}

	y /= 2;
if(y&x) {cout<<0;return true;}
	ll cnt = 0;

	for(ll bit = 0;(1ll << bit) <= x;bit++) {
		if((1ll << bit) & x) cnt++;
	}

	cout << (1ll << cnt) - 2ll * ll(y == 0) << '\n';

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}