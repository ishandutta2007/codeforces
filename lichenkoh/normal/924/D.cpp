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
#define DEBUG_CAT
#endif
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();

//ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }
class rat {
public:
  ll nu, de;
  rat(const ll &n = 0, const ll &d = 1) {
    nu = n; de = d;
    if (de < 0) { nu = -nu; de = -de; } }
  rat operator+(const rat& b) const
  { return rat( nu*b.de+de*b.nu, de*b.de ); }
  rat operator-(const rat& b) const
  { return rat( nu*b.de-de*b.nu, de*b.de ); }
  rat operator-() { return rat(-nu, de); }
  rat operator*(const rat& b) const
  { return rat( nu*b.nu, de*b.de ); }
  rat operator/(const rat& b) const
  { return rat( nu*b.de, de*b.nu ); }
  bool operator== (const rat & b) const {return nu * b.de == b.nu * de;}
  bool operator== (const ll &k) const { return nu == k * de; }
  bool operator< (const rat& b) const { return nu * b.de < b.nu * de; }
  bool operator<= (const rat& b) const { return nu * b.de <= b.nu * de; }
  bool operator> (const rat& b) const { return nu * b.de > b.nu * de; }
  bool operator>= (const rat& b) const { return nu * b.de >= b.nu * de; }
};

template<typename T> class RemapUnique {
public:
  vector<T> v;
  void sortmakeunique(vector<T> & myvector) {
    sort(myvector.begin(), myvector.end());
    auto it = std::unique (myvector.begin(), myvector.end());
    myvector.resize( std::distance(myvector.begin(),it) );
  }
  void init(vector<T> &_inp) { // Mutates the input!
    v=_inp;
    sortmakeunique(v);
    //for (auto &w:v) printf("%d ",w); printf("ENDDII\n");
  }
  int size() {
    return v.size();
  }
  int GTE(const T &key) {
    int imin=0,imax=v.size();
    while(imin<imax) {
      int imid=(imin+imax)>>1;
      if (v[imid]<key) imin=imid+1;
      else imax=imid;
    }
    //printf("key:%d imin:%d\n",key,imin);
    return imin;
  }
};

template<int _SEGSZ> class SumSegTree {
public:
  static const int SEGSZ = _SEGSZ;  // limit for array size
  int segn=_SEGSZ;  // array size
  typedef int S;
  S t[2 * SEGSZ];
  S identity = 0;
  S combine(const S& lefts, const S& rights) {
    return lefts+rights;
  }
  void init(int n) {segn=n;}
  void build() {  // build the tree
    int n=segn;
    for (int i = n - 1; i > 0; --i) t[i] = combine(t[i<<1], t[i<<1|1]);
  }

  void sset(int p, const S& value) { // set value at position p
    int n=segn;
    for (t[p += n] = value; p >>= 1; ) t[p] = combine(t[p<<1], t[p<<1|1]);
  }

  void modify(int p, const S& value) { // modify value at position p
    int n=segn;
    p+=n;
    for (t[p] = combine(t[p],value); p >>= 1; ) t[p] = combine(t[p<<1], t[p<<1|1]);
  }

  S query(int l, int r) { // sum on interval [l, r]
    r++;
    int n=segn;
    S resl=identity, resr=identity;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) resl = combine(resl, t[l++]);
      if (r&1) resr = combine(t[--r], resr);
    }
    return combine(resl, resr);
  }
};

const int mn=2e5+4;
vi a[mn];
SumSegTree<mn> closebyl;
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(); int w=rint();
  vector<pii> inp;
  vector<rat> seed;
  for (int i=0;i<n;i++) {
    int x=rint(),v=rint();
    inp.PB(MP(x,v));
    seed.PB(rat(v-w,-x));
    seed.PB(rat(v+w,-x));
  }
  RemapUnique<rat> remap;
  remap.init(seed);
  {
    for (auto &p:inp) {
      int x=p.fst,v=p.snd;
      int l=remap.GTE(rat(v-w,-x));
      int r=remap.GTE(rat(v+w,-x));
      a[r].PB(l);
    }
    for (int x=0;x<mn;x++) sort(a[x].begin(),a[x].end(),greater<int>());
  }
  closebyl.init(remap.size());
  ll ans=0;
  for (int x=0;x<mn;x++) {
    {
      for (auto &l:a[x]) {
        int got=(closebyl.query(l,remap.size()-1));
        closebyl.modify(l, 1);
        ans+=got;
      }
    }
  }
  printf("%lld\n",ans);
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