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

int findk(vi const & a, int k) {
  for (int i=0;i<a.size();i++) {
    if (a[i]==k) {return i+1;}
  }
  return -1;
}

vi proc(vi const & a, vi const & p) {
  //printf("p: ");
  //for (auto &w:p) printf("%d ",w);
  //printf("\n");
  vvi b;
  int x=0;
  for (auto &w:p) {
    vi tmp;
    for (int y=x;y<x+w;y++) tmp.PB(a[y]);
    b.PB(tmp);
    x+=w;
  }
  reverse(b.begin(),b.end());
  vi vout;
  for (auto &w:b) {
    for (auto &x:w) vout.PB(x);
  }
  return vout;
}

vi filterop(vi const & op) {
  vi vout;
  for (auto &w:op) if (w) vout.PB(w);
  return vout;
}


vvi vfinal;


vi gok(vi const & a, int k, bool isrev) {
  int n=a.size();
  int ik=findk(a,k);
  vi op;
  if (!isrev) {
    for (int x=1;x<k;x++) op.PB(1);
    op.PB(ik-k+1);
    op.PB(n-ik);
  {
    int sum=0;
    for (auto &w:op)sum+=w;
    assert(sum==n);
  }
  } else {
    op.PB(ik-1);
    op.PB( (n-k+1) - ik + 1);
    for (int x=1;x<k;x++) op.PB(1);
  {
    int sum=0;
    for (auto &w:op)sum+=w;
    assert(sum==n);
  }
  }
  op = filterop(op);
  if (op.size()>1) {
    vfinal.PB(op);
    return proc(a,op);
  }
  else {
    return a;
  }
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; cin>>n;
  vi a(n); for (int i=0;i<n;i++) cin>>a[i];
  bool isrev=(n%2==0);
  for (int k=1;k<n;k++) {
    vi b=gok(a,k,isrev);
    a=b;
    isrev=!isrev;
    //for (auto &x:a) printf("%d ",x);
    //printf("\n"); fflush(stdout);
    assert(a.size()==n);
  }
  assert(!isrev);
  for (int i=0;i<n;i++) assert(a[i]==i+1);
  int fsz=vfinal.size();
  printf("%d\n",fsz);
  for (auto &w:vfinal) {
    int wsz=w.size();
    printf("%d",wsz);
    for (auto &x:w) printf(" %d",x);
    printf("\n");
  }
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