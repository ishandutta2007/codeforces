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
void fail() {
  printf("-1\n"); exit(0);
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(); vi a(n+1);
  for (int c=1;c<=n;c++) {
    a[c]=rint();
  }
  vpii vans;
  vpii vone;
  int ru=n+1;
  {
    for (int c=1;c<=n;c++) {
      if (a[c]==1) {
        ru--; if (ru<=0) fail();
        vone.PB(MP(c,ru));
        vans.PB(MP(c,ru));
      }
    }
  }
  vpii vtwo;
  {
    int oi=0;
    for (int c=1;c<=n;c++) {
      if (a[c]==2) {
        while(oi < vone.size() && vone[oi].fst <= c) {
          vtwo.PB(vone[oi]);
          oi++;
        }
        if (oi>=vone.size()) fail();
        vans.PB(MP(c,vone[oi].snd));
        vtwo.PB(MP(c,vone[oi].snd));
        oi++;
      }
    }
    for (int i=oi;i<vone.size();i++) {
      vtwo.PB(vone[i]);
    }
    sort(vtwo.begin(),vtwo.end(),greater<pii>());
  }
  {
    int tc=-1,tr=-1;
    for (int c=n;c>=1;c--) {
      if (a[c]==3) {
        ru--; if (ru<=0) fail();
        if (tc==-1) {
          if (vtwo.size()) {tc=vtwo[0].fst;tr=vtwo[0].snd;}
          else fail();
          if (!(tc>c)) fail();
        }
        vans.PB(MP(c,ru));
        vans.PB(MP(tc,ru));
        //printf("c:%d ru:%d tc:%d tr:%d\n",c,ru,tc,tr);
        tc=c; tr=ru;
      }
    }
  }
  printf("%d\n",(int)(vans.size()));
  for (auto &w:vans) printf("%d %d\n",w.snd,w.fst);
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