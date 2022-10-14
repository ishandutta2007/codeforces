#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=200010;
int n,m,k,a[N],b[N],f[N],s[N];
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int x,y;m--;)
		cin>>x>>y,b[x]=max(b[x],y);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	memset(f,0x3f,sizeof f),f[0]=0;
	for(int i=1;i<=k;i++)
		for(int j=1;j<=i;j++)
			f[i]=min(f[i],f[i-j]+s[i]-s[i-j+b[j]]);
	cout<<f[k]<<"\n";
}