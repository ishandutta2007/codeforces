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
string s;
vector<int> vv[3];
int dp[77][77][77][3];
const int INF = 1e7;

int main() {
	cin >> n;
	cin >> s;
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'V')
			vv[0].push_back(i);
		else if (s[i] == 'K')
			vv[1].push_back(i);
		else
			vv[2].push_back(i);
	}
	for (int i = 0; i <= vv[0].size(); ++i)
		for (int j = 0; j <= vv[1].size(); ++j)
			for (int k = 0; k <= vv[2].size(); ++k)
				for (int l = 0; l <= 2; ++l)
					dp[i][j][k][l] = INF;
	dp[0][0][0][2] = 0;
	for (int i = 0; i <= vv[0].size(); ++i)
		for (int j = 0; j <= vv[1].size(); ++j)
			for (int k = 0; k <= vv[2].size(); ++k)
				for (int l = 0; l <= 2; ++l) {
					if (i + j + k == 0)
						continue;
					if (l == 0 && i == 0)
						continue;
					if (l == 1 && j == 0)
						continue;
					if (l == 2 && k == 0)
						continue;
					int cnt = 0;
					int cur = 0;
					if (l == 0)
						cur = vv[0][i - 1];
					else if (l == 1)
						cur = vv[1][j - 1];
					else
						cur = vv[2][k - 1];
					for (int it = i; it < vv[0].size() && vv[0][it] < cur; ++it)
						++cnt;
					for (int it = j; it < vv[1].size() && vv[1][it] < cur; ++it)
						++cnt;
					for (int it = k; it < vv[2].size() && vv[2][it] < cur; ++it)
						++cnt;
					if (l == 0) {
						int ans = INF;
						for (int it = 0; it <= 2; ++it)
							ans = min(ans, dp[i - 1][j][k][it]);
						dp[i][j][k][l] = min(INF, ans + cnt);
					}
					else if (l == 1) {
						int ans = INF;
						for (int it = 1; it <= 2; ++it)
							ans = min(ans, dp[i][j - 1][k][it]);
						dp[i][j][k][l] = min(INF, ans + cnt);
					}
					else {
						int ans = INF;
						for (int it = 0; it <= 2; ++it)
							ans = min(ans, dp[i][j][k - 1][it]);
						dp[i][j][k][l] = min(INF, ans + cnt);
					}
				}
	int ans = INF;
	for (int i = 0; i <= 2; ++i)
		ans = min(ans, dp[vv[0].size()][vv[1].size()][vv[2].size()][i]);
	cout << ans << "\n";
	return 0;
}