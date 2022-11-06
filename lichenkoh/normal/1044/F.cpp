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
// mt19937 rng; rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}
typedef int STD;
typedef int STV;
const STD NEUTRAL_STD=0;
const STV NEUTRAL_STV=0;
STD COMBINE_STD(STD x, STD y) {
  return x+y;
}
STV COMBINE_STV(STV x, STV y) {
  return x+y;
}

/*class SegTree {
public:
  int a[50000];
  void modify(int l, int r, STD delta) {
    for (int x=l;x<=r;x++) a[x]+=delta;
  }
  STV query(int l, int r) {
    STV ans=NEUTRAL_STV;
    for (int x=l;x<=r;x++) ans=COMBINE_STV(ans,a[x]);
    return ans;
  }
};*/
class SegTree {
public:
  vi sum,minval,maxval,tag; int segn;
  void init(int _segn) {
    segn=_segn;
    sum.clear();
    minval.clear();
    maxval.clear();
    tag.clear();
    sum.resize(segn*4);
    minval.resize(segn*4);
    maxval.resize(segn*4);
    tag.resize(segn*4);
  }
  bool break_condition(int node, int l, int r, int ql, int qr, STD delta) {
    if (delta==NEUTRAL_STD) return true;
    return l>qr||r<ql;
  }

  bool tag_condition(int node, int l, int r, int ql, int qr, STD delta) {
    assert(delta!=NEUTRAL_STD);
    if (!(ql<=l && r<=qr)) return false;
    if (delta>0) return !(minval[node]==0&&maxval[node]>0);
    else return !(minval[node]+delta==0&&maxval[node]+delta>0);
  }

  void puttag(int node, int l, int r, int ql, int qr, STD delta) {
    assert(delta!=NEUTRAL_STD);
    int len=r-l+1;
    if (delta>0) {
      if (maxval[node]==0) {
        sum[node]+=len;
      }
    }
    else {
      if (maxval[node]+delta==0) {
        sum[node]=0;
      }
    }
    minval[node]+=delta;
    maxval[node]+=delta;
    tag[node]+=delta;
  }

  void pushdown(int node, int l, int r, int ql, int qr) {
    if (tag[node]==NEUTRAL_STD||l==r) return;
    int mid = (l + r) >> 1;
    puttag(node * 2, l, mid, ql,qr,tag[node]);
    puttag(node * 2 + 1, mid + 1, r, ql,qr,tag[node]);
    tag[node] = NEUTRAL_STD;
  }

  void update(int node) {
    int nodeL=node*2,nodeR=node*2+1;
    minval[node]=min(minval[nodeL],minval[nodeR]);
    maxval[node]=max(maxval[nodeL],maxval[nodeR]);
    sum[node]=sum[nodeL]+sum[nodeR];
  }

  void modify(int node, int l, int r, int ql, int qr, STD delta) {
    if (break_condition(node,l,r,ql,qr,delta)) return;
    if (tag_condition(node,l,r,ql,qr,delta)) {
      puttag(node, l, r, ql, qr, delta);
      return;
    }
    pushdown(node,l,r,ql,qr);
    int mid = (l + r) >> 1;
    modify(node * 2, l, mid, ql,qr,delta);
    modify(node * 2 + 1, mid + 1, r, ql,qr,delta);
    update(node);
  }

  STV query(int node, int l, int r, int ql, int qr) {
    if (l>qr||r<ql) return NEUTRAL_STV;
    if (ql<=l && r<=qr) return sum[node];
    int mid = (l + r) >> 1;
    pushdown(node,l,r,ql,qr);
    return query(node * 2, l, mid, ql,qr) + query(node * 2 + 1, mid + 1, r, ql,qr);
  }

  void modify(int l, int r, STD delta) {
    modify(1,0,segn-1,l,r,delta);
  }
  STV query(int l, int r) {
    STV ans=query(1,0,segn-1,l,r);
    return ans;
  }

};

class HLD {
public:
  static const int mn=2e5+2;
  SegTree seg;
  vvi g;
  int sz[mn],in[mn],out[mn],rin[mn],top[mn],depth[mn],p[mn];
  int t=0;
  void dfs_sz(int v, int par, int d) {
    sz[v] = 1;
    depth[v]=d;
    p[v]=par;
    for(auto &u: g[v]) {
      if (u==par) continue;
      dfs_sz(u,v,d+1);
      sz[v] += sz[u];
      if(sz[u] > sz[g[v][0]]) {
        swap(u, g[v][0]);
      }
    }
  }
  void dfs_hld(int v, int par) {
    in[v] = t++;
    rin[in[v]] = v;
    for(auto u: g[v]) {
      if (u==par) continue;
      top[u] = (u == g[v][0] ? top[v] : u);
      dfs_hld(u,v);
    }
    out[v] = t;
  }
  void init(int root) {
    t=0;
    dfs_sz(root,-1,0); dfs_hld(root,-1);
    seg.init(t);
  }
  void modify_path(int a, int b, STD delta) {
    while(top[a]!=top[b]) {
      if (depth[top[a]] < depth[top[b]]) swap(a,b);
      seg.modify(in[top[a]], in[a], delta);
      a=p[top[a]];
    }
    if (depth[a]>depth[b]) swap(a,b);
    seg.modify(in[a],in[b],delta);
  }
  STV query_path(int a, int b) {
    STV ans=NEUTRAL_STV;
    while(top[a]!=top[b]) {
      if (depth[top[a]] < depth[top[b]]) swap(a,b);
      ans=COMBINE_STV(ans,seg.query(in[top[a]], in[a]));
      a=p[top[a]];
    }
    if (depth[a]>depth[b]) swap(a,b);
    ans=COMBINE_STV(ans, seg.query(in[a],in[b]));
    return ans;
  }
  void modify_subtree(int v, STD delta) { // Untested
    seg.modify(in[v], out[v]-1, delta);
  }
  STV query_subtree(int v) { // Untested
    return seg.query(in[v], out[v]-1);
  }
};
HLD hld;
void ae(int x, int y) {
  hld.g[x].PB(y);
  hld.g[y].PB(x);
}



// Answering LCA queries in O(1) with O(n*log(n)) preprocessing
class LcaSparseTable {
public:
  int len=0;
  int** up;
  int* tin;
  int* tout;
  int timestamp=0;
  int* vdepth;

  void dfs(vector<vector<int> > &tree, int u, int p, int depth) {
    vdepth[u] = depth;
    tin[u] = timestamp++;
    up[0][u] = p;
    for (int i = 1; i < len; i++)
      up[i][u] = up[i - 1][up[i - 1][u]];
    for (int v : tree[u])
      if (v != p)
        dfs(tree, v, u, depth+1);
    tout[u] = timestamp++;
  }

  void init(vector<vector<int> > &tree, int root) {
    int n=tree.size();
    len = 1;
    while ((1 << len) <= n) ++len;
    up = new int*[len];
    for (int i=0;i<len;i++) {up[i]=new int[n]; memset(up[i],0,sizeof(up[i][0])*n);}
    tin = new int[n]; memset(tin,0, sizeof(tin[0])*n);
    tout = new int[n]; memset(tout,0,sizeof(tout[0]*n));
    vdepth = new int[n]; memset(vdepth,0,sizeof(vdepth[0]*n));
    dfs(tree, root, root, 0);
  }

  bool isParent(int parent, int child) {
    return tin[parent] <= tin[child] && tout[child] <= tout[parent];
  }

  int getChildOfLCAIfParent(int a, int b) {
    if (isParent(a,b)) swap(a,b);
    if (isParent(b,a)) {
      for (int i = len - 1; i >= 0; i--)
        if (!isParent(up[i][a], b))
          a = up[i][a];
      return a;
    }
    return -1;
  }
};






void test() {
  ae(1,2);
  ae(2,3);
  ae(2,4);
  ae(3,5);
  ae(1,6);
  hld.init(1);
  hld.modify_path(3,6,1);
  assert(hld.query_path(3,3)==1);
  assert(hld.query_path(3,2)==2);
  hld.modify_path(1,4,2);
  hld.modify_path(5,4,4);
  hld.modify_path(3,3,8);
  assert(hld.query_path(5,3)==8+4+1+4);
  assert(hld.query_path(6,5)==1+2+1+4+2+1+8+4+1+4);
  assert(hld.query_path(4,4)==4+2);
  assert(hld.query_path(6,4)==1+2+1+4+2+1+4+2);
  assert(hld.query_subtree(6)==1);
  assert(hld.query_subtree(3)==8+4+1+4);
  assert(hld.query_subtree(2)==8+4+1+4+4+2+4+2+1);
}
LcaSparseTable lca;
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),q=rint();
  hld.g.resize(n+1);
  for (int i=1;i<n;i++) {
    int x=rint(),y=rint();
    ae(x,y);
  }
  hld.init(1);
  lca.init(hld.g,1);
  set<pii> s;
  for (int qi=0;qi<q;qi++) {
    int x=rint(),y=rint();
    if (x>y) swap(x,y);
    pii p=MP(x,y);
    auto it=s.find(p);
    if (lca.isParent(y,x)) swap(y,x);
    int z=lca.getChildOfLCAIfParent(x,y);
    if (it==s.end()) {
      s.insert(p);
      if (z!=-1) {
        hld.modify_subtree(z,1);
        hld.modify_subtree(y,-1);
      }
      else {
        hld.modify_subtree(1,1);
        hld.modify_subtree(x,-1);
        hld.modify_subtree(y,-1);
      }
    }
    else {
      s.erase(it);
      if (z!=-1) {
        hld.modify_subtree(y,1);
        hld.modify_subtree(z,-1);
      }
      else {
        hld.modify_subtree(x,1);
        hld.modify_subtree(y,1);
        hld.modify_subtree(1,-1);
      }
    }
    printf("%d\n",n-hld.query_subtree(1));
  }
}




static char stdinBuffer[1024];
static char* stdinDataEnd = stdinBuffer + sizeof (stdinBuffer);
static const char* stdinPos = stdinDataEnd;

void readAhead(size_t amount)
{
    size_t remaining = stdinDataEnd - stdinPos;
    if (remaining < amount) {
       memmove(stdinBuffer, stdinPos, remaining);
       size_t sz = fread(stdinBuffer + remaining, 1, sizeof (stdinBuffer) - remaining, stdin);
       stdinPos = stdinBuffer;
       stdinDataEnd = stdinBuffer + remaining + sz;
       if (stdinDataEnd != stdinBuffer + sizeof (stdinBuffer))
         *stdinDataEnd = 0;
    }
}

int rint()
{
    readAhead(16);

    int x = 0;
    bool neg = false;
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    if (*stdinPos == '-') {
       ++stdinPos;
       neg = true;
    }

    while (*stdinPos >= '0' && *stdinPos <= '9') {
       x *= 10;
       x += *stdinPos - '0';
       ++stdinPos;
    }

    return neg ? -x : x;
}
char rch()
{
    readAhead(16);
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    char ans=*stdinPos;
    ++stdinPos;
    return ans;
}
long long rlong()
{
    readAhead(32);

    long long x = 0;
    bool neg = false;
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    if (*stdinPos == '-') {
       ++stdinPos;
       neg = true;
    }

    while (*stdinPos >= '0' && *stdinPos <= '9') {
       x *= 10;
       x += *stdinPos - '0';
       ++stdinPos;
    }

    return neg ? -x : x;
}