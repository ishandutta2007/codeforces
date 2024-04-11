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
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif

// Subset increasing. Must break when sub==full
#define FORISI(sub, full) for(int sub = 0 ;; sub = (sub - (full)) & (full))

// Strict subset increasing
#define FORSSI(sub, full) for(int sub = 0 ;sub!=(full)  ; sub = (sub - (full)) & (full))
// Nonempty subset increasing
#define FORNESI(sub, full) for(int sub = 0 ;(sub = (sub - (full)) & (full))  ; )
// Nonempty subset decreasing
#define FORNESD(sub, full) for(int sub = (full) ; sub > 0 ; sub = (sub-1) & (full))

const int MAXN=1e6+4;
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

pair<ll,int> factorize_dest[64];
ll factorize_tmp[64];
map<ll,int> factorize(ll x) {
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
    ll p=factorize_tmp[tidx];
    if (tidx==0||p!=factorize_tmp[tidx-1]) {
      factorize_dest[didx++]=MP(p,1);
    }
    else factorize_dest[didx-1].snd++;
  }
  map<ll,int> h;
  for (int i=0;i<didx;i++) {
    h[factorize_dest[i].fst]=factorize_dest[i].snd;
  }
  return h;
}



const int mn=8;
const int mz=1<<mn;
ll a[mn];
map<ll, int> vh[mn];
const int INF=1<<28;
int gsmin[mz];
int vpc[mz][mn];
int f[mz][mz];
int g[mz][mn];
int final[mz];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  sieve();
  int n; scanf("%d",&n);
  for (int i=0;i<n;i++) scanf("%lld",&a[i]);
  int zlim=1<<n;
  sort(a,a+n);
  for (int r=0;r<n;r++) {
    vh[r]=factorize(a[r]);
    int got=0;
    for (auto &w:vh[r]) got+=w.snd;
  }
  for (int now=0; now<zlim;now++) {
    map<ll,int> hnow;
    for (int r=0;r<n;r++) {
      if (now&(1<<r)) {
        for (auto &w:vh[r]) hnow[w.fst]+=w.snd;
      }
    }
    for (int r=0;r<n;r++) {
      map<ll,int> hs=vh[r];
      for (auto &w:hnow) hs[w.fst]-=w.snd;
      int cost=0;
      for (auto &w:hs) {
        if (w.snd<0) {cost=INF; break;}
        cost+=w.snd;
      }
      vpc[now][r]=cost;
      //printf("now:%d r:%d cost:%d\n",now,r,cost);
    }
  }
  for (int now=0;now<zlim;now++) {
    for (int r=0;r<n;r++) {
      g[now][r]=INF;
    }
  }
  for (int r=0;r<n;r++) {
    int ans=vpc[0][r];
    if (ans>1) ans++;
    g[1<<r][r]=ans;
  }
  for (int z=0;z<zlim;z++) for (int y=0;y<zlim;y++) f[z][y]=INF;
  f[0][0]=0;
  for (int seen=1;seen<zlim;seen++) {
    FORNESI(now, seen) {
      //printf("!! seen:%d now:%d\n",seen,now);
      int best=INF;
      FORNESI(cseen, seen) {
        for (int r=0;r<n;r++) {
          int rmsk=1<<r;
          if ((rmsk&now)!=0&&(rmsk&cseen)!=0) {
            int prev=f[seen^cseen][now^(1<<r)];
            int cost=g[cseen][r];
            int cand=prev+cost;
            //printf("prev:%d cost:%d cseen:%d r:%d\n",prev,cost,cseen,r);
            if (cand<best) {
              best=cand;
            }
          }
        }
      }
      best++;
      for (int r=0;r<n;r++) {
        if ((1<<r)==now) {
          chkmin(best, g[seen][r]);
        }
      }
      //printf("seen:%d now:%d best:%d\n",seen,now,best);
      f[seen][now]=best;
      if (best<INF) {
        for (int r = 0; r < n; r++) {
          {
            int pcost = vpc[now][r];
            int ans=pcost+best;
            if (pcost>0) ans++;
            //printf("seen:%d r:%d ans:%d pcost:%d best:%d\n",seen,r,ans,pcost,best);
            if (pcost < INF) {
              //if ((seen|(1<<r))==3&&r==1) printf("@@ seen:%d r:%d ans:%d pcost:%d best:%d\n",seen,r,ans,pcost,best);
              chkmin(g[seen|(1<<r)][r], ans);
            }
          }
        }
      }
    }
  }
  for (int seen=0;seen<zlim;seen++) {
    int best=INF;
    for (int r=0;r<n;r++) {
      //printf("seen:%d r:%d g:%d\n",seen,r,g[seen][r]);
      chkmin(best, g[seen][r]);
    }
    gsmin[seen]=best;
  }
  final[0]=0;
  for (int z=1;z<zlim;z++) {
    int best=INF;
    for ( int seen = 0 ; seen = seen - z & z ; ) {
      chkmin(best, final[z^seen]+gsmin[seen]);
      //printf("z:%d seen:%d final:%d gsmin:%d best:%d\n",z,seen,final[z^seen],gsmin[seen],best);
    }
    final[z]=best;
  }
  int last=min(final[zlim-1]+1, gsmin[zlim-1]);
  printf("%d\n",last);
}