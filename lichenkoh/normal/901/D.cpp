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
#ifdef ONLINE_JUDGE
#define assert(XXX) XXX
#else
//#define DEBUG_CAT
#endif
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();

const int mn=1e5+2;
vector<pii> g[mn];
int inp[mn];

char vcol[mn];
int n;

int sodd=-1;
void findodd(int x, int p, int col) {
  if (vcol[x]!=-1) {
    if (vcol[x]==col) return;
    else {sodd=x; return;}
  }
  vcol[x]=col;
  for (auto &yy:g[x]) {
    int y=yy.fst;
    if (y==p) continue;
    findodd(y,x,col^1);
  }
}

vector<int> voddcyc;
bitset<mn> sn[2];
bool getoddcyc(int x, int p, int col) {
  if (sn[col][x]) return false;
  sn[col][x]=true;
  if (x==sodd&&col==1) return true;
  for (auto &yy:g[x]) {
    int y=yy.fst;
    if (y==p) continue;
    bool res=getoddcyc(y,x,col^1);
    if (res) {
      voddcyc.PB(yy.snd);
      dbg("x:%d y:%d e:%d\n",x,y,yy.snd);
      return true;
    }
  }
  return false;
}
ll vans[mn];
bitset<mn> seen;
ll dfs(int x, int p) {
  seen[x]=true;
  ll sum=0;
  for (auto &ye:g[x]) {
    int y=ye.fst,e=ye.snd;
    if (y==p||seen[y]) continue;
    ll got=dfs(y,x);
    vans[e]+=got;
    dbg("dfs e:%d got:%d\n",e,got);
    sum+=got;
  }
  ll need=inp[x]-sum;
  return need;
}
void fail(int t) {
  printf("NO\n"); exit(0);
}
bool check(int x) {
  ll sum=0;
  for (auto &ye:g[x]) {
    int e=ye.snd;
    sum+=vans[e];
  }
  if (sum!=inp[x]) dbg("x:%d sum:%d inpx:%d\n",x,sum,inp[x]);
  return sum==inp[x];
}
bool checkall() {
  for (int x=1;x<=n;x++) if (!check(x)) return false;
  return true;
}
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  n=rint(); int m=rint();
  for (int x=1;x<=n;x++) inp[x]=rint();
  for (int e=1;e<=m;e++) {
    int x=rint(),y=rint(); g[x].PB(MP(y,e)); g[y].PB(MP(x,e));
  }
  memset(vcol,-1,sizeof vcol);
  findodd(1,-1,0);
  if (sodd!=-1) {
    memset(vcol,-1,sizeof vcol);
    bool res=getoddcyc(sodd,-1,0);
    assert(voddcyc.size()&1);
    assert(res);
    dfs(sodd,-1);
    //for (int x=1;x<=n;x++) {
    //  if (x!=sodd) assert(check(x));
    //}
    ll extra=0;
    for (auto &ye:g[sodd]) {
      extra+=vans[ye.snd];
    }
    ll need=inp[sodd]-extra;
    dbg("sodd:%d need:%d\n",sodd,need);
    ll offset=(need)/2;
    for (auto &e:voddcyc) {
      vans[e]+=offset;
      dbg("cyc e:%d offset:%d\n",e,offset);
      offset*=-1;
    }
  }
  else {
    dfs(1,-1);
  }
  if (!checkall()) fail(3);
  printf("YES\n");
  for (int e=1;e<=m;e++) printf("%lld\n",vans[e]);
  //fflush(stdout);
  //checkall();
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
    readAhead(32);

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