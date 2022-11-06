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
const int mn=150000;
/*const int q=18;
inline ll MK(ll val, int x) {
  return (val<<q)|x;
}
inline ll VAL(ll x) {
  return x>>q;
}
inline int XX(ll x) {
  return x&((1<<q)-1);
}*/
int f[2][mn];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=readInt(),m=readInt(),dpt=readInt();
  int prevt;
  int cur=0,nxt=1;
  ll final=0;
  for (int i=0;i<m;i++) {
    int a=readInt()-1,bb=readInt(),t=readInt();
    final+=bb;
    if (i==0) {
      for (int x=0;x<n;x++) {
        f[nxt][x]=-abs(a-x);
      }
    }
    else {
      
      int K=(int)min((ll)n-1LL,(ll)dpt*(ll)(t-prevt));
      // pair<int, int> represents the pair (ARR[i], i)
      std::deque< std::pair<int, int> > window;
      for (int i = 0; i < n+K; i++) {
        if (i<n) {
         while (!window.empty() && window.back().first <= f[cur][i])
           window.pop_back();
         window.push_back(std::make_pair(f[cur][i], i));
        }
        while(window.front().second <= i - (1+2*K))
          window.pop_front();
        if(i-K>=0) f[nxt][i-K] = (window.front().first) - abs(a-(i-K));
      }
    }
    //for (int x=0;x<n;x++) printf("i:%d x:%d f:%lld\n",i,x,f[nxt][x]);
    prevt=t;
    swap(cur,nxt);
  }
  int ans=-(1<<30);
  for (int x=0;x<n;x++) chkmax(ans,f[cur][x]);
  printf("%lld\n",final+ans);
}