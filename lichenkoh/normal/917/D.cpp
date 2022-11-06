#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
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
typedef unsigned long long ull;
#ifdef ONLINE_JUDGE
#define assert(XXX) XXX
#else
#define DEBUG_CAT
#endif
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();

const int mn=101;

int mod_pow(int a, int n) {
  const int mod=MOD;
 int ret = 1; int p = a % mod; while (n) { if (n & 1) ret = (ret *(ll) p) % mod; p = (p *(ll) p) % mod; n >>= 1; } return ret; }
const int MAXFACT=mn;
int fact[MAXFACT+1],invfact[MAXFACT+1];
inline int mul(int x,int y) {return (x*(ll)y)%MOD;}
int binom[mn][mn];
int _binom(int n,int k) {
  if (n<k) return 0;
  if (n<0||k<0) return 0;
  return mul(fact[n],mul(invfact[k],invfact[n-k]));
}
void init() {
  int got=1;
  for (int x=0;x<=MAXFACT;x++) {
    fact[x]=got;
    got=mul(got,x+1);
  }
  got=mod_pow(got,MOD-2);
  for (int x=MAXFACT;x>=0;x--) {
    got=mul(got,x+1);
    invfact[x]=got;
  }
  for (int n=0;n<mn;n++) {
    for (int k=0;k<=n;k++) {
      binom[n][k]=_binom(n,k);
    }
  }
}

vector<int> tree[mn];
int vsz[mn];
bool cmp(const int &x, const int &y) {
  return vsz[x]<vsz[y];
}
int getsz(int x, int p) {
  int ans=1;
  for (auto &y:tree[x]) {
    if (y==p) continue;
    ans+=getsz(y,x);
  }
  return vsz[x]=ans;
}
const ull LLIM=ULLONG_MAX-((MOD-1)*(ll)(MOD-1));
typedef unsigned long long ull;
int dpf[mn][2][mn][mn]; // dp[vertex][live][allEdgesExceptLive]
bitset<mn> seen;
int gn;
void dfs(int x, int p) {
  int n=gn;
  if (seen[x]) return;
  seen[x]=true;
  int cur=0;
  for (auto &y:tree[x]) {
    if (y==p) continue;
    dfs(y,x);
    cur^=1;
  }
  auto &f=dpf[x];
  memset(f[cur],0,sizeof f[cur]);
  f[cur][1][0]=1;
  int rlim=0;
  int nodes=1;
  for (auto &ch:tree[x]) {
    if (ch==p) continue;
    int nxt=cur^1;
    int chnodes=vsz[ch];
    nodes+=chnodes;
    for (int rlive=1;rlive<=n;rlive++) {
      memset(f[nxt][rlive],0,sizeof(int)*nodes);
    }
    for (int tlive=1;tlive<=nodes;tlive++) {
      for (int tall=0;tall<=nodes-tlive;tall++) {
        ull sum=0;
        int clivelim=min(tlive,chnodes);
        int calllim=min(tall,chnodes);
        for (int clive=0;clive<=clivelim;clive++) {
          for (int call=0;call<=calllim;call++) {
            int rlive=tlive-clive;
            int rall=tall-call;
            int prev=f[cur][rlive][rall];
            int child=dpf[ch][0][clive][call];
            sum+=(prev*(ll)child);
            if (sum>=LLIM) sum%=MOD;
          }
        }
        if (sum>=MOD) sum%=MOD;
        f[nxt][tlive][tall]=sum;
      }
    }
    cur^=1;
  }
  for (int dest=1;dest<=nodes;dest++) {
    ull sum=0;
    for (int rlive=1;rlive<=min(dest,nodes);rlive++) {
      int rall=dest-rlive;
      sum+=(n*(rlive)*(ll)f[0][rlive][rall]);
    }
    sum%=MOD;
    f[cur][0][dest-1]=sum;
  }
}

int vans[mn];

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  init();
  int n=rint();
  gn=n;
  for (int i=1;i<n;i++) {
    int x=rint(),y=rint(); --x; --y;
    tree[x].PB(y);
    tree[y].PB(x);
  }
  getsz(0,-1);
  for (int x=0;x<n;x++) sort(tree[x].begin(),tree[x].end(),cmp);
  dfs(0,-1);
  int invn2=mod_pow(n*n,MOD-2);
  for (int rall=n-1;rall>=0;rall--) {
    int seed=dpf[0][0][0][rall];
    int sones=rall;
    for (int o=rall+1;o<n;o++) {
      int ozeros=n-1-o;
      int C=binom[n-1-ozeros][sones];
      seed=(seed-C*(ll)vans[o])%MOD;
      if (seed<0) seed+=MOD;
    }
    vans[rall]=seed;
  }
  for (int rall=0;rall<n;rall++) {
    int ans=(vans[rall]*(ll)invn2)%MOD;
    printf("%d ",ans);
  }
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