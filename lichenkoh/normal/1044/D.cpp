#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx,tune=native")
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

class UnionFind {
public:
typedef int UFTYPE;
UFTYPE ufIdentity = 0;
inline UFTYPE combine(UFTYPE x, UFTYPE y) {
  return x^y;
}
inline UFTYPE getInitialValue(int x) {
  return 0;
}
vi ufParent;
vi rank;
vector<UFTYPE> ufData;
map<int,int> h;
inline void ufreset(int x) {
  ufParent[x]=x;
  ufData[x]=getInitialValue(x);
}
int getid(int x) {
  auto it=h.find(x);
  if (it!=h.end()) {
    return it->snd;
  }
  int id=rank.size();
  ufParent.PB(id);
  rank.PB(0);
  ufData.PB(getInitialValue(x));
  h[x]=id;
  return id;
}
pii ffind(int x) {
  if (ufParent[x] != x) {
    auto got=ffind(ufParent[x]);
    ufParent[x] = got.fst;
    ufData[x] = combine(ufData[x],got.snd);
  }
  return MP(ufParent[x],ufData[x]);
}
void funion(int xr, int yr, int val) {
  assert(ufParent[xr]==xr);
  assert(ufParent[yr]==yr);
  assert(ufData[xr]==0);
  assert(ufData[yr]==0);
  if (xr==yr) return;
  if (rank[xr] > rank[yr]) swap(xr,yr);
  if (rank[xr]==rank[yr]) rank[yr]++;
  ufParent[xr] = yr;
  ufData[xr]=val;
  //printf("xr:%d -> yr:%d\n",xr,yr);
}
};
UnionFind uf;
void handleNewSeg(int _l, int _r, int val) {
  _r++;
  int l=uf.getid(_l),r=uf.getid(_r);
  int c[2]; c[0]=l,c[1]=r;
  int p[2],v[2];
  //printf("_l:%d _r:%d l:%d r:%d val:%d\n",_l,_r,l,r,val);
  for (int t=0;t<2;t++) {
    pii got=uf.ffind(c[t]);
    p[t]=got.fst; v[t]=got.snd;
    //printf("p:%d v:%d\n",p[t],v[t]);
  }
  if (p[0]==p[1]) {
    return;
  }
  else {
    uf.funion(p[0],p[1],v[0]^v[1]^val);
  }
}
int query(int _l, int _r) {
  _r++;
  int l=uf.getid(_l),r=uf.getid(_r);
  int c[2]; c[0]=l,c[1]=r;
  int p[2],v[2];
  //printf("_l:%d _r:%d l:%d r:%d\n",_l,_r,l,r);
  for (int t=0;t<2;t++) {
    pii got=uf.ffind(c[t]);
    p[t]=got.fst; v[t]=got.snd;
    //printf("p:%d v:%d\n",p[t],v[t]);
  }
  if (p[0]==p[1]) {
    return v[0]^v[1];
  }
  else {
    return -1;
  }
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int q; cin>>q;
  int last=0;
  for (int qi=0;qi<q;qi++) {
    int t; int l,r,x;
    cin>>t;
    if (t==1) {
      cin>>l>>r>>x;
      l^=last; r^=last; x^=last;
      if (l>r) swap(l,r);
      handleNewSeg(l,r,x);
    }
    else {
      cin>>l>>r;
      l^=last; r^=last;
      if (l>r) swap(l,r);
      int ans=query(l,r);
      printf("%d\n",ans);
      last=ans;
      if (last==-1) last=1;
    }
  }
}