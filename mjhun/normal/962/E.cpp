#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;

vector<ll> g,r,b;
int n;
ll c[1<<19];

ll doit(vector<ll>& a){
	if(!SZ(a))return 0;
	ll r=0;
	if(a[0]<g[0])r+=g[0]-a[0];
	if(a.back()>g.back())r+=a.back()-g.back();
	fore(i,0,SZ(g)-1){
		int k0=lower_bound(a.begin(),a.end(),g[i])-a.begin();
		if(k0==SZ(a)||a[k0]>g[i+1])continue;
		int k1=lower_bound(a.begin(),a.end(),g[i+1])-a.begin();
		assert(k0<k1);
		ll asd=0;
		asd=max(asd,a[k0]-g[i]);
		asd=max(asd,g[i+1]-a[k1-1]);
		fore(k,k0,k1-1)asd=max(asd,a[k+1]-a[k]);
		//r+=g[i+1]-g[i]-asd;
		c[i]+=g[i+1]-g[i]-asd;
	}
	return r;
}

int main(){
	scanf("%d",&n);
	fore(i,0,n){
		int p;char s[4];
		scanf("%d%s",&p,s);
		if(s[0]=='P')g.pb(p);
		else if(s[0]=='R')r.pb(p);
		else b.pb(p);
	}
	ll rr=0;
	if(SZ(g)==0){
		if(SZ(r))rr+=r.back()-r[0];
		if(SZ(b))rr+=b.back()-b[0];
	}
	else {
		rr+=g.back()-g[0];
		rr+=doit(r);
		rr+=doit(b);
		fore(i,0,SZ(g)-1)rr+=min(c[i],1LL*g[i+1]-g[i]);
	}
	printf("%lld\n",rr);
	return 0;
}