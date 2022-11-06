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
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();

const int mn=3e5+4;
int p[mn];
int c[mn];
int partiald(int l, int r, int d) {
  int gap=0;
  int last=p[l];
  for (int i=l+1;i<r;i++) {
    if (c[i]==d) {
      chkmax(gap,p[i]-last);
      last=p[i];
    }
  }
  chkmax(gap,p[r]-last);
  //dbg("l:%d r:%d d:%d gap:%d\n",l,r,d,gap);
  return gap;
}

ll partial(int l, int r) {
  ll top=p[r]-p[l];
  ll red=top-partiald(l,r,0);
  ll blu=top-partiald(l,r,1);
  return top+red+blu;
}

ll direct(int l, int r) {
  return 2LL*(p[r]-p[l]);
}

int lo[2],hi[2];
ll solve(int l, int r) {
  if (c[l]==2&&c[r]==2) {
    return min(direct(l,r),partial(l,r));
  }
  else {
    lo[0]=lo[1]=INF;
    hi[0]=hi[1]=-INF;
    for (int i=l;i<=r;i++) {
      int ch=c[i];
      if (ch==2) {
        for (int t=0;t<2;t++) {
          chkmin(lo[t],p[i]);
          chkmax(hi[t],p[i]);
        }
      }
      else {
        chkmin(lo[c[i]],p[i]);
        chkmax(hi[c[i]],p[i]);
      }
    }
    ll ans=0;
    for (int t=0;t<2;t++) {
      if (lo[t]!=INF) ans+=hi[t]-lo[t];
    }
    return ans;
  }
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  for (int i=0;i<n;i++) {
    p[i]=rint();
    char ch=rch();
    if (ch=='R') c[i]=0;
    else if (ch=='B') c[i]=1;
    else if (ch=='G') c[i]=2;
    else assert(0);
  }
  int lastg=0;
  ll final=0;
  for (int i=0;i<n;i++) {
    if (c[i]==2) {
      if (lastg!=i) final+=solve(lastg,i);
      lastg=i;
    }
  }
  if (lastg!=n-1) final+=solve(lastg,n-1);
  printf("%lld\n",final);
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