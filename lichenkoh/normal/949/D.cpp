#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
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
#define assert(XXX) XXX
#else
#define DEBUG_CAT
#endif
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();
int n,d,b;
const int mn=1e5+4;
int a[mn];
ll pre[mn];
ll query(int l, int r) {
  return pre[r]-pre[l-1];
}
bool f(int imid) {
  int ans=0;
  int lbad=1+(imid-1);
  int rbad=n-(imid-1);
  {
    int t=1;
    for (int l=lbad+1;l<=(n+1)/2;l++) {
      //if (imid==2) printf("l:%d\n",l);
      if (query(1,min(l+l*(ll)d,(ll)n))<t*(ll)b) return false;
      t++;
    }
  }
  {
    int t=1;
    for (int r=rbad-1;r>(n+1)/2;r--) {
      if (query(max(r-(n+1-r)*(ll)d,1LL),n)<t*(ll)b) return false;
      t++;
    }
  }
  return true;
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  n=rint(),d=rint(),b=rint();
  for (int x=1;x<=n;x++) a[x]=rint();
  for (int x=1;x<=n;x++) pre[x]=pre[x-1]+a[x];
  int imin=0,imax=((n+1)/2)+1;
  while(imin<imax) {
    int imid=(imin+imax)>>1;
    if (!f(imid)) imin=imid+1;
    else imax=imid;
  }
  printf("%d\n",imin);
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