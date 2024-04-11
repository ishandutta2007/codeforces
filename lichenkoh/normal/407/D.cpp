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
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
#define DEBUG_CAT
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
const int logmaxp=9;
inline int MK(int val, int pos) {
  return (val<<logmaxp)|pos;
}
inline int getpos(int x) {
  return x&((1<<logmaxp)-1);
}
inline int getval(int x) {
  return x>>logmaxp;
}
const int maxn=400;
const int maxv=400*400;
int n,m;
int b[maxn][maxn];
int binsearch(int x, int val, int pos) {
  int key=MK(val,pos);
  int imin=0,imax=m;
  while(imin<imax) {
    int imid=(imin+imax)>>1;
    if (b[x][imid]>key) imin=imid+1;
    else imax=imid;
  }
  if (imin>=m) return -1;
  int got=b[x][imin];
  int gval=getval(got);
  if (gval!=val) return -1;
  return getpos(got);
}
int a[maxn][maxn];
int xloYhi2ylo[maxn][maxn];
short v[maxn][maxn][maxn];
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  n=readInt(),m=readInt();
  for (int x=0;x<n;x++) {
    for (int y=0;y<m;y++) {
      int val=readInt();
      a[x][y]=val;
      b[x][y]=MK(val,y);
    }
    sort(b[x],b[x]+m,greater<int>());
  }
  for (int xhi=0;xhi<n;xhi++) {
    for (int yhi=0;yhi<m;yhi++) {
      int val=a[xhi][yhi];
      for (int xlo=0;xlo<n;xlo++) {
        int yr=yhi-((xlo==xhi)?1:0);
        short ylo=binsearch(xlo,val,yr)+1;
        v[xhi][xlo][yhi]=ylo;
      }
    }
  }
  int ans=0;
  for (int d=0;d<n;d++) {
    for (int xlo=0;xlo<n-d;xlo++) {
      int xhi=xlo+d;
      for (int yhi=0;yhi<m;yhi++) {
        short ylo=max(v[xlo][xhi][yhi],v[xhi][xlo][yhi]);
        if (yhi>0) chkmax(ylo,v[xlo][xhi][yhi-1]);
        if (xlo<xhi) {
          chkmax(ylo,v[xlo][xhi-1][yhi]);
          chkmax(ylo,v[xlo+1][xhi][yhi]);
        }
        v[xlo][xhi][yhi]=ylo;
        int cand=(xhi-xlo+1)*(yhi-ylo+1);
        chkmax(ans,cand);
      }
    }
  }
  printf("%d\n",ans);
}