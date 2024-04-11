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

int n, k;
vector<int> vv;
int dp[3200000];
vector<pair<int, int> > ans;
int l[1200000];
int r[1200000];

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", l + i, r + i);
		l[i] *= 2;
		r[i] *= 2;
		vv.push_back(l[i]);
		vv.push_back(r[i] + 1);
	}
	sort(vv.begin(), vv.end());
	vv.resize(unique(vv.begin(), vv.end()) - vv.begin());
	vv.push_back(2000000000 + 2);
	for (int i = 0; i < n; ++i) {
		int x = lower_bound(vv.begin(), vv.end(), l[i]) - vv.begin();
		++dp[x];
		x = upper_bound(vv.begin(), vv.end(), r[i]) - vv.begin();
		--dp[x];
	}
	int op = 0;
	int now = 0;
	int lp = 0;
	for (int i = 0; i < (int)vv.size(); ++i) {	
		now += dp[i];
		if (now < k && op) {
			ans.push_back(make_pair(lp, vv[i] - 1));
			op = 0;
		}
		if (now >= k && !op) {
			op = 1;
			lp = vv[i];
		}
	}
	printf("%d\n", (int)ans.size());
	for (int i = 0; i < (int)ans.size(); ++i) {
		printf("%d %d\n", ans[i].first / 2, ans[i].second / 2);
	}
	return 0;
}