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
const int MAXLOG=20;
const int mn=(6e5) + 10;
#define LOG2(X) ((unsigned) (31 - __builtin_clz((X))))
int table[MAXLOG][mn];
void preprocess_rmq(vi const & array) {
  int n=array.size();
  for(int i=0;i<n;i++)            
   table[ 0 ][ i ]=array[ i ];         //building base
  for(int j=1;j<=LOG2(n);j++)
   for(int i=0;i+(1<<(j-1))<n;i++) {
     table[ j ][ i ] = min ( table[ j-1 ][ i ], table[ j-1 ][ i+(1<<(j-1)) ] );  //use previously computed
   }
}
int query_rmq(int x, int y) {
  int len=y-x+1;
  int k=LOG2(len);
  //printf("Query. k:%intd x:%intd y:%intd y+1-(1<<k):%intd\n",k,x,y,y+1-(1<<k));
  return min(table[ k ][ x ],table[ k ][ y+1-(1<<k) ]);   // ranges may overlap
}

void go() {
  int n; cin>>n;
  vi a(n); for (int i=0;i<n;i++) cin>>a[i];
  preprocess_rmq(a);
  vi val2cnt(n+1);
  for (int p=0;p<n;p++) {
    int val=a[p];
    int l;
    {
      int imin=0,imax=p;
      while(imin<imax) {
        int imid=(imin+imax)/2;
        if (query_rmq(imid,p) < val) imin=imid+1;
        else imax=imid;
      }
      l=imin;
    }
    int r;
    {
      int imin=p,imax=n;
      while(imin<imax) {
        int imid=(imin+imax)/2;
        if (query_rmq(p,imid) >= val) imin=imid+1;
        else imax=imid;
      }
      r=imin-1;
    }
    chkmin(l,p);
    chkmax(r,p);
    int cnt=r-l+1;
    chkmax(val2cnt[val],cnt);
  }
  vvi cnt2val(n+1);
  for (int val=1;val<=n;val++) {
    cnt2val[val2cnt[val]].PB(val);
  }
  vector<bool> val2good(n+1);
  int good=0;
  for (int val=1;val<=n;val++) {
    if (val2cnt[val]>=1) {
      val2good[val]=true;
      good++;
    }
  }
  for (int k=1;k<=n;k++) {
    for (auto &val:cnt2val[k-1]) {
      if (val2good[val]) {
        val2good[val]=false; good--;
      }
    }
    int mm=n-k+1;
    if (good>=mm) printf("1");
    else printf("0");
    {
      int val=mm;
      if (val2good[val]) {
        val2good[val]=false; good--;
      }
    }
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