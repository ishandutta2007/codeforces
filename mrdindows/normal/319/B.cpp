#include <bits/stdc++.h>
using namespace std;

// =============================================================================
// BEGIN template
// =============================================================================
#ifdef ONLINE_JUDGE
  #define fastio        std::ios::sync_with_stdio(false)
  #define dbg(X)
  #define _             _
#else
  #include <unistd.h>
  #define fastio
  #define dbg(X)        cerr << ">>> (" << #X << ") = (" << X << ")\n"
  #define _             << " _ " <<
#endif
#define   ff            first
#define   ss            second
#define   pb            push_back
#define   eb            emplace_back
#define   em            emplace
#define   pq            priority_queue
#define   pqmin(X)      priority_queue<X,vector<X>,greater<X>>
#define   all(X)        (X).begin(),(X).end()
#define   sci1(X)       scanf("%d",&(X))
#define   sci2(X,Y)     scanf("%d%d",&(X),&(Y))
#define   sci3(X,Y,Z)   scanf("%d%d%d",&(X),&(Y),&(Z))
#define   scl(X)        scanf("%lld",&(X))
#define   scs(X)        scanf("%s",X)
#define   flush         fflush(stdout)
#define   lg(X)         (63 - __builtin_clzll(X))
#define   LG(X)         (lg(X)+((1<<lg(X)) < (X)))
#define    rp(i,L,R)    for (ll i = L, __R = R; i <= __R; i++)
#define   rpd(i,R,L)    for (ll i = R, __L = L; __L <= i; i--)

// dps
#define DP1(type,X)\
  static type dp[X];\
  static bool mark[X];\
  auto& ans = dp[i];\
  if (mark[i]) return ans;\
  mark[i] = true;
#define DP2(type,X,Y)\
  static type dp[X][Y];\
  static bool mark[X][Y];\
  auto& ans = dp[i][j];\
  if (mark[i][j]) return ans;\
  mark[i][j] = true;
#define DP3(type,X,Y,Z)\
  static type dp[X][Y][Z];\
  static bool mark[X][Y][Z];\
  auto& ans = dp[i][j][k];\
  if (mark[i][j][k]) return ans;\
  mark[i][j][k] = true;

// overloads
#define GET_SCI(_1,_2,_3,NAME,...) NAME
#define sci(...) GET_SCI(__VA_ARGS__,sci3,sci2,sci1)(__VA_ARGS__)
#define GET_DP(_1,_2,_3,_4,NAME,...) NAME
#define DP(...) GET_DP(__VA_ARGS__,DP3,DP2,DP1)(__VA_ARGS__)

// types
typedef   long long     ll;
typedef   pair<int,int> ii;
typedef   vector<int>   vi;
typedef   vector<bool>  vb;
typedef   set<int>      si;

// constants
const ll  oo =          0x3f3f3f3f3f3f3f3fll;
const int LGN =         25;
const int MOD =         1e9+7;
const int N =           1e5+5;
// =============================================================================
// END template
// =============================================================================

int n;

// segtree
struct LOL {
  int val[4*N],lz[4*N];
  void prop(int p, int L, int R) {
    if (!lz[p]) return;
    val[p] = lz[p];
    if (L < R) lz[2*p] = lz[p], lz[2*p+1] = lz[p];
    lz[p] = 0;
  }
  void update(int i, int v, int p = 1, int L = 0, int R = n) {
    if (R < L || i < L) return;
    prop(p,L,R);
    if (R <= i) {
      val[p] = v;
      if (L < R) lz[2*p] = v, lz[2*p+1] = v;
      return;
    }
    // L <= i && i < R
    int m = (L+R)>>1;
    update(i,v,2*p,L,m), update(i,v,2*p+1,m+1,R);
    val[p] = max(val[2*p],val[2*p+1]);
  }
  int find(int v, int h = 0, int p = 1, int L = 0, int R = n) {
    if (L == R) return L;
    prop(p,L,R);
    int m = (L+R)>>1;
    prop(2*p,L,m), prop(2*p+1,m+1,R);
    int tmp = max(h,val[2*p]);
    if (v < tmp) return find(v,h,2*p,L,m);
    return find(v,tmp,2*p+1,m+1,R);
  }
} st;

int main() {
    memset(&st, 0, sizeof(LOL));
  fastio;
  sci(n);
  int a;
  sci(a);
  st.update(n,a);
  static int ev[N];
  rp(i,2,n) {
    sci(a);
    int j = st.find(a);
    st.update(j,a);
    ev[0]++;
    ev[j+1]--;
  }
  rp(i,1,n) if (ev[i] == 0) {
    printf("%d\n",i-1);
    return 0;
  }
  return 0;
}