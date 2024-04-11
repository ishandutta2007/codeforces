#define DEBUG 0

#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <complex>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <sstream>
using namespace std;

#define LL long long
#define LD long double
#define PR pair<int,int>

#define Fox(i,n) for (i=0; i<n; i++)
#define Fox1(i,n) for (i=1; i<=n; i++)
#define FoxI(i,a,b) for (i=a; i<=b; i++)
#define FoxR(i,n) for (i=(n)-1; i>=0; i--)
#define FoxR1(i,n) for (i=n; i>0; i--)
#define FoxRI(i,a,b) for (i=b; i>=a; i--)
#define Foxen(i,s) for (auto i:s)
#define Min(a,b) a=min(a,b)
#define Max(a,b) a=max(a,b)
#define Sz(s) int((s).size())
#define All(s) (s).begin(),(s).end()
#define Fill(s,v) memset(s,v,sizeof(s))
#define pb push_back
#define mp make_pair
#define x first
#define y second

template<typename T> T Abs(T x) { return(x < 0 ? -x : x); }
template<typename T> T Sqr(T x) { return(x * x); }
string plural(string s) { return(Sz(s) && s[Sz(s) - 1] == 'x' ? s + "en" : s + "s"); }

const int INF = (int)1e9;
const LD EPS = 1e-12;
const LD PI = acos(-1.0);

//#if DEBUG
#define GETCHAR getchar
/*#else
#define GETCHAR getchar_unlocked
#endif*/

bool Read(int& x) {
  char c, r = 0, n = 0;
  x = 0;
  for (;;) {
    c = GETCHAR();
    if ((c < 0) && (!r))
      return(0);
    if ((c == '-') && (!r))
      n = 1;
    else if ((c >= '0') && (c <= '9'))
      x = x * 10 + c - '0', r = 1;
    else if (r)
      break;
  }
  if (n)
    x = -x;
  return(1);
}

bool ReadLL(LL& x) {
  char c, r = 0, n = 0;
  x = 0;
  for (;;) {
    c = GETCHAR();
    if ((c < 0) && (!r))
      return(0);
    if ((c == '-') && (!r))
      n = 1;
    else if ((c >= '0') && (c <= '9'))
      x = x * 10 + c - '0', r = 1;
    else if (r)
      break;
  }
  if (n)
    x = -x;
  return(1);
}

#define MOD 1000000007
#define LIM 100005

int T, N, M, K, Q;
LL V[LIM];

#define TVAL pair<LL,LL>
#define TLAZY LL
#define TLIM 1100000
#define LAZY 0

TVAL ZERO_VAL = mp((LL)1e18, -(LL)1e18);
TLAZY ZERO_LAZY = 0;

struct SegTree
{
  void UpdateValForUpdateOrLazy(TVAL& a, TLAZY v)
  {
    Min(a.x, v);
    Max(a.y, v);
  }

  void UpdateLazyForUpdateOrLazy(TLAZY& a, TLAZY v)
  {
    a = v;
  }

  TVAL CombVals(TVAL v1, TVAL v2)
  {
    return(mp(min(v1.x, v2.x), max(v1.y, v2.y)));
  }

  int N, sz;
  TVAL tree[TLIM];
  TLAZY lazy[TLIM];

  SegTree() {}

  SegTree(int _N)
  {
    Init(_N);
  }

  void Init(int _N)
  {
    N = _N;
    for (sz = 1; sz < N; sz <<= 1);
    Clear();
  }

  void Clear()
  {
    int i;
    Fox(i, sz << 1)
      tree[i] = ZERO_VAL;
    if (!LAZY)
      return;
    Fox(i, sz << 1)
      lazy[i] = ZERO_LAZY;
  }

  void Prop(int i)
  {
    if (!LAZY)
      return;
    TLAZY v = lazy[i];
    lazy[i] = ZERO_LAZY;
    UpdateValForUpdateOrLazy(tree[i], v);
    if (i < sz)
    {
      int c1 = i << 1, c2 = c1 + 1;
      UpdateLazyForUpdateOrLazy(lazy[c1], v);
      UpdateLazyForUpdateOrLazy(lazy[c2], v);
    }
  }

  void Comp(int i)
  {
    int c1 = i << 1, c2 = c1 + 1;
    tree[i] = CombVals(tree[c1], tree[c2]);
  }

  TVAL Query(
    int a, int b,
    int i = 1, int r1 = 0, int r2 = -1
  ) {
    if (r2 < 0)
    {
      Max(a, 0);
      Min(b, sz - 1);
      if (a > b)
        return ZERO_VAL;
      r2 = sz - 1;
    }
    Prop(i);
    if (a <= r1 && r2 <= b)
      return(tree[i]);
    int m = (r1 + r2) >> 1, c = i << 1;
    TVAL ret = ZERO_VAL;
    if (a <= m)
      ret = CombVals(ret, Query(a, b, c, r1, m));
    if (b > m)
      ret = CombVals(ret, Query(a, b, c + 1, m + 1, r2));
    return(ret);
  }

  void Update(
    int a, int b,
    TLAZY v,
    int i = 1, int r1 = 0, int r2 = -1
  ) {
    if (r2 < 0)
    {
      Max(a, 0);
      Min(b, sz - 1);
      if (a > b)
        return;
      r2 = sz - 1;
    }
    if (r2 < 0)
      r2 = sz - 1;
    Prop(i);
    if (a <= r1 && r2 <= b)
    {
      UpdateLazyForUpdateOrLazy(lazy[i], v);
      Prop(i);
      return;
    }
    int m = (r1 + r2) >> 1, c = i << 1;
    if (a <= m)
      Update(a, b, v, c, r1, m);
    if (b > m)
      Update(a, b, v, c + 1, m + 1, r2);
    if (LAZY)
      Prop(c), Prop(c + 1), Comp(i);
  }

  void UpdateOne(int i, TLAZY v) {
    i += sz;
    UpdateValForUpdateOrLazy(tree[i], v);
    while (i > 1)
    {
      i >>= 1;
      Comp(i);
    }
  }
};

int main() {
  if (DEBUG)
    freopen("in.txt", "r", stdin);
  int i, j, k;
  Read(N), Read(Q);
  Fox1(i, N)
    ReadLL(V[i]);
  Fox1(i, N)
    Read(k), V[i] -= k;
  SegTree ST(N + 1);
  Fox(i, N + 1)
  {
    if (i)
      V[i] += V[i - 1];
    ST.UpdateOne(i, V[i]);
  }
  while (Q--)
  {
    Read(i), Read(j);
    if (V[j] != V[i - 1])
    {
    Imp:;
      printf("-1\n");
      continue;
    }
    auto p = ST.Query(i, j);
    p.x -= V[i - 1];
    p.y -= V[i - 1];
    if (p.y > 0)
      goto Imp;
    cout << -p.x << endl;
  }
  return(0);
}