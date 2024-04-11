#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
#ifdef DEBUG_CAT

#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
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

int readInt()
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
const int mn=3e5+4;
vector<int> vc;
int n,p;
int bins(int x) {
  int imin=0,imax=n;
  while(imin<imax) {
    //printf("x:%d imin:%d imax:%d\n",x,imin,imax);
    int imid=(imin+imax)/2;
    if (vc[imid]>=x) imin=imid+1;
    else imax=imid;
  }
  return imin;
}
int a[mn];
map<int,int> g[mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	n=readInt(),p=readInt();
  for (int i=1;i<=n;i++) {
    int x=readInt(), y=readInt();
    g[x][y]++;
    g[y][x]++;
    a[x]++;
    a[y]++;
  }
  for (int i=1;i<=n;i++) {
    vc.PB(a[i]);
  }
  sort(vc.begin(),vc.end(),greater<int>());
  ll final=0;
  for (int x=1;x<=n;x++) {
    int need=p-a[x];
    int all=bins(need);
    if (a[x]>=need) all--;
    for (auto &w:g[x]) {
      int y=w.fst,sub=w.snd;
      if (a[x]+a[y]>=p&&a[x]+a[y]-sub<p) all--;
    }
    final+=all;
  }
  final/=2;
  printf("%lld\n",final);
}