#include <bits/stdc++.h>
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
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
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
const int mn=52;
void go(ll *a, int start) {
  for (int i=start;i<mn;i++) a[i]=a[i-2]+a[i-1];
}
void gg(char *fx, int n, int sx, int ex, int tx) {
  for (int i=0;i<n;i++) fx[i]='K';
  int xi=0;
  if(sx) fx[xi++]='C';
  for (int i=0;i<tx;i++) {
    fx[xi++]='A';fx[xi++]='C';
  }
  if(ex) fx[n-1]='A';
  fx[n]='\0';
}
ll x[mn],y[mn],xy[mn],yx[mn],yy[mn];
char fx[104],fy[104];

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int k,need,n,m; cin>>k>>need>>n>>m;
  x[1]=1; x[2]=0;
  go(x,3);
  y[1]=0; y[2]=1;
  go(y,3);
  xy[2]=0;xy[3]=1;
  go(xy,4);
  for (int i=4;i<mn;i++) yx[i]=yx[i-2]+yx[i-1]+((i&1)^1);
  for (int i=5;i<mn;i++) yy[i]=yy[i-2]+yy[i-1]+(i&1);
  //for (int i=1;i<=7;i++) printf("%d ",x[i]); printf("\n");
  //for (int i=1;i<=7;i++) printf("%d ",y[i]); printf("\n");
  //for (int i=1;i<=7;i++) printf("%d ",xy[i]); printf("\n");
  //for (int i=1;i<=7;i++) printf("%d ",yx[i]); printf("\n");
  //for (int i=1;i<=7;i++) printf("%d ",yy[i]); printf("\n");
  for (int z=0;z<(1<<4);z++) {
    int sx=(z>>0)&1;
    int ex=(z>>1)&1;
    int sy=(z>>2)&1;
    int ey=(z>>3)&1;
    int lx=n-sx-ex,ly=m-sy-ey;
    if (lx<0||ly<0) continue;
    ll want=need-(ex&sy)*xy[k]-(ey&sx)*yx[k]-(ey&sy)*yy[k];
    if (want<0) continue;
    for (ll tx=0;tx<=lx/2;tx++) for (ll ty=0;ty<=ly/2;ty++) {
      ll tmp;
      if (__builtin_smulll_overflow(tx,x[k],&tmp)||__builtin_smulll_overflow(ty,y[k],&tmp)) continue;
      ll have=tx*x[k]+ty*y[k];
      if (have<0) continue;
      if (have==want) {
        gg(fx, n, sx, ex, tx);
        gg(fy,m,sy,ey,ty);
        printf("%s\n%s\n",fx,fy);
        return 0;
      }
    }
  }
  printf("Happy new year!\n");
}