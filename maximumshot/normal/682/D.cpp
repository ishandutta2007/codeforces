#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <set>
#include <string>
#include <tuple>
#include <fstream>
#include <stdio.h>
#include <cstring>
#include <map>
#include <queue>
#include <bitset>
#include <list>
#include <stack>
#include <math.h>
#include <unordered_map>
#include <array>
#include <complex>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;
typedef pair< double, double > pdd;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1ll * inf * inf;

bool solve() {
		
	int n, m, kk;

	cin >> n >> m >> kk;

	string s, t;

	cin >> s >> t;

	vec< vec< int > > lcp(n, vec< int >(m));

	for(int i = 0;i < n;i++) {
		for(int j = 0;j < m;j++) {
			if(s[i] == t[j]) {
				lcp[i][j] = (i > 0 && j > 0?lcp[i - 1][j - 1] : 0) + 1;
			}
		}
	}

	vec< vec< vec< int > > > dp(n, vec< vec< int > >(m, vec< int >(kk + 1)));

	for(int i = 0;i < n;i++) {
		for(int j = 0;j < m;j++) {
			for(int k = 1;k <= kk;k++) {
				if(i > 0) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k]);
				if(j > 0) dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k]);
				int _lcp = lcp[i][j];
				if(_lcp > 0) {
					int tmp = (i - _lcp >= 0 && j - _lcp >= 0 ? dp[i - _lcp][j - _lcp][k - 1] : 0) + _lcp;
					dp[i][j][k] = max(dp[i][j][k], tmp);
				}
			}
		}
	}

	int res = 0;

	for(int k = 1;k <= kk;k++) res = max(res, dp[n - 1][m - 1][k]);

	cout << res << '\n';

	return true;
}

int main() {

	//while(solve());
	solve();

	return 0;
}