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
#define outl(x) cout << (x) << endl

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

struct GaussianElimination{
	vector<llint> vec;
	int dim;
	
	GaussianElimination(){
		init();
	}
	void init(){
		dim = 0;
		vec.clear();
	}
	void add(llint x) //
	{
		vec.push_back(x);
		int n = vec.size();
		
		int r = 0, p = -1;
		for(int i = 59; i >= 0 && r < n-1; i--){ //
			if((vec[r]&(1LL<<i)) == 0){
				if((vec[n-1]&(1LL<<i)) == 0 || p != -1) goto end;
				if(p == -1) p = r;
			}
			else if(vec[n-1]&(1LL<<i)) vec[n-1] ^= vec[r];
			r++;
			end:;
		}
		if(p != -1){
			llint tmp = vec[n-1];
			for(int i = n-1; i >= p+1; i--) vec[i] = vec[i-1];
			vec[p] = tmp;
		}
		if(vec[dim]) dim++;
	}
	
	bool check(llint x) //
	{
		int n = vec.size();
		
		int r = 0;
		for(int i = 59; i >= 0 && r < n; i--){
			if((x & (1LL<<i)) == 0){
				if(vec[r] & (1LL<<i)) r++;
				continue;
			}
 			if((vec[r]&(1LL<<i)) == 0) return false;
			x ^= vec[r];
			r++;
		}
		return x == 0;
	}
};


struct edge{
	ll to, cost;
	edge(){}
	edge(ll a, ll b){
		to = a, cost = b;
	}
};

ll n, m;
vector<edge> G[100005];
bool used[100005];
ll sum[100005];
GaussianElimination ge;

void dfs(int v, ll s)
{
	used[v] = true, sum[v] = s;
	for(auto e : G[v]){
		ll u = e.to;
		if(used[u]){
			ll x = sum[v] ^ sum[u] ^ e.cost;
			if(x) ge.add(x);
			continue;
		}
		dfs(u, s ^ e.cost);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	ll u, v, w;
	rep(i, 1, m){
		cin >> u >> v >> w;
		G[u].push_back(edge(v, w));
		G[v].push_back(edge(u, w));
	}
	dfs(1, 0);
	
	ll b = sum[1] ^ sum[n];
	
	ll pos = 59;
	rep(i, 0, (int)ge.vec.size()-1){
		while(pos >= 0 && (ge.vec[i] & (1LL<<pos)) == 0) pos--;
		if(pos < 0) break;
		if(b & (1LL<<pos)) b ^= ge.vec[i];
	}
	cout << b << endl;
	
	return 0;
}