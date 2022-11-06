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
int mod_pow(int a, int n) {
  const int mod=MOD;
  int ret = 1; int p = a % mod; while (n) { if (n & 1) ret = (ret *(ll) p) % mod; p = (p *(ll) p) % mod; n >>= 1; } return ret; }
inline int mul(int x,int y) {return (x*(ll)y)%MOD;}
const int mn=2e5+4;
void makeunique(vector<int> &vx) {
  sort(vx.begin(),vx.end());
  auto it=unique(vx.begin(),vx.end());
  vx.resize(std::distance(vx.begin(),it));
}
int bins(vector<int> &vx, int x) {
  int imin=0,imax=vx.size();
  while(imin<imax) {
    int imid=(imin+imax)>>1;
    if (vx[imid]<x) imin=imid+1;
    else imax=imid;
  }
  return imin;
}

bool iscyc;
bool seen[mn];
vector<int> g[mn];
int dfs(int x, int p) {
  if (seen[x]) {
    iscyc=true;
    return 0;
  }
  int ans=1;
  seen[x]=true;
  for (auto &y:g[x]) {
    if (y==p) continue;
    ans+=dfs(y,x);
  }
  return ans;
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);

  int n=rint();
  vector<int> vx,vy; vector<pii> vp;
  vx.reserve(n);vy.reserve(n);vp.reserve(n);
  for (int i=0;i<n;i++) {
    int x=rint(),y=rint();
    vp.PB(MP(x,y));
    vx.PB(x); vy.PB(y);
  }
  makeunique(vx);makeunique(vy);
  for (int i=0;i<n;i++) {
    int x=vp[i].fst,y=vp[i].snd;
    int bx=bins(vx,x);
    int by=bins(vy,y)+vx.size();
    g[bx].PB(by);
    g[by].PB(bx);
  }
  int k=vx.size()+vy.size();
  int final=1;
  for (int x=0;x<k;x++) {
    if (seen[x]) continue;
    iscyc=0;
    int sz=dfs(x,-1);
    if (iscyc) {
      final=mul(final,mod_pow(2,sz));
    }
    else {
      final=mul(final,(mod_pow(2,sz)+MOD-1)%MOD);
    }
  }
  printf("%d\n",final);
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