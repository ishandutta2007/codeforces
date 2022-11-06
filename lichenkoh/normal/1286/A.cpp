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
// mt19937 rng; rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}
const int mn=104;
int avail[2];
int a[mn];
int f[2][2][mn];
const int EV=0,ODD=1;
void clr(int cur) {
  for (int prev=0;prev<2;prev++) {
    for (int x=0;x<mn;x++) {
      f[cur][prev][x]=INF;
    }
  }
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; cin>>n;
  memset(a,-1,sizeof(a));
  avail[0]=n/2; avail[1]=(n+1)/2;
  for (int i=0;i<n;i++) {
    int inp; cin>>inp;
    if (inp) {
      int parity=inp%2;
      a[i]=parity;
      --avail[parity];
    }
  }
  int cur=0,nxt=1;
  clr(cur);
  for (int prev=0;prev<2;prev++) f[cur][prev][0]=0;
  int unk=0;
  for (int pos=0;pos<n;pos++) {
    clr(nxt);
    if (a[pos]==-1) {
      for (int prev=0;prev<2;prev++) {
        for (int odd=0;odd<mn;odd++) {
          int val=f[cur][prev][odd];
          int even=unk-odd;
          if (even <= avail[EV] && odd <= avail[ODD]) {
            if (odd < avail[ODD]) {
              chkmin(f[nxt][ODD][odd+1], val + (ODD!=prev?1:0));
            }
            if (even < avail[EV]) {
              chkmin(f[nxt][EV][odd], val + (EV!=prev?1:0));
            }
          }
        }
      }
      ++unk;
    } else {
      int par=a[pos];
      for (int prev=0;prev<2;prev++) {
        for (int odd=0;odd<mn;odd++) {
          chkmin(f[nxt][par][odd], f[cur][prev][odd] + (par!=prev?1:0));
        }
      }
    }
    swap(cur,nxt);
  }
  int ans=INF;
  for (int prev=0;prev<2;prev++) {
    for (int odd=0;odd<mn;odd++) {
      chkmin(ans, f[cur][prev][odd]);
    }
  }
  printf("%d\n", ans);

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