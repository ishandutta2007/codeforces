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

const ll MOD = 1000000007;
const int MAXN = 1200000;

ll dp[MAXN];

int n, k;
ll l;
int a[MAXN];
vector<int> vv1;
vector<pair<int, int> > vv;
map<int, int> mm;
ll ans;

void add(ll& a, ll b) {
	a += b;
	a %= MOD;
}


int main() {
	cin >> n >> l >> k;
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]), vv1.push_back(a[i]);
	ll oo = l % n;
	ll gr = l / n;
	for (int i = 0; i < oo; ++i)
		++mm[a[i]];
	sort(vv1.begin(), vv1.end());
	int cnt = 0;
	for (int i = 0; i < (int)vv1.size(); ++i) {
		++cnt;
		if (i == (int)vv1.size() - 1 || vv1[i + 1] != vv1[i])
			vv.push_back(make_pair(vv1[i], cnt)), cnt = 0;
	}
	dp[0] = 1;
	for (int i = 0; i < (int)vv.size(); ++i) {
		for (int j = 0; j < k; ++j)
			add(dp[j + 1], vv[i].second * dp[j]);
		int x = mm[vv[i].first];
		int y = vv[i].second;
		for (int j = 0; j < k; ++j) {
			if (j <= gr)
				add(ans, x * dp[j]);
			if (j < gr)
				add(ans, ((y * dp[j]) % MOD) * ((gr - j) % MOD));
		}
	}

	cout << ans << "\n";

	return 0;
}