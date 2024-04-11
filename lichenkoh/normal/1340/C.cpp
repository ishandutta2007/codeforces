#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
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
const int INF=1<<30;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;typedef vector<pii> vpii;
#ifdef ONLINE_JUDGE
#define assert(...) /* nothing */
#endif
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();
// mt19937 rng; rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}
const int mn=(1e4)+2;
const int mk=1000+8;
int a[mn];
int G,R,n;
int vdist[mn][mk];
ll bfs01() {
  ll final=LLONG_MAX;
  for (int x=0;x<n;x++) for (int k=0;k<G;k++) vdist[x][k]=INF;
  queue<pii> q[2];
  int cur=0,nxt=1;
  vdist[0][0]=0;
  q[cur].push(MP(0,0));
  while(!q[cur].empty()) {
    while(!q[cur].empty()) {
      pii qf=q[cur].front(); q[cur].pop();
      int x=qf.fst; int k=qf.snd;
      int dist=vdist[x][k];
      //printf("x:%d k:%d d:%d\n",x,k,dist);
      for (int d=-1;d<=1;d+=2) {
        int y=x+d;
        if (!(0<=y&&y<n)) continue;
        int nk=k + abs(a[y]-a[x]);
        //printf("y:%d nk:%d\n",y,nk);
        if (nk<=G) {
          if (y==n-1) {
            chkmin(final, dist*(ll)(R+G) + nk);
          } else {
            int ndist,tar;
            if (nk==G) {
              nk=0;
              ndist=dist+1;
              tar=nxt;
            } else {
              ndist=dist;
              tar=cur;
            }
            if (ndist<vdist[y][nk]) {
              vdist[y][nk]=ndist;
              q[tar].push(MP(y,nk));
            }
          }
        }
      }
    }
    swap(cur,nxt);
  }
  return final;
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int blah=rint();n=rint();
  for (int i=0;i<n;i++) a[i]=rint();
  G=rint();R=rint();
  sort(a,a+n);
  ll final=bfs01();
  if (final == LLONG_MAX) printf("-1\n");
  else printf("%lld\n",final);
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