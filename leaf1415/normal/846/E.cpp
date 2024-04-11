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

struct edge{
	ll to, cost;
	edge(){}
	edge(ll a, ll b){
		to = a, cost = b;
	}
};

ll n;
ll a[100005], b[100005];
vector<edge> G[100005];
bool used[100005];

bool dfs(int v, ll s)
{
	used[v] = true;
	s += b[v] - a[v];
	
	bool ret = false;
	if(G[v][0].cost >= 2) ret = true;
	if(used[G[v][0].to]) return s >= 0;
	return ret || dfs(G[v][0].to, s);
}

ll calc(ll v)
{
	used[v] = true;
	ll ret = b[v] - a[v];
	for(auto e : G[v]){
		ll res = calc(e.to);
		if(res >= 0) ret += res;
		else{
			if(abs(res) > 1e18 / e.cost){
				cout << "NO" << endl;
				exit(0);
			}
			ret += res * e.cost;
		}
		if(ret < -2e17){
			cout << "NO" << endl;
			exit(0);
		}
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) cin >> b[i];
	rep(i, 1, n) cin >> a[i];
	
	ll x, k;
	rep(i, 2, n){
		cin >> x >> k;
		G[x].push_back(edge(i, k));
	}
	
	if(calc(1) < 0){
		cout << "NO" << endl;
		return 0;
	}
	
	rep(i, 1, n){
		if(used[i]) continue;
		if(!dfs(i, 0)){
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	
	return 0;
}