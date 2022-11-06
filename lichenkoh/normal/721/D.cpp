#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;

#ifdef DEBUG
     #define debug(args...)            {dbg,args; cerr<<endl;}
#else
    #define debug(args...)              // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {    
        cerr<<v<<" ";    
        return *this;    
    }
} dbg;


const ll mn=2e5+4;

typedef pair<ll,pll> ppll;
const ppll udef=MP(UNDEF,MP(UNDEF,UNDEF));
ll gr(pll x,pll y) {
	ll a=x.first,b=x.second;
	ll c=y.first,d=y.second;
	return a*d>b*c;
}
ppll getbest(ppll best, ppll x) {
	if (best==udef) return x;
	if (x==udef) return best;
	if (gr(x.second,best.second)) return x;
	return best;
}
ll getsign(ll x) {
	return (x>=0)?1:-1;
}
ll a[mn];
ll n,k,d;

int main() {
	ios_base::sync_with_stdio(false);
	scanf("%lld %lld %lld",&n,&k,&d);
	for (ll i=0;i<n;i++) {
		scanf("%lld",&a[i]);
	}
	ll sign=1;
	pll least=MP(INF,INF);
	for (ll i=0;i<n;i++) {
		if (a[i]<0) {sign*=-1;}
		chkmin(least,MP(abs(a[i]),i));
	}
	if (sign==1) {
		ll leastidx=least.second;
		ll x=abs(a[leastidx]);
		ll need=(x+d)/d;
		if (need>k) {
			// Solve special case. Can't make anything negative.
			priority_queue<pll,vector<pll>,greater<pll> > qhi;
			for (ll i=0;i<n;i++) {
				ll x=abs(a[i]);
				qhi.push(MP(x,i));
			}
			while(k>0) {
				pll px=qhi.top();
				qhi.pop();
				ll x=px.first;
				px.first=abs(x-d);
				a[px.second]=px.first*getsign(a[px.second])*1;
				qhi.push(px);
				k-=1;
			}
			for (ll i=0;i<n;i++) {
				printf("%lld ",a[i]);
			}
			printf("\n");
			return 0;
		}
		else {
			x=abs(x-d*need);
			a[leastidx]=x*getsign(a[leastidx])*-1;
			k-=need;
		}
	}
	// Solve special case. Can't make anything negative.
	priority_queue<pll,vector<pll>,greater<pll> > qhi;
	for (ll i=0;i<n;i++) {
		ll x=abs(a[i]);
		qhi.push(MP(x,i));
	}
	while(k>0) {
		pll px=qhi.top();
		qhi.pop();
		ll x=px.first;
		px.first=abs(x+d);
		a[px.second]=px.first*getsign(a[px.second])*1;
		qhi.push(px);
		k-=1;
	}
	for (ll i=0;i<n;i++) {
		printf("%lld ",a[i]);
	}
	printf("\n");
	return 0;
}