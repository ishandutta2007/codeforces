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
int ask(string q,int x, int y) {
  cout<<q<<" "<<x<<" "<<y<<endl<<flush;
  cout.flush();
  int ans; cin>>ans;
  return ans;
}

int ilog2(int x) {
  return 31-__builtin_clz(x);
}
int n;
vi b;
pii findSame(int mask) {
  vi h(n);
  for (int s=1;s<=n;s++) {
    int t=h[b[s]&mask];
    if (t) {
      return MP(s,t);

    }
    h[b[s]&mask]=s;
  }
  return MP(-1,-1);
}

int main() 
{
  cin>>n;
  b.resize(n+1);
  for (int x=2;x<=n;x++) {
    b[x]=ask("XOR",1,x);
  }
  int log2n=ilog2(n);
  for (int sk=0;sk<log2n;sk++) {
    vi mask(2);
    mask[0]=1U<<sk; mask[1]=~(1U<<sk);
    pii p[2];
    for (int t=0;t<2;t++) p[t]=findSame(mask[t]);
    if (p[0].fst==-1 || p[1].fst==-1) continue;
    int f0=0;
    for (int t=0;t<2;t++) {
      int AND=ask("AND",p[t].fst,p[t].snd);
      int v0=AND^b[p[t].fst];
      f0 |= (v0 & mask[t]);
    }
    cout<<"!";
    for (int x=1;x<=n;x++) {
      cout<<" " << (b[x]^f0);
    }
    cout<<endl<<flush; cout.flush();
    return 0;
  }
}