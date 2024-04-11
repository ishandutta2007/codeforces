#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=233333,MOD=1000000007;
int t,n,k;
namespace combinatorics{
	int fac[N],inv[N];
	int qpow(int x,int y){
		return y?qpow(x*x%MOD,y>>1)*(y&1?x:1)%MOD:1;
	}
	int C(int n,int m){
		return n<m||m<0?0:fac[n]*inv[m]%MOD*inv[n-m]%MOD;
	}
	int invC(int n,int m){
		return n<m||m<0?0:inv[n]*fac[m]%MOD*fac[n-m]%MOD;
	}
	void init(){
		fac[0]=fac[1]=inv[0]=inv[1]=1;
		for(int i=2;i<N;i++)
			fac[i]=fac[i-1]*i%MOD;
		inv[N-1]=qpow(fac[N-1],MOD-2);
		for(int i=N-1;i>1;i--)
			inv[i-1]=inv[i]*i%MOD;
	}
}
using namespace combinatorics;
signed main(){
    ios::sync_with_stdio(0);
	for(cin>>t,init();t--;){
		cin>>n>>k;
		int ans=1;
		for(int i=1;i<n;i++)
			ans=(ans+C(n-(i-1)*(k-1),i)*invC(n,i)%MOD)%MOD;
		cout<<ans<<"\n";
	}
}