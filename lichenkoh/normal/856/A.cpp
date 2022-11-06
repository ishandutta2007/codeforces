#include <bits/stdc++.h>
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
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();
inline void fail() {
  printf("NO\n");
}
const int mn=101;
const int mc=(mn*(mn-1))/2;
template <typename LST> struct LimitedVec  {
  LST a[mn];
  int sz;
  void push_back(LST val) {
    a[sz++]=val;
  }
  LST * begin()
  {
    return &a[0];
  }
  LST * end()
  {
    return &a[sz];
  }
  void clear() {
    sz=0;
  }
};
int a[mn];
int d[mc];
const int mv=2000000;
bool used[mv+1];
LimitedVec<int> vans;
inline void solve(bool clr) {
  int n=rint();
  for (int i=0;i<n;i++) a[i]=rint();
  sort(a,a+n);
  for (int x=1;x<n;x++) {
    if (a[x]==a[x-1]) {
      fail();
      return;
    }
  }
  int didx=0;
  for (int x=0;x<n;x++) {
    for (int y=0;y<x;y++) {
      int diff=a[x]-a[y];
      d[didx++]=diff;
    }
  }
  for (int x=1;x<=mv;x++) {
    if (used[x]) continue;
    vans.PB(x);
    if (vans.sz==n) break;
    for (int di=0;di<didx;di++) {
      used[x+d[di]]=true;
    }
  }
  if (vans.sz==n) {
    printf("YES\n");
    for (auto &w:vans) printf("%d ",w);
    printf("\n");
  }
  else fail();
  if (clr) {
    vans.clear();
    memset(used,0,sizeof used);
  }
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int tt=rint();
  for (int i=0;i<tt;i++) solve(i!=tt-1);
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