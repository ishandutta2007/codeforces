#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=233333,MOD=1000000007;
int n,k,ans,fac[N],inv[N],pw1[N],pw2[N];
int qpow(int x,int y){
	return y?qpow(x*x%MOD,y>>1)*(y&1?x:1)%MOD:1;
}
int C(int n,int m){
	return m<0||n<m?0:fac[n]*inv[m]%MOD*inv[n-m]%MOD; 
}
signed main(){
	cin>>n>>k;
	fac[0]=pw1[0]=pw2[0]=1;
	for(int i=1;i<N;i++)
		fac[i]=fac[i-1]*i%MOD,
		pw1[i]=pw1[i-1]*(k-1)%MOD,pw2[i]=pw2[i-1]*k%MOD;
	inv[N-1]=qpow(fac[N-1],MOD-2);
	for(int i=N-1;i;i--)
		inv[i-1]=inv[i]*i%MOD;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			ans=(ans+(i+j&1?-1:1)*C(n,i)*C(n,j)%MOD
			    *pw1[n*(i+j)-i*j]%MOD*pw2[(n-i)*(n-j)]%MOD+MOD)%MOD;
	cout<<ans<<"\n";
}
//