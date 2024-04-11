#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef long long ll;
const int Maxb = 62;

ll n, k;
ll res;

int main()
{
	cin >> n >> k;
	ll cur = Maxb - 1;
	while ((1ll << cur) > n) cur--;
	for (ll i = Maxb - 1; i >= 0 && k > 0; i--) if (!(res & 1ll << i)) {
		ll my = 0;
		for (ll j = Maxb - 1; j >= 0; j--) if (!(res & 1ll << j) && (my | 1ll << j) <= n)
			my |= 1ll << j;
		res |= my;
		k--;
	}
	cout << res << endl;
	return 0;
}