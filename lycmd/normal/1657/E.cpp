#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=255,MOD=998244353;
int n,k,f[N][N],s[N][N],C[N][N],pw[N][N*N];
signed main(){
	cin>>n>>k,n--;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=i;j++)
			C[i][j]=!j||j==i?1:(C[i-1][j]+C[i-1][j-1])%MOD;
	for(int i=1;i<=k;i++)
		for(int j=0;j<=n*n;j++)
			pw[i][j]=j?pw[i][j-1]*i%MOD:1;
	f[0][0]=1;
	for(int i=1;i<=k;i++)
		for(int j=0;j<=n;j++)
			for(int t=0;j+t<=n;t++)
				f[i][j+t]=(f[i][j+t]+f[i-1][j]*C[n-j][t]%MOD*pw[k-i+1][((j+t)*(j+t-1)-j*(j-1))/2])%MOD;
	cout<<f[k][n]<<"\n"; 
}