#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef double ld;
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
#define assert(XXX) XXX
#else
#define DEBUG_CAT
#endif
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();

ld f[2][202][202];
ld g[2][202];
int a[202]; ld p[202];
pair<int,int> v[202];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),l=rint(),k=rint();
  for (int i=0;i<n;i++) v[i].snd=rint();
  for (int i=0;i<n;i++) v[i].fst=rint();
  sort(v,v+n,greater<pii>());
  for (int i=0;i<n;i++) p[i]=v[i].snd/100.0;
  for (int i=0;i<n;i++) a[i]=v[i].fst;
  chkmin(k,n);
  ld ans=0;
  {
    int cur=0,nxt=1;
    f[cur][0][k]=1;
    for (int i=0;i<n;i++) {
      memset(f[nxt],0,sizeof f[nxt]);
      for (int wins=0;wins<=n;wins++) {
        for (int sp=0;sp<=n;sp++) {
          ld now=f[cur][wins][sp];
          f[nxt][wins][sp]+=now*(1-p[i]);
          if (wins+1<=n&&sp+a[i]>=0) {
            f[nxt][wins+1][min(n,sp+a[i])]+=now*p[i];
          }
        }
      }
      swap(cur,nxt);
    }
    for (int wins=l;wins<=n;wins++) {
      for (int sp=0;sp<=n;sp++) {
        ans+=f[cur][wins][sp];
      }
    }
  }
  /*ld denom=0;
  {
    int cur=0,nxt=1;
    g[cur][0]=1;
    for (int i=0;i<n;i++) {
      memset(g[nxt],0,sizeof g[nxt]);
      for (int wins=0;wins<=n;wins++) {
        ld now=g[cur][wins];
        g[nxt][wins]+=now*(1-p[i]);
        if (wins+1<=n) {
          g[nxt][wins+1]+=now*p[i];
        }
      }
      swap(cur,nxt);
    }
    
    for (int wins=l;wins<=n;wins++) {
      denom+=g[cur][wins];
    }
  }
  printf("%f / %f\n",ans,denom);*/
  printf("%.16f\n",(double)ans);
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