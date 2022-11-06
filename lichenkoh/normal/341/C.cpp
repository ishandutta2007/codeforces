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
int dp[mn][mn];
int f(int s, int l) {
  if (dp[s][l]!=-1) return dp[s][l];
  ll ans=0;
  if (s>0) {
    if (s>=2) {
      ans+=(f(s-1,l)+f(s-2,l))*(ll)(s-1);
    }
    if (l>=1) {
      ans+=f(s-1,l)*(ll)l;
    }
  }
  else {
    if (l>=2) {
      ans+=f(0,l-1)*(ll)(l-1);
    }
    ans+=(f(0,l-1));
  }
  int res=ans%MOD;
  return dp[s][l]=res;
}
int a[mn];
int inva[mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  for (int x=1;x<=n;x++) a[x]=rint();
  for (int x=1;x<=n;x++) {
    if (a[x]!=-1) inva[a[x]]=x;
  }
  int lines=0,singles=0;
  for (int x=1;x<=n;x++) {
    if (a[x]==-1) {
      if (inva[x]==0) singles++;
      else lines++;
    }
  }
  memset(dp,-1,sizeof dp);
  dp[0][0]=1;
  int ans=f(singles,lines);
  printf("%d\n",ans);
}