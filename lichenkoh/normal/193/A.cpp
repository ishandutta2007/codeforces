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
const int mn=52;
bool seen[mn][mn];
string a[mn];
int n,m;
int vdx[]={1,0,-1,0};
int vdy[]={0,1,0,-1};

void dfs(int x, int y) {
  if (!(0<=x&&x<n&&0<=y&&y<m)) return;
  if (a[x][y]=='.') return;
  if (seen[x][y]) return;
  seen[x][y]=true;
  for (int k=0;k<4;k++) {
    int nx=vdx[k]+x;
    int ny=vdy[k]+y;
    dfs(nx,ny);
  }
}
bool isconn() {
  memset(seen,0,sizeof seen);
  int ix,iy;
  for (int x=0;x<n;x++) {
    for (int y=0;y<m;y++) {
      if (a[x][y]=='#') {
        ix=x,iy=y; break;
      }
    }
  }
  dfs(ix,iy);
  for (int x=0;x<n;x++) {
    for (int y=0;y<m;y++) {
      if (a[x][y]=='#'&&!seen[x][y]) {
        return false;
      }
    }
  }
  return true;
}

int f(int x, int y) {
  int ans=0;
  for (int k=0;k<4;k++) {
    int nx=vdx[k]+x;
    int ny=vdy[k]+y;
    if (!(0<=nx&&nx<n&&0<=ny&&ny<m)) continue;
    if (a[nx][ny]=='#') ans++;
  }
  return ans;
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin>>n>>m;
  for (int x=0;x<n;x++) {
    cin>>a[x];
  }
  int ans=3;
  int cnt=0;
  for (int x=0;x<n;x++) {
    for (int y=0;y<m;y++) {
      if (a[x][y]=='#') {
        cnt++;
        int got=f(x,y);
        chkmin(ans,got);
      }
    }
  }
  for (int x=0;x<n;x++) {
    for (int y=0;y<m;y++) {
      if (a[x][y]=='#') {
        a[x][y]='.';
        if (!isconn()) ans=1;
        a[x][y]='#';
      }
    }
  }
  if (cnt<=2) ans=-1;
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