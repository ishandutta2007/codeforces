#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx,tune=native")
#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const int MOD=998244353;
#define endl "\n"
#define fst first
#define snd second
const int UNDEF = -1;
const int INF=1<<30;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
typedef vector<pii> vpii;
const int mn=1e5+4;

const int mx=mn;
int spec[mx];
class UnionFind {
  typedef int UFTYPE;
public:
  UFTYPE ufIdentity = 0;
  inline UFTYPE combine(UFTYPE x, UFTYPE y) {
    return x+y;
  }
  inline UFTYPE getInitialValue(int x) {
    return spec[x];
  }
  int ufParent[mx];
  int rank[mx];
  UFTYPE ufData[mx];
  inline void ufreset(int x) {
    ufParent[x]=x;
    ufData[x]=getInitialValue(x);
    rank[x]=0;
  }
  void init(int n) {
    for (int x=0;x<n;x++) {
      ufreset(x);
    }
  }
  int ffind(int x) {
    if (ufParent[x] != x) {
      ufParent[x] = ffind(ufParent[x]);
    }
    return ufParent[x];
  }
  void funion(int _x, int _y) {
    int xr = ffind(_x);
    int yr = ffind(_y);
    if (xr==yr) return;
    if (rank[xr] > rank[yr]) swap(xr,yr);
    if (rank[xr]==rank[yr]) rank[yr]++;
    ufParent[xr] = yr;
    ufData[yr]=combine(ufData[xr],ufData[yr]);
  }
  int getDataForPos(int x) {
    return ufData[ffind(x)];
  }
};
UnionFind uf; 
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n,m,k; cin>>n>>m>>k;
  for (int i=0;i<k;i++) {
    int x; cin>>x; spec[x]++;
  }
  vector<pair<int,pii>>v;
  for (int i=0;i<m;i++) {
    int x,y,w; cin>>x>>y>>w;
    v.PB(MP(w,MP(x,y)));
  }
  sort(v.begin(),v.end());
  int ans=v[0].fst;
  uf.init(n+1);
  for (auto &p:v) {
    int w=p.fst; int x=p.snd.fst,y=p.snd.snd;
    uf.funion(x,y);
    ans=w;
    if (uf.getDataForPos(x)==k) break;
  }
  for (int i=0;i<k;i++) printf("%d ",ans);
  exit(0);
}