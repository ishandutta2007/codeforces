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
const int MX = 10000;
const ld eps = 1e-7;

ld dp[MX];
ld dp2[MX];
int k, q;
int ans[12000];

vector<pair<int, int> > vv;
int main() {
	dp[0] = 1;
	cin >> k >> q;
	for (int i = 1; i <= k; ++i) {
		dp2[0] = 0;
		for (int j = 1; j < MX; ++j)
			dp2[j] = (dp2[j - 1] * (ld)(i) / (ld)k + dp[j - 1] * (ld)(k - i + 1) / (ld)k);
		for (int j = 0; j < MX; ++j)
			dp[j] = dp2[j];
	}
	for (int i = 0; i < q; ++i) {
		int p;
		cin >> p;
		vv.push_back(make_pair(p, i));
	}
	sort(vv.begin(), vv.end());
	int now = 0;
	for (int i = 0; i < vv.size(); ++i) {
		ld pp = ((ld)vv[i].first - eps) / 2000.0;
		while (dp[now] < pp)
			++now;
		ans[vv[i].second] = now;
	}
	for (int i = 0; i < q; ++i)
		cout << ans[i] << "\n";
	return 0;
}