#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx,tune=native")
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
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}
const int BASE=5e3;
const int LOBASE=2e3;
const int HIBASE=8e3;
void fail() {
  printf("NO\n"); exit(0);
}
int getlo(int i) {return LOBASE-i;}
int gethi(int i) {return HIBASE-i;}
vector<pii> c[2];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),qq=rint();
  vi a(n+1);
  vector<bool> L(n+1),M(n+1),R(n+1);
  for (int i=1;i<=n;i++) a[i]=BASE;
  for (int q=0;q<qq;q++) {
    int t=rint(),l=rint(),r=rint();
    if (l>=r) continue;
    c[t].PB(MP(l,r));
    if (t==1) {
      L[l]=true; R[r]=true;
      for (int i=l+1;i<r;i++) M[i]=true;
    }
  }

  for (int i=1;i<=n;i++) {
    if (M[i]) continue;
    if (L[i]&&R[i]) continue;
    if (L[i]) {a[i]=getlo(i);}
    else if (R[i]) {a[i]=gethi(i);}
    else {
      if (i==1) a[i]=gethi(i);
      else a[i]=getlo(i);
    }
  }
  //for (int i=1;i<=n;i++) printf("%d ",a[i]);
  //printf("\n");
  for (auto &w:c[1]) {
    int l=w.fst,r=w.snd;
    for (int i=l;i<r;i++) if (a[i]>a[i+1]) fail();
  }
  for (auto &w:c[0]) {
    int l=w.fst,r=w.snd;
    bool ok=false;
    for (int i=l;i<r;i++) if (a[i]>a[i+1]) ok=true;
    if (!ok) fail();    
  }
  printf("YES\n");
  for (int i=1;i<=n;i++) printf("%d ",a[i]);
  printf("\n");
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