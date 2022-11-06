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
const int mn=1004;
int l[mn],r[mn];
int l2[mn],r2[mn];
int vans[mn];
void fail() {
  printf("NO\n");
  exit(0);
}
void go() {
  int n=rint();
  for (int x=1;x<=n;x++) {l[x]=rint(); l2[x]=l[x];}
  for (int x=1;x<=n;x++) {r[x]=rint(); r2[x]=r[x];}
  memset(vans,-1,sizeof vans);
  int val=n;
  while(1) {
    vi v;
    for (int x=1;x<=n;x++) {
      if (vans[x]==-1&&l[x]+r[x]==0) {
        vans[x]=val;
        v.PB(x);
      }
    }
    for (auto &x:v) {
      for (int y=1;y<=n;y++) {
        if (y<x) {
          --r[y];
        }
        if (y>x) {
          --l[y];
        }
      }
    }
    if (v.size()==0) break;
    val--;
  }

  /*for (int x=1;x<=n;x++) {
    printf("%d ",vans[x]);
  }
  printf("\n");*/


  for (int x=1;x<=n;x++) {
    if (vans[x]==-1) fail();
  }
  for (int x=1;x<=n;x++) {
    int L=0,R=0;
    for (int y=1;y<x;y++) if (vans[y]>vans[x]) L++;
    for (int y=x+1;y<=n;y++) if (vans[y]>vans[x]) R++;
    if (L!=l2[x]) fail();
    if (R!=r2[x]) fail();
  }
  printf("YES\n");
  for (int x=1;x<=n;x++) {
    printf("%d ",vans[x]);
  }
  printf("\n");
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  go();
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