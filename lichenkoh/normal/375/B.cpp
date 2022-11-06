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
const int mn=5004;
int a[mn][mn];
int b[mn][mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=readInt(),m=readInt();
  for (int x=0;x<n;x++) for (int y=0;y<m;y++) {
    a[x][y]=readCh()-'0';
  }
  for (int x=0;x<n;x++) {
    int start=-1;
    for (int y=0;y<=m;y++) {
      if (a[x][y]&&start==-1) start=y;
      if (0==a[x][y]&&start!=-1) {
        int l=start,r=y-1;
        b[l][r]++;
        //printf("l:%d r:%d\n",l,r);
        start=-1;
      }
    }
  }
  for (int l=0;l<m;l++) {
    for (int r=m-2;r>=l;r--) {
      b[l][r]+=b[l][r+1];
      //printf("A l:%d r:%d adds %d\n",l,r,b[l][r+1]);
    }
  }
  for (int r=0;r<m;r++) {
    for (int l=1;l<=r;l++) {
      b[l][r]+=b[l-1][r];
      //printf("B l:%d r:%d adds %d\n",l,r,b[l-1][r]);
    }
  }
  int final=0;
  for (int l=0;l<m;l++) for (int r=l;r<m;r++) {
    int cand=(r-l+1)*(b[l][r]);
    //if (cand==4) printf("l:%d r:%d b:%d\n",l,r,b[l][r]);
    chkmax(final,cand);
  }
  printf("%d\n",final);
}