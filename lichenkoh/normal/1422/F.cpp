#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
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


struct mint {
  unsigned x;
  inline int _norm(int x) {
    if (x<0) x+=MOD;
    return x;
  }
  mint() : x(0) {}
  mint(signed sig) {sig=_norm(sig); x=sig;}
  mint(signed long long sig) {sig=_norm(sig%MOD); x=sig;}
  int get() const { return (int)x; }
 
  mint &operator+=(mint that) { if((x += that.x) >= MOD) x -= MOD; return *this; }
  mint &operator-=(mint that) { if((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
  mint &operator*=(mint that) { x = ((unsigned long long)x * that.x) % MOD; return *this; }
  mint &operator/=(mint that) { return *this *= that.inverse(); }

  mint &operator+=(int that) {that=_norm(that); if((x += that) >= MOD) x -= MOD; return *this; }
  mint &operator-=(int that) {that=_norm(that); if((x += MOD - that) >= MOD) x -= MOD; return *this; }
  mint &operator*=(int that) {that=_norm(that); x = ((unsigned long long)x * that) % MOD; return *this; }
  mint &operator/=(int that) {that=_norm(that); return *this *= mint(that).inverse(); }

  mint operator+(mint that) const { return mint(*this) += that; }
  mint operator-(mint that) const { return mint(*this) -= that; }
  mint operator*(mint that) const { return mint(*this) *= that; }
  mint operator/(mint that) const { return mint(*this) /= that; }

  mint operator+(int that) const { return mint(*this) += that; }
  mint operator-(int that) const { return mint(*this) -= that; }
  mint operator*(int that) const { return mint(*this) *= that; }
  mint operator/(int that) const { return mint(*this) /= that; }


  mint inverse() const {
    signed a = x, b = MOD, u = 1, v = 0;
    while(b) {
      signed t = a / b;
      a -= t * b; std::swap(a, b);
      u -= t * v; std::swap(u, v);
    }
    if(u < 0) u += MOD;
    mint res; res.x = (unsigned)u;
    return res;
  }
 
  bool operator==(mint that) const { return x == that.x; }
  bool operator!=(mint that) const { return x != that.x; }
  mint operator-() const { mint t; t.x = x == 0 ? 0 : MOD - x; return t; }
  mint operator^(unsigned long long k) const {
    // 0^0 is 1. k must be taken modulo phi(MOD) (MOD-1 if prime) and NOT MOD itself
    mint a=(*this);
    mint r = 1;
    while(k) {
      if(k & 1) r *= a;
      a *= a;
      k >>= 1;
    }
    return r;
  }
};


#define mid(L,R) ((L+R)/2)
const int presize=30000000;
using STV=mint;
const STV identity=mint(1);
struct PersistentSeg {
  STV mergeSTV(STV const& x,STV const& y) {
    return x*y;
  }
  int gc = 0,gL=-1,gR=-1;
  struct Node{ STV cnt; int L , R;
    Node()
    {
        cnt=identity;
        L = R = -1;
    }
    Node(int x,int y,STV z)
    {
        L = x;
        R = y;
        cnt = z;
    }
  };
  vector<Node> vtree;
  PersistentSeg() {
    vtree.resize(presize);
  }
  void incGc() {
    ++gc;
    if (gc>=vtree.size()) vtree.resize(gc+1024);
  }
  int init(int L, int R) {
    gL=L;gR=R; return _build(L,R);
  }

  int _build(int L , int R)
  {
      incGc();
      if(L==R)
          return gc;
      int x = gc;
      vtree[x] = Node(_build(L,mid(L,R)),_build(mid(L,R)+1,R),identity);
      return x;
  }

  int _update(int L , int R , int root , int idx , STV val)
  {
      if(L>idx || R<idx)
          return root;
      incGc();
      if(L==idx&&R==idx)
      {
          vtree[gc] = Node(-1,-1,mergeSTV(vtree[root].cnt,val));
          return gc;
      }
      int x = gc;
      vtree[x]=Node(_update(L,mid(L,R),vtree[root].L,idx,val),_update(mid(L,R)+1,R,vtree[root].R,idx,val),mergeSTV(vtree[root].cnt,val));
      return x;
  }

  int upd(int root,int pos, STV val) {
    return _update(gL,gR,root,pos,val);
  }

  STV _query(int L , int R , int root , int qe , int qr)
  {
      if(qr<L || qe>R)return identity;
      if(qe<=L && R<=qr)
          return vtree[root].cnt;
      return mergeSTV(_query(L,mid(L,R),vtree[root].L,qe,qr),
              _query(mid(L,R)+1,R,vtree[root].R,qe,qr));
  }
  STV query(int root , int ql, int qr) {
    return _query(gL,gR,root,ql,qr);
  }
};


const int MAXP=2e5+2;
bitset<MAXP+1> sieve_array;
int ap[MAXP+1];

vector<mint> pinv[MAXP+1];

void sieve() {
  sieve_array.set();
  for (int i = 0; i <= MAXP; i++) {
    ap[i]=1<<30;
  }
  sieve_array[0] = false; sieve_array[1] = false;
  int lim = (int)(ceil(sqrt(MAXP)))+2;
  for (int i = 2; i <= lim; i++) {
    if(sieve_array[i]) {
      for (int j = i*i; j <= MAXP; j+=i) {
        sieve_array[j] = false;
        ap[j]=i;
      }
    }
  }
  for (int p = 2; p <= MAXP; p++) {
    if(sieve_array[p]) {
      ap[p]=p;

      ll pe=p;
      mint invp=mint(p).inverse();
      mint invpe=invp;
      while(1) {
        pinv[p].PB(invpe);
        pe*=p;
        if (pe > MAXP) break;
        invpe *= invp;
      }
    }
  }
}

pair<int,int> factorize_dest[500];
int factorize_tmp[500];
int factorize(int x) {
  const int power=1;
  int tsz=0;
  while(x>1) {
    int p=ap[x];
    x/=p;
    factorize_tmp[tsz++]=p;
  }
  if (x>1) factorize_tmp[tsz++]=x;
  sort(factorize_tmp,factorize_tmp+tsz);
  int didx=0;
  for (int tidx=0;tidx<tsz;tidx++) {
    int p=factorize_tmp[tidx];
    if (tidx==0||p!=factorize_tmp[tidx-1]) {
      factorize_dest[didx++]=MP(p,power);
    }
    else factorize_dest[didx-1].snd+=power;
  }
  return didx;
}

PersistentSeg Seg;
vpii p2ie[MAXP];
const int mn=(1e5)+2;
int root[mn];
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  sieve();
  int n=rint();
  int seg=Seg.init(0,n-1);
  for (int r=0;r<n;r++) {
    int nump=factorize(rint());
    for (int ip=0;ip<nump;ip++) {
      int p=factorize_dest[ip].fst;
      int orige=factorize_dest[ip].snd;
      int e=orige;
      while(e>0 && p2ie[p].size()) {
        int take=min(p2ie[p].back().snd,e); e-=take;
        int prevpos=p2ie[p].back().fst;
        seg=Seg.upd(seg,prevpos, pinv[p][take-1]);
        p2ie[p].back().snd-=take;
        if (p2ie[p].back().snd==0) {
          p2ie[p].pop_back();
        }
        else break;
      }
      int ppow=p;
      for (int i=1;i<orige;i++) {
        ppow*=p;
      }
      seg=Seg.upd(seg,r,ppow);
      p2ie[p].PB(MP(r,orige));
    }
    root[r]=seg;
  }
  int qn=rint();
  int last=0;
  for (int qi=0;qi<qn;qi++) {
    int l=(rint()+last)%n;
    int r=(rint()+last)%n;
    if (l>r) swap(l,r);
    last=Seg.query(root[r],l,r).get();
    printf("%d\n",last);
    //printf("l:%d r:%d ans:%d\n",l,r,last);
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