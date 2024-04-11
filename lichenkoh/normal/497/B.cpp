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
const int mn=1e5+4;
int a[mn];
int b[mn];
int n;
int f(int start, int t) {
  int imin=start+1,imax=n+1;
  while(imin<imax) {
    int imid=(imin+imax)>>1;
    int da=a[imid]-a[start];
    int db=b[imid]-b[start];
    if (da<t&&db<t) imin=imid+1;
    else imax=imid;
  }
  return imin;
}
vector<pair<int,int> > vans;
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  n=readInt();
  for (int i=1;i<=n;i++) {
    int x=readInt();
    if (x==1) a[i]++;
    else b[i]++;
  }
  for (int i=1;i<=n;i++) {a[i]+=a[i-1]; b[i]+=b[i-1];}
  for (int t=1;t<=n;t++) {
    int sa=0,sb=0;
    int x=0;
    int lastwin=-1;
    while(x<n) {
      int y=f(x,t);
      int da=a[y]-a[x];
      int db=b[y]-b[x];
      if (y!=n+1) {
        assert((da>=t) != (db>=t));
      }
      if (da>=t) {
        sa++;
        if (y==n) lastwin=1;
      }
      else {
        sb++;
        if (y==n) lastwin=2;
      }
      x=y;
    }
    bool ok=1;
    if (sa>sb&&lastwin!=1) ok=0;
    if (sb>sa&&lastwin!=2) ok=0;
    if (ok&&x==n&&sa!=sb) {
      int s=max(sa,sb);
      vans.PB(MP(s,t));
    }
  }
  sort(vans.begin(),vans.end());
  printf("%d\n",(int)vans.size());
  for (auto &w:vans) printf("%d %d\n",w.fst,w.snd);
}