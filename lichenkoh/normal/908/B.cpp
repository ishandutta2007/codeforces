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
const int INF=1<<30;
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
string a[mn];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int rl,cl; cin>>rl>>cl;
  for (int r=0;r<rl;r++) cin>>a[r];
  string t; cin>>t;
  vector<int> p; for (int i=0;i<4;i++) p.PB(i);
  pii s,e;
  for (int r=0;r<rl;r++) for (int c=0;c<cl;c++) {
    if (a[r][c]=='S') s=MP(r,c);
    if (a[r][c]=='E') e=MP(r,c);
  }
  int ans=0;
  do {
    int r=s.fst,c=s.snd;
    int ok=0;
    for (auto &ch:t) {
      int d=p[ch-'0'];
      int nr=r+dx[d];
      int nc=c+dy[d];
      if (nr<0||nc<0||nr>=rl||nc>=cl) break;
      if (a[nr][nc]!='#') {
        r=nr,c=nc;
        if (a[r][c]=='E') {
          ok=1;
          break;
        }
      }
      else break;
      //printf("zz:%d r:%d c:%d\n",zz,r,c);
    }
    ans+=ok;
  } while(next_permutation(p.begin(),p.end()));
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