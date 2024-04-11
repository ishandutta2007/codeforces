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

ll lcm(ll x, ll y) {
  chkmax(x,1ll);
  chkmax(y,1ll);
  return (x/__gcd(x,y))*y;
}
ll xx,yy,zz;
ll bf(ll n) {
  ll best=0;
  for (ll x=1;x<=n;x++) for (ll y=1;y<=n;y++) for (ll z=1;z<=n;z++) {
        ll cand=lcm(x,lcm(y,z));
        if (cand>best) {
          best=cand;
          xx=x,yy=y,zz=z;
        }
      }
  return best;
}
ll smart(ll n) {
  ll lo=max(1ll,n-50);
  ll best=0;
  for (ll x=lo;x<=n;x++) for (ll y=lo;y<=n;y++) for (ll z=lo;z<=n;z++) {
        ll cand=lcm(x,lcm(y,z));
        if (cand>best) {
          best=cand;
          xx=x,yy=y,zz=z;
        }
      }
  return best;
}
void go() {
  srand(clock());
  int n=rand()%200; n++;
  ll b=bf(n);
  ll s=smart(n);
  if (b!=s) {
    printf("%d. b:%lld s:%lld. %lld %lld %lld\n",n,b,s,xx,yy,zz);
    exit(0);
  }
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  //for (int k=0;k<1000;k++) go();
  //return 0;
  ll n; cin>>n;
  ll ans=smart(n);
  cout<<ans<<endl;
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