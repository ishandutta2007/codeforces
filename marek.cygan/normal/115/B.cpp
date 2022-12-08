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

const int N = 310;

char mapa[N][N];
PII t[N][N];

inline int between(int a,int b,int c){
  return a >= b && a <= c;
}

void popraw(int i, int j, PII p){
  if ((p.ST + (mapa[i][j] == 'W') > t[i][j].ST)
      || (p.ST + (mapa[i][j] == 'W') == t[i][j].ST)
      && p.ND+1 < t[i][j].ND) t[i][j] = MP(p.ST+(mapa[i][j] == 'W'),p.ND+1);
}

int main(){
  int n,m;
  scanf("%d %d",&n,&m);
  REP(i,n) scanf("%s",mapa[i]);

  FORD(i,n-1,0){
    int j = (i%2) ? 0 : m-1;
    int krok = (i%2) ? 1 : -1;
    while (between(j,0,m-1)){
      //liczymy t[i][j]
      if (mapa[i][j] == 'W') t[i][j] = MP(1,0);
      if (between(j-krok,0,m-1)) popraw(i,j,t[i][j-krok]);
      if (i+1<n) popraw(i,j,t[i+1][j]);
      j += krok;
    }
  }

  printf("%d\n",t[0][0].ND);
  return 0;
}