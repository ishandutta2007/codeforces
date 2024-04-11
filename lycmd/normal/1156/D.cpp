#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=200010;
int n,ans,f[N][2],sz[N][2];
int find(int x,int o){
	return x^f[x][o]?f[x][o]=find(f[x][o],o):x;
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		f[i][0]=f[i][1]=i,sz[i][0]=sz[i][1]=1;
	for(int i=1,x,y,v;i<n;i++){
		cin>>x>>y>>v;
		int fx=find(x,v),fy=find(y,v);
		f[fx][v]=fy,sz[fy][v]+=sz[fx][v];
	}
	for(int i=1;i<=n;i++)
		ans+=sz[find(i,0)][0]*sz[find(i,1)][1]-1;
	cout<<ans<<"\n";
}