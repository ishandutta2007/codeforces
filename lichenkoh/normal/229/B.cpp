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
const int mn=1e5+2;
vector<pii> vt[mn];
vector<pii> g[mn];
int vdist[mn];
int gett(int x, int t) {
  int imin=0,imax=vt[x].size();
  while(imin<imax) {
    int imid=(imin+imax)>>1;
    if (vt[x][imid].snd<t) imin=imid+1;
    else imax=imid;
  }
  if (imin<vt[x].size()) {
    pii got=vt[x][imin];
    int l=got.fst,r=got.snd;
    if (l<=t&&t<=r) return r+1;
  }
  return t;
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),m=rint();
  for (int i=0;i<m;i++) {
    int a=rint(),b=rint(),c=rint();
    g[a].PB(MP(b,c));
    g[b].PB(MP(a,c));
  }
  for (int x=1;x<=n;x++) {
    int k=rint();
    vector<int> v;
    v.reserve(k);
    for (int j=0;j<k;j++) {
      v.PB(rint());
    }
    vt[x].reserve(k);
    if (k>0) {
      int l = v[0];
      for (int i = 1; i < k; i++) {
        if (v[i]==v[i-1]||v[i]==v[i-1]+1) {
        }
        else {
          int r=v[i-1];
          vt[x].PB(MP(l,r));
          l=v[i];
        }
      }
      vt[x].PB(MP(l,v[k-1]));
    }
    //printf("x:%d\n",x);
    //for (auto &w:vt[x]) printf("%d %d\n",w.fst,w.snd);
  }
  for (int x=1;x<=n;x++) vdist[x]=INT_MAX;
  priority_queue<pii,vector<pii>,greater<pii> > pq;
  int st=gett(1,0);
  vdist[1]=st;
  pq.push(MP(st,1));
  int ans=INT_MAX;
  while(!pq.empty()) {
    pii got=pq.top(); pq.pop();
    int x=got.snd,dist=got.fst;
    if (x==n) {
      chkmin(ans,dist);
      printf("%d\n",ans);
      return 0;
    }
    //printf("x:%d dist:%d\n",x,dist);
    if (dist!=vdist[x]) continue;
    for (auto &yy:g[x]) {
      int y=yy.fst,c=yy.snd;
      int alt=dist+c;
      if (y==n) chkmin(ans,alt);
      int talt=gett(y,alt);
      //printf("x:%d y:%d alt:%d talt:%d\n",x,y,alt,talt);
      if (talt<vdist[y]) {
        vdist[y]=talt;
        pq.push(MP(talt,y));
      }
    }
  }
  if (ans==INT_MAX) printf("-1\n");
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