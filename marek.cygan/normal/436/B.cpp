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

const int N = 2100;
char mapa[N][N];
int wynik[N];

int main(){
  int n, m, k;
  scanf("%d %d %d",&n,&m,&k);
  REP(i,n) scanf("%s",mapa[i]);
  REP(i,n) REP(j,m) {
    if (mapa[i][j] == 'L') {
      int nj = j - i;
      if (nj >= 0) wynik[nj]++;
    } else if (mapa[i][j] == 'R') {
      int nj = j + i;
      if (nj < m) wynik[nj]++;
    } else if (mapa[i][j] == 'U') {
      if (i % 2 == 0) wynik[j]++;
    }
  }
  REP(j,m) {
    if (j) printf(" ");
    printf("%d", wynik[j]);
  }
  puts("");
  return 0;
}