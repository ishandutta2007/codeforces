#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=23333,INF=0x3f3f3f3f3f3f3f3fll;
int n,m,ans=INF,t[N],c[N],f[N];
signed main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>t[i]>>c[i],m=max(m,n+t[i]+1);
	memset(f,0x3f,sizeof f),f[0]=0;
	for(int i=1;i<=n;i++)
		for(int j=m;j>t[i];j--)
			f[j]=min(f[j],f[j-t[i]-1]+c[i]);
	for(int i=n;i<=m;i++)
		ans=min(ans,f[i]);
	cout<<ans<<"\n";
}