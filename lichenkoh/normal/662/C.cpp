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
const ll mn=1e5;
const ll mx=1<<20;
const ll mk=21;
ll a[mn];
ll f[2][mk][mx];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n,m; cin>>n>>m;
	memset(a,0,sizeof a);
	for (ll i=0;i<n;i++) {
		ll msk=1<<i;
		string s; cin>>s;
		for (ll j=0;j<m;j++) {
			if (s[j]=='1') {
				a[j]|=msk;
			}
		}
	}
	//for (ll j=0;j<m;j++) printf("%lld ",a[j]);
	//	printf("\n");
	memset(f,0,sizeof f);
	ll cur=0,nxt=1;
	for (ll j=0;j<m;j++) f[cur][0][a[j]]++;
	ll mz=1<<n;
	for (ll b=0;b<n;b++) {
		for (ll k=0;k<=n;k++)for (ll z=0;z<mz;z++) f[nxt][k][z]=f[cur][k][z];
		ll msk=1<<b;
		for (ll k=0;k<n;k++) {
			for (ll z=0;z<mz;z++) {
				f[nxt][k+1][z^msk]+=f[cur][k][z];
			}
		}
		swap(cur,nxt);
	}
	ll ans=INF;
	for (ll z=0;z<mz;z++) {
		ll cand=0;
		for (ll k=0;k<=n;k++) {
			cand+=min(k,n-k)*f[cur][k][z];
		}
		chkmin(ans,cand);
	}
	printf("%d\n",ans);
}