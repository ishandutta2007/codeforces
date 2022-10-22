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

ll n, m;
vector<ll> G[100005];
ll deg[100005], ans[100005];
priority_queue<ll> Q;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	ll u, v;
	rep(i, 1, m){
		cin >> u >> v;
		G[v].push_back(u);
		deg[u]++;
	}
	rep(i, 1, n) if(deg[i] == 0) Q.push(i);
	
	for(int i = n; i >= 1; i--){
		int v = Q.top(); Q.pop();
		ans[v] = i;
		for(auto u : G[v]){
			deg[u]--;
			if(deg[u] == 0) Q.push(u);
		}
	}
	rep(i, 1, n) cout << ans[i] << " "; cout << endl;
	
	return 0;
}