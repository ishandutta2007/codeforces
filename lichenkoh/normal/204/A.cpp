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
const ll INF=1e18;
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
int getfst(ll x) {
  int first=x%10;
  x/=10;
  while(x>0) {
    first=x%10;
    x/=10;
  }
  return first;
}
int getlast(ll x) {
  return x%10;
}
bool bf(ll x) {
  return getfst(x)==getlast(x);
}
int getdig(ll x) {
  int ans=0;
  while(x>0) {
   ans++;
    x/=10;
  }
  return x;
}
ll hard(ll n) {
  ll ans=0;
  for (ll x=1;x<=n;x++) {
    if (bf(x)) ans++;
  }
  return ans;
}
ll solve(ll n) {
  if (n<10) return hard(n);
  ll final=0;
  while(n%10 != 9) {
    if (bf(n)) final++;
    n--;
  }
  final+=(n-9)/10;
  final+=9;
  return final;
}

void go() {
  for (int k=0;k<10000;k++) {
    ll x=1+rand()%10000LL;
    ll bff=hard(x);
    ll ss=solve(x);
    if (bff!=ss) {
      printf("%lld %lld bff:%lld ss:%lld\n",x,bff,ss);
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  //go();
  //return 0;
  ll l,r; cin>>l>>r;
  ll ans=solve(r)-solve(l-1);
  printf("%lld\n",ans);
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