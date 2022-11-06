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
const int mn=(2e5)+4;

template<int _SEGSZ> class RangeSegTree {
public:
  static const int SEGSZ = _SEGSZ;  // limit for array size
  int segn=_SEGSZ;  // array size
  typedef int S;
  S t[2 * SEGSZ];
  S identity = -INF;
  S combine(const S& lefts, const S& rights) {
    return max(lefts,rights);
  }
  void init(int n) {segn=n; memset(t,0,sizeof t);}
  void modify(int l, int r, const S& value) {
    r++;
    int n=segn;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) {
        t[l] = combine(t[l], value);
        l++;
      }
      if (r&1) {
        --r;
        t[r] = combine(t[r], value);
      }
    }
  }

  S query(int p) {
    int n=segn;
    S res = identity;
    for (p += n; p > 0; p >>= 1) res = combine(res, t[p]);
    return res;
  }
  void push() {
    int n=segn;
    for (int i = 1; i < n; ++i) {
      t[i<<1] = combine(t[i<<1], t[i]);
      t[i<<1|1] = combine(t[i<<1|1], t[i]);
      t[i] = identity;
    }
  }
};
RangeSegTree<mn> seg;
int vl[mn],vh[mn],a[mn],b[mn];
void fail() {
  printf("NO\n"); exit(0);
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(); int qn=rint();
  for (int i=1;i<=n;i++) {
    a[i]=rint();
  }
  for (int i=0;i<mn;i++) {vl[i]=INF; vh[i]=-INF;}
  vl[1]=1; vh[1]=n;
  for (int i=1;i<=n;i++) {
    chkmin(vl[a[i]],i);
    chkmax(vh[a[i]],i);
  }
  seg.init(mn);
  for (int q=1;q<=qn;q++) {
    if (vl[q]!=INF) {
      seg.modify(vl[q],vh[q],q);
    }
  }
  for (int i=1;i<=n;i++) {
    b[i]=seg.query(i);
    if (a[i]!=0&&b[i]!=a[i]) {
      fail();
    }
  }
  bool hasqn=0;
  for (int i=1;i<=n;i++) if (b[i]==qn) hasqn=true;
  if (!hasqn) {
    bool found=0;
    for (int i=1;i<=n;i++) {
      if (a[i]==0&&!found) {
        b[i]=qn;
        found=true;
        break;
      }
    }
    if (!found) fail();
  }
  printf("YES\n");
  for (int i=1;i<=n;i++) printf("%d ",max(1,b[i]));
  printf("\n");
}

int rint()
{
  int x; scanf("%d",&x); return x;
}