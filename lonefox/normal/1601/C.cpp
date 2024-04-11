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
#define LIM 1000005
#define LIM2 2100000

struct BLT
{
  int N;
  vector<LL> V;

  BLT() {}

  BLT(int _N)
  {
    Init(_N);
  }

  void Init(int _N)
  {
    N = _N;
    V.resize(N + 1);
    Clear();
  }

  void Clear()
  {
    fill(All(V), 0);
  }

  void Update(int i, LL v)
  {
    for (i++; i <= N; i += (i & -i))
      V[i] += v;
  }

  LL Query(int i)
  {
    LL v = 0;
    Min(i, N - 1);
    for (i++; i > 0; i -= (i & -i))
      v += V[i];
    return(v);
  }
};

BLT B;
int S;
int X[LIM], Y[LIM];
int ind[LIM];
vector<int> C;

int Ins(int v)
{
  int r = S - B.Query(v);
  B.Update(v, 1), S++;
  return(r);
}

PR opt(int v, int a, int b)
{
  if (S > a)
  {
    printf("wtf\n");
    exit(1);
  }
  while (S < a)
    Ins(X[S]);
  int bigL = a - B.Query(v);
  int smR = 0;
  int i;
  FoxI(i, a, b - 1)
    if (X[i] < v)
      smR++;
  PR o = mp(bigL + smR, a);
  FoxI(i, a, b - 1)
  {
    if (X[i] < v)
      smR--;
    else if (X[i] > v)
      bigL++;
    Min(o, mp(bigL + smR, i + 1));
  }
  return(o);
}

void rec(int i, int j, int a, int b)
{
  int m = (i + j) >> 1;
  PR o = opt(Y[m], a, b);
  ind[m] = o.y;
  //ans += o.x;
  if (i < m)
    rec(i, m - 1, a, o.y);
  if (j > m)
    rec(m + 1, j, o.y, b);
}

int main() {
  if (DEBUG)
    freopen("in.txt", "r", stdin);
  int N, M, K;
  int i, j, k, a, b, c, x, y, z;
  int T;
  Read(T);
  while (T--)
  {
    Read(N), Read(M);
    C.clear();
    Fox(i, N)
      Read(X[i]), C.pb(X[i]);
    Fox(i, M)
      Read(Y[i]), C.pb(Y[i]);
    sort(Y, Y + M);
    sort(All(C));
    C.resize(unique(All(C)) - C.begin());
    Fox(i, N)
      X[i] = lower_bound(All(C), X[i]) - C.begin();
    Fox(i, M)
      Y[i] = lower_bound(All(C), Y[i]) - C.begin();
    B.Init(Sz(C)), S = 0;
    rec(0, M - 1, 0, N);
    /*while (S < N)
      ans += Ins(X[S]);*/
    LL ans = 0;
    B.Init(Sz(C)), S = 0;
    j = 0;
    Fox(i, N)
    {
      while (j < M && ind[j] == i)
        ans += Ins(Y[j++]);
      ans += Ins(X[i]);
    }
    while (j < M)
      ans += Ins(Y[j++]);
    cout << ans << endl;
  }
  return(0);
}