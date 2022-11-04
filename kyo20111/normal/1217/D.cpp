#include<bits/stdc++.h>
using namespace std;
int n,m,chk[5050],c[5050],fl,c2[5050];
vector<pair<int,int>> v[5050];
bool dfs(int cur){
	if(c2[cur]) return c[cur];
	c2[cur] = 1;
	c[cur] = 1;
	for(pair<int,int> nxt : v[cur]){
		if(dfs(nxt.first)){
			fl = 1;
			chk[nxt.second] = 1;
		}
	}
	c[cur] = 0;
	return false;
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		int a,b; scanf("%d %d",&a,&b);
		v[a].push_back({b,i});
	}
	for(int i=1;i<=n;i++) if(!c[i]) dfs(i);
	printf("%d\n",fl+1);
	for(int i=1;i<=m;i++) printf("%d ",chk[i]+1);
}