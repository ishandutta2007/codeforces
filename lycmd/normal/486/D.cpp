#include<bits/stdc++.h>
#define int long long 
using namespace std;
int const N=2010,MOD=1000000007;
int n,d,ans,a[N],f[N];
vector<int>e[N];
void add(int&x,int y){
	x=(x+y)%MOD;
}
void dfs(int x,int fa,int p){
	f[x]=1;
	for(int y:e[x]){
		if(y==fa||a[y]<a[p]||(a[y]==a[p]&&y<p)||a[y]-a[p]>d)continue;
		dfs(y,x,p),add(f[x],f[x]*f[y]%MOD);
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>d>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
		dfs(i,0,i),add(ans,f[i]);
	cout<<ans<<"\n";
}