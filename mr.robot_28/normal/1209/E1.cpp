#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
 
using namespace std;
 
#define MAXLEVEL 12
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
 
	int t, n, m, i, j, k, ans, d, s, c, p, nn;
 
	// compile reference list
	d = 1 << MAXLEVEL;
	vector<vector<int>> plist(d);
	for (i = 0; i < d; i++) {
		for (j = 0; j <= i; j++) {
			if ((i | j) == i) {
				plist[i].push_back(j);
			}
		}
	}
 
	cin >> t;
	while (t--) {
		cin >> n >> m;
		d = (1 << n);
 
		vector<vector<int>> a(n, vector<int>(m));
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) cin >> a[i][j];
		}
 
		// sort all columns by the max element and pick up the first n
		vector<pair<int, int>> pp(m);		// max, column id
		for (i = 0; i < m; i++) {
			int maxx = 0;
			for (j = 0; j < n; j++) maxx = max(maxx, a[j][i]);
			pp[i] = { maxx, i };
		}
 
		sort(pp.rbegin(), pp.rend());
		nn = min(n, m);
		vector<vector<int>> aa(n, vector<int>(nn));
		for (i = 0; i < n; i++) {
			for (j = 0; j < nn; j++) aa[i][j] = a[i][pp[j].second];
		}
 
		// calculate mask sum of every column
		vector<vector<vector<int>>> sum(nn, vector<vector<int>>(n, vector<int>(d, 0)));	// column, rotation, bitmask
		for (i = 0; i < nn; i++) {
			for (c = 0; c < n; c++) {		// rotation
				for (j = 0; j < n; j++) {
					p = 1 << j;
					for (k = 0; k < d; k++) {
						if (k & p) sum[i][c][k] += aa[(j + c) % n][i];
					}
				}
			}
			for (k = 0; k < d; k++) {
				for (c = 1; c < n; c++) sum[i][0][k] = max(sum[i][0][k], sum[i][c][k]);
			}
		}
 
		vector<vector<int>> dp(nn + 1, vector<int>(d, 0));
		for (i = 1; i <= nn; i++) {
			dp[i] = dp[i - 1];
			for (j = 0; j < d; j++) {
				for (auto p : plist[j]) {
					s = dp[i - 1][p] + sum[i - 1][0][j - p];
					dp[i][j] = max(dp[i][j], s);
				}
			}
		}
 
		ans = dp[nn][d - 1];
		cout << ans << "\n";
		cout.flush();
 
		//if (m == 2000) break;
	}
 
 
	return 0;
}