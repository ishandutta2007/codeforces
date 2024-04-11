#include<bits/stdc++.h>
using namespace std;
int const N=300010;
int t,n,m,ans,f[N];
vector<int>e[N];
void dfs(int x,int fa){
	int mx1=0,mx2=0;
	f[x]=0;
	for(int y:e[x])
		if(y!=fa){
			dfs(y,x),f[x]=max(f[x],f[y]);
			if(f[y]>mx1)mx2=mx1,mx1=f[y];
			else if(f[y]>mx2)mx2=f[y];
		}
	f[x]+=max(1,(int)e[x].size()-(fa>0));
	ans=max(ans,mx1+mx2+max(1,(int)e[x].size()-1));
}
int main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n,ans=0;
		for(int i=1;i<=n;i++)
			e[i].clear();
		for(int i=1;i<n;i++){
			int x,y;cin>>x>>y;
			e[x].push_back(y);
			e[y].push_back(x);
		}
		dfs(1,0);
		cout<<ans<<"\n";
	}
}