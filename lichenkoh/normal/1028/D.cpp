#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx,tune=native")
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

//const int BUY=0,SELL=1;
mint f[2][2];
map<int,int> h;
pii getbs(int _sell, int lastp) {
      int b,s;
      if (_sell==0) {
        auto it=h.lower_bound(lastp+1);
        assert(it!=h.end());
        s=it->fst;
        --it;
        b=it->fst;
        assert(s>b);
      }
      else {
        auto it=h.lower_bound(lastp);
        assert(it!=h.end());
        s=it->fst;
        --it;
        b=it->fst;
        //printf("s:%d b:%d\n",s,b);
        assert(s>b);
      }
      return MP(b,s);
}


bool bok(int x) {
  return -INF<x&&x<INF;
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int lastp;
  int n; cin>>n;
  
  h[INF]=1;
  h[-INF]=1;
  int cur=0,nxt=1;
  {
    int p=-INF/2;
    lastp=p;
    f[cur][0]=1;
  }
  vector<pair<map<int,int>,int> > gr;
  {
    map<int,int> add;
    for (int zz=0;zz<n;zz++) {
      int p; string s; cin>>s>>p;
      if (s=="ADD") {
        ++add[p];
      }
      else {
        gr.PB(MP(add,p));
        add.clear();
      }
    }
    gr.PB(MP(add,-1));
  }
  mint final=0;
  for (auto &g:gr) {
    for (int i=0;i<2;i++)f[nxt][i]=0;
    int nextp=g.snd;
    auto &add=g.fst;
    pii s2bs[2];
    for (int _sell=0;_sell<2;_sell++) {
      s2bs[_sell]=getbs(_sell, lastp);
    }
    for (auto &p:add) {
      h[p.fst]+=p.snd;
    }
    for (int _sell=0;_sell<2;_sell++) {
      pii bs=s2bs[_sell];
      int b=bs.fst,s=bs.snd;
      if (nextp==-1) {
        int C=1;
        for (auto &w:add) {
          if (b<w.fst&&w.fst<s) {
            C++;
          }
        }
        mint ans=f[cur][_sell]*C;
        final+=ans;
      }
      else {
        for (int _nsell=0;_nsell<2;_nsell++) {
          pii nbs=getbs(_nsell, nextp);
          int nb=nbs.fst,ns=nbs.snd;
          int cs=min(s,ns);
          int cb=max(b,nb);
          //printf("s:%d ns:%d b:%d nb:%d cs:%d cb:%d ans:%d\n",s,ns,b,nb,cs,cb,ans.get());
          bool ok=0;
          if (_nsell==1) {
            if (b<ns&&ns<=s) ok=1;
          }
          else {
            if (b<=nb&&nb<s) ok=1;
          }
          if (!ok) continue;
          //printf("OK\n");
          int C=1;
          for (auto &w:add) {
            if (cb<w.fst&&w.fst<cs) {
              C++;
            }
          }
          mint ans=f[cur][_sell]*C;
          f[nxt][_nsell]+=ans;
        }
      }
    }
    if(nextp!=-1) {
      auto it=h.find(nextp);
      it->snd -= 1;
      if (it->snd == 0) {
        //printf("Erase:%d\n",nextp);
        h.erase(it);
      }
      lastp=nextp;
    }
    //for (int s=0;s<2;s++) printf("nextp:%d sell:%d f:%d\n",nextp,s,f[nxt][s].get());
    swap(cur,nxt);
  }
  printf("%d\n",final.get());
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