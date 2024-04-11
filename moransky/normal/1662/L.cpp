// xtqqwq
#include<bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template<typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,v;
ll val[200005],p[200005];
pll a[200005];

void add(int x,ll c){
	for(;x<=n+1;x+=(x&(-x))) chkmax(val[x],c);
}

ll ask(int x){
	ll ret=-(1ll<<60);
	for(;x;x-=(x&(-x))) chkmax(ret,val[x]);
	return ret;
}

int main(){
	n=readint(); v=readint();
	for(int i=1;i<=n;i++) a[i].fi=readint();
	for(int i=1;i<=n;i++) a[i].se=readint();
	for(int i=1;i<=n;i++) a[i]=mp(a[i].fi*v-a[i].se,a[i].fi*v+a[i].se);
	for(int i=1;i<=n;i++) p[i]=a[i].se;
	p[n+1]=0;
	sort(p+1,p+n+2);
	a[n+1]=mp(0,0);
	for(int i=1;i<=n+1;i++) a[i].se=lower_bound(p+1,p+n+2,a[i].se)-p;
	sort(a+1,a+n+2);
	for(int i=1;i<=n+1;i++) val[i]=-(1ll<<60);
	ll ans=0;
	for(int i=1;i<=n+1;i++){
		ll tmp=ask(a[i].se)+1;
		if(a[i].fi==0&&p[a[i].se]==0) chkmax(tmp,0ll);
		add(a[i].se,tmp);
		chkmax(ans,tmp);
	}
	printf("%lld\n",ans);
	return 0;
}