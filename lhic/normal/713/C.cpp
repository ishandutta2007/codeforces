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


int n;
ll a[3100];
ll dp[3100];
vector<ll> vv;
int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < n; ++i)
		a[i] -= i, vv.push_back(a[i]);
	sort(vv.begin(), vv.end());
	vv.resize(unique(vv.begin(), vv.end()) - vv.begin());
	for (int i = 0; i < n; ++i) {
		ll mn = dp[0];
		for (int j = 0; j < (int)vv.size(); ++j) {
			mn = min(mn, dp[j]);
			dp[j] = mn + abs(a[i] - vv[j]);
		}
	}
	ll ans = dp[0];
	for (int i = 0; i < (int)vv.size(); ++i)
		ans = min(ans, dp[i]);
	cout << ans << "\n";
	return 0;
}