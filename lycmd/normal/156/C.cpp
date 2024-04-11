#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=3010,MOD=1000000007;
int t,n,k,fac[N],inv[N];
string s;
int qpow(int x,int y){
	return y?qpow(x*x%MOD,y>>1)*(y&1?x:1)%MOD:1;
}
int C(int n,int m){
	return m<0||n<m?0:fac[n]*inv[m]%MOD*inv[n-m]%MOD;
}
signed main(){
	ios::sync_with_stdio(0);
	fac[0]=fac[1]=inv[0]=inv[1]=1;
	for(int i=1;i<N;i++)
		fac[i]=fac[i-1]*i%MOD;
	inv[N-1]=qpow(fac[N-1],MOD-2);
	for(int i=N-1;i;i--)
		inv[i-1]=inv[i]*i%MOD;
	for(cin>>t;t--;){
		cin>>s,n=s.size(),k=0;
		for(char i:s)k+=i-96;
		int res=-1;
		for(int i=0;i<=n;i++)
			res=(res+(i&1?-1:1)*C(n,i)*C(k-26*i-1,n-1)%MOD+MOD)%MOD;
		cout<<res<<"\n";
	}
}