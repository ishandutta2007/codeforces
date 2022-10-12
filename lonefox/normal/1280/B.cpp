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
#define Foxen(i,s) for (i=s.begin(); i!=s.end(); i++)
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
#define LIM 65

int R, C;
char G[LIM][LIM], tmp[LIM][LIM];

// assume sweep down from top
int GetAns()
{
  int i, j, k, a;
  // 1
  Fox(j, C) // all good? or find first bad
    if (G[0][j] != 'A')
      goto Not1;
  return(1);
  // 2
Not1:;
  FoxI(k, j, C - 1) // find next good
    if (G[0][k] == 'A')
      break;
  k--;
  if (j == 0 && k == C - 1) // all bad?
    goto Next;
  if (G[0][0] == 'A' || G[0][C - 1] == 'A') // start/end good?
    return(2);
  // 2 alt
Next:;
  FoxR(k, C) // find last bad
    if (G[0][k] != 'A')
      break;
  Fox1(i, R - 1) // need to pull up j..k
  {
    FoxI(a, j, k) // row i has good interval j..k?
      if (G[i][a] != 'A')
        goto Nope;
    return(2);
  Nope:;
  }
  // 3
  Fox(j, C) // at least one good?
    if (G[0][j] == 'A')
      return(3);
  // 4
  return(4);
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
    Read(R), Read(C);
    bool hasA = 0;
    bool hasP = 0;
    Fox(i, R)
    {
      scanf("%s", &G[i]);
      Fox(j, C)
      {
        if (G[i][j] == 'A')
          hasA = 1;
        if (G[i][j] == 'P')
          hasP = 1;
      }
    }
    // 0
    if (!hasP)
    {
      printf("0\n");
      continue;
    }
    // imp
    if (!hasA)
    {
      printf("MORTAL\n");
      continue;
    }
    // try all rots
    int ans = 4;
    Fox(z, 4)
    {
      memcpy(tmp, G, sizeof(G));
      swap(R, C);
      Fox(i, R)
      {
        Fox(j, C)
          G[i][j] = tmp[j][R - i - 1];
      }
      Min(ans, GetAns());
    }
    printf("%d\n", ans);
  }
  return(0);
}