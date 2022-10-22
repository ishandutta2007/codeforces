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

ll gcd(ll x, ll y) {
	return (x == 0?y : gcd(y % x, x));			
}

ll lcm(ll x, ll y) {
	return (x / gcd(x, y)) * y;
}

bool solve() {
	
	ll n, a, b, p, q;

	cin >> n >> a >> b >> p >> q;

	ll res = 0;

	if(p >= q) {
		res += (n / a) * p;
		res += (n / b - n / lcm(a, b)) * q;
	}else {
		res += (n / b) * q;
		res += (n / a - n / lcm(a, b)) * p;
	}

	cout << res << '\n';

	return true;
}

int main() {

	//while(solve());
	solve();

	return 0;
}