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

const int S = 10100;
const int base = inf + 7;

bool solve() {

	int n;
	scanf("%d", &n);

	vec< int > dp(2 * S, 0), dp2;

	int ans = 0;

	for(int x, i = 0;i < n;i++) {
		scanf("%d", &x);
		dp2 = dp;
		dp.clear();
		dp.resize(2 * S, 0);
		for(int s = 0;s < 2 * S;s++) {
			if(s - x >= 0) dp[s] = (dp[s] + dp2[s - x]) % base;
			if(s + x < 2 * S) dp[s] = (dp[s] + dp2[s + x]) % base;
		}
		dp[S + x] = (dp[S + x] + 1) % base;
		dp[S - x] = (dp[S - x] + 1) % base;
		ans = (ans + dp[S]) % base;
	}
	
	printf("%d\n", ans);

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}