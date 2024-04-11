#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const int MOD=1000000007;
#define endl "\n"
#define fst first
#define snd second
const int UNDEF = -1;
const int INF=1<<30;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;typedef vector<pii> vpii;typedef vector<pll> vpll;
// mt19937 rng; rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}
//const bool DBG=0;
vll a;
vector<pair<ll,pll> > vans;
void op(ll i, ll j, ll x) {
	assert(x>=0);
  if (x!=0) vans.PB(MP(i,MP(j,x)));
  a[i]-=x*i;
  a[j]+=x*i;
}
bool go() {
  ll n; cin>>n;
  a.clear(); a.resize(n+1); vans.clear();
  ll sum=0;
  for (ll p=1;p<=n;p++) {
    cin>>a[p];
    sum+=a[p];
  }
  //pr();
  ll want=sum/n;
  {
  	ll goodi=-1;
  	for (ll i=n;i>=2;i--) {
  		if (a[i]>=i) {goodi=i; break;}
  	}
  	if (goodi!=-1) {
  		ll i=goodi;
  		op(i,1,a[i]/i);
  		op(1,i,(i-a[i]%i)%i);
  		op(i,1,a[i]/i);
  	}
  }
  {
    vector<pll> vsorted;
    for (ll i=2;i<=n;i++) {
      ll takemod=(i-(a[i]%i))%i;
      vsorted.PB(MP(takemod, i));
    }
    sort(vsorted.begin(),vsorted.end());
    int sz=vsorted.size();
    for (ll r=0;r<sz;r++) {
      ll i=vsorted[r].snd;
      ll give=(i-(a[i]%i))%i;
      //printf("give:%lld a[1]:%lld\n",give,a[1]);
      if (give<=a[1]) {
        op(1,i,give);
        op(i,1,a[i]/i);
      }
    }
  }
  //pr();
  for (ll j=2;j<=n;j++) {
    ll need=want-a[j];
    if (need<0) {
      return false;
    }
    ll x=need;
    ll i=1;
    op(i,j,x);
    if (a[i]<0) return false;
    assert(a[j]>=0);
  }
  for (ll i=2;i<=n;i++) {
    if (a[i]!=a[i-1]) {
      return false;
    }
  }
  int sz=vans.size();
  assert(sz<=3*n);
  printf("%d\n",sz);
  for (auto &w:vans) {
    printf("%lld %lld %lld\n",w.fst,w.snd.fst,w.snd.snd);
  }
  return true;
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t; cin>>t;
  for (int i=0;i<t;i++) {
    bool got=go();
    if (got==false) printf("-1\n");
  }
}