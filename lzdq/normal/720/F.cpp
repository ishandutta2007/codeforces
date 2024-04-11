#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pr;
#define mkp make_pair
const int MAXN=1e5+5;
const ll INF=1ll<<60;
int n,a[MAXN];
ll m,s[MAXN],mis[MAXN],as[MAXN];
pr f[MAXN],mx[MAXN];
int sum[MAXN],mi[MAXN];
ll rsum[MAXN];
ll ans,tot,res;
inline void query(int x){
	res=0;
	*mi=MAXN;
	for(int i=x; i; i&=i-1){
		ans-=rsum[i];
		res+=sum[i];
		*mi=min(*mi,mi[i]);
	}
}
inline void modify(int x,int pos){
	for(int i=x; i<=*as; i+=i&-i){
		rsum[i]+=s[pos];
		sum[i]++;
		mi[i]=min(mi[i],pos);
	}
}
int pre[MAXN];
bool Check(ll k){
	ans=tot=0;
	for(int i=1; i<=n+1; i++){
		pre[i]=rsum[i]=sum[i]=0;
		mi[i]=MAXN;
	}
	for(int i=1; i<=n; i++){
		modify(lower_bound(as+1,as+*as+1,s[i-1])-as,i-1);
		int t=upper_bound(as+1,as+*as+1,s[i]-k)-as-1;
		query(t);
		ans+=(s[i]-k)*res;
		tot+=res;
		if(*mi<MAXN){
			pre[*mi+1]++;
			pre[i+1]--;
		}
	}
	mx[0]=mkp(-k,0ll);
	int j=0;
	for(int i=1; i<=n; i++){
		pre[i]+=pre[i-1];
		if(!pre[i]) j=i,f[i].first=-INF;
		else f[i]=f[i-1];
		if(j) f[i]=max(f[i],mkp(mx[j-1].first+s[i],mx[j-1].second+1));
		else f[i]=mkp(0ll,0ll);
		mx[i]=max(mx[i-1],mkp(f[i].first-mis[i]-k,f[i].second));
	}
	pr res;
	res.first=-INF;
	for(int i=j; i<=n; i++)
		res=max(res,f[i]);
	ans+=res.first;
	tot+=res.second;
	return tot>=m;
}
int main(){
	n=1e5;
	m=1e5;
	scanf("%d%lld",&n,&m);
	for(int i=1; i<=n; i++){
		a[i]=5e4;
		scanf("%d",a+i);
		mis[i]=min(mis[i-1],as[i]=s[i]=s[i-1]+a[i]);
	}
	sort(as+1,as+n+2);
	*as=unique(as+1,as+n+2)-as-1;
	ll l=-5e9,r=5e9;
	while(l<r){
		ll mid=ceil((l+r)/2.0);
		if(Check(mid)) l=mid;
		else r=mid-1;
	}
	Check(r);
	printf("%lld\n",ans+r*m);
	return 0;
}