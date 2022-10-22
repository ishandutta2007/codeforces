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
typedef pair< ll, ll > pll;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1ll * inf * inf;

int n;
vec< int > a;

const int LOG = 21;
vec< pii > rmq[LOG];
vec< int > lg;

void build() {
	int cur = 0;
	while((1 << cur) <= n) cur++;
	lg.resize(n + 1);
	for(int i = n;i > 0;i--) {
		if((1 << cur) > i) cur--;
		lg[i] = cur; 
	}

	for(int i = 0;i < LOG;i++) {
		rmq[i].resize(n + 1, mp(0, 0));
	}

	for(int i = 1;i <= n;i++) {
		rmq[0][i] = mp(a[i], i);
	}

	for(int i = 1;i < LOG;i++) {
		for(int j = 1;j + (1 << (i - 1)) <= n;j++) {
			rmq[i][j] = max(rmq[i - 1][j], rmq[i - 1][j + (1 << (i - 1))]);
		}		
	}
}

pii get(int l, int r) {
	int LG = lg[r - l + 1];
	return max(rmq[LG][l], rmq[LG][r - (1 << LG) + 1]);
}

bool solve() {
	
	scanf("%d", &n);

	a.resize(n + 1);

	for(int i = 1;i < n;i++) scanf("%d", &a[i]);
	a[n] = n + 1;

	build();

	vec< ll > dp(n + 1);
	ll res = 0;

	for(int i = n - 1;i > 0;i--) {
		int to = get(i + 1, a[i]).second;
		int T = a[i];
		//cout << i << ' ' << to << '\n';
		dp[i] = n - T + dp[to] - (T - to) + T - i;
		res += dp[i];
	}

	cout << res << '\n';

	return true;
}

int main() {
		
	//while(solve());
	solve();

	return 0;
}