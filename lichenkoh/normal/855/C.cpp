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
const int mn=1e5+4;
const int mc=11;
vector<int> g[mn];
int n,m,k,clim;

inline int mul(int x, int y) {
  return (x*(ll)y)%MOD;
}
inline int add(int x, int y) {
  int ans=x+y;
  if (ans>=MOD) ans-=MOD;
  return ans;
}
const int mh=3;
const int LK=0;
const int ISK=1;
const int HK=2;
int df[mn][mh][mc];
bool done[mn][mh];
void go(int v, int p, int h) {
  if (done[v][h]) return;
  int f[2][mc];
  if (h==ISK) {
    int cur=0,nxt=1;
    memset(f,0,sizeof f);
    f[cur][1]=1;
    for (auto &y:g[v]) {
      if (y==p) continue;
      go(y,v,LK);
      memset(f[nxt],0,sizeof f[nxt]);
      for (int c=0;c<=clim;c++) {
        int got=df[y][LK][c];
        for (int t=c;t<=clim;t++) {
          f[nxt][t]=(f[nxt][t]+(f[cur][t-c]*(ll)got))%MOD;
        }
      }
      swap(cur,nxt);
    }
    for (int c=0;c<=clim;c++) df[v][h][c]=f[cur][c];
  }
  else if (h==LK)  {
    int cur=0,nxt=1;
    memset(f,0,sizeof f);
    f[cur][0]=1;
    for (auto &y:g[v]) {
      if (y==p) continue;
      go(y,v,LK);
      go(y,v,ISK);
      go(y,v,HK);
      memset(f[nxt],0,sizeof f[nxt]);
      for (int c=0;c<=clim;c++) {
        int got=add(add(df[y][LK][c],df[y][ISK][c]),df[y][HK][c]);
        for (int t=c;t<=clim;t++) {
          f[nxt][t]=(f[nxt][t]+(f[cur][t-c]*(ll)got))%MOD;
        }
      }
      swap(cur,nxt);
    }
    for (int c=0;c<=clim;c++) df[v][h][c]=(df[v][h][c]+f[cur][c]*(ll)(k-1))%MOD;
  }
  else  {
  assert(h==HK);
    int cur=0,nxt=1;
    memset(f,0,sizeof f);
    f[cur][0]=1;
    for (auto &y:g[v]) {
      if (y==p) continue;
      go(y,v,LK);
      go(y,v,HK);
      memset(f[nxt],0,sizeof f[nxt]);
      for (int c=0;c<=clim;c++) {
        int got=add(df[y][LK][c],df[y][HK][c]);
        for (int t=c;t<=clim;t++) {
          f[nxt][t]=(f[nxt][t]+(f[cur][t-c]*(ll)got))%MOD;
        }
      }
      swap(cur,nxt);
    }
    for (int c=0;c<=clim;c++) df[v][h][c]=(df[v][h][c]+f[cur][c]*(ll)(m-k))%MOD;
  }
  /*printf("\nv:%d h:%d\n",v,h);
  for (int c=0;c<=clim;c++) printf("c:%d ans:%d\n",c,df[v][h][c]);*/
  done[v][h]=true;
}


int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  n=rint(),m=rint();
  for (int i=1;i<n;i++) {
    int x=rint(),y=rint();
    g[x].PB(y); g[y].PB(x);
  }
  k=rint(),clim=rint();
  int ans=0;
  int v=1;
  for (int h=0;h<mh;h++) {
    go(v,-1,h);
    for (int c=0;c<=clim;c++) {
      ans=add(ans,df[v][h][c]);
    }
  }
  printf("%d\n",ans);
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