#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx,tune=native")
#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const int MOD=998244353;
#define endl "\n"
#define fst first
#define snd second
const int UNDEF = -1;
const int INF=1<<30;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#ifdef ONLINE_JUDGE
#define assert(...) /* nothing */
#endif
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();
// mt19937 rng; rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}

const int mn=2e5+4;
class UnionFind {
public:
typedef int UFTYPE;
UFTYPE ufIdentity = 0;
inline UFTYPE combine(UFTYPE x, UFTYPE y) {
  return x^y;
}
inline UFTYPE getInitialValue(int x) {
  return 0;
}
int ufParent[mn];
int rank[mn];
UFTYPE ufData[mn];
bool fail;
inline void ufreset(int x) {
  ufParent[x]=x;
  ufData[x]=getInitialValue(x);
}
inline void init(int n) {
  fail=false;
  for (int x=0;x<n;x++) ufreset(x);
}
/*int getid(int x) {
  auto it=h.find(x);
  if (it!=h.end()) {
    return it->snd;
  }
  int id=rank.size();
  ufParent.PB(id);
  rank.PB(0);
  ufData.PB(getInitialValue(x));
  h[x]=id;
  return id;
}*/
pii ffind(int x) {
  if (ufParent[x] != x) {
    auto got=ffind(ufParent[x]);
    ufParent[x] = got.fst;
    ufData[x] = combine(ufData[x],got.snd);
  }
  return MP(ufParent[x],ufData[x]);
}
void funion(int xr, int yr, int val) {
  if (xr==yr&&val!=0) fail=true;
  assert(ufParent[xr]==xr);
  assert(ufParent[yr]==yr);
  assert(ufData[xr]==0);
  assert(ufData[yr]==0);
  if (xr==yr) return;
  if (rank[xr] > rank[yr]) swap(xr,yr);
  if (rank[xr]==rank[yr]) rank[yr]++;
  ufParent[xr] = yr;
  ufData[xr]=val;
  //printf("xr:%d -> yr:%d\n",xr,yr);
}
};
UnionFind uf;
string s;
int sn;

int go(int k) {
  vi a(sn),b(k);
  int id=2;
  for (int i=0;i<(sn+1)/2;i++) {
    a[i]=id++;
    a[sn-1-i]=a[i];
  }
  for (int i=0;i<(k+1)/2;i++) {
    //cout<<k-1-i<<":"<<i<<":"<<k<<endl;
    b[i]=id++;
    if (k-1-i<k) b[k-1-i]=b[i];
  }
  int q=id;
  uf.init(q);
  uf.funion(0,1,1);
  uf.funion(b[0],1,0);
  for (int i=k;i<sn;i++) {
    if (s[i]=='1'||s[i]=='0') {
      int x=a[i];
      int bit=s[i]-'0';
      pii xr=uf.ffind(x);
      pii yr=uf.ffind(bit);
      uf.funion(xr.fst,yr.fst,xr.snd^yr.snd);
    }
  }
  for (int i=0;i<k;i++) {
    int x=a[i],y=b[i];
    pii xr=uf.ffind(x);
    pii yr=uf.ffind(y);
    if (s[i]=='1'||s[i]=='0') {
      int bit=s[i]-'0';
      uf.funion(xr.fst,yr.fst,xr.snd^yr.snd^bit);
    }
  }
  if (uf.fail) return 0;
  int zroot=uf.ffind(0).fst;
  int ans=1;
  for (int t=2;t<q;t++) {
    if (uf.ffind(t).fst==t&&t!=zroot) {
      ans*=2; ans%=MOD;
    }
  }
  return ans%MOD;
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin>>s; sn=s.length();
  ll final=0;
  for (int k=1;k<sn;k++) {
    final+=go(k);
  }
  final%=MOD;
  printf("%lld\n",final%MOD);
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