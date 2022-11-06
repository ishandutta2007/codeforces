#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
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
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;typedef vector<pii> vpii;
#ifdef ONLINE_JUDGE
#define assert(...) /* nothing */
#endif
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();
// mt19937 rng; rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}
const int mn=2004;
const int md=10;
int d2s[md]={
0b1110111,
0b0010010,
0b1011101,
0b1011011,
0b0111010,
0b1101011,
0b1101111,
0b1010010,
0b1111111,
0b1111011
};
//int h[1<<7];
int a[mn];
int dp[mn][mn];
int n;
int f(int p, int k) {
  //printf("p:%d k:%d n:%d\n",p,k,n);
  if (k<0) return 0;
  if (dp[p][k]!=-1) return dp[p][k];
  if (p==n+1) {
    return dp[p][k]=((k==0)?1:0);
  }
  int ap=a[p];
  for (int d=md-1;d>=0;d--) {
    int s=d2s[d];
    //printf("ap:%d d:%d s:%d\n",ap,d,s);
    if ((ap&s)==ap) {
      int need=__builtin_popcount(ap^s);
      int ans=f(p+1,k-need);
      if (ans==1) {
        return dp[p][k]=1;
      }
    }
  }
  return dp[p][k]=0;
}

vector<int> vans;
void go(int p, int k) {
  if (p==n+1) return;
  int ap=a[p];
  for (int d=md-1;d>=0;d--) {
    int s=d2s[d];
    if ((ap&s)==ap) {
      int need=__builtin_popcount(ap^s);
      int ans=f(p+1,k-need);
      if (ans==1) {
        vans.PB(d);
        go(p+1,k-need);
        return;
      }
    }
  }
}


int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  //memset(h,-1,sizeof h);
  //for (int d=0;d<md;d++) h[d2s[d]]=d;
  int k; cin>>n>>k;
  for (int p=1;p<=n;p++) {
    string s;
    cin>>s;
    int sig=0;
    for (auto &c:s) {sig*=2; sig+=(c-'0');}
    a[p]=sig;
  }
  memset(dp,-1,sizeof dp);
  int ans=f(1,k);
  if (ans==0) {
    printf("-1\n");
  } else {
    go(1,k);
    for (auto &w:vans) printf("%d",w);
    printf("\n");
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