#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define endl "\n"
#define fst first
#define snd second
const int UNDEF = -1;
const int INF=1<<30;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;typedef vector<pii> vpii;
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
using uint=unsigned int;
using ush=unsigned short;
const int mn=(2e5)+4;
const int mk=3;
//37781 | 37783 | 37799 | 37811 | 37813 | 37831
const uint csig[mk]={19,29,37}; // Primitive roots
//const uint csig[mk]={2,29,37};
const uint mod[mk]={37811,37813,37831};
ush psig[mk][mn];
ush sumpsig[mk][mn];
struct S {
  int len;
  int p;
  short last;
  ush sig[mk];
  S() {};
  S(short _last):len(1),p(0),last(_last) {for (int k=0;k<mk;k++) sig[k]=0;};
  bool operator==(S const & b) {
    if (len==b.len && p==b.p && last==b.last) {
      for (int k=0;k<mk;k++) if (sig[k]!=b.sig[k]) return false;
      return true;
    }
    return false;
  }
  void print(string const & s) {
    printf("%s: len:%d p:%d last:%d sig:%d\n",s.c_str(),len,p,(int)last,(int)sig[0]);
  }
};
uint getsumpsig(int k,int l,int r) {
  if (l>r) return 0U;
  int ans=sumpsig[k][r+1]-sumpsig[k][l];
  if (ans<0) ans+=mod[k];
  //printf("l:%d r:%d ans:%d\n",l,r,ans);
  return ans;
}
S combine(const S& l, const S& r) {
  if (l.len==0) return r;
  if (r.len==0) return l;
  S ans;
  for (int k=0;k<mk;k++) ans.sig[k]=0;
  ans.len=l.len+r.len;
  if (l.p+1==l.len) {
    if (l.last) {
      ans.p = l.p+l.last+r.p;
      ans.last=r.last;
      for (int k=0;k<mk;k++) ans.sig[k]=(r.sig[k] * (uint)psig[k][l.len])%mod[k];
    } else {
      if (r.p+1==r.len) {
        int ones=r.p+r.last;
        ans.p=l.p+(ones&(~1));
        ans.last=r.last&ones;
        if ( (ones&1) && ans.last==0 ) {
          for (int k=0;k<mk;k++) ans.sig[k]=psig[k][l.len+r.p-1];
        }
      } else {
        int ones=r.p;
        ans.p=l.p+(ones&(~1));
        ans.last=r.last;
        for (int k=0;k<mk;k++) {
          ans.sig[k] = (r.sig[k] * (uint)psig[k][l.len] +
            ((ones&1)? psig[k][l.len+r.p-1]: 0)
            )%mod[k];
        }
      }
    }
  } else {
    if (r.p+1==r.len) {
      int ones=l.last+r.p+r.last;
      ans.p=l.p+(ones&(~1));
      ans.last=r.last&ones;
      bool has_mid = (1==(ones&1)) && !ans.last;
      for (int k=0;k<mk;k++) {
        ans.sig[k]=(
          l.sig[k]*(uint)psig[k][ones&(~1U)] +
          (has_mid?( psig[k][l.len+r.p-1] ):0U)
        )%mod[k];
      }

    } else {
      //printf("len:%d %d. l.len+r.p-1:%d. psig:%d\n",l.len,r.len,l.len+r.p-1,psig[0][l.len+r.p-1]);
      int ones=l.last+r.p;
      ans.p=l.p+(ones&(~1));
      ans.last=r.last;
      for (int k=0;k<mk;k++) {
        ans.sig[k]=(
          l.sig[k]*(uint)psig[k][ones&(~1U)] +
          ((ones&1)?( psig[k][l.len+r.p-1] ):0U) +
          r.sig[k]*(uint)psig[k][l.len]
        )%mod[k];
      }
    }
  }
  return ans;
}
template<int _SEGSZ> class SegTree {
public:
  static const int SEGSZ = _SEGSZ;  // limit for array size
  int segn=_SEGSZ;  // array size
  S t[2 * SEGSZ];
  S identity;
  void build(int n) {  // build the tree
    segn=n;
    identity.len=0;
    for (int i = n - 1; i > 0; --i) t[i] = combine(t[i<<1], t[i<<1|1]);
  }

  /*void sset(int p, const S& value) { // set value at position p
    int n=segn;
    for (t[p += n] = value; p >>= 1; ) t[p] = combine(t[p<<1], t[p<<1|1]);
  }*/

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

S testa(vector<S> a) {
  while(a.size()>=2) {
    vector<S> b;
    int asz=a.size();
    int k=rand()%(asz-1);
    S c=combine(a[k],a[k+1]);
    /*if (a.size()==2 && c.sig[0]!=4) {
      a[k].print("L");
      a[k+1].print("R");
      c.print("C");
    }*/
    for (int i=0;i<k;i++) b.PB(a[i]);
    b.PB(c);
    for (int i=k+2;i<asz;i++) b.PB(a[i]);
    a=b;
  }
  return a[0];
}
void testr() {
  int k=50;//rand()%4+1;
  //vector<S> a = {S(1),S(0),S(1),S(0)};
  vector<S> a; for (int i=0;i<k;i++) a.PB(S(rand()%2));
  S res=testa(a);
  for (int i=0;i<50;i++) {
    S got=testa(a);
    if (!(got==res)) {
      for (int i=0;i<k;i++) printf("%d",a[i].last);
      printf("\n");
      res.print("res");
      got.print("got");
      printf("Bad\n");
      exit(0);
    }
  }
}
SegTree<mn> seg;
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);

  for (int k=0;k<mk;k++) {
    int C=csig[k];
    int M=mod[k];
    psig[k][0]=1;
    for (int i=1;i<mn;i++) {
      psig[k][i]=(psig[k][i-1] * C)%M;
    }
    sumpsig[k][0]=0;
    for (int i=1;i<mn;i++) {
      uint sum=sumpsig[k][i-1]+psig[k][i-1];
      if (sum>=M) sum-=M;
      sumpsig[k][i]=sum;
    }
  }

  //for (int i=0;i<500;i++) testr();
  //return 0;
  
  int n=rint();
  for (int i=0;i<n;i++) {
    char c=rch();
    seg.t[n+i]=S(c-'0');
  }
  seg.build(n);
  int qn=rint();
  for (int q=0;q<qn;q++) {
    int l1=rint()-1,l2=rint()-1,len=rint()-1;
    //printf("l1:%d l2:%d len:%d\n",l1,l2,len);
    S got1=seg.query(l1,l1+len);
    //got1.print("got1");
    S got2=seg.query(l2,l2+len);
    //got2.print("got2");
    if (got1==got2) printf("Yes\n");
    else printf("No\n");
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