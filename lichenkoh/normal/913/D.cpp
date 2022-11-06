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
typedef vector<pii> vpii;
typedef pair<ll,int> pli;
const int mn=2e5+4;

class Fenwick {
public:
  static const int MAXN=1<<18+1;
  int t[MAXN];
  // T[i] += value
  void add(int i, int value) {
    for (; i < MAXN; i |= i + 1)
      t[i] += value;
  }
    // sum[0..i]
  int sum(int i) {
    //printf("i:%d\n",i); fflush(stdout);
    if (i<0) return 0;
    int res = 0;
    for (; i >= 0; i = (i & (i + 1)) - 1)
      res += t[i];
    return res;
  }

  void sset(int i, int value) {
    int orig = sum(i)-sum(i-1);
    add(i,value-orig);
  }
};
class SumSegTree {
public:
  static const int MAXSEG = 1<<18; // Must be power of 2
  int segn=MAXSEG;  // array size
  typedef ll S;
  S t[2 * MAXSEG];
  S identity = 0;
  S combine(const S& lefts, const S& rights) {
    return lefts+rights;
  }
  void build() {  // build the tree
    int n=segn;
    for (int i = n - 1; i > 0; --i) t[i] = combine(t[i<<1], t[i<<1|1]);
  }

  void modifyset(int p, const S& value) { // set value at position p
    int n=segn;
    for (t[p += n] = value; p >>= 1; ) t[p] = combine(t[p<<1], t[p<<1|1]);
  }
  void modify(int p, const S&value) {
    //printf("Modify:%d %d\n",p,value);
    modifyset(p, combine(value,t[p+segn]));
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

  int fatleast(int atleast, int l, int r, int p) {
    // Finds leftmost idx with sum at least atleast
    if (l+1==r) return l;
    int m=(l+r)>>1;
    if (atleast <= t[p<<1]) {
      return fatleast(atleast, l, m, p<<1);
    }
    else {
      return fatleast(atleast-t[p<<1], m, r, (p<<1)|1);
    }
  }

  int gatleast(int atleast) {
    return fatleast(atleast,0,segn,1);
  }
};
Fenwick fen;
SumSegTree st;

int va[mn],vt[mn];
vi t2id[mn];
vi a2id[mn];
int g2id[mn];
int id2g[mn];
vpii a2ti[mn];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),T=rint();
  vpii vti;
  for (int i=0;i<n;i++) {
    int a=rint(); int t=rint();
    va[i]=a; vt[i]=t;
    vti.PB(MP(t,i));
    a2id[a].PB(i);
    a2ti[a].PB(MP(t,i));
  }
  sort(vti.begin(),vti.end());
  for (int g=0;g<n;g++) {
    g2id[g]=vti[g].snd;
  }
  for (int x=0;x<n;x++) {
    id2g[g2id[x]]=x;
  }
  pii final=MP(0,0);
  for (int a=n;a>=1;a--) {
    for (auto &id:a2id[a]) {
      int g=id2g[id];
      fen.add(g,1);
      st.modifyset(g,vt[id]);
      //printf("id:%d a:%d t:%d\n",id,va[id],vt[id]);
    }
    int idx=st.gatleast(T+1)-1;
    //printf("idx:%d T:%d\n",idx,T);
    {
      int score=fen.sum(idx);
      //printf("a:%d score:%d\n",a,score);
      chkmax(final,MP(min(a,score),a));
    }
  }
  //printf("final.snd:%d\n",final.snd);
  printf("%d\n%d\n",final.fst,final.fst);
  vpii v;
  for (int a=n;a>=final.snd;a--) {
    for (auto &t:a2ti[a]) v.PB(t);
  }
  sort(v.begin(),v.end());
  for (int i=0;i<final.fst;i++) {
    //printf("%d %d\n",v[i].fst,v[i].snd);
    printf("%d ",v[i].snd+1);
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