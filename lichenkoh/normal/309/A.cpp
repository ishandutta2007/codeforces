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
const int mn=1e6;
int a[2*mn];
int n,l,t,rounds,rem;
bool fl=0;
ld other;
ld solve(int q) {
  int imin=q,imax=2*n;
  while(imin<imax) {
    int imid=(imin+imax)>>1;
    if (!fl) {
      if (a[imid] <= a[q]+rem) imin = imid + 1;
      else imax = imid;
    }
    else {
      if (a[imid] >= a[q]-rem) imin = imid + 1;
      else imax = imid;
    }
  }
  int contrib=max(0,imin-q-1);
  //printf("q:%d rem:%d imin:%d contrib:%d other:%f\n",q,rem,imin,contrib,(double)other);
  return (contrib+other)*0.125;
}


int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  n=rint(),l=rint(),t=rint();
  rounds=2*t/l;
  rem=2*t-rounds*l;
  other=rounds*(ld)(n-1);
  for (int i=0;i<n;i++) a[i]=rint();
  for (int i=0;i<n;i++) a[i+n]=a[i]+l;
  ld all=0;
  for (int q=0;q<n;q++) {
    ld got=solve(q);
    //printf("q:%d got:%d\n",q,got);
    all+=got;
  }
  reverse(a,a+2*n);
  fl=1;
  for (int q=0;q<n;q++) {
    ld got=solve(q);
    //printf("q:%d got:%d\n",q,got);
    all+=got;
  }
  ld final=all;
  printf("%.10f\n",(double)final);
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