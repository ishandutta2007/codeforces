#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=1000010,MOD=1000000007;
int n,k,ans,x[N],y[N],fac[N],inv[N],pre[N],suf[N];
int qpow(int x,int y){
	return y?qpow(x*x%MOD,y>>1)*(y&1?x:1)%MOD:1;
}
signed main(){
	fac[0]=inv[0]=fac[1]=inv[1]=1;
	for(int i=2;i<N;i++)
		fac[i]=fac[i-1]*i%MOD;
	inv[N-1]=qpow(fac[N-1],MOD-2);
	for(int i=N-1;i;i--)
		inv[i-1]=inv[i]*i%MOD;
	cin>>n>>k,k+=2;
	for(int i=1;i<=k;i++)
		y[i]=(y[i-1]+qpow(i,k-2))%MOD;
	if(n<=k)
		cout<<y[n]<<"\n",exit(0);
	pre[0]=suf[k+1]=1;
	for(int i=1;i<=k;i++)
		pre[i]=pre[i-1]*(n-i)%MOD;
	for(int i=k;i>=1;i--)
		suf[i]=suf[i+1]*(n-i)%MOD;
	for(int i=1;i<=k;i++)
		ans=(ans+y[i]*pre[i-1]%MOD*suf[i+1]%MOD
			*inv[i-1]%MOD*inv[k-i]%MOD*((k-i)&1?-1:1)+MOD)%MOD;
	cout<<ans<<"\n";
}