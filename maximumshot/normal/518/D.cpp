#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <tuple>
#include <fstream>
#include <stdio.h>
#include <cstring>
#include <map>
#include <queue>

#include <time.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;

const int inf = 1000000000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);

bool solve() {

	int n, t;
	ld p;

	cin >> n >> p >> t;

	vec< vec< ld > > dp(t + 1, vec< ld >(n + 1));

	dp[0][0] = 1.0;

	for(int i = 0;i < t;i++) {
		for(int j = 0;j <= n;j++) {
			if(j == n) {
				dp[i + 1][j] += dp[i][j];
			}else {
				dp[i + 1][j] += dp[i][j] * (1 - p);
				dp[i + 1][j + 1] += dp[i][j] * p;
			}
		}
	}

	ld ans = 0.0;

	for(int i = 1;i <= n;i++) {
		ans += dp[t][i] * (ld)i;
	}

	cout.precision(10);
	cout << fixed << ans << '\n';

	return true;	
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}