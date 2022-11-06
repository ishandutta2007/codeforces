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
const int mn=52;
const int mt=100*50+2;
ld dp[mn][mt];
ld g00;
int f[mn],s[mn]; ld p[mn];
int n,r;
ld g(int l, int t) {
  ld res=0;
  if (t>r) return g00;
  if (t<=r&&l==n) return 0;
  //assert(l<=n&&t<=r);
  if (dp[l][t]>-1) {
    //printf("l:%d t:%d %Lf\n",l,t,dp[l][t]);
    return dp[l][t];
  }
  ld a=g(l+1,t+f[l])+f[l];
  ld b=g(l+1,t+s[l])+s[l];
  ld ans1=a*p[l]+b*(1-p[l]);
  ld ans=ans1;
  if (l>0) {
    ld ans2 = g00;
    chkmin(ans, ans2);
  }
  //printf("l:%d t:%d ans:%Lf a:%Lf b:%Lf=%Lf+%d. %d %d\n",l,t,ans,a,b,g(l+1,t+s[l]),s[l],l+1,t+s[l]);
  return dp[l][t]=ans;
}
void reset() {
  for (int l=0;l<=n;l++) {
    for (int t=0;t<=r;t++) {
      dp[l][t]=-2;
    }
  }
}
ld test() {
  reset();
  ld got=g(0,0);
  //printf("%Lf %Lf\n",g00,got);
  return got;
}
int main()
{
  time_t st=clock();
  ios_base::sync_with_stdio(false); cin.tie(0);
  n=rint(),r=rint();
  ld prod=1;
  ll ssum=0;
  for (int i=0;i<n;i++) {
    f[i]=rint(),s[i]=rint(),p[i]=rint()/100.0L;
    prod*=p[i];
    ssum+=s[i];
  }
  ld imin=0, imax=ssum/prod;
  chkmax(imax,(ld)1e18);
  for (int k=0;k<200;k++) {
    if (clock()-st > 1.5 * CLOCKS_PER_SEC) break;
    ld imid=(imin+imax)/2;
    g00=imid;
    ld got=test();
    if (got>g00) imin=imid;
    else imax=imid;
  }
  printf("%.10f\n",(double)imin);
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