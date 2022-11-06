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
int clim;
int f[1<<15];
vll a;

ll go(ll sig) {
  vll down(clim,-1),up(clim,-1);
  ll k=0;
  for (int c=0;c<clim;c++) {
    if (sig&(1LL<<c)) {
      down[c]=k;
      up[k]=c;
      ++k;
    }
  }
  int zlim=1<<k;
  for (int z=0;z<zlim;z++) f[z]=0;
  for (auto &x:a) {
    ll orig=x&sig;
    int z=0;
    for (int c=0;c<clim;c++) {
      if ((1LL<<c)&orig) {
        int d=down[c];
        if (d!=-1) {
          z|=1<<d;
        }
      }
    }
    ++f[z];
  }
  for (int i=0;i<k;i++) {
    for (int z=0;z<zlim;z++) {
      if (0==(z&(1<<i))) {
        f[z]+=f[z^(1<<i)];
      }
    }
  }
  int n=a.size();
  int need=(n+1)/2;
  pii best=MP(0,0);
  for (int z=0;z<zlim;z++) {
    if (f[z]>=need) {
      chkmax(best,MP(__builtin_popcount(z),z));
    }
  }
  ll final=0;
  for (int d=0;d<k;d++) {
    if (best.snd & (1LL<<d)) {
      int c=up[d];
      final|=1LL<<c;
    }
  }
  return final;
}

int main() 
{
  auto start=chrono::high_resolution_clock::now();
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n,p; cin>>n>>clim>>p;
  a.resize(n);
  vll h(clim,0);
  for (int i=0;i<n;i++) {
    string s; cin>>s;
    ll sig=0;
    for (int c=0;c<clim;c++) {
      ll got=s[c]-'0';
      sig|=got<<c;
      h[c]+=got;
    }
    a[i]=sig;
  }
  ll need=(n+1)/2;
  ll needsig=0;
  for (int c=0;c<clim;c++) {
    if (h[c]>=need) needsig|=1LL<<c;
  }
  for (int i=0;i<n;i++) {
    a[i]=a[i]&needsig;
  }
  pll best=MP(0LL,0LL);
  vi perm(n); for (int i=0;i<n;i++) perm[i]=i;
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  shuffle(perm.begin(), perm.end(), rng);
  for (int pi=0;pi<n;pi++) {
    if ((chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start).count()) > 2400) {
      break;
    }
    ll res=go(a[perm[pi]]);
    chkmax(best,MP((ll)__builtin_popcountll(res), res));
  }
  vector<char> vfinal;
  for (int c=0;c<clim;c++) {
    if (best.snd&(1LL<<c)) vfinal.PB('1');
    else vfinal.PB('0');
  }
  string sfinal=string(vfinal.begin(),vfinal.end());
  cout<<sfinal<<endl;


}