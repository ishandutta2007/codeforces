#ifdef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx,avx2")
#pragma GCC optimize("Ofast")
#endif
#include "bits/stdc++.h"
#ifndef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#pragma GCC optimize("Ofast")
#endif
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
const int INF=1<<28;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;typedef vector<pii> vpii;typedef vector<pll> vpll;
template<typename T> void makeunique(vector<T> &vx) {sort(vx.begin(),vx.end());auto it=unique(vx.begin(),vx.end());vx.resize(std::distance(vx.begin(),it));}
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
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=(int)v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}
const int mk=3;
const int ms=1<<mk;
const int mid=6;
int enc[1<<mk];
int decr[mid];
const int mz=1<<(mid-1);
void init() {
  memset(enc,-1,sizeof enc);
  int id=0;
  enc[(1<<0)]=id++;
  enc[(1<<1)]=id++;
  enc[(1<<2)]=id++;
  enc[(1<<0)|(1<<1)]=id++;
  enc[(1<<1)|(1<<2)]=id++;
  enc[(1<<0)|(1<<1)|(1<<2)]=id++;
  assert(id==mid);
  for (int s=0;s<ms;s++) {
    if (enc[s]!=-1) {
      decr[enc[s]]=s;
    }
  }
}
int mix(int sl, int sr, int k) {
  int sig=(1<<k)-1;
  return (sl&sig) | (sr & (~sig));
}


bool has(int zl, int sl) {
  int c=enc[sl];
  if (c==-1) return 0;
  return 0!=(zl&(1<<c));
}

int trans(int zl, int zr) {
  int oz=zl|zr;
  for (int sl=0;sl<ms;sl++) {
    if (!has(zl,sl)) continue;
    for (int sr=0;sr<ms;sr++) {
      if (!has(zr,sr)) continue;
      for (int k=0;k<mk;k++) {
        int got=mix(sl,sr,k);
        //printf("sl:%d sr:%d k:%d got:%d\n",sl,sr,k,got);
        int encgot=enc[got];
        if (encgot!=-1) {
          oz|=1<<encgot;
        }
      }
    }
  }
  return oz;
}
vpii voz[mz];
void build() {
  for (int zl=0;zl<mz;zl++) {
    for (int zr=0;zr<mz;zr++) {
      int oz=trans(zl,zr);
      if (oz<mz) {
        voz[oz].PB(MP(zl,zr));
        //printf("zl:%d zr:%d oz:%d\n",zl,zr,oz);
      }
    }
  }
}

struct S {
  S() {memset(a,0,sizeof a);}
  int a[mz];
};

S identity;
class SegTree {
public:
  int segn;
  vector<S> t;
  S combine(const S& sl, const S& sr) {
    S q;
    for (int oz=0;oz<mz;oz++) {
      int ans=INF;
      for (auto &w:voz[oz]) {
        chkmin(ans, sl.a[w.fst]+sr.a[w.snd]);
      }
      q.a[oz]=ans;
    }
    return q;
  }
  void init(int n) {segn=n; t.resize(2*segn);}
  void build() {  // build the tree
    int n=segn;
    for (int i = n - 1; i > 0; --i) t[i] = combine(t[i<<1], t[i<<1|1]);
  }

  void sset(int p, const S& value) { // set value at position p
    int n=segn;
    for (t[p += n] = value; p >>= 1; ) t[p] = combine(t[p<<1], t[p<<1|1]);
  }

  S query(int l, int r) { // sum on interval [l, r]
    if (l>r) return identity;
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
SegTree seg;
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  init(); build();
  int n,q; string s; cin>>n>>q>>s;
  seg.init(n);
  for (int i=0;i<n;i++) {
    int c=s[i]-'a';
    int s=1<<enc[1<<c];
    for (int z=0;z<mz;z++) seg.t[n+i].a[z]=1;
    seg.t[n+i].a[s]=0;
  }
  seg.build();
  for (int qi=0;qi<q;qi++) {
    int pos; char rawc; cin>>pos>>rawc;
    --pos; int c=rawc-'a';
    int s=1<<enc[1<<c];
    S inp;
    for (int z=0;z<mz;z++) inp.a[z]=1;
    inp.a[s]=0;
    seg.sset(pos,inp);
    S ans=seg.query(0,n-1);
    int final=INF;
    for (int z=0;z<mz;z++) {
      chkmin(final,ans.a[z]);
    }
    printf("%d\n",final);
  }

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