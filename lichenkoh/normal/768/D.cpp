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
const ll INF=1e9+4;
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
const ll mn=1002;
ld f[2][mn];
ll vans[mn];
ll k,q;
void clr(ll nxt) {
	for (ll x=0;x<=k;x++) f[nxt][x]=0;
}
const ld eps=1e-7;
int main()
{
	memset(vans,-1,sizeof vans);
	ios_base::sync_with_stdio(false); cin.tie(0);
	scanf("%d%d",&k,&q);
	clr(0);
	f[0][0]=1;
	ll cur=0,nxt=1;
	ll done=0;
	for (ll x=0;;x++) {
		for (ll o=0;o<=k;o++) {
			ld ans=f[cur][o]*(ld)o/(ld)k;
			if (o>0) {
				ld d2=f[cur][o-1]*(ld)(k-(o-1))/(ld)k;
				ans+=d2;
			}
			f[nxt][o]=ans;
			//if (ans>1e-9) {
			//	printf("x:%d o:%d ans:%f\n",x+1,o,(double)ans);
			//}
		}
		for (ll p=0;p<=1000;p++) {
			if (vans[p]!=-1) continue;
			if (f[nxt][k]>=((ld)p-eps)/(ld)2000) {
				vans[p]=x+1;
				done++;
			}
		}
		swap(cur,nxt);
		if (done>=1001) break;
	}
	for (ll i=0;i<q;i++) {
		ll p; scanf("%d",&p);
		printf("%d\n",vans[p]);
	}
}