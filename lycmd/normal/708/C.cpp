#include<bits/stdc++.h>
using namespace std;
int const N=400010;
int n,m,ans[N],sz[N],hs[N],f1[N],f2[N],p[N],mx[N];
vector<int>e[N];
void dfs1(int x,int fa){
	sz[x]=1;
	for(int y:e[x]){
		if(y==fa)
			continue;
		dfs1(y,x),sz[x]+=sz[y];
		int w=sz[y]>m?f1[y]:sz[y];
		if(sz[y]>sz[hs[x]])
			hs[x]=y;
		if(w>f1[x])
			f2[x]=f1[x],f1[x]=w,p[x]=y;
		else if(w>f2[x])
			f2[x]=w;
	}
}
void dfs2(int x,int fa){
	ans[x]=sz[hs[x]]>m?sz[hs[x]]-f1[x]<=m:
		n-sz[x]>m?n-sz[x]-mx[x]<=m:1;
	for(int y:e[x])
		if(y!=fa)
			mx[y]=max(n-sz[x]>m?mx[x]:n-sz[x],p[x]^y?f1[x]:f2[x]),dfs2(y,x);
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n,m=n/2;
	for(int i=1,x,y;i<n;i++)
		cin>>x>>y,e[x].push_back(y),e[y].push_back(x);
	dfs1(1,0),dfs2(1,0);
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	cout<<"\n";
}