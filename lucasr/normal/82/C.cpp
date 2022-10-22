#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;

#define all(x) x.begin(),x.end()
#define FOR(it,x) for(__typeof(x.begin())it=x.begin();it!=x.end();++it)
#define bits(x) __builtin_popcount(x)

vector<int> adj[5005];
vector<int> capAdj[5005];
int n;
map<int,int> prio;
int parent[5005];
int cap[5005];

int bfs(int from) {
	queue<int> cola;
	int vis[n];
	memset(vis,0,sizeof(vis));
	cola.push(from);
	vis[from]=true;
	parent[from]=-1;
	while (!cola.empty()) {
		int cu=cola.front(); cola.pop();
		for (int i=0;i<adj[cu].size();i++) {
			int v=adj[cu][i];
			if (!vis[v]) {
				vis[v]=true;
				cola.push(v);
				parent[v]=cu;
				cap[v]=capAdj[cu][i];
			}
		}
	}
}

vector<int> who[5005];
vector<int> nwho[5005];
int ans[5005];

int main(){
	int tmp, tmp2, tmp3;
	cin>>n;
	
	for (int i=0;i<n;i++) {
		cin>>tmp;
		who[i].push_back(tmp);
		prio[tmp]=i;
	}
	for (int i=0;i<n-1;i++) {
		cin>>tmp>>tmp2>>tmp3;
		tmp--; tmp2--;
		adj[tmp].push_back(tmp2);
		capAdj[tmp].push_back(tmp3);
		adj[tmp2].push_back(tmp);
		capAdj[tmp2].push_back(tmp3);
	}
	
	bfs(0);
	ans[0]=0;
	int llego=1, day=1;
	while (llego < n) {
		for (int i=0;i<n;i++) nwho[i].clear();
		for (int i=1;i<n;i++) if (!who[i].empty()) {
			sort(all(who[i]));
			int j;
			for (j=0;j<cap[i] && j<who[i].size();j++) {
				nwho[parent[i]].push_back(who[i][j]);
				if (parent[i]==0) {
					ans[prio[who[i][j]]] = day;
					llego++;
				}
			}
			for (;j<who[i].size();j++) {
				nwho[i].push_back(who[i][j]);
			}
		}
		for (int i=0;i<n;i++) who[i]=nwho[i];
		day++;
	}
	
	for (int i=0;i<n;i++) {
		if (i!=0) cout<<" ";
		cout<<ans[i];
	}
	cout<<endl;
	return 0;
}