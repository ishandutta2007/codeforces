#include<bits/stdc++.h>
using namespace std;
int const N=205,M=1010,MOD=1000000007;
int n,m,ans,a[N],f[N][N][M];
void add(int&x,long long y){
	x=(x+y%MOD)%MOD;
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	f[0][0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=i;j++)
			for(int k=0;k<=m;k++){
				int t=a[i]-a[i-1];
				if(j&&k>=(j-1)*t)
					add(f[i][j][k],f[i-1][j-1][k-(j-1)*t]);
				if(j<n&&k>=(j+1)*t)
					add(f[i][j][k],1ll*f[i-1][j+1][k-(j+1)*t]*(j+1));
				if(k>=j*t)
					add(f[i][j][k],1ll*f[i-1][j][k-j*t]*(j+1));
			}
	for(int i=0;i<=m;i++)
		add(ans,f[n][0][i]);
	cout<<ans<<"\n";
}