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
const int UNDEF = (1<<30)-1;
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
const int mn=1e5+4;
const int md=1e6+4;
vector<pii> vconf[md];
vector<int> vupd[md];
priority_queue<pii,vector<pii>,greater<pii> > vpq[mn];
int vminconf[mn];
int voldcost[mn];
bool sated[mn];
int k;
int gethome(int x, int d) {
  int need=d;
  while((!vpq[x].empty())&&vpq[x].top().snd<need) vpq[x].pop();
  if (vpq[x].empty()) return UNDEF;
  return vpq[x].top().fst;
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),m=rint();
  k=rint();
  for (int i=0;i<m;i++) {
    int d=rint(),f=rint(),t=rint(),c=rint();
    if (t==0) {
      vconf[d].PB(MP(f,c)); // MP(city, cost)
      vupd[d].PB(f);
    }
    else {
      d=d-k-1;
      if (d>=0) {
        vpq[t].push(MP(c,d)); // MP(cost, day)
        vupd[d+1].PB(t);
      }
    }
  }
  for (int x=1;x<=n;x++) vminconf[x]=UNDEF;
  ll now=0;
  ll final=1LL<<62;
  int tosat=n;
  for (int std=0;std<md;std++) {
    for (auto &w:vconf[std]) {
      int city=w.fst,cost=w.snd;
      chkmin(vminconf[city],cost);
    }
    for (auto &city: vupd[std]) {
      int newcost=vminconf[city]+gethome(city,std);
      if (newcost<UNDEF) {
        now+=newcost-voldcost[city];
        voldcost[city]=newcost;
        if (!sated[city]) {
          sated[city]=true;
          tosat--;
        }
        //assert(tosat>=0);
      }
      else {
        if (sated[city]) {
          now-=voldcost[city];
          sated[city]=false;
          tosat++;
          voldcost[city]=0;
        }
      }
    }
    if (tosat==0) {
      chkmin(final,now);
    }
  }
  if (final>=1LL<<62) final=-1;
  printf("%lld\n",final);
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