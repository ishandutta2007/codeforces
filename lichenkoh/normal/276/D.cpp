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
const int INVALID=-2;
ll gl,gr;
const int LS=0,EQ=1,GR=2;
int trans(int s, int cb, int gb) { // wb: candidate b. gb: global bit to compare against
  if (s!=EQ) return s;
  if (cb==gb) return EQ;
  else if (cb<gb) return LS;
  else return GR;
}
ll dp[64][3][3][3][3];
ll f(int k, int xl, int xr, int yl, int yr) {
  if (k==-1) return 0;
  ll dpval=dp[k][xl][xr][yl][yr];
  if (dpval!=-1) return dpval;
  ll ans=INVALID;
  for (int x=0;x<2;x++) {
    int nxl=trans(xl,x,(gl>>k)&1);
    int nxr=trans(xr,x,(gr>>k)&1);
    if (nxl==LS||nxr==GR) continue;
    for (int y=0;y<2;y++) {
      int nyl=trans(yl,y,(gl>>k)&1);
      int nyr=trans(yr,y,(gr>>k)&1);
      if (nyl==LS||nyr==GR) continue;
      ll got=f(k-1,nxl,nxr,nyl,nyr);
      if (got==INVALID) continue;
      ll cand=(((ll)(x^y))<<k)|got;
      chkmax(ans,cand);
    }
  }
  //printf("k:%d s1:%d s2:%d ans:%lld\n",k,s1,s2,ans);
  return dp[k][xl][xr][yl][yr]=ans;
}


ll solve(ll l, ll r) {
  gl=l,gr=r;
  memset(dp,-1,sizeof dp);
  return f(61,EQ,EQ,EQ,EQ);
}
ll bf(ll l, ll r) {
  ll ans=0;
  for (ll x=l;x<=r;x++) {
    for (ll y=x+1;y<=r;y++) {
      chkmax(ans,x^y);
    }
  }
  return ans;
}
void go() {
  for (int k=0;k<10000;k++) {
    ll x=1+rand()%1000000000000000000LL;
    ll y=min(1000000000000000000LL,x+rand()%100);
    ll l=min(x,y),r=max(x,y);
    ll bff=bf(l,r);
    ll ss=solve(l,r);
    if (bff!=ss) {
      printf("%lld %lld bff:%lld ss:%lld\n",l,r,bff,ss);
    }
  }
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  //go(); return 0;
  ll l,r; cin>>l>>r;
  ll smart=solve(l,r);
  printf("%lld\n",smart);
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