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

struct rational_t { ll nu, de;
  rational_t(const ll &n = 0, const ll &d = 1) {
    //ll g = gcd(abs(n), abs(d)); nu = n / g; de = d / g;
    nu=n; de=d;
    if (de < 0) { nu = -nu; de = -de; } }
  rational_t operator+(const rational_t& b) const
  { return rational_t( nu*b.de+de*b.nu, de*b.de ); }
  rational_t operator-(const rational_t& b) const
  { return rational_t( nu*b.de-de*b.nu, de*b.de ); }
  rational_t operator-() { return rational_t(-nu, de); }
  rational_t operator*(const rational_t& b) const
  { return rational_t( nu*b.nu, de*b.de ); }
  rational_t operator/(const rational_t& b) const
  { return rational_t( nu*b.de, de*b.nu ); }
  bool operator== (const rational_t & b) const {return nu * b.de == b.nu * de;}
  bool operator== (const ll &k) const { return nu == k * de; }
  bool operator< (const rational_t& b) const { return nu * b.de < b.nu * de; }
  bool operator<= (const rational_t& b) const { return nu * b.de <= b.nu * de; }
  bool operator> (const rational_t& b) const { return nu * b.de > b.nu * de; }
  bool operator>= (const rational_t& b) const { return nu * b.de >= b.nu * de; }
};
using rat=rational_t;

int rint();char rch();long long rlong();
// mt19937 rng; rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=(int)v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}
int n;
int pten[6], vfortune[6];
pair<rat,int> fortuneRatio[6];

int base[6];
const int me=906;
const int md=10;
const int fsz=2*me+1;
ll f[2][fsz];
void reset(int k) {
  for (int i=0;i<fsz;i++) f[k][i]=LLONG_MIN;
}

const bool DBG=0;  //////////////////////////////

int vinitExtra[7];

ll solve(int inp) {
  int tokens=inp/3;
  int initExtra=inp-tokens*3;
  ll initFortune=0;
  for (int ip=0;ip<6;ip++) {
    int p=fortuneRatio[ip].snd;
    int take=min(3*n,tokens/pten[p]);
    base[p]=take;
    int taketen=take * pten[p];
    tokens -= taketen;
    //printf("tokens:%d taketen:%d\n",tokens,taketen);
    int fortune=vfortune[p];
    initFortune += take * ll(fortune);
  }
  initExtra += tokens * 3;
  for (int p=0;p<6;p++) {
    vinitExtra[p]= initExtra%md;
    if (DBG) printf("p:%d ex:%d\n",p,vinitExtra[p]);
    initExtra/=md;
  }

  reset(0);
  //if (initExtra >= me) {printf("initExtra:%d\n",initExtra); exit(0);}
  f[0][me+vinitExtra[0]]=0;
  if (DBG) printf("initExtra:%d initFortune:%lld vinitExtra[0]:%d\n",initExtra,initFortune,vinitExtra[0]);
  for (int p=0;p<6;p++) {
    reset((p&1)^1);
    for (int deltaE=-me;deltaE<=me;deltaE++) {
      int dig=base[p]*3 + deltaE;
      if (0<=dig && dig<=9*n) {
        int pTokens = dig / 3;
        int pRem = dig - 3 * pTokens;
        int punish = 0;
        if (pRem > 0) punish = max(0, pTokens - 3*(n-1));
        ll scoreAdd = (pTokens - punish - base[p]) * ll(vfortune[p]);
        for (int e=-me;e<=me;e++) {
          ll now=f[p&1][me+e];
          if (now==LLONG_MIN) continue;
          if ((e-deltaE)%10==0) {
            int newE=(e-deltaE)/10 + vinitExtra[p+1];
            if (-me<=newE&&newE<=me) {
              if (DBG) printf("p:%d deltaE:%d dig:%d e:%d newE:%d now:%lld scoreAdd:%lld pTokens:%d punish:%d basep:%d\n"
                ,p,deltaE,dig,e,newE,now,scoreAdd,pTokens,punish,base[p]);
              chkmax(f[(p&1)^1][me+newE], now + scoreAdd);
            }
          }
        }
      }
    }
  }
  return f[0][me] + initFortune;
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  n=rint();
  pten[0]=1;
  for (int p=1;p<6;p++) pten[p]=10*pten[p-1];
  for (int p=0;p<6;p++) {
    vfortune[p]=rint();
    fortuneRatio[p]=MP(rat(vfortune[p],pten[p]),p);
  }
  sort(fortuneRatio, fortuneRatio+6);
  reverse(fortuneRatio, fortuneRatio+6);
  int qn=rint();
  for (int qi=0;qi<qn;qi++) {
    int inp=rint();
    ll ans=solve(inp);
    printf("%lld\n",ans);
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