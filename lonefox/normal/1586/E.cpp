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
#define LIM 300005

int N, M, K;
vector<int> con[LIM], ch[LIM];
bool vis[LIM];
int dep[LIM], par[LIM];
bool W[LIM];
vector<int> strt[LIM], End[LIM];

void rec(int i, int p)
{
  vis[i] = 1;
  par[i] = p;
  if (p >= 0)
    dep[i] = dep[p] + 1;
  Foxen(c, con[i])
    if (!vis[c])
    {
      ch[i].pb(c);
      rec(c, i);
    }
}

int ans;

int rec2(int i, int e)
{
  Foxen(c, ch[i])
  {
    if (W[c])
    {
      int e2 = rec2(c, 0);
      if (e && e2)
        ans--, e = 0;
      else if (!e && !e2)
        ans++, e = 1;
      else
        e = e2;
    }
    else
      rec2(c, 0);
  }
  return(e);
}

int main() {
  if (DEBUG)
    freopen("in.txt", "r", stdin);
  int i, j, k;
  Read(N), Read(M);
  while (M--)
  {
    Read(i), Read(j), i--, j--;
    con[i].pb(j);
    con[j].pb(i);
  }
  rec(0, -1);
  Read(K);
  Fox(i, K)
  {
    Read(j), Read(k), j--, k--;
    strt[i].pb(j);
    End[i].pb(k);
    while (j != k)
    {
      if (dep[j] > dep[k])
      {
        W[j] = !W[j];
        j = par[j];
        if (j != k)
          strt[i].pb(j);
      }
      else
      {
        W[k] = !W[k];
        k = par[k];
        if (j != k)
          End[i].pb(k);
      }
    }
  }
  bool good = 1;
  Fox(i, N)
    if (W[i])
      good = 0;
  if (good)
  {
    printf("YES\n");
    Fox(i, K)
    {
      printf("%d\n", Sz(strt[i]) + Sz(End[i]));
      reverse(All(End[i]));
      Foxen(v, strt[i])
        printf("%d ", v + 1);
      Foxen(v, End[i])
        printf("%d ", v + 1);
      printf("\n");
    }
    return(0);
  }
  printf("NO\n");
  rec2(0, 0);
  printf("%d\n", ans);
  return(0);
}