#include <bits/stdc++.h>
#define maxn 100005
int n,m,degr[maxn]={0},arr[maxn],arr2[maxn],tl=0,tl2=0,u,v,vis[maxn]={0};
std::vector<int>conj[maxn];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		scanf("%d%d",&u,&v);
		conj[v].push_back(u);conj[u].push_back(v);
		degr[u]++;degr[v]++;
	}int sel=1;
	for(int i=1;i<=n;++i)
		if (degr[u]<degr[sel])sel=u;
	for(int i=0;i<conj[sel].size();++i){vis[conj[sel][i]]=1;arr[++tl]=conj[sel][i];}
	for(int i=1;i<=n;++i)if(!vis[i])arr2[++tl2]=i;
	std::memset(vis,0,sizeof(vis));
	int ans=0;
	for(int i=1;i<=tl2;++i){
	//	printf("%d ",arr2[i]);
		for(int j=0;j<conj[arr2[i]].size();++j)vis[conj[arr2[i]][j]]=1;
		std::stack<int>stk;
		for(int j=1;j<=tl;++j)if (!vis[arr[j]])stk.push(j);
		while (!stk.empty()){
			int u=stk.top();stk.pop();arr2[++tl2]=arr[u];std::swap(arr[u],arr[tl]);tl--;
		}
		for(int j=0;j<conj[arr2[i]].size();++j)vis[conj[arr2[i]][j]]=0;
		if (i==tl2){
			if (!tl)break;
			ans++;arr2[++tl2]=arr[tl];tl--;
		}
				
	}printf("%d",ans);	
	return 0;
}