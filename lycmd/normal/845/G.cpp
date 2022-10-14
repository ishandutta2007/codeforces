#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=100010,M=30;
int n,m,ans,d[N],b[N];
vector<pair<int,int> >e[N];
void add(int x){
	for(int i=M;~i;i--)
		if(x>>i&1){
			if(b[i])
				x^=b[i];
			else
				return b[i]=x,void();
		}
}
void dfs(int x,int v){
	d[x]=v;
	for(auto i:e[x]){
		int y=i.first,w=i.second;
		if(~d[y])
			add(d[y]^w^v);
		else
			dfs(y,v^w);
	}
}
signed main(){
	ios::sync_with_stdio(0);
	for(cin>>n>>m;m--;){
		int a,b,c;cin>>a>>b>>c;
		e[a].push_back({b,c});
		e[b].push_back({a,c});
	}
	memset(d,-1,sizeof d),dfs(1,0),ans=d[n];
	for(int i=M;~i;i--)
		if((ans^b[i])<ans)
			ans^=b[i];
	cout<<ans<<"\n";
}