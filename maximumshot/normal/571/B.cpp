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

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ll inf = 1000000000ll;
const ll inf64 = inf * inf;
const ll base = inf + 7;

bool solve() 
{
	int n, k;

	scanf("%d %d", &n, &k);

	vec< ll > a(n + 1);
	for(int x, i = 1;i <= n;i++) {
		scanf("%d", &x);
		a[i] = x;
	}

	sort(a.begin() + 1, a.end());

	vec< vec< ll > > dp(n % k + 1, vec< ll >(k - n % k + 1, inf64));

	// dp[big][small]

	dp[0][0] = 0;

	for(int big = 0;big <= n % k;big++) {
		for(int small = 0;small <= k - n % k;small++) {
			if(small > 0) {
				int l, r;
				r = small * (n / k) + big * (n / k + 1);
				l = r - (n / k) + 1;
				dp[big][small] = min(dp[big][small], dp[big][small - 1] + a[r] - a[l]);
			}
			if(big > 0) {
				int l, r;
				r = small * (n / k) + big * (n / k + 1);
				l = r - (n / k + 1) + 1;
				dp[big][small] = min(dp[big][small], dp[big - 1][small] + a[r] - a[l]);
			}
		}
	}

	cout << dp[n % k][k - n % k] << '\n';

	return true;
}

int main() {

	//while(solve());
	solve();    

	return 0;
}