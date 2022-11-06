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
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define DEBUG_CAT
#ifdef DEBUG_CAT

#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
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
const int mn=2004;
int n,q;
ll **vt[4];
//ll **vs[4];
void add(int id, int r, int c, ll value) {
  ll **t=vt[id];
  //ll **s=vs[id];s[r][c]^=value;
  for (int i = r; i < mn; i |= i + 1)
    for (int j = c; j < mn; j |= j + 1)
      t[i][j] ^= value;
}

// sum[(0, 0), (r, c)]
ll sum(int id, int r, int c) {
  ll **t=vt[id];
  int res=0;
  for (int i = r; i >= 0; i = (i & (i + 1)) - 1)
    for (int j = c; j >= 0; j = (j & (j + 1)) - 1)
      res ^= t[i][j];
  return res;
}
ll qsum(ll x, ll y) {
  ll ans=0;
  bool xodd=x&1;
  bool yodd=y&1;
  if(xodd&&yodd) ans^=sum(0,mn-1,mn-1)^sum(0,x,y);
  ans^=sum(1,x,y);
  if(yodd) ans^=sum(2,x,mn-1)^sum(2,x,y);
  if(xodd) ans^=sum(3,mn-1,y)^sum(3,x,y);
  return ans;
}
void qadd(ll x, ll y, ll v) {
  bool xodd=x&1;
  bool yodd=y&1;
  add(0, x,y,v);
  if(xodd&&yodd) add(1,x,y,v);
  if (xodd) add(2, x,y,v);
  if (yodd) add(3, x,y,v);
}

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	n=rint();
  q=rint();
  for (int k=0;k<4;k++) {
    vt[k]=new ll*[mn];
    for (int x=0;x<mn;x++) {
      vt[k][x]=new ll[mn];
      memset(vt[k][x],0,sizeof(ll)*mn);
    }
  }
  for (int i=0;i<q;i++) {
    int t=rint();
    int r1=rint(),c1=rint(),r2=rint(),c2=rint();
    //printf("r1:%d c1:%d\n",r1,c1);
    if (t==1) {
      ll ans=0;
      ans^=qsum(r2, c2);
      ans^=qsum(r1 - 1, c2);
      ans^=qsum(r2, c1 - 1);
      ans^=qsum(r1 - 1, c1 - 1);
      printf("%lld\n",ans);
    }
    else {
      ll v=rlong();
      qadd(r2, c2, v);
      qadd(r1 - 1, c2, v);
      qadd(r2, c1 - 1, v);
      qadd(r1 - 1, c1 - 1, v);
    }
  }
}