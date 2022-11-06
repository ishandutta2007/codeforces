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

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int nc,k; cin>>nc>>k;
  int np=nc*k;
  vi vc(np);
  for (int i=0;i<np;i++) cin>>vc[i];
  int overlap=(nc+k-2)/(k-1);
  vector<bool> vdone(nc+1,false);
  vpii vans(nc+1);
  vvi c2pos(nc+1);
  vi vactive;
  for (int p=0;p<np;p++) {
    int oc=vc[p];
    if (vdone[oc]) continue;
    c2pos[oc].PB(p);
    if (c2pos[oc].size()==2) {
      vactive.PB(oc);
      if (vactive.size()==overlap) {
        for (int q:vactive) {
          vans[q]=MP(c2pos[q][0],c2pos[q][1]);
          vdone[q]=true;
        }
        for (int c=1;c<=nc;c++) c2pos[c].clear();
        vactive.clear();
      }
    }
  }
      {
        for (int q:vactive) {
          vans[q]=MP(c2pos[q][0],c2pos[q][1]);
          vdone[q]=true;
        }
        for (int c=1;c<=nc;c++) c2pos[c].clear();
        vactive.clear();
      }
  for (int c=1;c<=nc;c++) {
    //assert(vans[c]!=MP(0,0));
    printf("%d %d\n",vans[c].fst+1,vans[c].snd+1);
  }
}