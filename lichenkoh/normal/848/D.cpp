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
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();
const int mn=52;
int mod_pow(int a, int n, int mod) { int ret = 1; int p = a % mod; while (n) { if (n & 1) ret = (ret *(ll) p) % mod; p = (p *(ll) p) % mod; n >>= 1; } return ret; }
const int MAXFACT=52;
int fact[MAXFACT+1],invfact[MAXFACT+1];
inline int mul(int x,int y) {return (x*(ll)y)%MOD;}
void init() {
  int got=1;
  for (int x=0;x<=MAXFACT;x++) {
    fact[x]=got;
    got=mul(got,x+1);
  }
  got=mod_pow(got,MOD-2,MOD);
  for (int x=MAXFACT;x>=0;x--) {
    got=mul(got,x+1);
    invfact[x]=got;
  }
}
int dpg[mn][mn];
int h[mn][mn];
const int mc=51;
int g(int n, int f) {
  if (dpg[n][f]!=-1) {
    //printf("n:%d f:%d ans:%d\n",n,f,dpg[n][f]);
    return dpg[n][f];
  }
  int ans=0;
  for (int na=0;na<=n;na++) {
    int nb=n-na;
    for (int fa=f;fa<=mc;fa++) {
      int fb=f;
      ans=(ans + (h[na][fa]*(ll)(h[nb][fb])))%MOD;
    }
    for (int fb=f+1;fb<=mc;fb++) {
      int fa=f;
      ans=(ans + (h[na][fa]*(ll)(h[nb][fb])))%MOD;
    }
  }
  //printf("G n:%d f:%d ans:%d\n",n,f,ans);
  return dpg[n][f]=ans;
}
int binom(int n, int k) {
  if (k==0) return 1;
  if (n>k) return 0;
  int numer=n;
  for (int i=1;i<k;i++) {
    numer=mul(numer,n-i);
  }
  return mul(numer,invfact[k]);
}
int bincache[mn];
int solve(int gn, int igf) {
  int gf=mc;
  //memset(h,0,sizeof h);
  memset(dpg,-1,sizeof dpg);
  for (int f=0;f<mn;f++) {
    dpg[0][f]=0;
  }
  dpg[0][1]=1;
  h[0][1]=1;
  for (int nstep=1;nstep<=gn;nstep++) {
    for (int fstep=gf;fstep>=1;fstep--) {
      int klim=min((gn)/nstep, gf/fstep);
      int possible=g(nstep-1,fstep);
      //if(possible)printf("nstep:%d fstep:%d possible:%d klim:%d\n",nstep,fstep,possible,klim);
      int numer=possible;
      for (int k=1;k<=klim;k++) {
        int bin=mul(numer,invfact[k]);
        bincache[k]=bin;
        numer=mul(numer,possible+k);
      }
      for (int n=gn;n>=0;n--) {
        for (int f=gf;f>=0;f--) {
          int ncost=nstep,fcost=fstep;
          for (int k=1;k<=klim;k++) {
            if (n-ncost<0||f-fcost<0) break;
            int bin=bincache[k];
            int prev=h[n-ncost][f-fcost];
            ll toadd=prev*(ll)bin;
            //if(toadd) printf("n:%d f:%d prev:%d bin:%d gf:%d\n",n,f,prev,bin,gf);
            h[n][f]=(h[n][f]+toadd)%MOD;
            ncost+=nstep;
            fcost+=fstep;
          }
        }
      }
    }
  }
  return h[gn][igf];
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  init();
  //for (int flim=0;flim<mn;flim++) {
  //  for (int f=0;f<mn;f++) {
  //    dph[0][f][flim]=0;
  //  }
  //  dph[0][1][flim]=1;
  //}
  //assert(solve(0,1)==1);
  //assert(solve(1,1)==0);
  //assert(solve(1,2)==1);
  //assert(solve(2,0)==0);
  //assert(solve(2,1)==0);
  //assert(solve(2,2)==2);
  //assert(solve(2,3)==1);
  //printf("g(2,2):%d\n",g(2,2)); return 0;
  //return 0;
  int n=rint(),m=rint();
  int ans=solve(n,m);
  printf("%d\n",ans);
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