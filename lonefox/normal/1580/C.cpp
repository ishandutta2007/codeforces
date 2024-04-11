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
#define LIM 200005
#define MAG 500

int T, N, M, K;
int X[LIM], Y[LIM], C[LIM];
int freq[MAG + 1][MAG];
int ans[LIM], add[LIM], off[LIM];
vector<int> ind[LIM];

int main() {
  if (DEBUG)
    freopen("in.txt", "r", stdin);
  int i, j, k, o, a, b;
  Read(N), Read(M);
  Fox(i, N)
    Read(X[i]), Read(Y[i]), C[i] = X[i] + Y[i];
  Fox(i, M)
  {
    Read(o), Read(a), a--;
    int c = C[a];
    if (c <= MAG)
    {
      int m = o == 1 ? 1 : -1;
      int z = i;
      if (o == 1)
        off[a] = z;
      else
        z = off[a];
      Fox(j, Y[a])
      {
        k = X[a] + j + z;
        k = (k % c + c) % c;
        freq[c][k] += m;
      }
    }
    else
      ind[a].pb(i);
    Fox1(j, MAG)
      ans[i] += freq[j][i % j];
  }
  Fox(i, N)
    for (j = 0; j < Sz(ind[i]); j += 2)
    {
      b = j == Sz(ind[i]) - 1 ? M : ind[i][j + 1];
      a = ind[i][j] + X[i];
      while (a < b)
      {
        int a2 = min(b, a + Y[i]);
        add[a]++;
        add[a2]--;
        a += C[i];
      }
    }
  j = 0;
  Fox(i, M)
  {
    j += add[i];
    printf("%d\n", ans[i] + j);
  }
  return(0);
}