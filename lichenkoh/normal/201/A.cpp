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
//int rint();char rch();long long rlong();
const int mn=102;
int a[mn][mn];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int paint(int xx, int yy, int n) {
  int ans=4;
  vector<pii> v;
  v.PB(MP(xx,yy));
  v.PB(MP(n-1-xx,yy));
  v.PB(MP(xx,n-1-yy));
  v.PB(MP(n-1-xx,n-1-yy));
  for (auto &w:v) {
    int x=w.fst,y=w.snd;
    ans-=a[x][y];
    a[x][y]=1;
    for (int d=0;d<4;d++) {
      int nx=x+dx[d];
      int ny=y+dy[d];
      if (nx<0||ny<0) continue;
      if (a[nx][ny]) return 0;
    }
  }
  return ans;
}
int want;
bool solve(int n, int r) {
  for (int x=0;x<n;x++) for (int y=0;y<n;y++) a[x][y]=0;
  int az=0,b=0,c=0;
  for (int x=0;x<n;x++) {
    for (int y=(r+x)&1;y<n;y+=2) {
      int got=paint(x,y,n);
      //printf("n:%d r:%d x:%d y:%d got:%d\n",n,r,x,y,got);
      if (got==0) continue;
      if (got==1) az++;
      else if (got==2) b++;
      else if (got==4) c++;
      else {
        assert(0);
      }
    }
  }
  for (int aa=0;aa<=az;aa++) {
    for (int bb=0;bb<=b;bb++) {
      for (int cc=0;cc<=c;cc++) {
        int tot=aa+bb*2+cc*4;
        if (tot==want) return true;
      }
    }
  }
  return false;
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin>>want;
  for (int n=1;;n++) {
    for (int r=0;r<2;r++) {
      if (solve(n,r)) {
        printf("%d\n",n);
        return 0;
      }
    }
  }
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