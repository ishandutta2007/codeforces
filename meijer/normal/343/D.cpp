#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

#define REP(a,b,c) for(ll a=ll(b); a<ll(c); a++)
#define RE(a,b) REP(a,0,b)
#define INF 1e18
#define pb push_back
#define fi first
#define se second

const int MX=5e5;
int n, a, b, q, c, v;
vi adjList[MX], chl[MX];
int beg[MX], order[MX], parent[MX], cur=0;
bitset<MX*4> SEG, LAZY;

void dfsChl(int u, int p) {
  parent[u] = p;
  for(int v:adjList[u])
    if(v != p)
      dfsChl(v, u), chl[u].pb(v);
}
void dfsPost(int u) {
  beg[u] = cur;
  for(int v:chl[u])
    dfsPost(v);
  order[u] = cur++;
}
void buildSeg(int p=0, int l=0, int r=n-1) {
  SEG [p] = 1;
  LAZY[p] = 0;
  if(l != r) {
    int m=(l+r)/2;
    buildSeg(p*2+1,l,m);
    buildSeg(p*2+2,m+1,r);
  }
}
void cleanInt(int i, int j, bool lazy=0, int p=0, int l=0, int r=n-1) {
  if(lazy) SEG[p] = 0, LAZY[p]=1;
  if(j<l || i>r) return;
  if(i <= l && j >= r) {
    SEG[p] = 0;
    LAZY[p] = 1;
  } else {
    int m=(l+r)/2;
    cleanInt(i,j,LAZY[p],p*2+1,l,m);
    cleanInt(i,j,LAZY[p],p*2+2,m+1,r);
    LAZY[p]=0;
    SEG [p] = (SEG[p*2+1] || SEG[p*2+2]);
  }
}
void colorVert(int i, bool lazy=0, int p=0, int l=0, int r=n-1) {
  if(lazy) SEG[p] = 0, LAZY[p]=1; 
  if(i<l || i>r) return;
  if(l == r) {
    SEG[p] = 1;
  } else {
    int m=(l+r)/2;
    colorVert(i,LAZY[p],p*2+1,l,m);
    colorVert(i,LAZY[p],p*2+2,m+1,r);
    LAZY[p] = 0;
    SEG [p] = (SEG[p*2+1] || SEG[p*2+2]);
  }
}
bool isColored(int i, int j, bool lazy=0, int p=0, int l=0, int r=n-1) {
  if(lazy) SEG[p] = 0, LAZY[p]=1; 
  if(j<l || i>r) return 0;
  if(i <= l && j >= r) return SEG[p];
  int m=(l+r)/2;
  bool A=isColored(i,j,LAZY[p],p*2+1,l,m);
  bool B=isColored(i,j,LAZY[p],p*2+2,m+1,r);
  LAZY[p] = 0;
  return A||B;
}

int main() {
  cin>>n;
  RE(i,n-1) cin>>a>>b, a--, b--, adjList[a].pb(b), adjList[b].pb(a);
  dfsChl(0,-1);
  dfsPost(0);
  buildSeg();
  
  cin>>q;
  RE(Q,q) {
    cin>>c>>v; v--;
    if(c == 1) {
      if(isColored(beg[v], order[v])) {
        if(parent[v] != -1) colorVert(order[parent[v]]);
      }
      cleanInt(beg[v], order[v]);
    }
    if(c == 2) {
      colorVert(order[v]);
    }
    if(c == 3) {
      cout<<!isColored(beg[v], order[v])<<endl;
    }
  }
}