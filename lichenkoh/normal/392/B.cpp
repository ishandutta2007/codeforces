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
ll vc[3][3];
ll dp[44][3][3];
ll f(ll n, ll s, ll t) {
  if (n==0) return 0;
  ll dpval=dp[n][s][t];
  if (dpval!=-1) return dpval;
  ll spare=-1;
  for (ll i=0;i<3;i++) if (i!=s&&i!=t) spare=i;
  ll ans1=f(n-1,s,spare)+vc[s][t]+f(n-1,spare,t);
  ll ans2=f(n-1,s,t)+vc[s][spare]+f(n-1,t,s)+vc[spare][t]+f(n-1,s,t);
  ll final=min(ans1,ans2);
  return dp[n][s][t]=final;
}

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
  memset(dp,-1,sizeof dp);
  for (int i=0;i<3;i++) for (int j=0;j<3;j++) cin>>vc[i][j];
  int n; cin>>n;
  ll ans=f(n,0,2);
  printf("%lld\n",ans);
}