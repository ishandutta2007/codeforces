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
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
// mt19937 rng; rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}
int n;
void goEven() {
  printf("First\n");
  for (int i=1;i<=n;i++) printf("%d ",i);
  for (int i=1;i<=n;i++) printf("%d ",i);
  printf("\n");
  fflush(stdout);
  exit(0);
}
const int mn=500001;
bitset<2*mn> b;
bitset<2*mn> anti;
pii prevdc[2*mn];
int slim;

void badd(int d, int c) {
  //printf("badd d:%d c:%d\n",d,c);
  int k=(d*(ll)c)%(2*n);
  bitset<2*mn> shifted=(b<<k) | (b>>(2*n-k));
  bitset<2*mn> fresh = shifted&(~b);
  b|=fresh;
  for (int i=fresh._Find_first(); i < fresh.size(); i = fresh._Find_next(i)) {
    prevdc[i]=MP(d,c);
  }
}

void fastKnap(int d, int cnt) {
  //printf("knap d:%d cnt:%d\n",d,cnt);
  for (int j = 0;; j++) {
    if ((1<<j) <= cnt) {
      cnt -= (1<<j);
      badd(d,1<<j);
    } else {
      break;
    }
  }
  if (cnt > 0) badd(d,cnt);
}

int g[mn+1][2];
int d2cnt[2*mn];

int d2need[2*mn];
vi d2p[2*mn];
bitset<mn+1> usehi;
void succeed(int last) {
  //printf("succeed last:%d\n",last);
  if (last!=-1) ++d2need[2*n-last];
  int x=0;
  while(1) {
    pii dc=prevdc[x];
    if (dc.fst==0) break;
    int d=dc.fst,c=dc.snd;
    //printf("succeed d:%d c:%d x:%d\n",d,c,x);
    d2need[d]+=c;
    int k=(d*(ll)c)%(2*n);
    x=(x+2*n-k)%(2*n);
  }
  for (int d=1;d<2*n;d++) {
    for (int i=0;i<d2need[d];i++) {
      usehi[d2p[d][i]]=true;
    }
  }
  for (int p=1;p<=n;p++) {
    int lo=g[p][0],hi=g[p][1];
    if (lo>hi) swap(lo,hi);
    printf("%d ",usehi[p]?hi:lo);  
  }
  printf("\n"); fflush(stdout);
  exit(0);
}

void goOdd() {
  printf("Second\n"); fflush(stdout);
  for (int x=1;x<=2*n;x++) {
    int p; scanf("%d",&p);
    if (g[p][0]==0) g[p][0]=x;
    else g[p][1]=x;
  }
  ll basesum=0;
  for (int p=1;p<=n;p++) {
    int lo=g[p][0],hi=g[p][1];
    if (lo>hi) swap(lo,hi);
    basesum += lo;
    int d=hi-lo;
    ++d2cnt[d];
    d2p[d].PB(p);
  }
  basesum%=(2*n);
  b[basesum]=true;
  if (b[0]) succeed(-1);
  vector<pii> dsplit[2];
  for (int d=1;d<2*n;d++) {
    int cnt=d2cnt[d];
    if (cnt>=slim) {
      dsplit[0].PB(MP(d,cnt));
    } else if (cnt>0) {
      dsplit[1].PB(MP(d,cnt));
    }
  }
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  for (int q=0;q<2;q++) {
    shuffle(dsplit[q].begin(), dsplit[q].end(), rng);
    for (auto &p:dsplit[q]) {
      int d=p.fst,cnt=p.snd;
      fastKnap(d,cnt);
      if (b[0]) succeed(-1);
      anti[2*n-d]=false;
      bitset<2*mn> inter=b&anti;
      if (inter.any()) {
        succeed(inter._Find_first());
      }
    }
  }
  printf("-1\n");
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  scanf("%d",&n);
  slim=max(1,(int)sqrt((ld)n));
  if (n%2==0) goEven();
  else goOdd();
  fflush(stdout);
}