#include <iostream>
#include <math.h>
#include <vector>
#include <tuple>
#include <string>
#include <stdio.h>
#include <set>
#include <map>
#include <fstream>
#include <algorithm>
#include <deque>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple
#define vec vector

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair< int, int > pii;

const int inf = 1000000000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);

bool solve() {

	int n;
	cin >> n;

	ll ans = 1;

	ll ok = 0;

	for(int last = 0, i = 1;i <= n;i++) {
		int x;
		cin >> x;
		if(x == 1) {
			ok = 1;
			if(last == 0) last = i;
			else ans *= ll(i - last), last = i;
		}
	} 

	cout << ans * ok << '\n';

	return true;
}

int main() {

	//while(solve());
	solve();

	return 0;
}