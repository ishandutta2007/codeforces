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
#define LIM 3005

int T, N, M, K;
int A[LIM], nxt[LIM], prv[LIM];
vector<int> P[LIM];
int dyn[LIM][LIM];

int main() {
  if (DEBUG)
    freopen("in.txt", "r", stdin);
  int i, j, k, d, m1, m2, cor;
  Read(T);
  //T = 1000;
  while (T--)
  {
    Read(N);
    //N = 7;
    Fox(i, N)
      P[i].clear(), nxt[i] = -1, prv[i] = -1;
    Fox(i, N)
      Read(A[i]), A[i]--,/*A[i] = rand() % 5, */P[A[i]].pb(i);
    Fox(i, N)
      Fox(j, Sz(P[i]) - 1)
    {
      nxt[P[i][j]] = P[i][j + 1];
      prv[P[i][j + 1]] = P[i][j];
    }
    Fox(j, N)
      Fox(i, j + 1)
      dyn[i][j] = INF;
    Fox(i, N)
      dyn[i][i] = 0;
    Fox1(d, N - 1)
      Fox(i, N - d)
    {
      j = i + d;
      if (d == 1)
      {
        dyn[i][j] = (A[i] == A[j] ? 0 : 1);
        continue;
      }
      dyn[i][j] = dyn[i + 1][j - 1] + (A[i] == A[j] ? 1 : 2);
      if (DEBUG)
      {
        cor = dyn[i][j];
        m1 = i;
        while (m1 >= 0 && m1 < j)
        {
          m2 = j;
          while (m2 >= 0 && m2 > m1)
          {
            int v = 0;
            if (m1 > i)
              v += dyn[i + 1][m1];
            if (m2 < j)
              v += dyn[m2][j - 1];
            if (m2 == m1 + 1)
              v += (A[i] == A[j] ? 0 : 1);
            else
              v += dyn[m1 + 1][m2 - 1] + (A[i] == A[j] ? 1 : 2);
            Min(cor, v);
            m2 = prv[m2];
          }
          m1 = nxt[m1];
        }
      }
      m1 = nxt[i];
      while (m1 >= 0 && m1 < j)
      {
        /*int v = dyn[i + 1][m1];
        if (j == m1 + 1)
          v += (A[i] == A[j] ? 0 : 1);
        else
          v += dyn[m1 + 1][j - 1] + (A[i] == A[j] ? 1 : 2) - (A[m1 + 1] == A[j] || A[j - 1] == A[j] ? 1 : 0);*/
        int v = dyn[i][m1] + dyn[m1 + 1][j] + 1;
        if (A[i] == A[m1 + 1] || A[i] == A[j])
          v--;
        Min(dyn[i][j], v);
        m1 = nxt[m1];
      }
      m2 = prv[j];
      while (m2 >= 0 && m2 > i)
      {
        /*int v = dyn[m2][j - 1];
        if (i == m2 - 1)
          v += (A[i] == A[j] ? 0 : 1);
        else
          v += dyn[i + 1][m2 - 1] + (A[i] == A[j] ? 1 : 2) - (A[m2 - 1] == A[i] || A[i + 1] == A[i] ? 1 : 0);*/
        int v = dyn[i][m2 - 1] + dyn[m2][j] + 1;
        if (A[j] == A[m2 - 1] || A[i] == A[j])
          v--;
        Min(dyn[i][j], v);
        m2 = prv[m2];
      }
      if (DEBUG && dyn[i][j] != cor)
      {
        printf("bad\n");
        Fox(i, N)
          printf("%d ", A[i]);
        return(0);
        i = i;
      }
    }
    printf("%d\n", dyn[0][N - 1]);
  }
  return(0);
}