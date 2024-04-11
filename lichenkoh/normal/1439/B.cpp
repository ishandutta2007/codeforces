#ifdef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#pragma GCC optimize("Ofast")
#endif
#include "bits/stdc++.h"
#ifndef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#pragma GCC optimize("Ofast")
#endif
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
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;typedef vector<pii> vpii;typedef vector<pll> vpll;
template<typename T> void makeunique(vector<T> &vx) {sort(vx.begin(),vx.end());auto it=unique(vx.begin(),vx.end());vx.resize(std::distance(vx.begin(),it));}
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
template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=(int)v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}
vvi g;
vi deg;
int findS(int n, int k) {
  queue<int> q;
  for (int x=0;x<n;x++) {
    deg[x]=g[x].size();
    if (deg[x] < k) q.push(x);
  }
  while(!q.empty()) {
    int x=q.front(); q.pop();
    deg[x]=0;
    for (auto &y:g[x]) {
      if (deg[y]==k) q.push(y);
      --deg[y];
    }
  }
  int sz=0;
  for (int x=0;x<n;x++) {
    if (deg[x]>=k) sz++;
  }
  return sz;
}

void test() {
  g.clear(); deg.clear();
  int n=rint();
  int m=rint();
  int k=rint();
  g.resize(n); deg.resize(n);
  for (int e=0;e<m;e++) {
    int x=rint()-1; int y=rint()-1;
    g[x].PB(y); g[y].PB(x);
  }
  if (k==1) {
    printf("2\n1\n");
    return;
  }
  {
    int sz=findS(n,k);
    if (sz>0) {
      assert(sz>=k+1);
      printf("1 %d\n",sz);
      for (int x=0;x<n;x++) {
        if (deg[x]>=k) printf("%d ",x+1);
      }
      printf("\n");
      return;
    }
  }
  {
    int sz=findS(n,k-1);
    if (sz>0) {
      for (int x=0;x<n;x++) sort(g[x].begin(),g[x].end());
      assert(sz>=k);
      vi ver(n);
      queue<int> qinit;
      for (int init=0;init<n;init++) {
        if (deg[init]==k-1) qinit.push(init);
      }
      while(!qinit.empty()) {
        int init=qinit.front(); qinit.pop();
        if (deg[init]!=k-1) continue;
        //printf("init:%d\n",init+1);
        int version=init+1;
        vi Q;
        ver[init]=version; Q.PB(init);
        for (auto &x:g[init]) {
          if (deg[x]>=k-1) {
            ver[x]=version; Q.PB(x);
          }
        }
        assert(Q.size()==k);
        bool ok=true;
        for (int xi=0;ok&&xi<k;xi++) {
          int Qx=Q[xi];
          for (int yi=0;yi<xi;yi++) {
            int Qy=Q[yi];
            int idx=bins(g[Qx],Qy);
            if (!(idx<g[Qx].size() && g[Qx][idx]==Qy)) {
              ok=false; break;
            }
          }
        }
        if (ok) {
          printf("2\n");
          for (auto &q:Q) printf("%d ",q+1);
          printf("\n");
          return;
        }
        queue<int> q;
        q.push(init);
        while(!q.empty()) {
          int x=q.front(); q.pop();
          deg[x]=0;
          for (auto &y:g[x]) {
            if (deg[y]==k-1) q.push(y);
            --deg[y];
            if (deg[y]==k-1) qinit.push(y);
          }
        }
      }
    }
  }
  printf("-1\n");
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t=rint();
  for (int i=0;i<t;i++) test();
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