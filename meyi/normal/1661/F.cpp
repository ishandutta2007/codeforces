#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
static char pbuf[1000000],*p1=pbuf,*p2=pbuf;
#define getchar() p1==p2&&(p2=(p1=pbuf)+fread(pbuf,1,1000000,stdin),p1==p2)?EOF:*p1++
inline ll qr(){
	ll in=0;char ch;
	while(!isdigit(ch=getchar()));
	do in=(in<<1)+(in<<3)+(ch^48);while(isdigit(ch=getchar()));
	return in;
}
int n;
ll a[maxn],ans,cnt,m;
inline ll sqr(ll k){return k*k;}
inline ll calc(ll x,ll y){
	ll c1=x%y,c2=y-c1,len=x/y;
	return c1*sqr(len+1)+c2*sqr(len);
}
inline ll half(ll x,ll y,ll v){
	ll l=y+1,r=x,ret=y,vv=calc(x,y);
	if(vv-calc(x,y+1)!=v)return y;
	if(y+2<=x&&vv-calc(x,y+2)!=v*2)return y+1;
	while(l<=r){
		ll mid=l+r>>1;
		if(vv-calc(x,mid)==v*(mid-y))ret=mid,l=mid+1;
		else r=mid-1;
	}
	return ret;
}
typedef pair<int,int> pii;
typedef pair<ll,pii> plp;
#define fi first
#define se second
struct cmp{
	inline bool operator()(const plp &x,const plp &y){
		return x.fi<y.fi;
	}
};
priority_queue<plp,vector<plp>,cmp>q;
signed main(){
	n=qr();
	for(ri i=1;i<=n;++i){
		a[i]=qr();
		ans+=sqr(a[i]-a[i-1]);
		ri k=2;
		if(a[i]-a[i-1]>=k)q.emplace(calc(a[i]-a[i-1],k-1)-calc(a[i]-a[i-1],k),pii(i,k));
	}
	m=qr();
	ans-=m;
	while(ans>0){
		plp p=q.top();q.pop();
		ll k=half(a[p.se.fi]-a[p.se.fi-1],p.se.se,p.fi),sum=min(k-p.se.se+1,(ans+p.fi-1)/p.fi);
		ans-=sum*p.fi,cnt+=sum;
		ri i=p.se.fi;
		++k;
		if(a[i]-a[i-1]>=k)q.emplace(calc(a[i]-a[i-1],k-1)-calc(a[i]-a[i-1],k),pii(i,k));
	}
	printf("%lld",cnt);
	return 0;
}