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
const int mn=1e6+4;
int a[mn];
int vpeak[mn];
int vtrough[mn];
ll f[mn];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=readInt();
  for (int i=0;i<n;i++) a[i]=readInt();
  {
    int peak=n-1;
    int trough=n-1;
    for (int i=n-2;i>=0;i--) {
      if (a[i]>=a[i+1]) peak=i;
      vpeak[i]=peak;
      if (a[i]<=a[i+1]) trough=i;
      vtrough[i]=trough;
    }
  }
  memset(f,0,sizeof f);
  for (int i=0;i<n;i++) {
    vector<int> cand;
    cand.PB(i+1);
    if (i!=n-1) {
      int peak=vpeak[i],trough=vtrough[i];
      for (int x=peak-1;x<=peak+1;x++) if (x>i+1) cand.PB(x);
      for (int x=trough-1;x<=trough+1;x++) if (x>i+1) cand.PB(x);
    }
    chkmax(f[i+1],f[i]);
    for (auto &x:cand) {
      chkmax(f[x+1],f[i]+abs((ll)a[x]-(ll)a[i]));
    }
  }
  printf("%lld\n",f[n]);
}