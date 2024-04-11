#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

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

int readInt()
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
int n,a,b,k;
const int mn=5002;
ll f[2][mn];
ll g[mn];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	n=readInt(),a=readInt(),b=readInt(),k=readInt();
  int cur=0,nxt=1;
  f[cur][a]=1;
  for (int t=0;t<k;t++) {
    memset(f[nxt],0,sizeof f[nxt]);
    memset(g,0,sizeof g);
    for (int x=1;x<=n;x++) {
      int val=f[cur][x]%MOD;
      int d=max(0,abs(x-b)-1);
      int lo=max(1,x-d);
      int hi=min(n,x+d);
      f[nxt][lo]+=val;
      g[x]-=val;
      f[nxt][hi+1]-=val;
    }
    for (int x=2;x<=n;x++) {
      f[nxt][x]+=f[nxt][x-1];
    }
    for (int x=1;x<=n;x++) {
      ll v=f[nxt][x]+g[x];
      v%=MOD;
      if (v<0) v+=MOD;
      f[nxt][x]=v;
    }
    swap(cur,nxt);
  }
  ll ans=0;
  for (int x=1;x<=n;x++) ans=(ans+f[cur][x])%MOD;
  ans%=MOD;
  printf("%lld\n",ans);
}