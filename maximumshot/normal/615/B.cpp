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

bool solve() {

	int n, m;

	cin >> n >> m;

	vec< vec< int > > e(n + 1); 
	vec< int > deg(n + 1, 0);

	for(int i = 0;i < m;i++) {
		int u, v;
		cin >> u >> v;
		deg[u]++;
		deg[v]++;
		if(u > v) swap(u, v);
		e[v].push_back(u);
	}

	vec< int > dp(n + 1);
	ll ans = 0;

	for(int i = 1;i <= n;i++) {
		dp[i] = 1;
		for(auto to : e[i]) dp[i] = max(dp[i], dp[to] + 1);
		ans = max(ans, 1ll * dp[i] * deg[i]);
	}
	
	cout << ans << '\n';

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}