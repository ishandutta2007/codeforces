#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=500010,MOD=998244353;
int t,n,m,fac[N],inv[N],ff[N],fi[N];
int qpow(int x,int y){
	return y?qpow(x*x%MOD,y>>1)*(y&1?x:1)%MOD:1;
}
int C(int n,int m){
	return m<0||n<m?0:fac[n]*inv[m]%MOD*inv[n-m]%MOD;
}
signed main(){
	ios::sync_with_stdio(0);
	fac[0]=fac[1]=inv[0]=inv[1]=ff[0]=fi[0]=fi[1]=1,ff[1]=2;
	for(int i=2;i<N;i++)
		fac[i]=fac[i-1]*i%MOD,ff[i]=ff[i-1]*(4*i-2)%MOD,
		fi[i]=(fi[i-1]+fi[i-2]*(i-1)%MOD)%MOD;
	inv[N-1]=qpow(fac[N-1],MOD-2);
	for(int i=N-1;i>1;i--)
		inv[i-1]=inv[i]*i%MOD;
	for(cin>>t;t--;){
		cin>>n;
		int res=0;
		for(int i=0;i<=n/4;i++)
			res=(res+C(n-2*i,2*i)*ff[i]%MOD*fi[n-4*i]%MOD)%MOD;
		cout<<res<<"\n";
	}
}