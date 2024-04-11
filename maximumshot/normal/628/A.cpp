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
	
	int n, b, p;

	cin >> n >> b >> p;

	ll ans1 = 0, ans2 = 1ll * n * p;

	while(n > 1) {
		int k = 0;
		while((1 << k) <= n) k++; k--;
		ans1 += 1ll * (1ll << (k - 1)) * ll(2 * b + 1);
		n -= (1 << (k - 1));
	}

	cout << ans1 << ' ' << ans2 << '\n';

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}