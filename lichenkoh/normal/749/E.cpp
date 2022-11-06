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
const ll mn=1e5+4;
ll a[mn];
ll tcnt[2*mn],tsum[2*mn];
// T[i] += value
void add(ll *t, ll n, ll i, ll value) {
  for (; i < n; i |= i + 1)
    t[i] += value;
}

  // sum[0..i]
ll sum(ll *t, ll i) {
  ll res = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1)
    res += t[i];
  return res;
}

void sset(ll *t, ll n, ll i, ll value) {
  ll orig = sum(t,i)-sum(t,i-1);
  add(t,n,i,value-orig);
}

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n; scanf("%lld",&n);
	for (ll i=0;i<n;i++) scanf("%lld",a+i);
	for (ll i=0;i<n;i++) a[i]--;
	ld ans=0;
	ld norm=2.0L/(n*(n+1));
	ll inv=0;
	memset(tcnt,0,sizeof tcnt);
	memset(tsum,0,sizeof tsum);
	ll r=1;
	for (ll i=n-1;i>=0;i--) {
		ll x=a[i];
		ll sumr=sum(tsum,x);
		ll cnt=sum(tcnt,x);
		ll cand=(i+1)*sumr;
		//printf("i:%lld cand:%lld x:%lld sumr:%lld cnt:%lld\n",i,cand,x,sumr,cnt);
		inv+=cnt;
		ans-=cand*norm;
		add(tsum,n,x,r);
		add(tcnt,n,x,1);
		r++;
	}
	for (ll len=1;len<=n;len++) {
		ll num=n-len+1;
		ll cand=num*(len*(len-1))/2;
		//printf("len:%lld cand:%lld\n",len,cand);
		ans+=cand*norm/2;
	}
	ans+=inv;
	//printf("inv:%lld\n",inv);
	printf("%.10f\n",(double)ans);
}