#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#include <complex>
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll n;
vector<ll> G[100005];
double dp[100005];

void dfs(int v, int p)
{
	ll cnt = 0; double sum = 0;
	for(auto u : G[v]){
		if(u == p) continue;
		dfs(u, v);
		sum += dp[u]+1, cnt++;
	}
	if(cnt == 0) dp[v] = 0;
	else dp[v] = sum / cnt;
}

int main(void)
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n;
	ll u, v;
	rep(i, 1, n-1){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1, -1);
	
	printf("%.11f\n", dp[1]);
	
	return 0;
}