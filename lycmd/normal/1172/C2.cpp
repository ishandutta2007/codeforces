#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=200010,M=3010,MOD=998244353;
int n,m,a[N],w[N],s[M],f[M][M],g[M][M];
int qpow(int x,int y){
	return y?qpow(x*x%MOD,y>>1)*(y&1?x:1)%MOD:1; 
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>w[i],s[a[i]]+=w[i];
	for(int i=0;i<=m;i++)
		f[i][m-i]=g[i][m-i]=1;
	for(int i=m;~i;i--)
		for(int j=min(s[0],m-i-1);~j;j--){
			int cur=qpow(s[0]+s[1]+i-j,MOD-2);
			f[i][j]=((f[i+1][j]*(s[1]+i+1)%MOD+
				f[i][j+1]*(s[0]-j)%MOD)%MOD*cur%MOD);
			g[i][j]=((g[i+1][j]*(s[1]+i)%MOD+
				g[i][j+1]*(s[0]-j-1)%MOD)%MOD*cur%MOD);
		}
	for(int i=1;i<=n;i++)
		cout<<w[i]*(a[i]?f[0][0]:g[0][0])%MOD<<"\n";
}