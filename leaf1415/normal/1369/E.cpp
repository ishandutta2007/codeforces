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
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define mod 1000000007

using namespace std;
typedef pair<llint, llint> P;

struct edge{
	llint to, id;
	edge(){}
	edge(llint a, llint b){
		to = a, id = b;
	}
};

llint n, m;
vector<edge> G[200005];
llint w[200005];
bool used[200005];
set<P> S;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> w[i];
	
	llint u, v;
	for(int i = 1; i <= m; i++){
		cin >> u >> v;
		G[u].push_back(edge(v, i));
		G[v].push_back(edge(u, i));
	}
	
	for(int i = 1; i <= n; i++){
		w[i] = (llint)G[i].size() - w[i];
		S.insert(P(w[i], i));
	}
	
	vector<llint> ans;
	while(S.size() && S.begin()->first <= 0){
		llint v = S.begin()->second;
		used[v] = true;
		S.erase(P(w[v], v));
		for(int i = 0; i < G[v].size(); i++){
			llint u = G[v][i].to;
			if(used[u]) continue;
			ans.push_back(G[v][i].id);
			S.erase(P(w[u], u));
			w[u]--;
			S.insert(P(w[u], u));
		}
	}
	if(S.size() > 0) cout << "DEAD" << endl;
	else{
		cout << "ALIVE" << endl;
		reverse(ans.begin(), ans.end());
		for(int i = 0; i < ans.size(); i++) cout << ans[i] << " "; cout << endl;
	}
	
	return 0;
}