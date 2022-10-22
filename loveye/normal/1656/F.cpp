#include<cstdio>
#include<cmath>
#include<numeric>
#include<cassert>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

int read();
typedef long long ll;
typedef __int128 lll;
#define fr(i,l,r) for(int i=(l);i<=(r);++i)
#define rf(i,l,r) for(int i=(l);i>=(r);--i)
#define fo(i,l,r) for(int i=(l);i<(r);++i)
#define foredge(i,u,v) for(int i=fir[u],v;v=to[i],i;i=nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N=2e5+5;
int n,a[N];
ll chk(ll t) {
	ll ans=-(n-1)*t*t;
	if(a[1]+t>=0) {
		fr(i,2,n) ans+=(a[1]+t)*(a[i]+t);
	} else if(a[n]+t<=0) {
		fo(i,1,n) ans+=(a[i]+t)*(a[n]+t);
	} else {
		fr(i,1,n) if(a[i]+t<0) ans+=(a[i]+t)*(a[n]+t);
		else ans+=(a[i]+t)*(a[1]+t);
		ans-=(a[1]+t)*(a[n]+t);
	} return ans;
}
ll chk2(ll t) {
	t=t*2+1;
	ll ans=-(n-1)*t*t;
	if(a[1]*2+t>=0) {
		fr(i,2,n) ans+=(a[1]*2+t)*(a[i]*2+t);
	} else if(a[n]*2+t<=0) {
		fo(i,1,n) ans+=(a[i]*2+t)*(a[n]*2+t);
	} else {
		fr(i,1,n) if(a[i]*2+t<0) ans+=(a[i]*2+t)*(a[n]*2+t);
		else ans+=(a[i]*2+t)*(a[1]*2+t);
		ans-=(a[1]*2+t)*(a[n]*2+t);
	} return ans/4;
}
int main() {
	int t; cin>>t; while(t--) {
		cin>>n;
		fr(i,1,n) cin>>a[i];
		sort(a+1,a+n+1);
		if(accumulate(a+2,a+n+1,0ll)+1ll*(n-1)*a[1]>0) {
			cout<<"INF\n"; continue;
		}
		if(accumulate(a+1,a+n,0ll)+1ll*(n-1)*a[n]<0) {
			cout<<"INF\n"; continue;
		}
		ll l=-1e6-1,r=1e6+1;
		while(r-l>2) {
			ll m1=l+r>>1,m2=m1+1;
			if(chk(m1)>chk(m2)) r=m2;
			else l=m1;
		}
		ll ans=-1e18;
		//cout<<l<<' '<<r<<endl;
		fr(i,l,r) {
			ans=max(ans,chk(i));
			ans=max(ans,chk2(i));
		}
		printf("%lld\n",ans);
	}
	return 0;
}

const int S=1<<21;
char p0[S],*p1,*p2;
#define getchar() (p2==p1&&(p2=(p1=p0)+fread(p0,1,S,stdin))==p1?EOF:*p1++)
inline int read() {
	static int x,c,f;x=0;f=1;
	do c=getchar(),c=='-'&&(f=-1); while(!isdigit(c));
	do x=x*10+(c&15),c=getchar(); while(isdigit(c));
	return x*f;
}