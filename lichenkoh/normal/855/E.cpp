#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
//const int MOD=1000000007;
#define endl "\n"
#define fst first
#define snd second
const int UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
//#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif

const int MAXFACT=100+4;
typedef unsigned long long ull;
ull binom[MAXFACT+1][MAXFACT+1];
void init() {
  for (int i = 0; i <= MAXFACT; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      // Base Cases
      if (j == 0 || j == i)
        binom[i][j] = 1;

        // Calculate value using previosly stored values
      else
        binom[i][j] = binom[i-1][j-1] + binom[i-1][j];
    }
  }
}


const int md=11;
const ll llim=(1000LL*1000LL*1000LL)*(1000LL*1000LL*1000LL)+1;
const int MS=66;
const int mz=1<<10;
ull df[2][MS];
ull es[md][mz][MS];
//ull ez[md][MS];
int vspacelim[md];
void initd(int d) {
  int spacelim=0;
  ll have=1;
  while(1) {
    ll res;
    bool ovf=__builtin_smulll_overflow(have,(ll)d,&res);
    if (ovf||res>llim) break;
    spacelim++;
    have=res;
  }
  vspacelim[d]=spacelim;
  int zlim=1<<d;
  for (int z=0;z<zlim;z++) {
    int cur=0,nxt=1;
    memset(df[cur],0,sizeof df[cur]);
    df[cur][0]=1;
    for (int dig=0;dig<d;dig++) {
      memset(df[nxt],0,sizeof df[nxt]);
      int par=(z>>dig)&1;
      for (int s=0;s<=spacelim;s++) {
        for (int t=par;t<=spacelim;t+=2) {
          if (s+t>spacelim) break;
          df[nxt][s+t]+=(df[cur][s]*binom[s+t][s]);
        }
      }
      swap(cur,nxt);
    }
    for (int s=0;s<=spacelim;s++) {
      es[d][z][s]=df[cur][s];
    }
  }
  /*for (int s=1;s<=spacelim;s++) {
    ull plus=es[d][0][s];
    if (plus!=0) plus--;
    ez[d][s]=ez[d][s-1]+plus;
    if (d==2&&s<5) dbg("d:%d s:%d es:%lld plus:%lld\n",d,s,(ll)es[d][0][s],(ll)plus);
  }*/
}

void initalld() {
  for (int d=2;d<=10;d++) {
    initd(d);
  }
}

int prefix[MS];
ull solve(int d, int slen) {
  /*int slen=0;
  for (int x=MS-1;x>=0;x--) {
    if (prefix[x]!=0) {
      slen=x; break;
    }
  }
  slen++;*/
  int prez=0;
  int spaces=slen-1;
  ull ans=0;
  for (int s=slen;s>=1;s--) {
    int dig=prefix[s-1];
    int dlo=0;
    if (s==slen) dlo=1;
    for (;dlo<dig;dlo++) {
      int z=prez^(1<<dlo);
      ull got=es[d][z][spaces];
      ans+=got;
      //dbg("d:%d dig:%d dlo:%d prez:%d z:%d got:%lld\n",d,dig,dlo,prez,z,(ll)got);
    }
    spaces--;
    prez^=(1<<dig);
  }
  spaces=slen-2;
  for (int s=slen-1;s>=1;s--) {
    for (int dlo=1;dlo<d;dlo++) {
      int z=(1<<dlo);
      ull got=es[d][z][spaces];
      ans+=got;
      //dbg("PHASE d:%d dlo:%d prez:%d z:%d got:%lld\n",d,dlo,prez,z,(ll)got);
    }
    spaces--;
  }

  return ans;
}

ull go(ll lim, int d) {
  lim++;
  //dbg("lim:%lld\n",lim);
  int slen=0;
  while(lim>0) {
    int r=lim%d;
    prefix[slen++]=r;
    lim/=d;
  }
  return solve(d,slen);
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  init();
  initalld();
  int q; scanf("%d",&q);
  for (int qi=0;qi<q;qi++) {
    int d; ll l,r;
    scanf("%d%lld%lld",&d,&l,&r);
    ull lans=go(l-1,d);
    ull rans=go(r,d);
    ull final=rans-lans;
    printf("%lld\n",(ll)final);
  }
}