#include <bits/stdc++.h>
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
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();
const ll mn=1000000;
vector<ll> cand={50626,
6724,
82,
16,
4,
0
};
ll mex(vector<ll> &v) {
  sort(v.begin(),v.end());
  ll ans=0;
  for (auto &w:v) {
    if (w==ans)ans++;
  }
  return ans;
}
//const ll MAGIC=6562;
ll smart(ll x) {
  if (x>=mn) {
    ll x4=round(pow((ld)x,0.25L))-2;
    while(x4*x4*x4*x4<x) x4++;
    ll x2=round(sqrt((ld)x))+2;
    while(x2*x2>x) x2--;
    ll lo=max(x4,0ll),hi=min(x2,x-1);
    vector<ll> v;
    for (auto &w:cand) {
      for (ll y=w-1;y<=w+1;y++) {
        if (lo<=y&&y<=hi) {
          v.PB(smart(y));
          //if (x==MAGIC) printf("y:%lld smart:%lld\n",y,smart(y));
        }
      }
    }
    //if (x==MAGIC) {
    //  printf("lo:%lld hi:%lld\n",lo,hi);
    //}
    return mex(v);
  }
  if (x>=50626) return 1;
  if (x>=6724) return 3;
  if (x>=82) return 0;
  if (x>=16) return 2;
  if (x>=4) return 1;
  return 0;
}


/*
ll dp[mn];

ll nim(ll x) {
  if (dp[x]!=-1) return dp[x];
  vector<ll> v;
  ll x4=round(pow((ld)x,0.25L));
  ll x2=round(sqrt((ld)x));
  ll lo=max(0ll,x4-1);
  ll hi=min(x-1,x2+1);
  for (ll y=lo;y<=hi;y++) {
    //printf("x:%d y:%d\n",x,y);
    ll y4=y*y*y*y;
    ll y2=y*y;
    if (y4>=x&&y2<=x) {
      v.PB(nim(y));
    }
  }
  ll ans=mex(v);
  return dp[x]=ans;
}
*/
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  ll n; cin>>n;
  ll ans=0;
  for (ll i=0;i<n;i++) {
    ll x; cin>>x;
    ans^=smart(x);
  }
  if (ans==0) printf("Rublo\n");
  else printf("Furlo\n");
  return 0;
  /*
  memset(dp,-1,sizeof dp);
  ll last=0;
  for (ll x=0;x<mn;x++) {
    if (nim(x)!=last) printf("%lld: %lld\n",x,nim(x));
    last=nim(x);
    if (smart(x)!=nim(x)) {
      printf("x:%lld smart:%lld nim:%lld\n",x,smart(x),nim(x));
      exit(0);
    }
    assert(smart(x)==nim(x));
  }*/
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