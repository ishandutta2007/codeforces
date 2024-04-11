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
// mt19937 rng; rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}


vi findTreeCenters(vvi tree) {
    int n = tree.size();
    vi leaves;
    vi degree(n);
    for (int i = 0; i < n; i++) {
        degree[i] = tree[i].size();
        if (degree[i] <= 1) {
            leaves.PB(i);
        }
    }
    int removedLeaves = leaves.size();
    while (removedLeaves < n) {
        vi nleaves;
        for (int u : leaves) {
            for (int v : tree[u]) {
                if (--degree[v] == 1) {
                    nleaves.PB(v);
                }
            }
        }
        leaves = nleaves;
        removedLeaves += leaves.size();
    }
    return leaves;
}

void fail() {
  printf("No\n");
  exit(0);
}
void succ() {
  printf("Yes\n");
  exit(0);
}
void must(bool cond) {
  if (!cond) fail();
}
vvi g;

void dfs(int x, int p, int k) {
  int numchild=g[x].size();
  if (p!=-1) numchild--;
  if (k==0) {must(numchild==0);return;}
  if (numchild==0) {must(k==0);return;}
  must(numchild>=3);
  for (auto &y:g[x]) {
    if (y!=p) {
      dfs(y,x,k-1);
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n,k; cin>>n>>k;
  g.resize(n);
  for (int i=1;i<n;i++) {
    int x,y; cin>>x>>y; --x; --y;
    g[x].PB(y); g[y].PB(x);
  }
  vi centers=findTreeCenters(g);
  if (centers.size()!=1) fail();
  int center=centers[0];
  dfs(center,-1,k);
  succ();
}