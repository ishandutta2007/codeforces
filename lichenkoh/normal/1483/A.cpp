#ifdef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#pragma GCC optimize("Ofast")
#endif
#include "bits/stdc++.h"
#ifndef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#pragma GCC optimize("Ofast")
#endif
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

void go() {
  int oldn,n; cin>>oldn>>n;
  vvi v(n);
  map<int,int> h;
  for (int d=0;d<n;d++) {
    int k; cin>>k;
    for (int i=0;i<k;i++) {
      int x;cin>>x;v[d].PB(x);
      ++h[x];
    }
  }
  int lim=(n+1)/2;
  vi hi;
  for (auto &w:h) {
    if (w.snd>lim) hi.PB(w.fst);
  }
  if (hi.size()<=1) {
    int a=(hi.size())?hi[0]:-1;
    vi vans(n);
    int acnt=0;
    for (int d=0;d<n;d++) {
      int use=-1;
      for (auto &x:v[d]) if (x!=a) use=x;
      if (use==-1) use=v[d][0];
      if (use==a) acnt++;
      assert(use!=-1);
      vans[d]=use;
    }
    if (acnt<=lim) {
      printf("YES\n"); for (auto &w:vans) printf("%d ",w);
      printf("\n");
    } else {
      printf("NO\n");
    }
  } else {
    hi.resize(2);
    int a=hi[0],b=hi[1];
    vi q[4];
    for (int d=0;d<n;d++) {
      int hasa=0,hasb=0;
      for (auto &x:v[d]) {
        if (x==a) hasa=1;
        if (x==b) hasb=1;
      }
      q[(hasb<<1)|hasa].PB(d);
    }
    int rema=q[1].size();
    int remb=q[2].size();
    int clim=q[3].size();
    int goodc=-1;
    for (int c=0;c<=clim;c++) {
      if (rema+c <= lim && remb+clim-c <= lim) {
        goodc=c; break;
      }
    }
    if (goodc==-1) {
      assert(0);
      printf("NO\n"); return;
    }
    for (int i=0;i<goodc;i++) q[1].PB(q[3][i]);
    for (int i=goodc;i<clim;i++) q[2].PB(q[3][i]);
    vi vans(n);
    for (auto &x:q[1]) vans[x]=a;
    for (auto &x:q[2]) vans[x]=b;
    for (auto &x:q[0]) vans[x]=v[x][0];
    printf("YES\n");
    for (auto &w:vans) printf("%d ",w);
    printf("\n");
  }
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t; cin>>t; for (int i=0;i<t;i++) go();
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