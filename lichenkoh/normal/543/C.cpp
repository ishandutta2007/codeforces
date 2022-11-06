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
const ll INF=2e9;
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
int f[1<<21];
char s[27][27];
int cost[27][27];
int xMask[27][27];
int a[27][27];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n,m; scanf("%d %d\n",&n,&m);
  for (int x=0;x<n;x++) scanf("%s\n",s[x]);
  for (int x=0;x<n;x++) for (int y=0;y<m;y++) scanf("%d", &a[x][y]);
  for (int y=0;y<m;y++) {
    for (int x=0;x<n;x++) {
      int c=s[x][y]-'a';
      xMask[y][c]|=1<<x;
    }
    for (int c=0;c<26;c++) {
      int most=0;
      int sum=0;
      for (int x=0;x<n;x++) {
        if ((1<<x)&xMask[y][c]) {
          chkmax(most,a[x][y]);
          sum+=a[x][y];
        }
      }
      cost[y][c]=sum-most;
    }
  }
  
  int maxz=1<<n;
  for (int z=0;z<maxz;z++) f[z]=INF;
  f[0]=0;
  for (int y=0;y<m;y++) {
    for (int z=0;z<maxz;z++) {
      if (f[z]>=INF) continue;
      for (int x=0;x<n;x++) {
        chkmin(f[z|(1<<x)], f[z]+a[x][y]);
      }
      for (int c=0;c<26;c++) {
        chkmin(f[z|xMask[y][c]], f[z]+cost[y][c]);
      }
    }
  }
  printf("%d\n",f[maxz-1]);
}