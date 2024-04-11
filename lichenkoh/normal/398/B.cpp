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
const int mn=2000+4;
bitset<mn> br,bc;
ld dp[mn][mn];
bool valid[mn][mn];
int gn;
ld f(int r, int c) {
  int n=gn;
  if (r>n||c>n) return 0;
  if (r==n&&c==n) return 0;
  if (valid[r][c]) return dp[r][c];
  ld ans=0;
  int rl=n-r,cl=n-c;
  if (rl*cl){
    ans+=(rl*cl*(f(r+1,c+1)))/(n*n-r*c);
  }
  if (r*cl) {
    ans+=(r*cl*(f(r,c+1)))/(n*n-r*c);
  }
  if (rl*c){
    ans+=(rl*c*(f(r+1,c)))/(n*n-r*c);
  }
  ld p=(ld)(n*n)/(ld)(n*n-r*c);
  ans+=p;
  //printf("r:%d c:%d ans:%f p:%.9f\n",r,c,ans,p);
  dp[r][c]=ans;
  valid[r][c]=true;
  return ans;
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n,m; scanf("%d%d",&n,&m);
  gn=n;
  for (int i=0;i<m;i++) {
    int r,c; scanf("%d%d",&r,&c);
    br[r]=true; bc[c]=true;
  }
  int r=br.count();
  int c=bc.count();
  ld ans=f(r,c);
  printf("%.10f\n",(double)ans);
}