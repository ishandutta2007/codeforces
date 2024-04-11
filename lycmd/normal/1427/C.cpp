#include<bits/stdc++.h>
using namespace std;
int const N=100010;
int n,r,ans,f[N],t[N],x[N],y[N],g[N];
int main(){
	ios::sync_with_stdio(0);
	cin>>r>>n;
	for(int i=1;i<=n;i++)
		cin>>t[i]>>x[i]>>y[i];
	x[0]=y[0]=1;
	memset(f,0xcc,sizeof f),f[0]=0;
	for(int i=1;i<=n;i++){
		int j=i-1;
		for(;j>=0&&t[i]-t[j]<=2*r;j--)
			if(abs(x[i]-x[j])+abs(y[i]-y[j])<=t[i]-t[j])
				f[i]=max(f[i],f[j]+1);
		if(j>=0)
			f[i]=max(f[i],g[j]+1);
		g[i]=max(g[i-1],f[i]);
	}
	cout<<g[n]<<"\n";
}