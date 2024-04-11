#ifdef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#pragma GCC optimize("Ofast")
#endif
#include "bits/stdc++.h"
#ifndef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#pragma GCC optimize("Ofast")
#endif
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
const int mn=int(1e6)+4;
template<typename T, int amaxsize> struct Prevec  {
  T a[amaxsize];
  int sz;
  void push_back(T val) {a[sz++]=val;}
  T * begin() {return &a[0];}
  T * end() {return &a[sz];}
  T operator [](int i) const {return a[i];}
  T & operator [](int i) {assert(i>=0);return a[i];}
  int size() const {return sz;}
  void clear() {sz=0;}
};

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

mint two[mn];
mint invtwo[mn];

void prep() {
  {
    mint got=1;
    for (int i=0;i<mn;i++) {
      two[i]=got;
      got=got+got;
    }
  }
  {
    mint got=(mint(2).inverse())^(mn-1);
    for (int i=mn-1;i>=0;i--) {
      invtwo[i]=got;
      got=got+got;
    }
  }  
}
const bool DBG=0;
/*
int ask(int len, int r) {
  int k=1<<(r-1);
  int ans=(len+k)>>r;
  if (DBG) {
    int cnt=0;
    for (int x=1;x<=len;x++) {
      if (__builtin_ctz(x)==r-1) ++cnt; 
    }
    printf("len:%d r:%d ans:%d cnt:%d\n",len,r,ans,cnt);
    assert(cnt==ans);
  }  
  return ans;
}*/

int askhi(int len) {
  if (len==0) return 0;
  return 32-__builtin_clz(len);
}

Prevec<char,mn> v;
const int mlogn=31-__builtin_clz(mn);
int f[mlogn+1][mn];
int vslen[mn];
mint h[mn][26];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  prep();
  int tlen,q; string s,t;
  cin>>tlen>>q>>s>>t;
  assert(t.length()==tlen);
  t.resize(tlen+1);
  for (int i=tlen;i>=1;i--) t[i]=t[i-1];
  for (int ti=1;ti<=tlen;ti++) {
    memcpy(h[ti],h[ti-1],sizeof h[0]);
    int c=t[ti]-'a';
    h[ti][c]+=invtwo[ti];
  }
  int slen=s.length();
  memset(vslen,-1,sizeof vslen);
  vslen[0]=slen;
  for (int x=1;x<=tlen;x++) {
    vslen[x]=(vslen[x-1]*2)+1;
    if (vslen[x]>mn) break;
  }

  for (int qi=0;qi<q;qi++) {
    int gk; string a; cin>>gk>>a;
    int alen=a.length();
    mint final=0;
    if (vslen[gk]!=-1&&vslen[gk]<alen) {
      printf("0\n");
      continue;
    }
    for (int psinit=0;psinit<=slen;psinit++) {
      v.clear();
      {
        bool ok=true;
        int ps=psinit;
        for (int pa=0;pa<alen;pa++) {
          //printf("init:%d pa:%d ps:%d\n",init,pa,ps);
          if (ps<slen && a[pa]!=s[ps]) {
            ok=false; break;
          }
          if (ps==slen) {
            v.PB(a[pa]);
          }
          ps++;
          if (ps>=(slen+1)) ps-=(slen+1);
        }
        //printf("init:%d ok:%d\n",init,ok);
        if (!ok) continue;
      }
      int vsz=v.size();
      //for (int i=0;i<vsz;i++) printf("%c",v[i]);
      //printf(" end v\n");
      mint ans=0;
      if (vsz==0) {
        ans=two[gk];
        //printf("psinit:%d vsz:%d ans:%d\n",psinit,vsz,ans.get());
      }
      else {
        int rmax=askhi(vsz-1);
        for (int r=1;r<=rmax;r++) {
          for (int p=0;p<vsz;p++) {
            int last=p-(1<<r);
            if (last>=0&&v[p]==v[last]) {
              f[r][p]=f[r][last]+1;
            } else {
              f[r][p]=1;
            }
          }
        }
        int prevlen=(gk==0)?0:vslen[gk-1]; if (prevlen==-1) prevlen=INF;
        int painit=slen-psinit;
        for (int s=0;s<vsz;s++) {
          int pa=painit+s*(slen+1);
          if (pa>prevlen || alen-pa-1 > prevlen) continue;
          int rlim=max(askhi(s),askhi(vsz-s-1));
          //printf("s:%d vsz-s-1:%d rlim:%d\n",s,vsz-s-1,rlim);
          assert(rlim>=0);
          //printf("pa:%d alen-pa-1:%d prevlen:%d s:%d\n",pa,alen-pa-1,prevlen,s);
          bool ok=1;
          for (int r=1;r<=rlim;r++) {
            assert(r<31);
            int down=s-(1<<(r-1));
            if (down>=0) {
              int downtimes=(down>>r)+1;
              if (DBG){
                int cnt=0;
                int last=down;
                for (int x=down;x>=0;x-=(1<<r)) {
                  cnt++;
                  last=x;
                }
                //printf("s:%d r:%d down:%d last:%d cnt:%d downtimes:%d\n",
                //  s,r,down,last,cnt,downtimes);
                assert(cnt==downtimes);
              }
              //printf("r:%d ")
              if (v[down]!=t[r] || f[r][down] < downtimes) {
                //printf("down:%d r:%d v[down]:%c t[r]:%c f[r][down]:%d\n",down,r,v[down],t[r],f[r][down]);
                ok=0;break;
              }
            }
            int up=s+(1<<(r-1));
            if (up<vsz) {
              int uptimes=((vsz-1-up)>>r) + 1;
              int uplim=up+((uptimes-1)<<r);
              if (DBG && up<vsz) {
                int steps=0;
                int last=up;
                for (int x=up;x<vsz;x+=(1<<r)) {
                  steps++;
                  last=x;
                }
                assert(steps==uptimes);
                assert(last==uplim);
              }
              if (v[up]!=t[r]) {
//                printf("up:%d r:%d\n",down,r);
                ok=0;break;
              }
              if (f[r][uplim]-f[r][up] + 1 < uptimes) {
//                printf("B up:%d r:%d\n",down,r);
                ok=0;break;
              }
            }
          }
          if (ok) {
            int c=v[s]-'a';
            mint got=(h[gk][c]-h[rlim][c]) * two[gk];
            //printf("psinit:%d vsz:%d s:%d v[s]:%c gk:%d rlim:%d got:%d\n"
            //  ,psinit,vsz,s,v[s],gk,rlim,got.get());
            ans+=got;
          } // if ok
        } // for s
      } // if vsz==0 else
      final+=ans;
    } // for init
    printf("%d\n",final.get());
  } // for qi

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