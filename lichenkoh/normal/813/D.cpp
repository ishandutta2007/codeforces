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

int readInt()
{
  int j; scanf("%d",&j); return j;
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
const int mn=5004;
int f[mn][mn];
vector<int> g[mn][3];
vector<int> gr[mn];
int h[mn][3];
int a[mn];
inline int bins(int x, int m) {
  int i=h[x][m];
  if (i>=g[x][m].size()) return -1;
  else return g[x][m][i];
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=readInt();
	for (int i=1;i<=n;i++) a[i]=readInt();
	memset(f,-1,sizeof f);
	for (int x=1;x<=n;x++) {
		for (int y=x+1;y<=n;y++) {
			int diff=a[x]-a[y];
			if (diff==1) {g[x][0].PB(y); gr[y].PB(((x<<2)|0));}
      else if (diff==-1) {g[x][1].PB(y); gr[y].PB(((x<<2)|1));}
      else if (diff%7==0) {g[x][2].PB(y); gr[y].PB(((x<<2)|2));}
		}
	}
  //for (int x=1;x<=n;x++) g[0][0].PB(x);
  //for (int x=1;x<=n;x++) f[0][x]=f[x][0]=1;
  //for (int x=1;x<=n;x++) for (int y=1;y<=n;y++) if (x!=y) f[x][y]=2;
  f[0][0]=0;
	for (int s=0;s<=n;s++) {
    for (auto &w:gr[s]) {
      h[w>>2][w&3]++;
    }
    for (int low=0;low<=s;low++) {
      int x=low,y=s;
      for (int k=0;k<2;k++) {
        if (f[x][y]==-1) continue;
        int mxy=s;
        int nv=f[x][y]+1;
        for (int m=0;m<3;m++) {
          int nx=bins(x,m);
          if (nx!=-1) chkmax(f[nx][y], nv);
          int ny=bins(y,m);
          if (ny!=-1) chkmax(f[x][ny],nv);
          //printf("x:%d y:%d f:%d m:%d nx:%d ny:%d\n",x,y,f[x][y],m,nx,ny);
        }
        if (x==0) {
          for (int nx=mxy+1;nx<=n;nx++) chkmax(f[nx][y],nv);
        }
        if (y==0) {
          for (int ny=mxy+1;ny<=n;ny++) chkmax(f[x][ny],nv);
        }
        swap(x,y);
      }
    }
  }
  int final=0;
  for (int x=0;x<=n;x++) for (int y=0;y<=n;y++) chkmax(final,f[x][y]);
	printf("%d\n",final);
}