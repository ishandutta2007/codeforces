#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<int> cents;

int target = 0;
vector<int> edges[220000];
vector<int> len[220000];
int used[220000];
int sz[220000];

int count(int par, int v){
	sz[v] = 1;
	for(int i = 0; i < edges[v].size(); i++){
		if(edges[v][i] != par) sz[v] += count(v,edges[v][i]);
	}
	return sz[v];
}

void find_centroid(int v){
	count(-1,v);
	int cur = v;
	int prev = -1;
	while(1){
		int found = 0;
		for(int i = 0; i < edges[cur].size(); i++){
			if(edges[cur][i] != prev){
				if(sz[edges[cur][i]]*2 > sz[v]){
					found = 1;
					prev = cur;
					cur = edges[cur][i];
					break;
				} else if(sz[edges[cur][i]]* 2 == sz[v]){
					cents.push_back(edges[cur][i]);
				}
			}
		}
		if(!found){
			cents.push_back(cur);
			return;
		}
	}
}

vector<int> ans1, ans2, ans3;

vector<int> pq, q;
void dfs(int par, int a){
	pq.push_back(par);
	q.push_back(a);
	for(int i = 0; i < edges[a].size(); i++){
		if(edges[a][i] == par) continue;
		dfs(a, edges[a][i]);
	}
}
void solve(int par, int a){
	pq.clear(); q.clear();
	dfs(par, a);
	if(pq.size() == 1) return;
	int x = par;
	int y = a;
	int yp = q[pq.size() - 1];
	ans1.push_back(x); ans2.push_back(y); ans3.push_back(yp);
	for(int j = pq.size() - 2; j >= 0; j--){
		x = q[j+1];
		y = pq[j+1];
		yp = q[j];
		ans1.push_back(x); ans2.push_back(y); ans3.push_back(yp);
	}
	q.push_back(par);
	for(int i = 2; i < q.size(); i++){
		ans1.push_back(q[i]);
		ans2.push_back(q[i-1]);
		ans3.push_back(q[1]);
	}
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0, a, b; i < n-1; i++){
		scanf("%d%d", &a, &b);

		a--; b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	find_centroid(0);
	cents.push_back(-1);
	for(int zz = 0; zz < cents.size(); zz++){
		int a = cents[zz];
		if(a == -1) continue;
		for(int j = 0; j < edges[a].size(); j++){
			int d = edges[a][j];
			if(d == cents[0] || d == cents[1]) continue;
			solve(a, d);
		}
	}

	printf("%d\n", ans1.size());
	for(int i = 0; i < ans1.size(); i++){
		printf("%d %d %d\n", ans1[i] + 1, ans2[i] + 1, ans3[i] + 1);
	}
}