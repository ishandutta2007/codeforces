#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx,tune=native")
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
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#ifdef ONLINE_JUDGE
#define assert(...) /* nothing */
#endif
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();
// mt19937 rng; rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}
vector<ll> d;
vector<ll> presum;
ll getpre(ll l, ll r) {
  if (l<=r) return presum[r]-presum[l-1];
  else return 0;
}
ll n;
ll getmin(ll sidx, ll k) {
  ll imin=sidx,imax=n+1;
  while(imin<imax) {
    ll imid=(imin+imax)/2;
    if (d[imid]>k) imin=imid+1;
    else imax=imid;
  }
  ll ans=(imin-sidx)*k + getpre(imin,n);
  //printf("sidx:%lld imin:%lld pre:%lld\n",sidx,imin,getpre(imin,n));
  // SLOW
  /*
  ll check=0;
  for (ll x=sidx;x<=n;x++) {
    check+=min(k,d[x]);
  }
  assert(ans==check);
  */
  return ans;
}
void fail(int code) {
  //printf("code:%d\n",code);
  printf("-1\n"); exit(0);
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin>>n; d.resize(n); presum.resize(n+1);
  for (int i=0;i<n;i++) cin>>d[i];
  sort(d.begin(),d.end());
  reverse(d.begin(),d.end());
  d.insert(d.begin(),n); d.PB(0);
  for (int k=1;k<=n;k++) {
    presum[k]=presum[k-1]+d[k];
  }
  vector<ll> upper(n+2);
  ll lastUpper=n;
  for (ll k=n+1;k>=1;k--) {
    ll rhs=k*(k-1) + getmin(k,k);
    ll lhsMinusOne = getpre(1,k-1);
    chkmin(lastUpper,rhs-lhsMinusOne);
    upper[k-1]=lastUpper; // Inject between d[k-1] and d[k]
  }
  vector<ll> lower(n+2,0);
  ll prefix=0;
  ll lowerbound=0;
  //ll lastk=0;
  for (ll k=1;k<=n;k++) {
    prefix+=d[k];
    ll right=k*(k-1)+getmin(k+1,k);
    if (prefix>right) {
      ll need=prefix-right;
      //printf("k:%lld prefix:%lld right:%lld\n",k,prefix,right);
      if (need>k) need=n+3;
      chkmax(lowerbound,need);
      //lastk=k;
    }
    lower[k]=lowerbound;
  }
  vector<int> vans(n+5,0);
  for (ll k=0;k<=n;k++) {
    // Range between d[k] and d[k+1] INCLUSIVE.
    ll L=max(d[k+1],lower[k]),R=min(upper[k],d[k]);
    //printf("k:%lld d[k]:%lld d[k+1]:%lld lower:%lld upper:%lld L:%lld R:%lld\n",
    //  k,d[k],d[k+1],lower[k],upper[k],L,R);
    if (L<=R) {
      if (L<n+5) ++vans[L];
      if (R+1<n+5) --vans[R+1];
    }
  }
  ll allsum=presum[n];
  ll now=0;
  vector<ll> vfinal;
  for (int x=0;x<n+5;x++) {
    now+=vans[x];
    if (now>0 && (allsum+x)%2==0) vfinal.PB(x);
  }
  if (vfinal.size()==0) fail(123);
  for (auto &x:vfinal) printf("%lld ",x);
  printf("\n");
}




static char stdinBuffer[1024];
static char* stdinDataEnd = stdinBuffer + sizeof (stdinBuffer);
static const char* stdinPos = stdinDataEnd;

void readAhead(size_t amount)
{
    size_t remaining = stdinDataEnd - stdinPos;
    if (remaining < amount) {
       memmove(stdinBuffer, stdinPos, remaining);
       size_t sz = fread(stdinBuffer + remaining, 1, sizeof (stdinBuffer) - remaining, stdin);
       stdinPos = stdinBuffer;
       stdinDataEnd = stdinBuffer + remaining + sz;
       if (stdinDataEnd != stdinBuffer + sizeof (stdinBuffer))
         *stdinDataEnd = 0;
    }
}

int rint()
{
    readAhead(16);

    int x = 0;
    bool neg = false;
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    if (*stdinPos == '-') {
       ++stdinPos;
       neg = true;
    }

    while (*stdinPos >= '0' && *stdinPos <= '9') {
       x *= 10;
       x += *stdinPos - '0';
       ++stdinPos;
    }

    return neg ? -x : x;
}
char rch()
{
    readAhead(16);
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    char ans=*stdinPos;
    ++stdinPos;
    return ans;
}
long long rlong()
{
    readAhead(32);

    long long x = 0;
    bool neg = false;
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    if (*stdinPos == '-') {
       ++stdinPos;
       neg = true;
    }

    while (*stdinPos >= '0' && *stdinPos <= '9') {
       x *= 10;
       x += *stdinPos - '0';
       ++stdinPos;
    }

    return neg ? -x : x;
}