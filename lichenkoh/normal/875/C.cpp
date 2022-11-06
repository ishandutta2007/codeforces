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
const int mn=1e5+2;
const int LO=1,HI=2;
vector<int> s[mn];
int vans[mn];
int vl[mn];
vector<int> im[mn];

void dfs(int x) {
  vans[x]|=HI;
  for (auto &y:im[x]) {
    if (0==(vans[y]&HI)) dfs(y);
  }
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),m=rint();
  for (int i=0;i<n;i++) {
    int l=vl[i]=rint();
    for (int j=0;j<l;j++) {
      int x=rint();
      s[i].PB(x);
    }
  }
  for (int t=0;t<n-1;t++) {
    int l1=vl[t],l2=vl[t+1];
    bool ch=0;
    for (int i=0;i<min(l1,l2);i++) {
      int x=s[t][i],y=s[t+1][i];
      if (x<y) {
        //printf("%d->%d\n",y,x);
        im[y].PB(x);
        ch=1;
        break;
      }
      else if (x>y) {
        vans[x]|=HI;
        vans[y]|=LO;
        ch=1;
        break;
      }
    }
    if (!ch) {
      if (l1>l2) {
        printf("No\n");
        return 0;
      }
    }
  }
  for (int y=0;y<mn;y++) {
    if (vans[y]&HI) {
      dfs(y);
    }
  }
  vector<int> fin;
  for (int x=0;x<mn;x++) {
    if(vans[x]==3) {
      printf("No\n");
      return 0;
    }
    else if (vans[x]==HI) fin.PB(x);
  }
  printf("Yes\n%d\n",(int)fin.size());
  for (auto &w:fin) printf("%d ",w);
  printf("\n");
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