#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T;
int n;
vector<int> G[1005];
vector<int> treeA, treeB;

int dist[1005];
void dfs(int v, int pre, int d)
{
	dist[v] = d;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == pre) continue;
		dfs(G[v][i], v, d+1);
	}
}

int main(void)
{
	cin >> T;
	for(int t = 0; t < T; t++){
		
		cin >> n;
		for(int i = 1; i <= n; i++) G[i].clear();
		int a, b;
		for(int i = 1; i <= n-1; i++){
			cin >> a >> b;
			G[a].push_back(b);
			G[b].push_back(a);
		}
		
		int k1, k2, v;
		treeA.clear(), treeB.clear();
		cin >> k1;
		for(int i = 0; i < k1; i++){
			cin >> v;
			treeA.push_back(v);
		}
		sort(treeA.begin(), treeA.end());
		cin >> k2;
		for(int i = 0; i < k2; i++){
			cin >> v;
			treeB.push_back(v);
		}
		sort(treeB.begin(), treeB.end());
		
		int res;
		cout << "B " << treeB[0] << endl;
		cin >> res;
		
		int rt = res;
		auto p = lower_bound(treeA.begin(), treeA.end(), rt);
		if(p != treeA.end() && *p == rt){
			cout << "C " << rt << endl;
			continue;
		}
		
		for(int i = 1; i <= n; i++) dist[i] = 0;
		dfs(rt, -1, 0);
		
		int min_dist = 5000, min_v;
		for(int i = 0; i < treeA.size(); i++){
			int v = treeA[i];
			if(min_dist > dist[v]){
				min_dist = dist[v];
				min_v = v;
			}
		}
		
		cout << "A " << min_v << endl;
		cin >> res;
		
		p = lower_bound(treeB.begin(), treeB.end(), res);
		if(p != treeB.end() && *p == res){
			cout << "C " << min_v << endl;
		}
		else cout << "C -1" << endl;
	}
	return 0;
}