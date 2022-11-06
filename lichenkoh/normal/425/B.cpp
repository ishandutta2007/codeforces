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
const int INF=1<<30;
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
const int mx=102,mk=11;
int a[mx][mx];
int xlim,ylim,klim;
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	xlim=readInt(),ylim=readInt(),klim=readInt();
  for (int x=0;x<xlim;x++) for (int y=0;y<ylim;y++) a[x][y]=readInt();
  int final=INF;
  if (xlim<=klim) {
    int zlim=1<<xlim;
    for (int z=0;z<zlim;z++) {
      int ans=0;
      for (int y=0;y<ylim;y++) {
        int cost0=0,cost1=0;
        for (int x=0;x<xlim;x++) {
          if (a[x][y]!=((z>>x)&1)) cost0++;
          if (a[x][y]==((z>>x)&1)) cost1++;
        }
        ans+=min(cost0,cost1);
      }
      chkmin(final,ans);
    }
  }
  else {
    for (int mx=0;mx<xlim;mx++) {
      int ans=0;
      for (int x=0;x<xlim;x++) {
        int cost0=0,cost1=0;
        for (int y=0;y<ylim;y++) {
          if (a[x][y]!=a[mx][y]) cost0++;
          if (a[x][y]==a[mx][y]) cost1++;
        }
        ans+=min(cost0,cost1);
      }
      chkmin(final,ans);
    }
  }
  if (final>klim) final=-1;
  printf("%d\n",final);
}