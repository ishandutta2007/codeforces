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
int n,m;
bool val(int x, int y) {
  return 0<=x&&x<=n&&0<=y&&y<=m;
}
vector<pii> v;
ld ddist(int a, int b) {
  ll dx=v[a].fst-v[b].fst;
  ll dy=v[a].snd-v[b].snd;
  return sqrt((ld)(dx*dx+dy*dy));
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin>>n>>m;
  vector<int> vx; vx.PB(0);vx.PB(n);
  vector<int> vy; vy.PB(0);vy.PB(m);

  for (auto &ix:vx) {
    for (auto &iy:vy) {
      for (int dx=-2;dx<=2;dx++) {
        for (int dy=-2;dy<=2;dy++) {
          int x=ix+dx,y=iy+dy;
          if (val(x,y)) v.PB(MP(x,y));
        }
      }
    }
  }
  int vsz=v.size();
  pair<ld,pair<pii,pii> > best;
  best.fst=0;
  for (int a=0;a<vsz;a++) {
    for (int b=0;b<vsz;b++) {
      for (int c=0;c<vsz;c++) {
        for (int d=0;d<vsz;d++) {
          set<pii> s;
          s.insert(v[a]);
          s.insert(v[b]);
          s.insert(v[c]);
          s.insert(v[d]);
          if (s.size()!=4) continue;
          ld dddist=ddist(a,b)+ddist(b,c)+ddist(c,d);
          pair<ld,pair<pii,pii> > cand=MP(dddist,MP(MP(a,b),MP(c,d)));
          chkmax(best,cand);
        }
      }
    }
  }
  {
    int t[4];
    int i=0;
    t[i++]=best.snd.fst.fst;
    t[i++]=best.snd.fst.snd;
    t[i++]=best.snd.snd.fst;
    t[i++]=best.snd.snd.snd;
    for (int j=0;j<4;j++) {
      auto got=v[t[j]];
      printf("%d %d\n",got.fst,got.snd);

    }
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