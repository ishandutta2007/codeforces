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
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long ll;
typedef long long llint;
typedef pair<llint, llint> P;

llint dtmp[200005];
void distdfs(vector<llint> G[], int v, int p, llint d)
{
	dtmp[v] = d;
	for(int i = 0; i < G[v].size(); i++){
		llint u = G[v][i], c = 1; //
		if(u == p) continue;
		distdfs(G, u, v, d+c);
	}
}

llint getDiameter(vector<llint> G[], llint n, llint &u, llint &v)
{
	distdfs(G, 1, -1, 0);
	llint max_val = -1, max_v;
	for(int i = 1; i <= n; i++){
		if(max_val < dtmp[i]){
			max_val = dtmp[i];
			max_v = i;
		}
	}
	u = max_v;

	distdfs(G, u, -1, 0);
	max_val = -1;
	for(int i = 1; i <= n; i++){
		if(max_val < dtmp[i]){
			max_val = dtmp[i];
			max_v = i;
		}
	}
	v = max_v;

	return max_val;
}

ll n, k;
vector<ll> G[200005];
queue<ll> Q;
vector<P> ans;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	if(n-k == 1){
		cout << 2 << endl;
		rep(i, 2, n) cout << 1 << " " << i << endl;
		return 0;
	}

	if(n-k == 2){
		cout << 3 << endl;
		cout << 1 << " " << 2 << endl;
		rep(i, 3, n) cout << i%2+1 << " " << i << endl;
		return 0;
	}

	ll id = 1;
	rep(i, 1, min(n-1-k, k)){
		id++;
		ans.push_back(P(1, id));
		Q.push(id);
	}

	while(id < n){
		id++;
		ans.push_back(P(Q.front(), id));
		if(id > n-k) Q.push(Q.front());
		else Q.push(id);
		Q.pop();
	}

	ll u, v;
	for(auto e : ans){
		u = e.first, v = e.second;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	cout << getDiameter(G, n, u, v) << endl;
	for(auto e : ans) cout << e.first << " " << e.second << endl;

	return 0;
}