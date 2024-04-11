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
typedef pair<llint, llint> P;

llint n, m;
llint t[500005];
vector<llint> G[500005];
vector<llint> vec[500005];
vector<llint> ans;
bool used[500005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	llint u, v;
	for(int i = 1; i <= m; i++){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	for(int i = 1; i <= n; i++){
		cin >> t[i];
		vec[t[i]].push_back(i);
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < vec[i].size(); j++){
			llint v = vec[i][j];
			for(int k = 1; k <= i; k++) used[k] = false;
			for(int k = 0; k < G[v].size(); k++){
				llint u = G[v][k];
				used[t[u]] = true;
			}
			for(int k = 1; k < i; k++){
				if(!used[k]){
					cout << -1 << endl;
					return 0;
				}
			}
			if(used[i]){
				cout << -1 << endl;
				return 0;
			}
			ans.push_back(v);
		}
	}
	for(int i = 0; i < ans.size(); i++) cout << ans[i] << " "; cout << endl;
	
	return 0;
}