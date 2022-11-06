#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
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

const int mn=1e6+4;
vi g[mn];
int gsz[mn];
map<vi,int> h[mn];
int vq[mn];
bool cmp(int x, int y) {
  return gsz[x]<gsz[y];
}
bitset<mn> done;

template <typename LST, int _MAXSIZE> struct LimitedVec  {
  static const int mn=_MAXSIZE;
  LST a[_MAXSIZE];
  int sz;
  void push_back(LST val) {
    a[sz++]=val;
  }
  LST * begin()
  {
    return &a[0];
  }
  LST * end()
  {
    return &a[sz];
  }
  void clear() {
    sz=0;
  }
  int size() {
    return sz;
  }
  LST operator [](int i) const    {return a[i];}
  LST & operator [](int i) {return a[i];}
};
LimitedVec<int,mn> lv;
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),m=rint();
  for (int i=0;i<m;i++) {
    int x=rint()-1,y=rint()-1;
    g[x].PB(y); g[y].PB(x);
  }
  int z=0;
  for (int q=0;q<n;q++) {
    vq[q]=q;
    gsz[q]=g[q].size();
    if (gsz[q]==0) z++;
    sort(g[q].begin(),g[q].end());
  }
  ll final=z*(ll)(z-1);
  sort(vq,vq+n,cmp);
  for (int i=0;i<n;i++) {
    int q=vq[i];
    int maxsz=0;
    for (auto &x:g[q]) {
      if (done[x]) continue;
      done[x]=true;
      chkmax(maxsz,gsz[x]);
      ++h[g[x].size()][g[x]];
    }
    for (int s=0;s<=maxsz;s++) {
      for (auto &w:h[s]) {
        final+=w.snd*(ll)(w.snd-1);
      }
      h[s].clear();
    }
  }
  done.reset();
  for (int x=0;x<n;x++) {
    g[x].PB(x); sort(g[x].begin(),g[x].end());
  }
  for (int i=0;i<n;i++) {
    int q=vq[i];
    int maxsz=0;
    for (auto &x:g[q]) {
      if (done[x]) continue;
      done[x]=true;
      chkmax(maxsz,gsz[x]);
      ++h[g[x].size()][g[x]];
    }
    for (int s=1;s<=maxsz+1;s++) {
      for (auto &w:h[s]) {
        final+=w.snd*(ll)(w.snd-1);
      }
      h[s].clear();
    }
  }
  final/=2;
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