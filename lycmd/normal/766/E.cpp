#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=100010;
int n,ans,a[N],f[N][2];
vector<int>e[N];
void dfs(int x,int fa,int b){
	int t=!!(a[x]&b);
	f[x][t]=1,f[x][!t]=0;
	for(int y:e[x]){
		if(y==fa)continue;
		dfs(y,x,b),ans+=b*(f[x][0]*f[y][1]+f[x][1]*f[y][0]);
		f[x][0]+=f[y][t],f[x][1]+=f[y][!t];
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],ans+=a[i];
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	for(int i=0;i<20;i++)
		dfs(1,0,1<<i);
	cout<<ans<<"\n";
}