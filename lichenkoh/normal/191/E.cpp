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
int n; ll k;
const int mn=100000;
const int MAXN=mn;
int t[MAXN];
// T[i] += value
void fadd(int i, int value) {
  for (; i < MAXN; i |= i + 1)
    t[i] += value;
}

// sum[0..i]
int fsum(int i) {
  if (i<0) return 0;
  int res = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1)
    res += t[i];
  return res;
}


ll vpre[mn];
pair<ll,int> vsorted[mn];
int o2s[mn];

ll fcount(ll guess) {
  memset(t,0,sizeof t);
  int total=0;
  ll allcount=0;
  for (int i=n-1;i>=0;i--) {
    total++;
    fadd(o2s[i],1);
    ll pre=(i==0)?0LL:vpre[i-1];
    ll need=pre+guess;
    int imin=0,imax=n;
    while(imin<imax) {
      int imid=(imin+imax)>>1;
      if (vsorted[imid].fst<need) imin=imid+1;
      else imax=imid;
    }
    int got=total-fsum(imin-1);
    allcount+=got;
  }
  return allcount;
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  n=rint();k=rlong();
  ll spre=0;
  for (int i=0;i<n;i++) {
    int inp=rint();
    spre+=inp;
    vpre[i]=spre;
    vsorted[i]=MP(spre,i);
  }
  sort(vsorted,vsorted+n);
  for (int s=0;s<n;s++) {
    o2s[vsorted[s].snd]=s;
  }
  //printf("%lld\n",fcount(0));
  ll imin=-1e14-2,imax=1e14+2;
  while(imin<imax) {
    ll imid=(imin+imax)>>1;
    if (fcount(imid)>=k) imin=imid+1;
    else imax=imid;
  }
  ll final=imin-1;
  printf("%lld\n",final);
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