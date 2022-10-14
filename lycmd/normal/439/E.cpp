#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=100010,MOD=1000000007;
int q,n,k,tot,vis[N],mu[N],pr[N],fac[N],inv[N];
vector<int>e[N];
int qpow(int x,int y){
	return y?qpow(x*x%MOD,y>>1)*(y&1?x:1)%MOD:1;
}
int C(int n,int m){
	return m<0||n<m?0:fac[n]*inv[m]%MOD*inv[n-m]%MOD;
}
signed main(){
	ios::sync_with_stdio(0);
	fac[0]=inv[0]=mu[1]=1;
	for(int i=1;i<N;i++)
		for(int j=i;j<N;j+=i)
			e[j].push_back(i);
	for(int i=1;i<N;i++)
		fac[i]=fac[i-1]*i%MOD;
	inv[N-1]=qpow(fac[N-1],MOD-2);
	for(int i=N-1;i;i--)
		inv[i-1]=inv[i]*i%MOD; 
	for(int i=2;i<N;i++){
		if(!vis[i])pr[tot++]=i,mu[i]=-1;
		for(int j=0;j<tot&&i*pr[j]<N;j++){
			vis[i*pr[j]]=1;
			if(i%pr[j])
				mu[i*pr[j]]=-mu[i];
			else break;
		}
	}
	for(cin>>q;q--;){
		cin>>n>>k;
		int res=0;
		for(int i:e[n])
			res=(res+mu[i]*C(n/i-1,k-1)+MOD)%MOD;
		cout<<res<<"\n";
	}
}