#include<bits/stdc++.h>
using namespace std;
int s[100001],f[100001];
vector<int>e[100001];
int solve(int u){
	int nxt;
	if(f[u]==-1)
	for(nxt=0,f[u]=s[u];nxt<e[u].size();nxt++)
	f[u]=max(f[u],max(0,s[u]-s[e[u][nxt]])+solve(e[u][nxt]));
	return f[u];
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int x=1;x<=n;x++)
	cin>>s[x],f[x]=-1;
	for(int x=1,u,v;x<=m;x++)cin>>u>>v,e[v+1].push_back(u+1);
	int ans=0;
	for(int e=1;e<=n;e++)ans=max(ans,solve(e));
	cout<<ans<<endl;
}