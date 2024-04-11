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
const int mn=1e5+4;
const int smax=sqrt(mn)+2;
vector<int> g[mn];
int vgsz[mn];
bitset<mn> isdensex;
vector<int> denseb4;
bool exist(int x, int y) {
  int imin=0,imax=vgsz[x];
  while(imin<imax) {
    int imid=(imin+imax)>>1;
    if (g[x][imid]<y) imin=imid+1;
    else imax=imid;
  }
  return imin<vgsz[x]&&g[x][imin]==y;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
  int n=readInt();
  for (int i=0;i<n;i++) {
    int x=readInt(),y=readInt();
    g[x].PB(y);
  }
  for (int x=0;x<mn;x++) {
    sort(g[x].begin(),g[x].end());
  }
  int slim=sqrt(n)+1;
  for (int x=0;x<mn;x++) {
    int gsz=g[x].size();
    vgsz[x]=gsz;
    if (gsz>=slim) {
      isdensex[x]=true;
    }
  }
  ll final=0;
  for (int x=0;x<mn;x++) {
    if (vgsz[x]>=slim) {
      int ans=0;
      for (auto &bx:denseb4) {
        int k=x-bx;
        for (auto y:g[x]) {
          if (exist(x,y+k)&&exist(bx,y)&&exist(bx,y+k)) {
            //dbg("A x:%d bx:%d y:%d y+k:%d\n",x,bx,y,y+k);
            ans++;
          }
        }
      }
      final+=ans;
      denseb4.PB(x);
    }
    else {
      int ilim=vgsz[x];
      int ans=0;
      for (int i=0;i<ilim;i++) for (int j=i+1;j<ilim;j++) {
        int ay=g[x][i],by=g[x][j];
        int k=by-ay;
        {
          int bx=x-k;
          if (bx>=0) {
            if (exist(bx,ay)&&exist(bx,by)) {
              //dbg("B x:%d bx:%d ay:%d by:%d\n",x,bx,ay,by);
              ans++;
            }
          }
        }
        {
          int bx=x+k;
          if (bx<mn&&isdensex[bx]) {
            if (exist(bx,ay)&&exist(bx,by)) {
              //dbg("C x:%d bx:%d ay:%d by:%d\n",x,bx,ay,by);
              ans++;
            }
          }
        }
      }
      final+=ans;
    }
  }
  printf("%lld\n",final);
}