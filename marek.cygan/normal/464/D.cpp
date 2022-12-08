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

const int MAX = 10000;
double t[2][MAX+1];
double zostaje[MAX+1];
double przejscie[MAX+1];
double zysk[MAX+1];

int main(){
  int n, k;
  scanf("%d %d",&n,&k);
//  n = 100000; k = 1.0;
  int m = min(n+1,MAX);
  double *cur = t[0];
  double *nowy = t[1];

  FOR(j,1,m-1) {
    zysk[j] = (double)(j+2.0) / 2.0 - 1.0 / (double)(j+1.0);
    zysk[j] /= k;

    przejscie[j] = 1.0 / (double)k / (double)(j + 1.0);

    zostaje[j] = 1.0 - przejscie[j];
  }
  zysk[m] = (double)(m+2.0) / 2.0 - 1.0 / (double)(m+1.0);
  zysk[m] /= k;

  REP(i,n) {
    FOR(j,1,m-1) {
      nowy[j] = zysk[j] + zostaje[j] * cur[j] + przejscie[j] * cur[j+1];
    }
    nowy[m] = zysk[m] + cur[m];
    swap(cur, nowy);
  }
  printf("%.12lf\n", cur[1] * k);
  return 0;
}