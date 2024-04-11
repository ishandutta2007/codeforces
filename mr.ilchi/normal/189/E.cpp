/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int,int> pii;

const int MAXN = 100000+10;
const int inf = 1000000000;

int n,e,k,start,finish;
int a[MAXN],par[MAXN],dis[MAXN],poi[MAXN];
vector <int> adj[MAXN];

int root (int x){
	return (par[x]!=x) ? (par[x] = root(par[x])) : (x);
}

void Union (int a, int b){
	a=root(a); 
	b=root(b);
	par[a] = b;
}

int main(){
	cin >> n >> e >> k;
	for (int i=0; i<k; i++){
		cin >> a[i];
		a[i]--;
	}
	for (int i=0; i<e; i++){
		int e1,e2; cin >> e1 >> e2;
		e1--; e2--;
		adj[e1].push_back(e2);
		adj[e2].push_back(e1);
	}
	for (int i=0; i<n; i++)
		par[i] = i;
	cin >> start >> finish; 
	start--; finish--;
	a[k++] = finish;
	memset(dis,-1,sizeof dis);
	queue <int> Q;
	for (int i=0; i<k; i++) if (dis[a[i]]==-1){
		dis[a[i]] = 0;
		poi[a[i]] = a[i];
		Q.push(a[i]);
	}
	int ans = inf;
	while (!Q.empty()){
		queue <int> QQ;
		vector <pii> check; 
		while (!Q.empty()){
			int front = Q.front(); Q.pop();
			vector <int> unCheck;
			for (int i=0; i<(int)adj[front].size(); i++){
				int tmp = adj[front][i];
				if (dis[tmp]==-1){
					poi[tmp] = poi[front];
					dis[tmp] = dis[front] + 1;
					QQ.push(tmp);
				}else if (dis[tmp] == dis[front]){
					Union(poi[tmp],poi[front]);
					if (root(start) == root(finish))
						ans = min(ans, dis[tmp] + dis[front] + 1);
				}else if (dis[tmp] == dis[front] + 1)
					check.push_back(pii(front,tmp));;
			}
		}
		for (int i=0; i<(int)check.size(); i++){
			Union(poi[check[i].first], poi[check[i].second]);
			if (root(start) == root(finish))
				ans = min(ans, dis[check[i].first] + dis[check[i].second] + 1);
		}
		Q = QQ;
	}
	cout << (ans==inf ? -1 : ans) << endl;
	return 0;
}