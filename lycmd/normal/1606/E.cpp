#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=505,MOD=998244353;
int n,k,ans,C[N][N],pw[N][N],f[N][N];
int qpow(int x,int y){
	return y?qpow(x*x%MOD,y>>1)*(y&1?x:1)%MOD:1;
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=0;i<N;i++)
		for(int j=0;j<=i;j++)
			C[i][j]=j&&j<i?(C[i-1][j]+C[i-1][j-1])%MOD:1;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			pw[i][j]=j?pw[i][j-1]*i%MOD:1;
	for(int i=2;i<=n;i++)
		for(int j=1;j<=k;j++)
			if(i>j)
				f[i][j]=(pw[j][i]-pw[j-1][i]+MOD)%MOD;
			else for(int p=1;p<=i;p++)
				f[i][j]=(f[i][j]+C[i][p]*f[p][j-i+1]%MOD*pw[i-1][i-p]%MOD)%MOD;
	for(int i=1;i<=k;i++)
		ans=(ans+f[n][i])%MOD;
	cout<<ans<<"\n";
}