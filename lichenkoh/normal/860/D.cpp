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

const int mn=2e5+4;
vector<int> g[mn];
int edest[2*mn];
bool blocked[2*mn];
int seen[mn];
vector<int> vans;
int partition(int v) {
  seen[v]=true;
  vector<int> adjacent;
  for (auto &id:g[v]) {
    if (!blocked[id]) {
      int u=edest[id];
      adjacent.PB(u);
      blocked[id]=true;
      blocked[id^1]=true;
    }
  }
  vector<int> unpaired;
  for (auto &u:adjacent) {
    int w=partition(u);
    if (w==0) {
      unpaired.PB(u);
    }
    else {
      vans.PB(v);vans.PB(u);vans.PB(w);
    }
  }
  while(unpaired.size()>=2) {
    int u=unpaired.back(); unpaired.pop_back();
    int w=unpaired.back(); unpaired.pop_back();
    vans.PB(u);vans.PB(v);vans.PB(w);
  }
  if (unpaired.size()>0) {
    return unpaired[0];
  }
  else return 0;
}
int gid=0;
void ae(int x, int y) {
  edest[gid]=y;
  g[x].PB(gid);
  gid++;
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n,m;
  scanf("%d%d",&n,&m);
  for (int i=0;i<m;i++) {
    int x,y;
    scanf("%d%d",&x,&y);
    ae(x,y);
    ae(y,x);
  }
  for (int x=1;x<=n;x++) {
    if (seen[x]) continue;
    partition(x);
  }
  int anssz=vans.size()/3;
  printf("%d\n",anssz);
  int tidx=0;
  for (int i=0;i<anssz;i++) {
    for (int j=0;j<3;j++) printf("%d ",vans[tidx++]);
    printf("\n");
  }
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