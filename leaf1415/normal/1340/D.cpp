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

using namespace std;
typedef pair<int, int> P;

llint n;
vector<llint> G[100005];
vector<P> ans;

void dfs(int v, int p, int s)
{
	llint t = s-1, deg = 0;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		deg++;
	}
	if(deg == 0){
		ans.push_back(P(v, t));
		return;
	}
	
	vector<llint> vec;
	for(int i = 0; i < max(0LL, deg-t); i++) vec.push_back(s+i);
	deg = min(deg, t);
	for(int i = 0; i < deg; i++) vec.push_back(t-deg+i);
	
	bool flag = false; int id = 0;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		if(!flag && vec[id] < s){
			ans.push_back(P(v, vec[id]));
			flag = true;
		}
		ans.push_back(P(G[v][i], vec[id]+1));
		dfs(G[v][i], v, vec[id]+1);
		ans.push_back(P(v, vec[id]+1));
		id++;
	}
	if(!flag) ans.push_back(P(v, t));
}

int main(void)
{
	cin >> n;
	llint u, v;
	for(int i = 1; i <= n-1; i++){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	if(n == 1){
		cout << 1 << endl;
		cout << 1 << " " << 0 << endl;
		return 0;
	}
	
	ans.push_back(P(1, 0));
	for(int i = 0; i < G[1].size(); i++){
		ans.push_back(P(G[1][i], i+1));
		dfs(G[1][i], 1, i+1);
		ans.push_back(P(1, i+1));
	}
	
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++) cout << ans[i].first << " " << ans[i].second << "\n";
	flush(cout);
	
	return 0;
}