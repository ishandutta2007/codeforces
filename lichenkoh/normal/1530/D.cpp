#ifdef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx,avx2")
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
  int n; cin>>n;
  vi a(n+1);
  for (int i=1;i<=n;i++) cin>>a[i];
  vvi vin(n+1);
  for (int x=1;x<=n;x++) vin[a[x]].PB(x);
  set<int> vl,vr;
  vi vfinal(n+1);
  for (int r=1;r<=n;r++) {
    pii best=MP(INF,INF);
    for (int l: vin[r]) {
      chkmin(best, MP(int(vin[l].size()), l));
    }
    for (int l: vin[r]) {
      if (l!=best.snd) vl.insert(l);
    }
    if (best.snd!=INF) {
      vfinal[best.snd]=r;
    } else {
      vr.insert(r);
    }
  }
  //assert(vl.size()==vr.size());
  vi both;
  for (int l:vl) {
    if (vr.count(l)) {
      both.PB(l);
    }
  }
  for (int x:both) {
    vl.erase(x); vr.erase(x);
  }
  //assert(vl.size()==vr.size());
  if (both.size()==1) {
    //assert(vr.size()>0);
    //assert(vl.size()>0);
    int b=both[0];
    int r=*(vr.begin());
    vfinal[b]=r;
    vr.erase(r);
    int l=*(vl.begin());
    vfinal[l]=b;
    vl.erase(l);
    //assert(vl.size()==vr.size());
  } else {
    int sz=both.size();
    for (int i=0;i<sz;i++) {
      int l=both[i],r=both[(i+1)%sz];
      vfinal[l]=r;
    }
  }
  //assert(vl.size()==vr.size());
  vi L,R;
  for (int x:vl) L.PB(x);
  for (int x:vr) R.PB(x);
  //assert(L.size()==R.size());
  for (int i=0;i<L.size();i++) {
    vfinal[L[i]]=R[i];
  }
  int good=0;
  for (int i=1;i<=n;i++) {
    if (vfinal[i]==a[i]) good++;
  }
  printf("%d\n",good);
  for (int i=1;i<=n;i++) {
    printf("%d ",vfinal[i]);
  }
  printf("\n");
  //set<int> perm;
  //for (int i=1;i<=n;i++) {
  //  perm.insert(vfinal[i]);
  //  assert(vfinal[i]!=i);
  //  assert(1<=vfinal[i]);
  //  assert(vfinal[i]<=n);
  //}
  //assert(perm.size()==n);
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