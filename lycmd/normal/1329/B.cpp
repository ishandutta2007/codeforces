#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=45;
int t,n,m,MOD,ans,a[N][N],b[N][N],hib[N];
int len(int x){
	return x?len(x>>1)+1:x;
}
signed main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>m>>MOD,n=__lg(m)+1;
		int k=__lg(m)+2;
		for(int i=0;i<=k;i++)
			a[1][i]=1,b[1][i]=((1ll<<i)-1)%MOD;
		for(int i=2;i<=n;i++)
			for(int j=i;j<=k;j++)
				a[i][j]=b[i-1][j-1],b[i][j]=(b[i][j-1]+(1ll<<(j-1))%MOD*a[i][j]%MOD)%MOD;
		int res=0;
		for(int n=1;n<=k;n++)
			res=(res+b[n][len(m)-1]+(m-(1ll<<(len(m)-1))+1)%MOD*a[n][len(m)]%MOD)%MOD;
		cout<<res<<"\n";
	}
	return 0;
}