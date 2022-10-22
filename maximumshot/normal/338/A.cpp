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

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define deb(x) cerr << #x << " = " << x << '\n';

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll inf = 1000000000ll;
const ll inf64 = inf * inf;
const ll base = inf + 9;

ll binpow(ll n, ll m) {
	if(m == 0) return 1ll;
	ll q = binpow(n, m / 2);
	q = (q * q) % base;
	return (m % 2?(q * n) % base : q);
}

bool solve() 
{
	ll n, m, k;

	cin >> n >> m >> k;

	ll x = (n + 1) / k;
	ll ost = max(0ll, n - x * k);

	ll now = x * (k - 1) + ost;

	if(now >= m) {
		cout << m << '\n';
	}else {
		if(x * k <= n) x++;

		ll need = m - now;

		ll sum = binpow(2ll, need + 1) - 2;
		sum = (sum % base + base) % base;
		sum = (sum * k) % base;

		sum += (m - need * k);

		sum = (sum % base + base) % base;

		cout << sum << '\n';
	}

	return true;
}

int main() {

	//while(solve());
	solve();    

	return 0;
}