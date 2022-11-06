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
template<typename V, typename T> int bins(V &v, T key) {int imin=0,imax=int(v.size());while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}
template<typename T, int amaxsize> struct Prevec  {
  T a[amaxsize];
  int sz;
  void push_back(T val) {a[sz++]=val;}
  T * begin() {return &a[0];}
  T * end() {return &a[sz];}
  T operator [](int i) const {assert(0<=i&&i<sz); return a[i];}
  T & operator [](int i) {assert(0<=i&&i<sz); return a[i];}
  int size() const {return sz;}
  void clear() {sz=0;}
  void resize(int newsz) {sz=newsz;}
};
const int mn=3004;
int a[mn][mn];
int asz[mn];
ll asum[mn];
ll f[mn];
ll fsum[2][mn];
Prevec<int,mn> fpoint;
const ll BAD=-1;

ll pi2val(int cur, int asize, int dest, int pi) {
  if (0<=pi&&pi<fpoint.size()) {
    int point=fpoint[pi];
    int ai=dest-point;
    if (0<=ai&&ai<=asize) {
      return fsum[cur][point]+asum[dest-point];
    }
  }
  return BAD;
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int qn=rint(); int klim=rint();
  for (int q=0;q<qn;q++) {
    int t=rint();
    asz[q]=min(klim,t);
    for (int i=1;i<=t;i++) {
      int x=rint();
      if (i<=klim) {
        a[q][i]=x;
      }
    }
  }
  for (int q=0;q<qn;q++) {
    int cur=q&1;
    int nxt=cur^1;
    int fr=klim;
    int ar=asz[q];
    {
      ll sum=0;
      for (int ai=1;ai<=ar;ai++) {
        sum+=a[q][ai];
        asum[ai]=sum;
      }
    }
    for (int fi=1;fi<=fr;fi++) {
      f[fi]=fsum[cur][fi]-fsum[cur][fi-1];
    }
    fpoint.clear();
    fpoint.PB(0);
    for (int fi=1;fi<=fr;fi++) {
      if (f[fi]>f[fi+1]) fpoint.PB(fi);
    }
    int pi=0;
    for (int dest=1;dest<=klim;dest++) {
      // pi must be high enough so that fpoint[pi]+(ar-1)>=dest
      pi=bins(fpoint,dest-ar+1);

      // TODO: I don't think this while loop is necessary
      while(pi2val(cur,ar,dest,pi+1) > pi2val(cur,ar,dest,pi)) pi++;

      ll apartialcur=pi2val(cur,ar,dest,pi);
      // npi takes as much from f as possible
      int npi=bins(fpoint,dest+1)-1;
      ll apartialnew=pi2val(cur,ar,dest,npi);
      if (apartialnew>apartialcur) {
        pi=npi;
      }
      ll apartial=max(apartialcur,apartialnew);
      ll afull=(dest>=ar)?(asum[ar]+fsum[cur][dest-ar]):BAD;
      //if (dest>=ar) {
      //  printf("asum[ar(%d)]:%lld fsum[cur(%d)][dest(%d)-ar(%d)]:%lld\n",
      //    ar,asum[ar],cur,dest,ar,fsum[cur][dest-ar]);
      //}
      ll orig=fsum[cur][dest];
      ll ans=max(orig,max(apartial,afull));
      fsum[nxt][dest]=ans;
      //printf("q:%d dest:%d orig:%lld apartialcur:%lld apartialnew:%lld afull:%lld fsum:%lld\n"
      //  ,q,dest,orig, apartialcur,apartialnew,afull,fsum[nxt][dest]);
    }
  }
  ll final=fsum[qn&1][klim];
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