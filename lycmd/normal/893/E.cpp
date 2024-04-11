#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=2000010,MOD=1000000007;
int t,n,m,tot,fac[N],inv[N],pr[N],vis[N];
int qpow(int x,int y){
	return y?qpow(x*x%MOD,y>>1)*(y&1?x:1)%MOD:1;
}
int C(int n,int m){
	return m<0||n<m?0:fac[n]*inv[m]%MOD*inv[n-m]%MOD;
}
signed main(){
	ios::sync_with_stdio(0);
	fac[0]=fac[1]=inv[0]=inv[1]=1;
	for(int i=2;i<N;i++)
		fac[i]=fac[i-1]*i%MOD;
	inv[N-1]=qpow(fac[N-1],MOD-2);
	for(int i=N-1;i;i--)
		inv[i-1]=inv[i]*i%MOD;
	for(int i=2;i<N;i++)
		if(!vis[i]){
			pr[++tot]=i;
			for(int j=i*i;j<N;j+=i)
				vis[j]=1;
		}
	for(cin>>t;t--;){
		cin>>n>>m;
		int res=qpow(2,m-1);
		for(int i=1;pr[i]*pr[i]<=n;i++)
			if(n%pr[i]==0){
				int cnt=0;
				while(n%pr[i]==0)
					cnt++,n/=pr[i];
				res=res*C(cnt+m-1,cnt)%MOD;
			}
		if(n>1)
			res=res*m%MOD;
		cout<<res<<"\n";
	}
}