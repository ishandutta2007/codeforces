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

ll gcd(ll x, ll y) {
	return (x == 0?y : gcd(y % x, x));
}

ll lcm(ll x, ll y) {
	return (x / gcd(x, y)) * y;
}

bool solve() {

	int n, k;

	scanf("%d %d", &n, &k);

	ll t = 1;

	for(int x, i = 0;i < n;i++) {
		scanf("%d", &x);
		t = gcd(k, lcm(t, x));
	}

	printf("%s\n", t == k?"Yes" : "No");

	return true;
}

int main() {
	
	//while(solve());
	solve();

	return 0;
}