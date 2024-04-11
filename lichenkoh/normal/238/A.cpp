#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const int MOD=1000000009;
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
int a[100];
int bf(int n, int logk) {
  int k=(1<<logk)-1;
  int zlim=1; for (int i=0;i<n;i++) zlim*=k;
  int ans=0;
  for (int zz=0;zz<zlim;zz++) {
    int z=zz;
    for (int i=0;i<n;i++) {
      a[i]=(z%k)+1;
      z/=k;
    }
    bool ok=1;
    for (int l=0;ok&&l<n;l++) {
      int sum=0;
      for (int r=l;r<n;r++) {
        sum^=a[r];
        if (sum==0) {ok=0;break;}
      }
    }
    if (ok) ans++;
  }
  return ans;
}
int mul(int x, int y) {
  return (int)((x*(ll)y)%MOD);
}
int mod_pow(int a, int n, int mod) { int ret = 1; int p = a % mod; while (n) { if (n & 1) ret = (ret *(ll) p) % mod; p = (p *(ll) p) % mod; n >>= 1; } return ret; }
int smart(int n, int k) {
  int x=mod_pow(2,k,MOD)-1;
  if (x<0) x+=MOD;
  int ans=1;
  for (int i=0;i<n;i++) {
    if (x==0) return 0;
    ans=mul(x,ans);
    x--;
  }
  return ans;
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),k=rint();
  int ans=smart(n,k);
  printf("%d\n",ans%MOD);
  /*for (int k=1;k<=6;k++) {
    for (int n=1;n<=6;n++) {
      int bans=bf(n,k)%MOD;
      int sans=smart(n,k);
      printf("k:%d n:%d b:%d s:%d\n",k,n,bans,sans);
      assert(bans==sans);
    }
  }*/
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