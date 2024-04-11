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

int p[1200000];
int was[1200000];
int n;
int k;

int dfs1(int v) {
	was[v] = 1;
	if (was[p[v]])
		return 1;
	else
		return 1 + dfs1(p[v]);
}

vector<int> vv;
int dp[510000];

int can(int k) {
	dp[0] = 1;
	int cnt = 0;
	for (int i = 0; i < (int)vv.size(); ++i) {
		++cnt;
		if (i == (int)vv.size() - 1 || vv[i + 1] != vv[i]) {
			int x = vv[i];
			for (int j = k - x; j >= 0; --j) {
				if (dp[j]) {
					int now = j + x;
					for (int l = 0; l < cnt && now <= k && !dp[now]; ++l, now += x) {
						dp[now] = 1;
					}
				}
			}
			cnt = 0;
		}
	}
	return dp[k];
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i)
		scanf("%d", p + i), --p[i];
	for (int i = 0; i < n; ++i) {
		if (was[i])
			continue;
		vv.push_back(dfs1(i));
	}
	sort(vv.begin(), vv.end());
	int c1 = 0;
	int c2 = 0;
	for (int i = 0; i < (int)vv.size(); ++i) {
		c2 += vv[i] / 2;
		if (vv[i] % 2 == 1)
			++c1;
	}
	int mx = 0;
	if (k <= c2)
		mx = 2 * k;
	else
		mx = 2 * c2 + min(c1, k - c2);
	int mn = k + 1;
	if (can(min(k, n - k)))
		mn = k;
	cout << mn << " " << mx << "\n";
	return 0;
}