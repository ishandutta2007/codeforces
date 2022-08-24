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

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long double ld;

using namespace std;

ll n, l, r;
vector<ll> vv;
ll dp[1000];

int get(ll x, int lv = 0) {
	if (x == dp[lv + 1] + 1)
		return vv[lv] % 2;
	if (dp[lv + 1] >= x)
		return get(x, lv + 1);
	else
		return get(x - dp[lv + 1] - 1, lv + 1);
}

int main() {
	cin >> n >> l >> r;
	ll tmp = n;
	while (tmp > 1) {
		vv.push_back(tmp);
		tmp /= 2;
	}
	vv.push_back(tmp);
	dp[vv.size() - 1] = 1;
	for (int i = (int)vv.size() - 2; i >= 0; --i) {
		dp[i] = 2 * dp[i + 1] + 1;
	}
	int cnt = 0;
	for (ll i = l; i <= r; ++i) {
		if (get(i))
			++cnt;
	}
	cout << cnt << "\n";
	return 0;
}