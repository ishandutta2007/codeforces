#include<bits/stdc++.h>
using namespace std;
int const N=200010;
int t,n,ans,k;
vector<int>e[N];
int dfs(int x,int fa){
	int flg=0;
	for(int y:e[x])
		if(y^fa){
			int t=dfs(y,x);
			flg|=t,!fa&&(k|=t);
		}
	return fa&&flg?(ans-=2,0):1;
}
int main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n,ans=n;
		for(int i=1;i<=n;i++)
			e[i].clear();
		for(int i=1;i<n;i++){
			int x,y;cin>>x>>y;
			e[x].push_back(y);
			e[y].push_back(x);
		}
		dfs(1,k=0),cout<<ans-k<<"\n";
	}
}