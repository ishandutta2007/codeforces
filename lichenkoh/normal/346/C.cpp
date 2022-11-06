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
const int mn=1e5+4;
int d[mn];
const int mx=1e6+4;
int tmp[mx];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int on=rint();
  for (int i=0;i<on;i++) d[i]=rint();
  sort(d,d+on);
  int a=rint(),b=rint();
  int BASE=b;
  auto uu=unique(d,d+on);
  int n=uu-d;
  tmp[b-BASE]=b;
  for (int x=b+1;x<=a;x++) tmp[x-BASE]=x-1; 
  for (int k=0;k<n;k++) {
    //printf("%d ",d[k]);
    int e=d[k];
    int start=b;
    int mod=b%e;
    if (mod>0) start+=e-mod;
    for (int x=start;x<=a;x+=e) {
      chkmin(tmp[min(a,x+e-1)-BASE],x);
    }
  }
  //printf("\n");
  for (int x=a-1;x>=b;x--) {
    chkmin(tmp[x-BASE],tmp[x+1-BASE]);
  }
  //for (int x=b;x<=a;x++) printf("x:%d tmp:%d\n",x,tmp[x-BASE]);
  {
    int ans=0;
    int x=a;
    while(x>b) {
      x=tmp[x-BASE]; ans++;
      //printf("x:%d\n",x);
    }
    printf("%d\n",ans);
  }
}