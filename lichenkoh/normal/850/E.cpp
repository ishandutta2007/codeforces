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
const int mn=(1<<20)+1;

typedef ll ST;
void FastWalshHadamardTransform(vector<ST> &P, bool inverse) {
  // deg MUST be a power of 2
  int deg=P.size();
  assert(__builtin_popcount(deg)==1);
  for (int len = 1; 2 * len <= deg; len <<= 1) {
    for (int i = 0; i < deg; i += 2 * len) {
      for (int j = 0; j < len; j++) {
          ST u = P[i + j];
          ST v = P[i + len + j];
          P[i + j] = u + v;
          P[i + len + j] = u - v;
      }
    }
  }
  
  if (inverse) {
    for (int i = 0; i < deg; i++) P[i] = P[i] / deg;
  }
}

char a[mn];
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n;
  scanf("%d\n%s\n",&n,a);
  int zlim=1<<n;
  vector<ll> P;
  P.resize(zlim);
  for (int i=0;i<zlim;i++) P[i]=a[i]-'0';
  FastWalshHadamardTransform(P,false);
  for (int i=0;i<zlim;i++) P[i]=P[i]*P[i];
  FastWalshHadamardTransform(P,true);
  ll ans=0;
  for (int x=0;x<zlim;x++) {
    int cnt=n-__builtin_popcount(x);
    ans+=P[x]<<cnt;
  }
  ans%=MOD;
  ans*=3;
  printf("%d\n",(int)(ans%MOD));
  /*ll ans=0;
  for (int x=0;x<zlim;x++) {
    if (a[x]=='0') continue;
    for (int y=0;y<zlim;y++) {
      if (a[y]=='0') continue;
      int xy=x^y;
      int cnt=n-__builtin_popcount(xy);
      ans+=1<<cnt;
    }
  }
  ans*=3;
  printf("%d\n",(int)(ans%MOD));*/
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