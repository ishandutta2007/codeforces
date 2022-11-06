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

auto start=std::chrono::high_resolution_clock::now().time_since_epoch();

const int mn=140582+1;
ll a[mn],b[mn];
int n;
int prev(int i) {
  return (i==0)?(n-1):(i-1);
}
int nxt(int i) {
  return (i==n-1)?0:(i+1);
}
void fail() {
  printf("NO\n"); exit(0);
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  n=rint();
  for (int i=0;i<n;i++) {b[i]=rint();}

  bool allz=true;
  for (int i=0;i<n;i++) if (b[i]!=0) allz=false;
  if (allz) {
    printf("YES\n");
    //for (int i=0;i<n;i++) assert(a[i]%a[nxt(i)]==b[i]);
    for (int i=0;i<n;i++) printf("%d ",1);
    exit(0);
  }
  ll hi=LLONG_MIN;
  for (int i=0;i<n;i++) chkmax(hi,b[i]);
  int init=-1;
  for (int i=0;i<n;i++) {
    if (b[i]==hi&&b[prev(i)]!=hi) init=i;
  }
  if (init==-1) fail();
  int x=init;
  a[x]=b[x];
  x=prev(x);
  for (int t=1;t<n;t++) {
    ll need=max(a[prev(x)],a[init]+1);
    ll needc=(need-b[x])/a[nxt(x)];
    a[x]=b[x]+a[nxt(x)]*needc;
    if (a[x]<need) a[x]+=a[nxt(x)];
    x=prev(x);
  }
  for (int i=0;i<n;i++) if(a[i]%a[nxt(i)]!=b[i]) fail();
  printf("YES\n");
  //for (int i=0;i<n;i++) assert(a[i]%a[nxt(i)]==b[i]);
  for (int i=0;i<n;i++) printf("%lld ",a[i]);
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