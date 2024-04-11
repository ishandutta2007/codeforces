#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=233; 
int n,d,a[N],x[N],y[N],f[N][N];
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>d;
	for(int i=2;i<n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>x[i]>>y[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i^j)f[i][j]=d*(abs(x[i]-x[j])+abs(y[i]-y[j]))-a[i];
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	cout<<f[1][n]<<"\n";
}