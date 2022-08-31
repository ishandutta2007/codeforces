#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<int> edges[1100000];
int deg[1100000];
int hasedge[1100000];
int vis[1100000];
void dfs(int a){
	if(vis[a]) return;
	vis[a] = 1;
	for(int b = 0; b < edges[a].size(); b++){
		dfs(edges[a][b]);
	}
}
int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	int loops = 0;
	for(int i = 0; i < n; i++){
		deg[i] = 0;
		hasedge[i] = 0;
		vis[i] = 0;
	}
	for(int i = 0; i < m; i++){
		int a, b;
		scanf("%d%d", &a, &b);
		a--; b--;
		hasedge[a] = 1;
		hasedge[b] = 1;
		if(a == b){
			loops++;
		} else {
			edges[a].push_back(b);
			edges[b].push_back(a);
			deg[a]++;
			deg[b]++;
		}
	}
	for(int i = 0; i < n; i++){
		if(hasedge[i]){
			dfs(i);
			break;
		}
	}
	for(int i = 0; i < n; i++){
		if(hasedge[i] && !vis[i]){
			cout << 0 << endl;
			return 0;
		}
	}
	LL ans = 0;
	LL l = loops;
	ans += (l*(l-1))/2;
	LL m2 = m;
	ans += l*(m2-l);
	for(int i = 0; i < n; i++){
		LL d = deg[i];
		ans += (d*(d-1))/2;
	}
	cout << ans << endl;

}