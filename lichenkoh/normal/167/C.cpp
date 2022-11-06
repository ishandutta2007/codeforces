#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
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
#ifdef ONLINE_JUDGE
#define assert(XXX) XXX
#else
#define DEBUG_CAT
#endif
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();

bool fast(ll a, ll x) {
  if (a&1) return (x&1)^1;
  else {
    x%=(a+1);
    return (x&1)^1;
  }
}
bool f(ll a, ll b) {
  if (a==0||b==0) return false;
  if (a>b) swap(a,b);
  bool nextwin=f(b%a,a);
  if (!nextwin) return true;
  return fast(a,b/a);
}
/*
const int mn=50+4;
int dp[mn];
bool g(ll a, ll x) {
  if (dp[x]!=-1) return dp[x];
  if (x==0) return dp[x]=1;
  ll t=1;
  while(t<=x) {
    if (!g(a,x-t)) return dp[x]=1;
    t=t*a;
  }
  return dp[x]=0;
}

void test() {
  for (ll x=0;x<=9;x++) {
    printf("%lld",x);
  }
  printf("\n");
  for (ll a=2;a<=8;a++) {
    memset(dp,-1,sizeof dp);
    for (ll x=0;x<=50;x++) {
      assert(g(a,x)==fast(a,x));
      //printf("x:%lld g:%d\n",x,g(a,x));
      //cout<<bitset<9>(x)<<" "<<g(2,x)<<endl;
      //bool gotnim=nim(a,x);
      //if(g(a,x)!=gotnim) {
      //  cout<<bitset<9>(x);
      //  printf("x:%lld g:%d nim:%d\n",x,g(a,x),gotnim);
      //}
      printf("%d",g(a,x));
    }
    printf("\n");
  }
}
*/

int main() 
{
  //test(); return 0;
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t; cin>>t;
  for (int i=0;i<t;i++) {
    ll a,b; cin>>a>>b;
    bool ans=f(a,b);
    if (ans) printf("First\n");
    else printf("Second\n");
  }
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