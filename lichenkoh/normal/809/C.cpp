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
/*const int mn=20;
int a[mn][mn];
int mex(vector<int> &v) {
  sort(v.begin(),v.end());
  int ans=1;
  for (auto &w:v) {
    if (w==ans)ans++;
  }
  return ans;
}*/
const int me=31;
ll k;
ll x,y;
pll dp[me][2][2][2];
ll dphit[me][2][2][2];
const int LS=0,EQ=1,GR=2;
int trans(int s, int b, int tb) {
  if (s==LS) return LS;
  if (b<tb) return LS;
  else if (b==tb) return EQ;
  else return GR;
}
ll final=0;
pll f(int e, int xs, int ys, int ks) {
  if (e==-1) {
    if(xs+ys+ks==0) return MP(1ll,1ll);
    else return MP(0ll,0ll);
  }
  auto dpval=dp[e][xs][ys][ks];
  if (dpval.fst!=-1) return dpval;
  pll ans=MP(0ll,0ll);
  for (int xb=0;xb<2;xb++) {
    for (int yb=0;yb<2;yb++) {
      {
        int kb=xb^yb;
        int nxs=trans(xs,xb,(x>>e)&1);
        int nys=trans(ys,yb,(y>>e)&1);
        int nks=trans(ks,kb,(k>>e)&1);
        if (nxs!=GR&&nys!=GR&&nks!=GR) {
          auto got=f(e-1,nxs,nys,nks);
          ans.fst+=got.fst;
          ans.snd+=got.snd;
          if(kb==1) ans.snd+=(got.fst<<e)%MOD;
          ans.fst%=MOD;
          ans.snd%=MOD;
        }
      }
    }
  }
  return dp[e][xs][ys][ks]=ans;
}

int bf(int x, int y, int k) {
  int ans=0;
  for (int i=0;i<x;i++) for (int j=0;j<y;j++) {
    if ((i^j)<k) ans+=(i^j)+1;
  }
  return ans;
}

int query(int _x, int _y, int _k) {
  k=_k; x=_x; y=_y;
  if (x<0||y<0) return 0;
  memset(dp,-1,sizeof dp);
  memset(dphit,0,sizeof dphit);
  auto ans=f(me-1,1,1,1);
  return (ans.snd)%MOD;
}
void tester() {
  //printf("%d %d\n",bf(1,4,4),query(1,4,4));
  //return;
  //assert(query(1,4,4)==bf(1,4,4));
  int lim=4;
  for (int i=0;i<1000;i++) {
    int x=rand()%lim+1,y=rand()%lim+1,k=rand()%lim+1;
    if (bf(x,y,k)!=query(x,y,k)) {
      printf("x:%d y:%d k:%d. BF:%d QUE:%d\n",x,y,k,bf(x,y,k),query(x,y,k));
    }
    //else printf("%d %d %d\n",x,y,k);
  }
  printf("\n");
}
int main()
{
  //tester();
  //return 0;
	ios_base::sync_with_stdio(false); cin.tie(0);
  int q=readInt();
  for (int ii=0;ii<q;ii++) {
    int x1=readInt(),y1=readInt(),x2=readInt(),y2=readInt(),_k=readInt();
    --x1;--y1;
    int ans=query(x2,y2,_k)-query(x2,y1,_k)-query(x1,y2,_k)+query(x1,y1,_k);
    ans%=MOD;
    if (ans<0) ans+=MOD;
    printf("%d\n",ans);
  }

	//a[0][0]=1;
  //for (int x=0;x<mn;x++) {
  //  for (int y=0;y<mn;y++) {
  //    vector<int> v;
  //    for (int i=0;i<x;i++)v.PB(a[i][y]);
  //    for (int j=0;j<y;j++)v.PB(a[x][j]);
  //    a[x][y]=mex(v);
  //    printf("%02d ",a[x][y]);
  //  }
  //  printf("\n");
  //}
}