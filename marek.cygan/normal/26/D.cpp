#include <cassert>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <list>
#include <queue>
#include <deque>
#include <cctype>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <numeric>
#include <cmath>
using namespace std;

typedef vector <int > VI;
typedef vector < VI > VVI;
typedef long long LL;
typedef vector < LL > VLL;
typedef vector < double > VD;
typedef vector < string > VS;
typedef pair<int,int> PII;
typedef vector <PII> VPII;
typedef istringstream ISS;

#define ALL(x) x.begin(),x.end()
#define REP(i,n) for (int i=0; i<(n); ++i)
#define FOR(var,pocz,koniec) for (int var=(pocz); var<=(koniec); ++var)
#define FORD(var,pocz,koniec) for (int var=(pocz); var>=(koniec); --var)
#define FOREACH(it, X) for(__typeof((X).begin()) it = (X).begin(); it != (X).end(); ++it)
#define PB push_back
#define PF push_front
#define MP(a,b) make_pair(a,b)
#define ST first
#define ND second
#define SIZE(x) (int)x.size()

typedef long double LD;

const int N = 210000;
LD silnia[N];

int main(){
  silnia[0] = silnia[1] = 0.0;
  FOR(i,2,N-1) silnia[i] = silnia[i-1] + logl(i);

  int n,m,k;
  scanf("%d %d %d",&n,&m,&k);
  if (m > n + k) printf("0.00000\n");
  else if (k >= m) printf("1.000000\n");
  else {
    int start = -(k+1);
    int final = n+k-m+1;
    int gora = final - start; //n-m+2k-1
    int reszta = n+m - gora;
    assert(reszta % 2 == 0);

    gora += reszta/2;

   // LD res = nk(n+m,gora) / nk(n+m,n);
     LD res = silnia[n] + silnia[m] - silnia[gora] - silnia[n+m-gora];
     res = expl(res);
     printf("%.6lf\n", (double)(1.0-res));
  }
  return 0;
}