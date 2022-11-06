#ifdef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
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
const int MOD=998244353;
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


const int mn=404;
int n;
vi g[mn];
int vdist[mn][mn];
vi d2v[mn][mn];
void bfs(int init) {
  queue<int> q;
  vdist[init][init]=0;
  q.push(init);
  while(!q.empty()) {
    int x=q.front(); q.pop();
    int ndist=vdist[init][x]+1;
    for (auto &y:g[x]) {
      if (vdist[init][y]==INF) {
        vdist[init][y]=ndist;
        q.push(y);
      }
    }
  }
  for (int x=1;x<=n;x++) {
    d2v[init][vdist[init][x]].PB(x);
  }
}

vi getPath(int s, int t) {
  vi vans;
  int x=s;
  vans.PB(s);
  while(x!=t) {
    int goody=-1;
    for (auto &y:g[x]) {
      if (vdist[s][y]==vdist[s][x]+1 && vdist[t][y]==vdist[t][x]-1) {
        if (goody!=-1) {vans.clear(); return vans;}
        goody=y;
      }
    }
    if (goody==-1) {
      assert(false);
      vans.clear(); return vans;
    }
    vans.PB(goody);
    x=goody;
  }
  return vans;
}


//int td2cnt[mn];
int v2td[mn];
mint solve(int s, int t) {
  //printf("s:%d t:%d\n",s,t);
  vi pathST=getPath(t,s);
  if (pathST.size()==0) return 0;
  //memset(td2cnt,0,sizeof td2cnt);
  memset(v2td,-1,sizeof v2td);
  {
    int k=pathST.size();
    for (int td=0;td<k;td++) {
      int x=pathST[td];
      //++td2cnt[x];
      v2td[x]=td;
    }
  }
  mint final=1;
  for (int td=0;td<=n;td++) {
    for (auto &x:d2v[t][td]) {
      if (v2td[x]==-1) {
        int good=0;
        for (auto &p:g[x]) {
          if (v2td[p]!=-1 && v2td[p]==vdist[t][x]-1 && vdist[s][p]==vdist[s][x]-1) {
            //printf("%d ",p);
            good++;
          }
        }
        //printf(" are good parents for x:%d\n",x);
        if (good==0) return 0;
        final*=good;
        v2td[x]=vdist[t][x];
      }
    }
  }
  return final;
}

int vfinal[mn][mn];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  n=rint(); int m=rint();
  for (int x=1;x<=n;x++) for (int y=1;y<=n;y++) vdist[x][y]=INF;
  for (int i=0;i<m;i++) {
    int x=rint(); int y=rint();
    g[x].PB(y); g[y].PB(x);
  }
  for (int x=1;x<=n;x++) bfs(x);
  for (int x=1;x<=n;x++) for (int y=1;y<=x;y++) vfinal[x][y]=solve(x,y).get();
  for (int x=1;x<=n;x++) {
    for (int y=1;y<=n;y++) {
      int ans=vfinal[max(x,y)][min(x,y)];
      printf("%d ",ans);
    }
    printf("\n");
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