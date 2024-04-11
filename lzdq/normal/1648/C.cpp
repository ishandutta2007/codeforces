#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int MAXN=2e5+5,mod=998244353;
int n,m;
int s[MAXN],t[MAXN];
int c[MAXN],sum[MAXN];
inline void Add(int x,int y){
	for(int i=x; i<MAXN; i+=i&-i)
		sum[i]+=y;
}
inline int query(int x){
	int res=0;
	for(int i=x; i; i&=i-1)
		res+=sum[i];
	return res;
}
ll Fstpw(ll a,int b){
	ll res=1;
	while(b){
		if(b&1) res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}
ll fac[MAXN],inv[MAXN];
ll mul=1;
int ans;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++)
		scanf("%d",s+i);
	for(int i=1; i<=m; i++)
		scanf("%d",t+i);
	fac[0]=1;
	for(int i=1; i<=n; i++)
		fac[i]=fac[i-1]*i%mod;
	inv[n]=Fstpw(fac[n],mod-2);
	for(int i=n; i; i--)
		inv[i-1]=inv[i]*i%mod;
	for(int i=1; i<=n; i++)
		c[s[i]]++,Add(s[i],1);
	for(int i=1; i<MAXN; i++)
		mul=mul*inv[c[i]]%mod;
	for(int i=1; i<=min(n,m); i++){
		int x=query(t[i]-1);
		ans=(ans+x*mul%mod*fac[n-i])%mod;
		if(!c[t[i]]) break;
		if(i==n&&i<m) ans=(ans+1)%mod;
		mul=mul*c[t[i]]%mod;
		c[t[i]]--;
		Add(t[i],-1);
	}
	printf("%d\n",ans);
	return 0;
}