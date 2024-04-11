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
const int INF=1<<29;
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

const int mx=6;
const int mz=1<<mx;
int f[2][mz][mz];
void rst(int cur) {
  for (int x=0;x<mz;x++) for (int y=0;y<mz;y++) f[cur][x][y]=INF;
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int rlim=rint(),clim=rint();
  if (rlim>clim) swap(rlim,clim);
  assert(rlim<=6);
  int zlim=1<<rlim;
  int cur=0,nxt=1;
  for (int c=0;c<clim;c++) {
    for (int r=0;r<rlim;r++) {
      rst(nxt);
      for (int a=0;a<zlim;a++) {
        for (int b=0;b<zlim;b++) {
          int now=f[cur][a][b];
          int fmsk=1<<(rlim-1);
          {
            // Don't move spider. Position is filled
            chkmin(f[nxt][a>>1][(b>>1)|fmsk],now+1);
          }
          if (0==(a&1)) {
            // Move spider left
            if (c!=0) {
              if (b&1) {
                chkmin(f[nxt][a>>1][b>>1],now);
              }
            }
            // Move spider up
            if (r!=0) {
              if (b&fmsk) {
                chkmin(f[nxt][a>>1][b>>1],now);
              }
              else {
                chkmin(f[nxt][a>>1][(b|fmsk)>>1],now+1);
              }
            }
            if (r<rlim-1) {
              // Move spider down
              chkmin(f[nxt][(a>>1)|1][b>>1], now);
            }
            if (c<clim-1) {
              // Move spider right
              chkmin(f[nxt][(a>>1)|fmsk][b>>1], now);
            }
          }
        }
      }
      swap(cur,nxt);
    }
  }
  int ans=INT_MAX;
  for (int a=0;a<zlim;a++) for (int b=0;b<zlim;b++) chkmin(ans,f[cur][a][b]);
  printf("%d\n",(rlim*clim)-ans);
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