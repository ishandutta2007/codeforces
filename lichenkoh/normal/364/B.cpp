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
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define DEBUG_CAT
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
const int mn=50*10000+1;
bool f[mn];
int c[51];
vector<int> v;
int bins(int start, int key) {
  int imin=0,imax=v.size();
  while(imin<imax) {
    int imid=(imin+imax)>>1;
    if (v[imid]<=key) imin=imid+1;
    else imax=imid;
  }
  return imin-1;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=readInt(),d=readInt();
  for (int i=0;i<n;i++) c[i]=readInt();
  f[0]=1;
  int cur=0,nxt=1;
  for (int i=0;i<n;i++) {
    int now=c[i];
    for (int x=mn-1;x>=now;x--) {
      f[x]|=f[x-now];
    }
  }
  for (int x=0;x<mn;x++) {
    if (f[x]) {
      //printf("x:%d\n",x);
      v.PB(x);
    }
  }
  int step=0;
  int now=0;
  while(1) {
    int aft=bins(now,v[now]+d);
    if (aft==now) break;
    now=aft;
    step++;
  }
  printf("%d %d\n",v[now],step);
}