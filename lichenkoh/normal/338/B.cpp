#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
//const ll UNDEF = -1;
const int INF=1e9;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

const int maxn=1e5+4;
typedef pair<int,int> pii;
int vbad[maxn];
vector<int> g[maxn];
typedef struct S {
    int val;
    S () {
      val=0;
    }
    S(const int &_val) {
      val=_val;
    }
    S operator*(const S &b) const {
      // Must be commutative
      return S(max(val,b.val));
    }
    void upd(int x) {
      /*
      The problem may require t[x]= g(\prod_{y \in neighbor(x)} t[y]).
      At this point in time, we have t[x]= \prod_{y \in neighbor(x)} t[y].
      So we now want to perform the operation t[x]=g(t[x]).
      This function performs that operation.
      */
      val++;
      if (vbad[x]) chkmax(val,0);
    }
} S;
S identity=S(-INF);
typedef struct VS {
    vector<S> prefix;
    vector<S> suffix;
    S all;
} VS;
S t[maxn];
VS vt[maxn];

void euler_init(int x, int p) {
  int numchildren=g[x].size() - ((p==-1)?0:1);
  for (auto &y:g[x]) {
    if (y==p) continue;
    euler_init(y,x);
    t[x]=t[x]*t[y];
  }
  t[x].upd(x);
  {
    S prefix=identity;
    vt[x].prefix.resize(numchildren);
    int id=0;
    for (auto &y:g[x]) {
      if (y==p) continue;
      vt[x].prefix[id]=prefix;
      prefix=prefix*t[y];
      id++;
    }
    vt[x].all=prefix;
  }
  {
    S suffix=identity;
    vt[x].suffix.resize(numchildren);
    int id=0;
    for (auto it=g[x].rbegin();it!=g[x].rend();++it) {
      int y=*it;
      if (y==p) continue;
      vt[x].suffix[id]=suffix;
      suffix=suffix*t[y];
      id++;
    }
    reverse(vt[x].suffix.begin(),vt[x].suffix.end());
  }
}

bitset<maxn> bfinal;
int gd;
void euler_vertex(int x, int p) {
  // Start vertex custom code
  //printf("x:%d p:%d val:%d\n",x,p,t[x].val);
  if (t[x].val<=gd) {
    bfinal[x]=true;
  }
  // End vertex custom code
  int yid=0;
  for (auto &y:g[x]) {
    if (y==p) continue;
    //printf("p:%d x:%d->y:%d\n",p,x,y);
    S old_tx=t[x];
    t[x]=vt[x].prefix[yid]*vt[x].suffix[yid];
    if (p!=-1) t[x]=t[x]*t[p];
    t[x].upd(x);
    S old_ty=t[y];
    t[y]=vt[y].all*t[x];
    t[y].upd(y);
    euler_vertex(y,x);
    t[y]=old_ty;
    t[x]=old_tx;
    yid++;
  }
}

int rint() {
  int x; scanf("%d",&x); return x;
}
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  bfinal.reset();
  int n=rint(),m=rint();gd=rint();
  for (int x=1;x<=m;x++) {
    int bad=rint();
    vbad[bad]=true;
  }
  for (int x=1;x<=n;x++) {
    /*if (vbad[x]) t[x].val=0;
    else t[x].val=-INF;*/
    t[x].val=-INF;
  }
  for (int i=1;i<n;i++) {
    int a=rint(),b=rint();
    g[a].PB(b); g[b].PB(a);
  }
  euler_init(1,-1);
  euler_vertex(1,-1);
  int final=bfinal.count();
  printf("%d\n",final);
}