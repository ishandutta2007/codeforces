#include<bits/stdc++.h>
using namespace std;
int const N=200010;
int n,a[N],f[N],sz[N],mrk[N];
long long ans[N];
vector<int>e[N],g[N];
int find(int x){
	return x^f[x]?f[x]=find(f[x]):x;
}
int merge(int x,int y){
	int fx=find(x),fy=find(y);
	return fx^fy?(f[fx]=fy,sz[fy]+=sz[fx],1):0; 
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=1;j*j<=a[i];j++)
			if(a[i]%j==0){
				g[j].push_back(i);
				if(j*j<a[i])
					g[a[i]/j].push_back(i);
			}
	}
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	for(int i=1;i<N;i++){
		for(int x:g[i])
			f[x]=x,sz[x]=mrk[x]=1;
		for(int x:g[i])
			for(int y:e[x])
				if(mrk[y])
					merge(x,y);
		for(int x:g[i])
			if(x==find(x))
				ans[i]+=1ll*sz[x]*(sz[x]+1)/2;
		for(int x:g[i])
			mrk[x]=0;
	}
	for(int i=N-1;i;i--)
		for(int j=i*2;j<N;j+=i)
			ans[i]-=ans[j];
	for(int i=1;i<N;i++)
		if(ans[i])
			cout<<i<<" "<<ans[i]<<"\n";
}