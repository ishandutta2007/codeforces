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
typedef pair<int,int> pii;
const int maxn=2004;
string a[maxn];
int vdx[]={1,0,-1,0};
int vdy[]={0,1,0,-1};
int n,m;
int getcnt(int x, int y) {
  int cnt=0;
  for (int k=0;k<4;k++) {
    int dx=vdx[k],dy=vdy[k];
    int nx=x+dx,ny=y+dy;
    if ((0<=nx&&nx<n)&&(0<=ny&&ny<m)) {
      if (a[nx][ny]=='.') {
        cnt++;
      }
    }
  }
  return cnt;
}
pii getneigh(int x, int y) {
  for (int k=0;k<4;k++) {
    int dx=vdx[k],dy=vdy[k];
    int nx=x+dx,ny=y+dy;
    if ((0<=nx&&nx<n)&&(0<=ny&&ny<m)) {
      if (a[nx][ny]=='.') return MP(nx,ny);
    }
  }
  return MP(-1,-1);
}
//bool seen[maxn][maxn];
queue<pii> q;
void upd(int x, int y) {
  for (int k=0;k<4;k++) {
    int dx=vdx[k],dy=vdy[k];
    int nx=x+dx,ny=y+dy;
    if ((0<=nx&&nx<n)&&(0<=ny&&ny<m)) {
      if (a[nx][ny]=='.'&&getcnt(nx,ny)==1) {
        //seen[nx][ny]=1;
        q.push(MP(nx,ny));
      }
    }
  }
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin>>n>>m;
  for (int x=0;x<n;x++) cin>>a[x];
  for (int x=0;x<n;x++) for (int y=0;y<m;y++) {
    //printf("x:%d y:%d gc:%d\n",x,y,getcnt(x,y));
    if (getcnt(x,y)==1) {
      q.push(MP(x,y));
      //seen[x][y]=1;
    }
  }
  while(!q.empty()) {
    pii top=q.front(); q.pop();
    int x=top.fst,y=top.snd;
    if (a[x][y]!='.') continue;
    pii p=getneigh(x,y);
    int px=p.fst,py=p.snd;
    if (px==-1) continue;
    if (a[px][py]!='.') continue;
    if (x==px) {
      if (y+1==py) a[x][y]='<',a[x][py]='>';
      else if (py+1==y) a[x][py]='<',a[x][y]='>';
      else assert(0);
    }
    else if (y==py) {
      if (x+1==px) a[x][y]='^',a[px][y]='v';
      else if (px+1==x) a[px][y]='^',a[x][y]='v';
      else assert(0);
    }
    else assert(0);
    upd(x,y); upd(px,py);
  }
  for (int x=0;x<n;x++) for (int y=0;y<m;y++) {
    if (a[x][y]=='.') {
      cout<<"Not unique"<<endl;
      //for (int x=0;x<n;x++) cout<<a[x]<<endl;
      return 0;
    }
  }
  for (int x=0;x<n;x++) cout<<a[x]<<endl;
}