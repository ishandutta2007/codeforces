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
int n,m;
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
const int maxn=1004;
char a[maxn][maxn];
bool seen[maxn][maxn][4][3];
bool final=false;
int vdx[4]={1,0,-1,0};
int vdy[4]={0,1,0,-1};
void bfs(int x, int y, int dir, int k) {
  if (a[x][y]=='T') final=true;
  if (seen[x][y][dir][k]||a[x][y]=='*') return;
  seen[x][y][dir][k]=true;
  {
    int dx=vdx[dir],dy=vdy[dir];
    int nx=x+dx,ny=y+dy;
    if (0<=nx&&nx<n&&0<=ny&&ny<m) {
      bfs(nx,ny,dir,k);
    }
  }
  if (k<2) {
    for (int ndir=0;ndir<4;ndir++) {
      int dx=vdx[ndir],dy=vdy[ndir];
      int nx=x+dx,ny=y+dy;
      if (0<=nx&&nx<n&&0<=ny&&ny<m) {
        bfs(nx,ny,ndir,k+1);
      }
    }
  }
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	scanf("%d %d\n",&n,&m);
  for (int x=0;x<n;x++) scanf("%s\n",a[x]);
  int sx,sy;
  for (int x=0;x<n;x++) for (int y=0;y<m;y++) {
    if (a[x][y]=='S') {
      sx=x;sy=y;
    }
  }
  for (int dir=0;dir<4;dir++) bfs(sx,sy,dir,0);
  if (final) {
    printf("YES\n");
  }
  else printf("NO\n");
}