#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5,mod=998244353;
int n,m;
int x[MAXN],y[MAXN];
int del[MAXN],cnt;
int rsum[MAXN];
inline void Add(int x,int y){
	for(int i=x; i<=n; i+=i&-i)
		rsum[i]+=y;
}
inline int Query(int x){
	int res=0;
	for(int i=x; i; i-=i&-i)
		res+=rsum[i];
	return res;
}
int getk(int y){
	int l=1,r=n;
	while(l<r){
		int mid=l+r>>1;
		if(Query(mid)>=y) r=mid;
		else l=mid+1;
	}
	return l;
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
ll fac[MAXN<<1],inv[MAXN<<1];
ll C(int n,int m){
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int main(){
	n=2e5;
	for(int i=1; i<=n; i++)
		Add(i,1);
	n=4e5;
	fac[0]=1;
	for(int i=1; i<=n; i++)
		fac[i]=fac[i-1]*i%mod;
	inv[n]=Fstpw(fac[n],mod-2);
	for(int i=n; i; i--)
		inv[i-1]=inv[i]*i%mod;
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d%d",&n,&m);
		for(int i=1; i<=m; i++)
			scanf("%d%d",x+i,y+i);
		*del=cnt=0;
		for(int i=m; i; i--){
			int k=getk(y[i]);
			if(Query(k+1)>y[i]) cnt++;
			del[++*del]=k;
			Add(k,-1);
		}
		for(int i=1; i<=*del; i++)
			Add(del[i],1);
		//printf("cnt %d\n",cnt);
		printf("%lld\n",C(n*2-cnt-1,n-cnt-1));
	}
	return 0;
}