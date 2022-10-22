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
vector<P> G[105];

void dfs(int v, int p, double t)
{
	t += 1;
	while(t >= 2) t -= 2;
	
	ll deg = G[v].size();
	
	for(auto e : G[v]){
		ll u = e.first, id = e.second;
		if(u == p) continue;
		t += 2.0 / deg; while(t >= 2) t -= 2;
		
		cout << 1 << " " << id << " ";
		if(t <= 1){
			cout << u << " " << v << " ";
			printf("%.11f\n", 1-t);
		}
		else{
			cout << v << " " << u << " ";
			printf("%.11f\n", 2-t);
		}
		dfs(u, v, t);
	}
}

int main(void)
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n;
	ll u, v;
	rep(i, 1, n-1){
		cin >> u >> v;
		G[u].push_back(P(v, i));
		G[v].push_back(P(u, i));
	}
	
	cout << n-1 << endl;
	dfs(1, -1, 0);
	
	return 0;
}