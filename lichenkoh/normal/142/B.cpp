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
const int mn=1006;
bitset<mn> a[mn];
int ans=0;
int n,m; clock_t start;
int dx[]={1, 1,2, 2};
int dy[]={2,-2,1,-1};
void bf() {
  time_t now=clock();
  if (now-start>0.78 * CLOCKS_PER_SEC) {
    printf("%d\n",ans); exit(0);
  }
  srand(now);
  for (int x=0;x<n;x++) a[x].reset();
  int cand=0;
  for (int x=0;x<n;x++) for (int y=0;y<m;y++) {
    if (a[x][y]) continue;
    if (rand()&1) {
      cand++;
      //printf("x:%d y:%d\n",x,y);
      for (int k=0;k<4;k++) {
        int nx=x+dx[k],ny=y+dy[k];
        if (ny>=0) a[nx][ny]=true;
      }
    }
  }
  //printf("cand:%d\n",cand);
  chkmax(ans,cand);
}
int fast(int n, int m) {
  int n4=n;
  int m3=(m+2)/3;
  return n4*m3;
}
int g(int n, int m) {
  int r1=(m+1)/2;
  int r2=m/2;
  int ans=(n/2)*(r1+r2) + (n%2)*r1;
  return ans;
}
const int mz=1<<(2*5);
int f[2][1<<(2*5)];
int go(int n, int m) {
  if (m!=2) return 0;
  int cur=0,nxt=1;
  memset(f,-1,sizeof f);
  f[0][0]=0;
  for (int x=0;x<n;x++) {
    for (int z=0;z<mz;z++) {
      int now=f[cur][z]; if (now==-1) continue;
      for (int u=0;u<2;u++) {
        if(u) if (z&((1<<7))) continue;
        for (int d=0;d<2;d++) {
          if(d) if (z&((1<<6))) continue;
          int nz=(z>>2)|(u<<8)|(d<<9);
          chkmax(f[nxt][nz],now+u+d);
        }
      }
    }
    swap(cur,nxt);
  }
  int ans=0;
  for (int z=0;z<mz;z++) chkmax(ans,f[cur][z]);
  return ans;
}
int main() 
{
  start=clock();
  ios_base::sync_with_stdio(false); cin.tie(0);
  n=rint(),m=rint();
  chkmax(ans,fast(n,m));
  chkmax(ans,fast(m,n));
  chkmax(ans,g(n,m));
  chkmax(ans,g(m,n));
  chkmax(ans,go(n,m));
  chkmax(ans,go(m,n));
  printf("%d\n",ans);
  //while(1) bf();
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