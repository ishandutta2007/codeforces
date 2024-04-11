#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=5010,MOD=998244353;
int n,ans,a[N],cnt[N],f[N][N],s[N][N],inv[N];
int qpow(int x,int y){
	return y?qpow(x*x%MOD,y>>1)*(y&1?x:1)%MOD:1;
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n,inv[0]=1;
	for(int i=1;i<=n;i++)
		cin>>a[i],cnt[a[i]]++,inv[i]=qpow(i,MOD-2);
	s[0][0]=1;
	for(int i=1;i<=n;i++){
		s[i][0]=1;
		for(int j=1;j<=i;j++)
			f[i][j]=s[i-1][j-1]*cnt[i]%MOD*inv[n-j+1]%MOD,
			s[i][j]=(s[i-1][j]+f[i][j])%MOD,
			ans=(ans+s[i-1][j-1]*cnt[i]%MOD*(cnt[i]-1)%MOD
				*inv[n-j+1]%MOD*inv[n-j]%MOD)%MOD;
	}
	cout<<ans<<"\n";
}//