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
int norma(int x, int n) {
  x%=n;
  if (x<0) x+=n;
  return x%n;
}
const int ROW=0,COL=1,VAL=2;
void go() {
  int n,q; cin>>n>>q;
  vvi a(n);
  for (int r=0;r<n;r++) {
    a[r].resize(n);
    for (int c=0;c<n;c++) {
      int x; cin>>x; a[r][c]=x-1;
    }
  }
  string s; cin>>s;
  vi perm(3); for (int x=0;x<3;x++) perm[x]=x;
  vi change(3,0);
  for (int qi=0;qi<q;qi++) {
    char qc=s[qi];
    if (qc=='R') {
      change[perm[COL]]++;
    } else if (qc=='L') {
      change[perm[COL]]--;
    } else if (qc=='D') {
      change[perm[ROW]]++;
    } else if (qc=='U') {
      change[perm[ROW]]--;
    } else if (qc=='I') {
      swap(perm[COL],perm[VAL]);
    } else if (qc=='C') {
      swap(perm[ROW],perm[VAL]);
    } else {
      assert(0);
    }
  }
  const bool DBG=0;
  if (DBG) {
    for (int x=0;x<3;x++) printf("%d ",perm[x]);
    printf("\n");
    for (int x=0;x<3;x++) printf("%d ",change[x]);
    printf("\n");
  }
  vvi vans(n);
  for (int r=0;r<n;r++) {
    vans[r].resize(n);
  }
  vi orig(3);
  for (int r=0;r<n;r++) {
    for (int c=0;c<n;c++) {
      orig[ROW]=r;
      orig[COL]=c;
      orig[VAL]=a[r][c];
      int nr=norma(orig[perm[ROW]]+change[perm[ROW]],n);
      int nc=norma(orig[perm[COL]]+change[perm[COL]],n);
      int nv=norma(orig[perm[VAL]]+change[perm[VAL]],n);
      if (DBG)printf("r:%d c:%d v:%d nr:%d nc:%d nv:%d\n",r,c,a[r][c],nr,nc,nv);
      vans[nr][nc]=nv;
    }
  }
  for (int r=0;r<n;r++) {
    for (int c=0;c<n;c++) {
      printf("%d ",vans[r][c]+1);
    }
    printf("\n");
  }
  printf("\n");
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