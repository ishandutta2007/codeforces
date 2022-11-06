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
const int mn=104;
vector<int> v[mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; scanf("%d",&n);
  for (int i=0;i<n;i++) {
    int s; scanf("%d",&s);
    for (int j=0;j<s;j++) {
      int x; scanf("%d",&x); v[i].PB(x);
    }
  }
  int l=0,r=0;
  vector<int> g;
  for (int k=0;k<n;k++) {
    int s=v[k].size();
    if (s%2==1) {
      g.PB(v[k][s/2]);
      for (int i=0;i<s/2;i++) l+=v[k][i];
      for (int i=s/2+1;i<s;i++) r+=v[k][i];
    }
    else {
      for (int i=0;i<s/2;i++) l+=v[k][i];
      for (int i=s/2;i<s;i++) r+=v[k][i];
    }
  }
  sort(g.begin(),g.end(),greater<int>());
  int t=0;
  for (auto &w:g) {
    if (t==0) l+=w;
    else r+=w;
    t^=1;
  }
  printf("%d %d\n",l,r);
}