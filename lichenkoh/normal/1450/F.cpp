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
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=(int)v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}
int go() {
  int n; cin>>n;
  vi a(n);
  for (int i=0;i<n;i++) cin>>a[i];
  map<int,int> raw;
  for (int i=0;i<n;i++) ++raw[a[i]];
  for (auto &w:raw) {
    int rem=n-w.snd;
    if (w.snd >= rem+2) return -1;
  }
  map<int,int> hsingles; map<pii,int> hedges;
  int base=0;
  {
    int s=a[0];
    for (int i=1;i<=n;i++) {
      if (i==n||a[i]==a[i-1]) {
        int e=a[i-1];
        base++;
        if (s==e) ++hsingles[s];
        else ++hedges[MP(s,e)];
        if (i<n) s=a[i];
      }
    }
  }
  vpii singles; vector<pair<int,pii > > edges;
  for (auto &w:hsingles) singles.PB(MP(w.snd,w.fst));
  sort(singles.begin(),singles.end()); reverse(singles.begin(),singles.end());
  for (auto &w:hedges) edges.PB(MP(w.snd,w.fst));
  sort(edges.begin(),edges.end()); reverse(edges.begin(),edges.end());
  if (singles.size()) {
    int mainx=singles[0].snd;
    int lone=singles[0].fst;
    for (int i=1;i<singles.size();i++) lone-=singles[i].fst;
    for (auto &w:edges) {
      //lone-=w.fst;
      if (w.snd.fst!=mainx && w.snd.snd!=mainx) lone-=w.fst;
    }
    chkmax(lone,0);
    // Having 1 lone is fine
    int splits = max(0,lone-1);
    chkmax(splits,0);
    //printf("lone:%d spl:%d\n",lone,splits);
    int segs=base+splits;
    return max(0,segs-1);
  } else {
    /*int extra=0;
    if (edges.size()==2) {
      pii x=edges[0].snd;
      pii y=edges[1].snd;
      if (x==MP(y.snd,y.fst)) extra=0;
    }
    chkmax(extra,0);*/
    int segs=base;
    return max(0,segs-1);
  }
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t; cin>>t; for (int i=0;i<t;i++) {int ans=go(); cout<<ans<<endl;}
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