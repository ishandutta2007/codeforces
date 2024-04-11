#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=233333,MOD=998244353;
int n,m,ans,cur=1,s[N],t[N],tr[N],cnt[N];
namespace combinatorics{
	int fac[N],inv[N];
	int qpow(int x,int y){
		return y?qpow(x*x%MOD,y>>1)*(y&1?x:1)%MOD:1;
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
void add(int x,int y){for(;x<N;x+=x&-x)tr[x]+=y;}
int ask(int x){int res=0;for(;x;x&=x-1)res+=tr[x];return res;} 
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>m,init();
	for(int i=1;i<=n;i++)
		cin>>s[i],add(s[i],1),cnt[s[i]]++;
	for(int i=1;i<=m;i++)cin>>t[i];
	for(int i=1;i<N;i++)
		cur=cur*inv[cnt[i]]%MOD;
	for(int i=1;i<=min(n,m);i++){
		ans=(ans+fac[n-i]*cur%MOD*ask(t[i]-1)%MOD)%MOD;
		if(!cnt[t[i]])break;
		cur=cur*cnt[t[i]]--%MOD,add(t[i],-1);
		if(i==n&&n<m)ans=(ans+1)%MOD;
	}
	cout<<ans<<"\n";
}