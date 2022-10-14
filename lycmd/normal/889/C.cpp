#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=2333333,MOD=1000000007;
int n,k,ans,fac[N],inv[N],f[N],s[N];
inline int qpow(int x,int y){
	return y?qpow(x*x%MOD,y>>1)*(y&1?x:1)%MOD:1;
}
signed main(){
	ios::sync_with_stdio(0);
	for(int i=0;i<N;i++)
		fac[i]=i?fac[i-1]*i%MOD:1;
	inv[N-1]=qpow(fac[N-1],MOD-2);
	for(int i=N-1;i;i--)
		inv[i-1]=inv[i]*i%MOD;
	cin>>n>>k;
	ans=fac[n],f[0]=1;
	for(int i=1;i<=n;i++){
		s[i]=(s[i-1]+f[i-1])%MOD;
		f[i]=(s[i]-s[max(0ll,i-k)]+MOD)*qpow(i,MOD-2)%MOD;
		ans=(ans-f[i-1]*fac[n-1]%MOD+MOD)%MOD;
	}
	cout<<ans<<"\n";
}