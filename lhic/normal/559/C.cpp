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
typedef long double ld;

using namespace std;

const int MAXN = 220000;

const ll MOD = 1000000007;

ll ff[MAXN];
ll bff[MAXN];

vector<pair<int, int> > vv;
int h, w, n;
ll dp[3000];

ll cnk(int n, int k) {
	if (n < 0 || k < 0 || k > n)
		return 0;
	ll ans = (ff[n] * bff[k]) % MOD;
	ans = (ans * bff[n - k]) % MOD;
	return ans;
}

ll pw(ll a, ll b) {
	ll ans = 1;
	while (b) {
		while (b % 2 == 0)
			a = (a * a) % MOD, b /= 2;
		--b;
		ans = (ans * a) % MOD;
	}
	return ans;
}


void init() {
	int n = MAXN - 10;
	ff[0] = 1;
	for (int i = 0; i < n; ++i)
		ff[i + 1] = (ff[i] * (i + 1)) % MOD;
	for (int i = 0; i <= n; ++i)
		bff[i] = pw(ff[i], MOD - 2);
}

int main() {
	scanf("%d%d%d", &h, &w, &n);
	vv.push_back(make_pair(0, 0));
	vv.push_back(make_pair(h - 1, w - 1));
	for (int i = 0; i < n; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		vv.push_back(make_pair(x - 1, y - 1));
	}
	sort(vv.begin(), vv.end());
	init();

	dp[0] = 1;
	for (int i = 1; i < (int)vv.size(); ++i) {
		dp[i] = cnk(vv[i].first + vv[i].second, vv[i].first);
		for (int j = 1; j < i; ++j) {
			dp[i] = (dp[i] - dp[j] * cnk(vv[i].first + vv[i].second - vv[j].first - vv[j].second, vv[i].first - vv[j].first) + MOD * MOD) % MOD;
		}
	}
	cout << dp[(int)vv.size() - 1] << "\n";
	return 0;
}