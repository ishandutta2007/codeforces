#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
#ifdef DEBUG_CAT

#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
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

int readInt()
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
const int INF=1<<30;
const int mn=1e5+4;
const int md=302;
//int f[mn][md];
int g[2][md];
vector<int> val2bidx[mn];
int v2bsz[mn];
int a[mn],b[mn];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=readInt(),m=readInt(),s=readInt(),e=readInt();
  for (int i=1;i<=n;i++) a[i]=readInt();
  for (int i=1;i<=m;i++) {
    b[i]=readInt();
    val2bidx[b[i]].PB(i);
  }
  for (int v=0;v<mn;v++) v2bsz[v]=val2bidx[v].size();
  //for (int x=0;x<mn;x++) for (int d=0;d<md;d++) f[x][d]=INF;
  int cur=0,nxt=1;
  for (int d=0;d<md;d++) g[cur][d]=INF;
  g[cur][0]=0;
  int final=0;
  for (int x=1;x<=n;x++) {
    memcpy(g[nxt],g[cur],sizeof(g[cur]));
    int v=a[x];
    for (int d=1;d<md;d++) {
      int prevbidx=g[cur][d-1];
      if (prevbidx==INF) continue;
      int imin=0,imax=v2bsz[v];
      while(imin<imax) {
        int imid=(imin+imax)>>1;
        if (val2bidx[v][imid]<=prevbidx) imin=imid+1;
        else imax=imid;
      }
      if (imin<v2bsz[v]) {
        int nxtbidx=val2bidx[v][imin];
        //printf("x:%d d:%d prevbidx:%d nxtbidx:%d\n",x,d,prevbidx,nxtbidx);
        chkmin(g[nxt][d],nxtbidx);
        int cost=x+nxtbidx+d*e;
        if (cost<=s) {
          chkmax(final,d);
        }
      }
    }
    swap(cur,nxt);
  }
  printf("%d\n",final);
}