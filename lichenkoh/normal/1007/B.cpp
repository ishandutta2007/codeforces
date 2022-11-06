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
#define assert(...) /* nothing */
#endif
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();


const int MAXN=1e5+4;
const int MAXP=MAXN;
bool sieve_array[MAXP+1];
int ap[MAXP+1];
vector<int> gpv;

void sieve() {
  for (int i = 0; i <= MAXP; i++) {
    sieve_array[i] = true;
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
  for (int i = 2; i <= MAXP; i++) {
    if(sieve_array[i]) {
      gpv.PB(i);
      ap[i]=i;
    }
  }
}

pair<int,int> factorize_dest[500*5];
int factorize_tmp[500*5];
int factorize(int x) {
  const int power=1;
  int tsz=0;
  while(x>=MAXP) {
    bool found=false;
    for (auto &p:gpv) {
      if (p*(ll)p>x) break;
      while ((x%p)==0) {
        //printf("x:%lld p:%d\n",x,p);
        x/=p;
        factorize_tmp[tsz++]=p;
        found=true;
      }
    }
    if (x<MAXP) break;
    if (!found) break;
  }
  if (x<MAXP) {
    while(x>1) {
      int p=ap[x];
      x/=p;
      factorize_tmp[tsz++]=p;
    }
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

//int divisors_dest[50000*2]; // This needs to be larger than you think
void getdivisors(int x, vi &divisors_dest) {
  // Puts all divisors into int divisors_dest[], and returns the count
  int numprimes=factorize(x);
  int sz=1;
  divisors_dest.PB(1);
  for (int pi=0;pi<numprimes;pi++) {
    int p=factorize_dest[pi].fst; int elim=factorize_dest[pi].snd;
    int pp=1;
    int prevsz=sz;
    for (int e=1;e<=elim;e++) {
      pp*=p;
      for (int i=0;i<prevsz;i++) {
        divisors_dest.PB(divisors_dest[i]*pp);
        sz++;
      }
    }
  }
}

inline ll cl(ll n, int l) {
  if (l==1) return n;
  else if (l==2) return (n*(n-1))/2;
  else return (n*(n-1)*(n-2))/6;
}

const int mn=MAXN;
vi vd[mn];
int inp[3];
const int ms=1<<3;
int g[ms];
const int mz=1<<ms;
int f[2][mz];
const int ml=4;
int sz2z[ms][mz][ml];
vi vz;
pii t[3][128];
vector<pii> v;
vector<pii> tmp;
int tsz[3];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  sieve();
  v.resize(128*3); tmp.resize(128*2);
  for (int z=1;z<mz;z++) if (z&(1<<(ms-1))) vz.PB(z);

  for (int ns=1;ns<ms;ns++) {
    for (int z=0;z<mz;z++) {
      for (int l=1;l<=3;l++) {
        int nz=0;
        for (int cs=0;cs<ms;cs++)  {
          if (z&(1<<cs)) {
            for (int ts=0;ts<ms;ts++) {
              if (__builtin_popcount(ts)==l) if ((ts&cs)==0 && (ts&ns)==ts) {
                nz|=1<<(cs|ts);
              }
            }
          }
        }
        sz2z[ns][z][l]=nz;
      }
    }
  }

  //pii h;
  for (int x=1;x<=100000;x++) {
    getdivisors(x,vd[x]);
    sort(vd[x].begin(),vd[x].end());
    //chkmax(h,MP((int)vd[x].size(),x));
  }
  //printf("h:%d\n",h.snd);
  int tlim=rint();
  for (int ti=0;ti<tlim;ti++) {
    for (int i=0;i<3;i++) inp[i]=rint();
    {
      memset(g,0,sizeof g);
      int vsz=0;
      for (int i=0;i<3;i++) {
        int sz=0;
        for (auto &w:vd[inp[i]]) t[i][sz++]=MP(w,1<<i);

        tsz[i]=sz;
        vsz+=sz;
      }
      auto tmpend = merge(t[0],t[0]+tsz[0],t[1],t[1]+tsz[1],tmp.begin());
      merge(tmp.begin(),tmpend,t[2],t[2]+tsz[2],v.begin());
      {
        int sig=0;
        for (int tidx=0;tidx<vsz;tidx++) {
          int p=v[tidx].fst;
          int s=v[tidx].snd;
          //printf("p:%d s:%d\n",p,s);
          if (tidx==0||p!=v[tidx-1].fst) {
            if (sig) {
              ++g[sig];
            }
            sig=s;
          }
          else sig|=s;
        }
        if (sig) ++g[sig];
      }
      memset(f[0],0,sizeof f[0]);
      f[0][1]=1;
      int nxt,cur;
      for (int s=1;s<ms;s++) {
        nxt=s&1; cur=nxt^1;
        memcpy(f[nxt],f[cur],sizeof f[0]);
        int gs=g[s];
        if(gs==0) continue;
        //printf("s:%d gs:%d\n",s,gs);
        for (int z=1;z<mz;z++) {
          int now=f[cur][z];
          if (now==0) continue;
          {
            int l=1;
            int nz=sz2z[s][z][l];
            f[nxt][nz]+=now*gs;
          }
          {
            int l=2;
            int nz=sz2z[s][z][l];
            f[nxt][nz]+=now*((gs*(gs-1))/2);
          }
          {
            int l=3;
            int nz=sz2z[s][z][l];
            f[nxt][nz]+=now*((gs*(gs-1)*(gs-2))/6);
          }
        }
      }
      ll final=0;
      for (auto &z:vz) final+=f[nxt][z];
      //printf("Dist:%lld\n",final);
      // 3 same
      final+=g[ms-1];
      //printf("same:%d\n",g[ms-1]);
      // 2 same
      {
        int s1=ms-1;
        int cand=(g[s1]*(ll)(g[s1]-1));
        final+=cand;
        //printf("g:%d candms:%d\n",g[s1],cand);
      }
      for (int s1=1;s1<ms;s1++) {
        for (int s2=s1+1;s2<ms;s2++) {
          if ((s1|s2) == ms-1) {
            int cand=g[s1]*(ll)g[s2];
            final+=cand;
            if (__builtin_popcount(s1)>1 && __builtin_popcount(s2)>1) final+=cand;
            //if (cand)printf("s1:%d s2:%d cand:%d\n",s1,s2,cand);
          }
        }
      }
      printf("%lld\n",final);
    }
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