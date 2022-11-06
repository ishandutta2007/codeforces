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

int ilog2(ll x) {return 63-__builtin_clzll(x);}

struct Op {
  Op(char _t, ll _x, ll _y): t(_t),x(_x),y(_y) {}
  char t; ll x; ll y;
};
vector<Op> vfinal;

void mul(ll x, ll k) {
  ll origk=k;
  ll r=0;
  ll a=x;
  while(k) {
    if(k & 1) {
      vfinal.PB(Op('+',r,a));
      r += a;
    }
    vfinal.PB(Op('+',a,a));
    a += a;
    k >>= 1;
  }
  assert(r==x*origk);
}

pii f(int x) {
  if (x==(1<<(1+ilog2(x))) - 1) {
    return MP(-1,-1);
  }
  ll x2=x*(ll)x;
  ll C=x*x2;
  for (int a=x;a>=1;a--) {
    // C=a*x2
    ll D=C+x;
    ll r=C^D;
    ll s=r^x;
    if (0<s && s<x) {
      return MP(a,s);
    }
    C-=x2;
  }
  assert(0);
}


int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int x; cin>>x;
  while(x!=1) {
    pii fgot=f(x);
    if (fgot.fst==-1) {
      vfinal.PB(Op('+',x,x));
      vfinal.PB(Op('^',x,2*x));
      vfinal.PB(Op('+',x,(x^(2*x))));
      vfinal.PB(Op('+',x,2*x));
      vfinal.PB(Op('^', ((x^(2*x))+x),(3*x) ));
      x=((x^(2*x))+x)^(3*x);
    } else {
      int a=fgot.fst;
      mul(x,a*(ll)x);
      ll ax2=a*(ll)x*(ll)x;
      vfinal.PB(Op('+',ax2,x));
      ll r=ax2^(ax2+x);
      vfinal.PB(Op('^',ax2,ax2+x));
      ll s=x^r;
      vfinal.PB(Op('^',x,r));
      assert(s==fgot.snd);
      int diff=ilog2(x)-ilog2(s);
      mul(s,1<<diff);
      s = s<<diff;
      vfinal.PB(Op('^',x,s));
      assert((x^s) < x);
      x=x^s;
    }
  }
  int cnt=0;
  for (auto &w:vfinal) {
    if (w.x && w.y) cnt++;
  }
  printf("%d\n",cnt);
  for (auto &w:vfinal) {
    if (w.x && w.y) printf("%lld %c %lld\n",w.x,w.t,w.y);
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