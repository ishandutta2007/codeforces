#include<bits/stdc++.h>
using namespace std;
int const N=150010;
int n,m,x[N],y[N],sz[N],se[N],f[N];
int find(int x){
	return x^f[x]?f[x]=find(f[x]):x;
}
void merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx^fy)f[fx]=fy,sz[fy]+=sz[fx];
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		f[i]=i,sz[i]=1;
	for(int i=1;i<=m;i++)
		cin>>x[i]>>y[i],merge(x[i],y[i]);
	for(int i=1;i<=m;i++)
		se[find(x[i])]++;
	for(int i=1;i<=n;i++)
		if(f[i]==i&&se[i]!=1ll*sz[i]*(sz[i]-1)/2)
			cout<<"NO\n",exit(0);
	cout<<"YES\n";
}