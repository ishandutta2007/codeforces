#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=233333,MOD=998244353;
int n,m;
namespace combinatorics{
	int fac[N],inv[N];
	int qpow(int x,int y){
		return y?qpow(x*x%MOD,y>>1)*(y&1?x:1)%MOD:1;
	}
	int C(int n,int m){
		return n<m||m<0?0:fac[n]*inv[m]%MOD*inv[n-m]%MOD;
	}
	void init(){
		fac[0]=fac[1]=inv[0]=inv[1]=1;
		for(int i=2;i<N;i++)
			fac[i]=fac[i-1]*i%MOD;
		inv[N-1]=qpow(fac[N-1],MOD-2);
		for(int i=N-1;i>1;i--)
			inv[i-1]=inv[i]*i%MOD;
	}
	int stirling2(int n,int m){
		int ans=0;
		for(int i=0;i<=m;i++)
			ans=(ans+(i&1?-1:1)*C(m,i)*qpow(m-i,n)%MOD+MOD)%MOD;
		return ans;
	}
}
using namespace combinatorics;
signed main(){
	init(),cin>>n>>m;
	cout<<(m>=n?0:stirling2(n,n-m)*C(n,m)%MOD*(!!m+1)%MOD)<<"\n";
}