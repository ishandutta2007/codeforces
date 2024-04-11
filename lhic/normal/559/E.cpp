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

const int MAXN = 102;

int n;

pair<int, int> arr[MAXN];
vector<int> vv;
int dp[MAXN][MAXN][MAXN * 3];
int aa[MAXN][MAXN * 3];

int fnd(int x) {
	return lower_bound(vv.begin(), vv.end(), x) - vv.begin();
}


int main() {
//	freopen("input", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d%d", &arr[i].first, &arr[i].second), vv.push_back(arr[i].first - arr[i].second), vv.push_back(arr[i].first), vv.push_back(arr[i].first + arr[i].second);
	sort(arr, arr + n);
	sort(vv.begin(), vv.end());
	vv.resize(unique(vv.begin(), vv.end()) - vv.begin());
	for (int i = n - 1; i >= 0; --i) {
		for (int j = i; j < n; ++j) {
			for (int l = 0; l < (int)vv.size(); ++l) {
				if (j > i)
					dp[i][j][l] = dp[i + 1][j][l];
				else
					dp[i][j][l] = l;
				if (arr[i].first > vv[l])
					continue;
				int go = dp[i][j][l];
				if (vv[go] <= arr[i].first)
					dp[i][j][l] = min(dp[i][j][l], fnd(arr[i].first - arr[i].second));
				int now = j;
				if (arr[i].first + arr[i].second > vv[l])
					continue;
				while (now > i && vv[dp[now][j][l]] > arr[i].first + arr[i].second)
					--now;
				if (now != i || arr[i].first + arr[i].second == vv[l]) {
					if (arr[i].first + arr[i].second == vv[l])
						now = j + 1;
					int mn = arr[i].first;
					for (int k = i + 1; k < now; ++k)
						mn = min(mn, arr[k].first - arr[k].second);
					dp[i][j][l] = min(dp[i][j][l], fnd(mn));
				}
			}
		}
	}


	for (int i = 0; i < n; ++i)
		for (int j = 0; j < (int)vv.size(); ++j) {
			for (int i1 = i; i1 < n; ++i1)
				for (int j1 = j + 1; j1 < (int)vv.size(); ++j1)
					if (dp[i][i1][j1] >= j)
						aa[i1 + 1][j1] = max(aa[i1 + 1][j1], aa[i][j] + vv[j1] - vv[dp[i][i1][j1]]);
		}

	int ans = 0;
	for (int i = 0; i < (int)vv.size(); ++i)
		ans = max(ans, aa[n][i]);
	cout << ans << "\n";


	return 0;
}