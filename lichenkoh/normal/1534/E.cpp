#ifdef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx,avx2")
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
// mt19937 rng; rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=(int)v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}
int n,k;

int ask(vi const& vq) {
  //assert(vq.size()==k);
  printf("?");
  for (auto &x:vq) printf(" %d",x);
  printf("\n");
  fflush(stdout);
  int ans; scanf("%d",&ans);
  return ans;
}

void done(int ans) {
  printf("! %d\n",ans);
  fflush(stdout);
  exit(0);
}

void nosol() {
  printf("-1\n");
  fflush(stdout);
  exit(0);
}

const int mn=504;
pii f[mn][mn];
int cost[mn];
void go() {
  for (int o=0;o<=n;o++) {
    int ko=k-o;
    int cand=2*ko;
    if (cand>0 && cand+o<=n) {
      cost[cand]=2;
    }
  }
  cost[k]=1;
  vpii vcost;
  for (int a=0;a<=n;a++) {
    if (cost[a]>0) vcost.PB(MP(a,cost[a]));
  }
  for (int x=1;x<mn;x++) f[0][x].fst=INF;
  for (int q=0;q<=n;q++) {
    for (int t=0;t<=n;t++) {
      pii best=MP(f[q][t].fst,0);
      for (auto &w:vcost) {
        int a=w.fst,c=w.snd;
        int s=t-a;
        if (s<0) break;
        int cand=f[q][s].fst+c;
        chkmin(best,MP(cand,a));
      }
      f[q+1][t]=best;
    }
  }
  if (f[n+1][n].fst>=INF-5) {
    nosol();
  }
  vi vop;
  {
    int t=n;
    for (int q=n+1;q>=1;q--) {
      pii best=f[q][t];
      int a=best.snd;
      if (a>0) vop.PB(a);
      t-=a;
    }
  }
  int final=0;
  int lim=1;
  for (auto &a:vop) {
    if (a==k) {
      vi vx;
      for (int x=lim;x<(lim+a);x++) vx.PB(x);
      int got=ask(vx);
      final^=got;
    } else {
      int ko=a/2;
      //assert(ko>0);
      int o=k-ko;
      //assert(o>=0);
      vi q1,q2;
      for (int x=lim;x<(lim+(a/2));x++) q1.PB(x);
      for (int x=(lim+(a/2));x<(lim+a);x++) q2.PB(x);
      //assert(q1.size()==ko);
      //assert(q2.size()==ko);
      for (int x=1;x<=n;x++) {
        if (q1.size()==k) break;
        if (!(lim<=x&&x<lim+a)) {
          q1.PB(x);
          q2.PB(x);
        }
      }
      int got1=ask(q1);
      int got2=ask(q2);
      final^=(got1^got2);
    }
    lim+=a;
  }
  //assert(lim==n+1);
  done(final);
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  scanf("%d%d",&n,&k);
  go();
}