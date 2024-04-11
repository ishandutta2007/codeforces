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
char readCh()
{
    readAhead(16);
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    char ans=*stdinPos;
    ++stdinPos;
    return ans;
}
const int mn=504;
string inp[504];
int a[mn][mn];
bool done[mn][mn];
const int HASH=2,FILL=1,EMP=0;
int n,m;
bool canuse(int x, int y) {
  return (0<=x&&x<n&&0<=y&&y<m&&a[x][y]==FILL); 
}
pair<int,int> get(int x, int y) {
  {
    int ny=y;
    for (int nx=x-1;nx<=x+1;nx+=2) {
      if (canuse(nx,ny)) return MP(nx,ny);
    }
  }
  {
    int nx=x;
    for (int ny=y-1;ny<=y+1;ny+=2) {
      if (canuse(nx,ny)) return MP(nx,ny);
    }
  }
  return MP(-1,-1);
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int k; cin>>n>>m>>k;
  for (int x=0;x<n;x++) cin>>inp[x];
  int hash=0;
  int sx=-1,sy=-1;
  for (int x=0;x<n;x++) for (int y=0;y<m;y++) {
    if ((inp[x][y]=='#')) hash++;
    else {sx=x,sy=y;}
    a[x][y]=(inp[x][y]=='#')?HASH:FILL;
  }
  if (k==0) {
    for (int x=0;x<n;x++) cout<<inp[x]<<endl;
    return 0;
  }
  assert(sx!=-1);
  int empty=n*m-hash-k;
  a[sx][sy]=EMP;
  empty--;
  queue<pair<int,int> > q;
  q.push(MP(sx,sy));
  while(!q.empty()) {
    if (empty==0) break;
    auto got=q.front(); q.pop();
    int x=got.fst,y=got.snd;
    assert(a[x][y]==EMP);
    pair<int,int> neigh=get(x,y);
    if (neigh.fst==-1) {
      done[x][y]=true;
    }
    else {
      int nx=neigh.fst,ny=neigh.snd;
      assert(a[nx][ny]==FILL);
      a[nx][ny]=EMP;
      empty--;
      if (!done[x][y]) q.push(MP(x,y));
      q.push(MP(nx,ny));
    }
  }
  for (int x=0;x<n;x++) {
    for (int y=0;y<m;y++) {
      char c;
      if (a[x][y]==HASH) c='#';
      else if (a[x][y]==EMP) c='.';
      else c='X';
      printf("%c",c);
    }
    printf("\n");
  }
}