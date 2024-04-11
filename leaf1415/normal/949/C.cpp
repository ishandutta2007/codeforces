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
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) =) min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll n, m, h;
ll a[100005];
vector<ll> G[100005], revG[100005];
vector<int> topo;
bool used[100005];
int scc[100005];

void tpsort(int v)
{
	used[v] = true;
	for(int i = 0; i < G[v].size(); i++){
		if(!used[G[v][i]]) tpsort(G[v][i]);
	}
	topo.push_back(v);
}
void sccdfs(int v, int id)
{
	used[v] = true;
	scc[v] = id;
	for(int i = 0; i < revG[v].size(); i++){
		if(!used[revG[v][i]]) sccdfs(revG[v][i], id);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> h;
	rep(i, 1, n) cin >> a[i];
	ll u, v;
	rep(i, 1, m){
		cin >> u >> v;
		if((a[u]+1)%h == a[v]) G[u].push_back(v), revG[v].push_back(u);
		if((a[v]+1)%h == a[u]) G[v].push_back(u), revG[u].push_back(v);
	}

	for(int i = 1; i <= n; i++) if(!used[i]) tpsort(i);
	reverse(topo.begin(), topo.end());

	int id = 0;
	for(int i = 1; i <= n; i++) used[i] = false;
	for(int i = 0; i < topo.size(); i++) if(!used[topo[i]]) sccdfs(topo[i], id++);

	map<ll, ll> mp;
	rep(i, 1, n) mp[scc[i]]++;
	rep(i, 1, n){
		for(auto u: G[i]){
			if(scc[i] != scc[u]) mp[scc[i]] = inf;
		}
	}

	ll ans = inf, ans_i;
	for(auto p : mp){
		if(ans > p.second){
			ans = p.second;
			ans_i = p.first;
		}
	}
	vector<ll> vec;
	rep(i, 1, n){
		if(scc[i] == ans_i) vec.push_back(i);
	}

	cout << vec.size() << endl;
	for(auto v : vec) cout << v << " "; cout << endl;

	return 0;
}