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
const int mn=1004;
bool g[mn][mn];
void ae(int x,int y) {
  //printf("x:%d y:%d\n",x,y);
  g[x][y]=g[y][x]=1;
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int k; scanf("%d",&k);
  vector<int> instr;
  while(k>1) {
    if (k%2==0) {
      k/=2;
      instr.PB(0);
    }
    else {
      k--;
      instr.PB(1);
    }
  }
  reverse(instr.begin(),instr.end());
  int len=1;
  ae(1,3);
  int src=3;
  int gid=4;
  for (auto &bit:instr) {
    if (bit==0) {
      int x=gid,y=gid+1,t=gid+2;
      ae(src,x);
      ae(src,y);
      ae(x,t);
      ae(y,t);
      gid=t+1;
      src=t;
      len+=2;
    }
    else {
      int x=1;
      for (int i=0;i<len-1;i++) {
        int y=gid;
        ae(x,y);
        x=y;
        gid++;
      }
      ae(x,src);
    }
  }
  ae(src,2);
  int n=gid-1;
  printf("%d\n",n);
  for (int x=1;x<=n;x++) {
    for (int y=1;y<=n;y++) {
      printf("%c",g[x][y]?'Y':'N');
    }
    printf("\n");
  }
}