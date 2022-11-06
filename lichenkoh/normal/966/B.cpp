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
int bins(vector<pii> &v, int key) {
  int imin=0,imax=v.size();
  while(imin<imax) {
    int imid=(imin+imax)>>1;
    if (v[imid].fst<key) imin=imid+1;
    else imax=imid;
  }
  return imin;
}
int q[2];
const int mn=(3e6)+4;
bitset<mn> used;
pii losum[2]; int lok[2];
int vk[2];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(); q[0]=rint(); q[1]=rint();
  vector<pii> c;
  for (int i=0;i<n;i++) c.PB(MP(rint(),i+1));
  sort(c.begin(),c.end());
  for (int t=0;t<2;t++) {
    losum[t].fst=INT_MAX/2-1; lok[t]=INT_MAX/2-1;
    for (int k=1;k<n;k++) {
      int need=(q[t]+k-1)/k;
      int g=bins(c,need);
      if (k<=n-g) {
        chkmin(losum[t],MP(k+g,k));
        chkmin(lok[t],k);
      }
    }
  }
  for (int ot=0;ot<2;ot++) {
    if (losum[ot].fst+lok[ot^1]<=n) {
      printf("Yes\n");
      vk[ot]=losum[ot].snd;
      vk[ot^1]=lok[ot^1];
      printf("%d %d\n",vk[0],vk[1]);
      for (int t=0;t<2;t++) {
        int k=vk[t];
        int need=(q[t]+k-1)/k;
        int x=bins(c,need);
        while(k--) {
          while(used[x]) x++;
          used[x]=true;
          printf("%d ",c[x].snd);
        }
        printf("\n");
      }
      exit(0);
    }
  }
  printf("No\n");
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