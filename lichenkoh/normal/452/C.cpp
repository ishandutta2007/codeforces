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

const int mn=1e6+4;
ld logt[mn];
ld logfact[mn];
ld logbinom(int n, int k) {
  assert(n>=k);
  return logfact[n]-logfact[k]-logfact[n-k];
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(16);
  {
    ld sum=0;
    logfact[0]=0;
    for (int x=1;x<mn;x++) {
      ld logx = log((ld) x);
      logt[x] = logx;
      sum+=logx;
      logfact[x]=sum;
    }
  }
  int n,m; cin>>n>>m;
  ld final=0;
  ld denom=logbinom(n*m,n);
  for (int k=1;k<=m;k++) {
    //printf("n:%d k:%d.. %d >= %d\n",n,k,(m*n-m),(n-k));
    if (n>=k&&(m * n - m)>=(n-k)) {
      ld A = logbinom(m, k);
      ld B = logbinom(m * n - m, n - k);
      ld other=2*logt[k]-logt[n];
      ld got=exp(A+B-denom+other);
      final+=got;
      //printf("k:%d L:%Lf O:%Lf\n",k,exp(A+B-denom),exp(other));
    }
  }
  cout<<final<<endl;
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