#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple 

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const ll inf = 1000000000ll;
const ll inf64 = inf * inf;
const ll base = inf + 7;

bool solve()
{
	int n, k;

	scanf("%d %d", &n, &k);

	vec< int > a(n + 1);

	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);

	vec< vec< ull> > dp(n + 1, vec< ull >(k + 2)), c;
	c = dp;

	for(int i = 1;i <= n;i++) {
		dp[i][1] = 1;
		int value = a[i];
		for(int j = 2;j <= k + 1;j++) {
			for(int cur = value;cur > 0;cur = (cur & (cur + 1)) - 1) {
				dp[i][j] += c[cur][j - 1];
			}
		}
		for(int j = 1;j <= k + 1;j++) {
			for(int cur = value;cur <= n;cur = (cur | (cur + 1))) {
				c[cur][j] += dp[i][j];
			}
		}
	}

	ull ans = 0;

	for(int i = 1;i <= n;i++) ans += dp[i][k + 1];

	cout << ans << '\n';

	return true;
} 

int main() {
	
	//while(solve());
	solve();	

	return 0;
}