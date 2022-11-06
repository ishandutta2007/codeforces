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
vector<int> p;
vector<int> bestp;
void go(int n) {
  p.clear();
  for (int i=0;i<=n;i++) p.PB(i);
  ll best=0;
  sort(p.begin(),p.end());
  do {
    ll res=0;
    for (int i=0;i<=n;i++) res+=i^p[i];
    if (res>=best) {
      best=res;
      bestp=p;
    }
  } while(next_permutation(p.begin(),p.end()));
  //
  for (auto &w:bestp) printf("%d ",w); printf("  best:%lld n:%d\n",best,n);printf("\n"); fflush(stdout);
  //printf("%lld ",best);fflush(stdout);
}
const int mn=2e6+2;
int vans[mn];
int getp(int x) {
  int ans=1;
  while((ans-1)<x) ans*=2;
  return ans-1;
}
void smart(int on) {
  memset(vans,0,sizeof vans);
  int n=on;
  while(n) {
    int o=getp(n);
    for (int x=o-n,y=n;x<=n;x++,y--) {
      //printf("n:%d o:%d x:%d y:%d\n",n,o,x,y);
      vans[x]=y;
    }
    n=o-n-1;
  }
  ll ans=0;
  for (int x=0;x<=on;x++) ans+=x^vans[x];
  printf("%lld\n",ans);
  for (int x=0;x<=on;x++) printf("%d ",vans[x]); printf("\n");
  //assert(ans==on*(on+1));
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
  //for (int k=1;k<=20;k++) smart(k);
  int n; scanf("%d",&n);
  smart(n);
}