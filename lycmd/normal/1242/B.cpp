#include<bits/stdc++.h>
using namespace std;
int const N=233333;
int n,m,ans,f[N],sz[N],deg[N],vis[N],inq[N];
vector<int>e[N];
int find(int x){
	return x==f[x]?x:f[x]=find(f[x]);
}
void merge(int x,int y){
	f[find(x)]=find(y);
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)f[i]=i;
	while(m--){
		int x,y;cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
		deg[x]++,deg[y]++;
	}
	int mn=n,p;
	for(int i=1;i<=n;i++)
		if(deg[i]<mn)mn=deg[i],p=i;
	memset(vis,0,sizeof vis);
	for(int i=0;i<e[p].size();i++)
		vis[e[p][i]]++;
	for(int i=1;i<=n;i++)
		if(vis[i]){
			memset(inq,0,sizeof inq);
			for(int j=0;j<e[i].size();j++)
				inq[e[i][j]]++;
			for(int j=1;j<=n;j++)
				if(!inq[j])
					merge(j,i);
		}else merge(i,p);
	for(int i=1;i<=n;i++)
		sz[find(i)]++;
	for(int i=1;i<=n;i++)
		ans+=!!sz[i];
	cout<<ans-1<<"\n";
}