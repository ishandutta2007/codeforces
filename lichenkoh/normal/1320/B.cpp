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
const int mn=(2e5)+4;
vi r[mn];
int p[mn],dist[mn];
void bfs(int init, int n) {
  queue<int> q;
  for (int x=1;x<=n;x++) dist[x]=INF;
  dist[init]=0;
  q.push(init);
  while(!q.empty()) {
    int x=q.front(); q.pop();
    //printf("x:%d dist:%d\n",x,dist[x]);
    int nd=dist[x]+1;
    for (auto &y:r[x]) {
      if (nd<dist[y]) {
        dist[y]=nd;
        q.push(y);
      }
    }
  }
}
vi f[mn];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),e=rint();
  for (int i=0;i<e;i++) {
    int x=rint(),y=rint();
    r[y].PB(x);
    f[x].PB(y);
  }
  int k=rint();
  for (int i=0;i<k;i++) {
    p[i]=rint();
  }
  bfs(p[k-1],n);
  int lofinal=0;
  for (int i=0;i<k-2;i++) {
    int px=p[i],nx=p[i+1];
    //printf("px:%d (%d) -> nx:%d (%d)\n",px,dist[px],nx,dist[nx]);
    if (dist[nx] >= dist[px]) lofinal++;
  }
  int hifinal=0;
  for (int i=0;i<k-2;i++) {
    int px=p[i],nx=p[i+1];
    if (dist[nx]>=dist[px]) hifinal++;
    else {
      int want=dist[nx];
      for (auto &y:f[px]) {
        if (y!=nx && dist[y]==want) {
          hifinal++; break;
        }
      }
    }
  }
  printf("%d %d\n",lofinal,hifinal);
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