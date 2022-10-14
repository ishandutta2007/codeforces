#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=233333;
int n,ans,t,dep[N];
vector<pair<int,int> >e[N];
void dfs(int x,int fa){
	t=max(t,dep[x]);
	for(auto i:e[x]){
		int y=i.first,k=i.second;
		if(y==fa)continue;
		dep[y]=dep[x]+k,dfs(y,x);
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<n;i++){
		int a,b,c;
		cin>>a>>b>>c;
		e[a].push_back({b,c});
		e[b].push_back({a,c});
		ans+=2*c;
	}
	dfs(1,0);
	cout<<ans-t<<"\n";
}