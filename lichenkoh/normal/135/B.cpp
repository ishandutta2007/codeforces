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
#define assert(...) /* nothing */
#endif
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();
ll dist2(pll a, pll b) {
  ll dx=a.fst-b.fst;
  ll dy=a.snd-b.snd;
  return dx*dx+dy*dy;
}
bool isrect(vector<pll> v) {
  assert(v.size()==4);
  sort(v.begin(),v.end());
  do {
    bool ok=1;
    for (int i=0;i<4;i++) {
      int a=i,b=(i+1)%4,c=(i+2)%4;
      if (dist2(v[a],v[c])!=dist2(v[a],v[b])+dist2(v[b],v[c])) ok=0;
    }
    if (ok) return 1;
  } while(next_permutation(v.begin(),v.end()));
  return false;
}
bool issq(vector<pll> v) {
  assert(v.size()==4);
  sort(v.begin(),v.end());
  do {
    bool ok=1;
    for (int i=0;i<4;i++) {
      int a=i,b=(i+1)%4,c=(i+2)%4;
      if (dist2(v[a],v[c])!=dist2(v[a],v[b])+dist2(v[b],v[c])) ok=0;
      //printf("%lld %lld\n",dist2(v[a],v[b]),dist2(v[b],v[c]));
      if (dist2(v[a],v[b])!=dist2(v[b],v[c])) ok=0;
    }
    if (ok) return 1;
  } while(next_permutation(v.begin(),v.end()));
  return false;
}
pll vp[8];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  for (int i=0;i<8;i++) vp[i]=MP(rint(),rint());
  for (int z=0;z<(1<<8);z++) {
    //int z=0b11110000;
    if (__builtin_popcount(z)!=4) continue;
    vector<pll> v[2];
    for (int x=0;x<8;x++) {
      v[(z>>x)&1].PB(vp[x]);
    }
    //printf("%d %d\n",issq(v[1]),isrect(v[0]));
    if (issq(v[1])&&isrect(v[0])) {
      printf("YES\n");
      for (int x=0;x<8;x++) {
        if ((z>>x)&1) printf("%d ",x+1);
      }
      printf("\n");
      for (int x=0;x<8;x++) {
        if (0==((z>>x)&1)) printf("%d ",x+1);
      }
      printf("\n");
      return 0;
    }
  }
  printf("NO\n");
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