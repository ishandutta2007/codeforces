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

#define dbg(...)   //printf( __VA_ARGS__ )
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

const int mn=8e4+4;
vector<int> g[mn];
int sz[mn];
int getsz(int x, int p) {
  int ans=1;
  for (auto &y:g[x]) {
    if (y==p) continue;
    ans+=getsz(y,x);
  }
  return sz[x]=ans;
}
ll final=0;
void go(int x, int p) {
  for (auto &y:g[x]) {
    if (y==p) continue;
    go(y,x);
  }
  int cum=0;
  ll ab=0;
  for (auto &y:g[x]) {
    if (y==p) continue;
    int a=cum;
    int b=sz[y];
    ll tab=a*(ll)b;
    ab+=tab;
    cum+=sz[y];
  }
  int c=cum;
  int d=sz[1]-sz[x];
  ll cd=c*(ll)d;
  int down=cum;
  int up=sz[1]-sz[x];
  ll ans=0;
  ans+=1ll*ab*ab;
  //printf("x:%d ab*ab:%lld\n",x,ab*ab);
  ans+=2ll*ab*cd;
  //printf("x:%d 2ab*cd:%lld\n",x,2*ab*cd);
  ans+=2ll*ab*down;
  //printf("x:%d 2ab*down:%lld\n",x,2*ab*down);
  ans+=2ll*ab*up;
  //printf("x:%d 2ab*up:%lld\n",x,2*ab*up);
  ans+=2ll*down*cd;
  //printf("x:%d 2down*cd:%lld\n",x,2*down*cd);
  ans+=2ll*down*up;
  ////printf("x:%d 2down*up:%lld\n",x,2*down*up);
  ans+=1ll*down*down;
  ////printf("x:%d down*down:%lld\n",x,down*down);
  final+=ans;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=rint();
  for (int i=1;i<n;i++) {
    int x=rint(),y=rint();
    g[x].PB(y); g[y].PB(x);
  }
  getsz(1,-1);
  go(1,-1);
  ll all=(1ll*n*(n-1))/2;
  all=all*all;
  //printf("all:%lld\n",all);
  ll lft=all-final;
  printf("%lld\n",lft);
}