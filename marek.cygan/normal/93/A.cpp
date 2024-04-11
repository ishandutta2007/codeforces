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

int licz(){
  int n,m,a,b;
  scanf("%d %d %d %d",&n,&m,&a,&b);
  a--; b--;
  int w1 = a/m;
  int w2 = b/m;
  if (w1 == w2) return 1;
  if (a%m == 0 && (b%m==(m-1) || b==n-1)) return 1;
  if (a%m == 0 || (b%m==(m-1) || b==n-1)) return 2;
  if ((a%m) == (b%m)+1) return 2;
  if (w2 - w1 <= 1) return 2;
  return 3;
}

int main(){
  printf("%d\n",licz());
  return 0;
}