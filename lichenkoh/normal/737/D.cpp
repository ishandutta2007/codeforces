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
const ll mn=4000;
char *flim[2][mn];
void solve(ll p, ll k, ll l, ll r) {
	if (l>r) return;
	if (k>flim[p][r][l]) flim[p][r][l]=k;
	else return;
	if (p==0) {
		solve(p^1,k,l+k,r);
		solve(p^1,k+1,l+k+1,r);
	}
	else {
		solve(p^1,k,l,r-k);
		solve(p^1,k+1,l,r-k-1);
	}
}
ll a[mn],b[mn+1];
ll getsum(ll l, ll r) {
	return b[r+1]-b[l-1+1];
}
ll** dp[2][mn];
ll go(ll p, ll k, ll l, ll r) {
	if (l==r+1) {
		//printf("p:%d l:%d r:%d k:%d ans:ZERO\n",p,l,r,k);
		return 0;
	}
	else if (l>r) return INF;
	else if (dp[p][r][l][k-1]!=INF) return dp[p][r][l][k-1];
	else if (r-l+1<k) return 0;
	ll ans;
	if (p==0) {
		ans=-INF;
		{
			ll cand=go(p^1,k,l+k,r);
			if (cand!=INF) {
				chkmax(ans,cand+getsum(l,l+k-1));
			}
		}
		{
			ll cand=go(p^1,k+1,l+k+1,r);
			if (cand!=INF) {
				chkmax(ans,cand+getsum(l,l+k));
			}
		}
	}
	else {
		ans=INF;
		{
			ll cand=go(p^1,k,l,r-k);
			if (cand!=INF) {
				chkmin(ans,cand-getsum(r-k+1,r));
			}
		}
		{
			ll cand=go(p^1,k+1,l,r-k-1);
			if (cand!=INF) {
				chkmin(ans,cand-getsum(r-k,r));
			}
		}
	}
	dp[p][r][l][k-1]=ans;
	//printf("p:%d l:%d r:%d k:%d ans:%d\n",p,l,r,k,ans);
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n; scanf("%d",&n);
	for (ll i=0;i<n;i++) scanf("%d",a+i);
	b[0]=0;
	for (ll i=1;i<=n;i++) b[i]=b[i-1]+a[i-1];
	for (ll p=0;p<2;p++) for (ll r=0;r<n;r++) {
		flim[p][r]=(char*)malloc(sizeof(ll)*(r+1));
		for (ll l=0;l<=r;l++) {
			flim[p][r][l]=0;
		}
	}
	solve(0,1,0,n-1);
	//ll all=0;
	//ll maxk=0;
	for (ll p=0;p<2;p++) for (ll r=0;r<n;r++) {
		dp[p][r]=(ll**)malloc((r+1)*sizeof(ll*));
		for (ll l=0;l<=r;l++) {
			ll klim=flim[p][r][l];
			if (klim==0) continue;
			//chkmax(maxk,klim);
			//all+=klim;
			dp[p][r][l]=(ll*)malloc(klim*sizeof(ll));
			for (ll k=0;k<klim;k++) {
				dp[p][r][l][k]=INF;
			}
		}
		free(flim[p][r]);
	}
	//printf("all:%d maxk:%d\n",all,maxk);
	ll ans=go(0,1,0,n-1);
	printf("%d\n",ans);
}