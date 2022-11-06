#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll UNDEF = -1;
const ll INF=1e9;
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
const ll mn=1024;
ll a[2][mn];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n,k,xo; scanf("%d%d%d",&n,&k,&xo);
	memset(a,0,sizeof a);
	for (ll i=0;i<n;i++) {
		ll x; scanf("%d",&x);a[0][x]++;
	}
	ll cur=0,nxt=1;
	for (ll jj=0;jj<k;jj++) {
		for (ll x=0;x<mn;x++) {a[nxt][x]=0;}
		ll now=0;
		for (ll x=0;x<mn;x++) {
			ll num=a[cur][x];
			if (num==0) continue;
			ll take=(num+1-now)/2;
			//printf("x:%d num:%d now:%d take:%d. %d gets %d. %d gets %d\n",x,num,now,take,x,num-take,x^xo,take);
			a[nxt][x]+=(num-take);
			a[nxt][x^xo]+=take;
			now=(now+num)&1;
		}
		swap(cur,nxt);
	}
	ll lo=INF,hi=-INF;
	for (ll x=0;x<mn;x++) {
		if (a[cur][x]>0) {
			chkmin(lo,x);
			chkmax(hi,x);
		}
	}
	printf("%d %d\n",hi,lo);
}