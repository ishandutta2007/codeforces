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
char readCh()
{
    readAhead(16);
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    char ans=*stdinPos;
    ++stdinPos;
    return ans;
}

int a[104][104];
int sum[104];
int res[104];
bitset<104> vans;
int main() 
{
  int n=readInt();
  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) a[i][j]=(readCh()=='1')?1:0;
  }
  for (int i=0;i<n;i++) res[i]=readInt();
  while(1) {
    bool change=0;
    for (int i=0;i<n;i++) {
      if (sum[i]==res[i]&&!vans[i]) {
        vans[i]=true;
        change=1;
        for (int j=0;j<n;j++) {
          sum[j]+=a[i][j];
        }
      }
    }
    if (!change) break;
  }
  for (int i=0;i<n;i++) {
    if (sum[i]==res[i]) {
      printf("-1\n"); return 0;
    }
  }
  printf("%d\n",(int)vans.count());
	for (int i=0;i<n;i++) {
    if (vans[i]) printf("%d ",i+1);
  }
  printf("\n");
}