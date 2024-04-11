#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
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
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();

const int mn=604;
bitset<mn> q[mn];



map<vector<int>,int> h;
/*
int askraw(vector<int> v) {
  if (v.size()<=1) return 0;
  sort(v.begin(),v.end());
  auto it=h.find(v);
  if (it!=h.end()) return it->snd;

  int ans=0;
  for (auto &x:v) {
    for (auto &y:v) {
      if (x<y&&q[x][y]) ans++;
    }
  }

  h[v]=ans;
  return ans;
}
*/
int askraw(vector<int> v) {
  if (v.size()<=1) return 0;
  sort(v.begin(),v.end());
  auto it=h.find(v);
  if (it!=h.end()) return it->snd;
  printf("? %d\n",(int)v.size());
  for (auto &w:v) printf("%d ",w);
  printf("\n");
  fflush(stdout);
  int ans; scanf("%d",&ans);
  h[v]=ans;
  return ans;
}

int askx(int x, vector<int> v) {
  int raw=askraw(v); v.PB(x);
  int withx=askraw(v);
  return withx-raw;
}
void yes(vector<int> &v) {
  printf("Y %d\n",(int)v.size());
  for (auto &w:v) printf("%d ",w);
  printf("\n");
  fflush(stdout);
  exit(0);
}

void no(vector<int> &v) {
  printf("N %d\n",(int)v.size());
  for (auto &w:v) printf("%d ",w);
  printf("\n");
  fflush(stdout);
  exit(0);
}

int vcol[mn];
vi g[mn];

int getedge(int x, vector<int> &inp) {
  if (inp.size()==0) {
    return -1;
  }
  if (inp.size()==1) {
    int got=askx(x,inp);
    if (got>0) {
      int y=inp[0];
      g[x].PB(y); g[y].PB(x);
      return y;
    }
    else return -1;
  }
  vector<int> v[2];
  for (int i=0;i<inp.size()/2;i++) {v[0].PB(inp[i]);}
  for (int i=inp.size()/2;i<inp.size();i++) {v[1].PB(inp[i]);}
  int got=askx(x,v[0]);
  if (got>0) return getedge(x,v[0]);
  else return getedge(x,v[1]);
}

int n;
void dfs1(int x, int col) {
  vcol[x]=col;
  while(1) {
    vector<int> v; for (int i=1;i<=n;i++) if (vcol[i]==-1) v.PB(i);
    //for (auto &w:v) printf("%d ",w); printf("\n");
    int y=getedge(x,v);
    //printf("x:%d y:%d\n",x,y);
    if (y==-1) return;
    dfs1(y, col^1);
  }
}

vector<int> c2v[2];

bitset<mn> seen[2];
vector<int> st;
void dfs2(int x, int col) {
  if (seen[col^1][x]) {
    no(st);
  }
  st.PB(x);
  if (!seen[col][x]) {
    seen[col][x]=true;
    int ncol=col^1;
    for (auto &y:g[x]) {
      dfs2(y,ncol);
    }
  }
  assert(st.back()==x);
  st.pop_back();
}


bitset<mn> tmp;
void dfs3(int x) {
  if (tmp[x]) return;
  tmp[x]=true;
  for (int y=1;y<=n;y++) if (q[x][y]) dfs3(y);
}

void init() {
  ll seed=std::chrono::high_resolution_clock::now().time_since_epoch().count();
  //seed=1538953249283970216LL;
  printf("%lld\n",seed); srand(seed);
  n=rand()%20+1;
  while(1) {
    for (int x=1;x<=n;x++) for (int y=1;y<x;y++) {
      q[x][y]=q[y][x]=rand()&1;
    }
    tmp.reset();
    dfs3(1);
    if (tmp.count()==n) break;
  }
  //for (int x=1;x<=n;x++) for (int y=x+1;y<=n;y++) if (q[x][y]) printf("%d %d\n",x,y);
}


int main() 
{
  memset(vcol,-1,sizeof vcol);
  //init();
  scanf("%d",&n);



  dfs1(1,0);
  for (int x=1;x<=n;x++) {
    if(vcol[x]==-1) {
      printf("ERROR\n");
      assert(0);
    }
    c2v[vcol[x]].PB(x);
  }
  for (int c=0;c<2;c++) {
    //printf("Checking col:%d\n",c);
    int got=askraw(c2v[c]);
    if (got>0) {
      for (auto &x:c2v[c]) {
        vector<int> inp; for (auto &w:c2v[c]) if (w!=x) inp.PB(w);
        int y=getedge(x,inp);
        if (y!=-1) {
          dfs2(x,0);
          assert(-1);
        }
      }
    }
  }
  yes(c2v[0]);
}