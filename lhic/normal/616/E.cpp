#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef double ld;

using namespace std;

const ll MOD = 1000000007;
const ll SQ = 2000000;

ll n, m;


int main() {
	cin >> n >> m;
	ll sum = (n % MOD) * (m % MOD);
	sum %= MOD;
	m = min(n, m);
	ll lst = m + 1;
	for (int i = 1; i <= min(SQ, n); ++i) {
		ll r = n / i;
		ll l = n / (i + 1) + 1;
		r = min(r, m);
		if (l > r)
			continue;
		lst = min(lst, l);
		ll ss = l + r;
		ll cc = r - l + 1;
		if ((ss & 1) == 0)
			ss /= 2;
		else
			cc /= 2;
		ss %= MOD;
		cc %= MOD;
		ss = (ss * cc) % MOD;
		ss = (ss * i) % MOD;
		sum -= ss;
		if (sum < 0)
			sum += MOD;
	}
	for (int i = 1; i < lst; ++i) {
		sum -= (n - n % i);
		sum %= MOD;
		if (sum < 0)
			sum += MOD;
	}
	cout << sum << "\n";
	return 0;
}