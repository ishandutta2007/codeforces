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

const int MAXP=300000000;
const int MAXS=17320;
const int SS=131;
bitset<MAXS+1> sieve_array;
bitset<MAXP/4> b;
void sieve() {
  sieve_array.set();
  sieve_array[0] = false; sieve_array[1] = false;
  for (int i = 2; i <= SS; i++) {
    if(sieve_array[i]) {
      for (int j = i*i; j <= MAXS; j+=i) {
        sieve_array[j] = false;
      }
    }
  }
  b.set();
  b[0]=false;
  for (int p=3;p<=MAXS;p++) {
    if (sieve_array[p]) {
      for (int j=p*p;j<=MAXP;j+=p) {
        if ((j&3)==1) {
          b[j>>2]=false;
        }
      }
    }
  }
  /*for (int x=1;x<=20;x+=4) {
    printf("x:%d x>>2:%d b:%d\n",x,x>>2,(int)b[x>>2]);
  }*/
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  sieve();
  int l=rint(),r=rint();
  int ans=0;
  if (l<=2&&2<=r) ans++;
  while((l&3)!=1) ++l;
  while((r&3)!=1 && r>0) --r;
  if (l<=r) {
    //printf("l:%d %d  r:%d %d\n",l,l>>2,r,r>>2);
    ans+=(b>>(l>>2)).count()-(int)((b>>(1+(r>>2))).count());
  }
  printf("%d\n",ans);
  /*int l,r; cin>>l>>r;
  int ans=(sieve_array>>l).count() - (sieve_array>>r).count();
  printf("%d\n",ans);*/
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