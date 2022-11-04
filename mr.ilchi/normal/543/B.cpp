#include <bits/stdc++.h>
using namespace std;

int n,e;
int dis[3010][3010];
vector<int> adj[3010];

void bfs (int v){
	queue <int> Q;
	memset(dis[v],-1,sizeof dis[v]);
	dis[v][v] = 0;
	Q.push(v);
	while (!Q.empty()){
		int front = Q.front(); Q.pop();
		for (int i=0; i<(int)adj[front].size(); i++){
			int temp = adj[front][i];
			if (dis[v][temp] == -1){
				dis[v][temp] = dis[v][front] + 1;
				Q.push(temp);
			}
		}
	}
}

int main(){
	cin >> n >> e;
	for (int i=0; i<e; i++){
		int e1,e2; cin >> e1 >> e2;
		e1--; e2--;
		adj[e1].push_back(e2);
		adj[e2].push_back(e1);
	}
	for (int i=0; i<n; i++)
		bfs(i);
	int s1,t1,l1; cin >> s1 >> t1 >> l1; s1--; t1--; 
	int s2,t2,l2; cin >> s2 >> t2 >> l2; s2--; t2--;
	if (dis[s1][t1]>l1 || dis[s2][t2]>l2){
		cout << -1 << endl;
		return 0;
	}
	int ans = dis[s1][t1] + dis[s2][t2];
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++){
			int f1 = dis[s1][i] + dis[i][j] + dis[j][t1];
			int f2 = dis[s2][i] + dis[i][j] + dis[j][t2];
			if (f1<=l1 && f2<=l2) ans = min(ans,f1+f2-dis[i][j]);
			f2 = dis[t2][i] + dis[i][j] + dis[j][s2];
			if (f1<=l1 && f2<=l2) ans = min(ans,f1+f2-dis[i][j]);
		}
	cout << e-ans << endl;
	return 0;
}