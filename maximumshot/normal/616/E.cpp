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

const ll base = inf + 7;

bool solve() {
	
	ll n, m;

	cin >> n >> m;

	ll ans = 0;

	if(m > n) {
		ll tmp1 = (m - n) % base;
		ll tmp2 = n % base;
		ans = (tmp1 * tmp2) % base;
	}

	for(ll d = 1, r = n;r > 0;) {
		ll st = n % r; 
		ll x = (st + r * d) / (d + 1) + 1;
		
		// [x .. r]

		ll ql, qr;

		ql = x;
		qr = min(m, r);

		if(ql <= qr) {
			
			ll tmp1 = (n % ql) + (n % qr);
			ll tmp2 = qr - ql + 1;

			if(tmp1 % 2 == 0) tmp1 /= 2;
			else tmp2 /= 2;

			tmp1 %= base;
			tmp2 %= base;
			tmp1 = (tmp1 * tmp2) % base;

			ans = (ans + tmp1) % base;
		}

		r = x - 1;
		d++;
	}

	cout << ans << '\n';

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}