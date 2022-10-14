#include<bits/stdc++.h>
using namespace std;
int const N=3010;
int n,q,x,y,i,j,a[N];
double ans,f[N][N];
int main(){
	cin>>n>>q;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			f[i][j]=a[i]>a[j];
	for(j=q;j--;){
		cin>>x>>y,f[x][y]=f[y][x]=(f[x][y]+f[y][x])/2;
		for(i=1;i<=n;i++)
			if(i^x&&i^y)
				f[i][x]=f[i][y]=(f[i][x]+f[i][y])/2,
				f[x][i]=f[y][i]=(f[x][i]+f[y][i])/2;
	}
	for(i=1;i<=n;i++)
		for(j=i;j<=n;j++)
			ans+=f[i][j];
	cout<<fixed<<setprecision(8)<<ans<<"\n";
}