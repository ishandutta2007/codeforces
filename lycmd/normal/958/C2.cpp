#include<bits/stdc++.h>
using namespace std;
int const N=500010,M=105;
int n,k,p,a[N],s[N],f[N][M],g[N][M];
int sum(int l,int r){
	return (s[r]-s[l-1]+p)%p;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>k>>p;
	for(int i=1;i<=n;i++)
		cin>>a[i],s[i]=(s[i-1]+a[i])%p;
	memset(f,0xcc,sizeof f),f[0][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++)
			f[i][j]=max(f[i][j],f[g[i-1][j-1]][j-1]+sum(g[i-1][j-1]+1,i));
		for(int j=0;j<=k;j++)
			g[i][j]=f[i][j]>f[g[i-1][j]][j]?i:g[i-1][j];
	}
	cout<<f[n][k]<<"\n";
}