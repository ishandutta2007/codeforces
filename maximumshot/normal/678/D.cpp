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

const ll mod = inf + 7;

ll mul(ll a, ll b) {
	return ((a % mod) * (b % mod)) % mod;
}

ll sum(ll a, ll b) {
	return (a + b) % mod;
}

ll binpow(ll n, ll p) {
	if(p == 0) return 1ll;
	ll q = binpow(n, p / 2);
	q = mul(q, q);
	if(p % 2) q = mul(q, n);
	return q;
}

ll del(ll a, ll b) {
	return mul(a, binpow(b, mod - 2));
}

ll raz(ll a, ll b) {
	return ((a - b) % mod + mod) % mod;
}

bool solve() {
	
	ll a, b, n, x;

	cin >> a >> b >> n >> x;

	if(a == 1) {
		cout << sum(x, mul(n, b)) << '\n';
	}else {
		cout << sum(mul(binpow(a, n), x), mul(b, del(raz(binpow(a, n), 1), raz(a, 1)))) << '\n';	
	}

	return true;
}

int main() {

	//while(solve());
	solve();

	return 0;
}