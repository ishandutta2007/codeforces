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

const int N = 110;
char mapa[N][N];

void impossible(){
  puts("IMPOSSIBLE");
  exit(0);
}

int main(){
  int n,m,a,b,c;
  scanf("%d %d %d %d %d",&n,&m,&a,&b,&c);
  int norig = n, morig = m;
  if (n%2 && m%2) impossible();
  else if (n%2 && m%2==0){
    if (a < m/2) impossible();
    a -= m/2;
    int pos = 0;
    int co = 0;
    while (pos < m){
      mapa[n-1][pos] = mapa[n-1][pos+1] = 'a'+co;
      co = 1-co; pos += 2;
    }
    n--;
  } else if (n%2==0 && m%2){
    if (b < n/2) impossible();
    b -= n/2;
    int pos = 0;
    int co = 0;
    while (pos < n){
      mapa[pos][m-1] = mapa[pos+1][m-1] = 'a' + co;
      co = 1-co; pos += 2;
    }
    m--;
  }

  a -= a%2;
  b -= b%2;

  if (a*2 + b*2 + c*4< n*m) impossible();

  for (int i = 0; i < n; i += 2){
    char start = ((i/2%2) ? 'l' : 'c');
    for (int j = 0; j < m; j += 2){
      char start2 = start;
      if (j/2%2) start2 += 2;
      if (c > 0){
        mapa[i][j] = mapa[i][j+1] = mapa[i+1][j] = mapa[i+1][j+1] = start2;
        c--;
      } else if (a > 0){
        mapa[i][j] = mapa[i][j+1] = start2;
        mapa[i+1][j] = mapa[i+1][j+1] = start2+1;
        a -= 2;
      } else {
        mapa[i][j] = mapa[i+1][j] = start2;
        mapa[i][j+1] = mapa[i+1][j+1] = start2+1;
        b -= 2;
      }
    }
  }

  REP(i,norig){
    mapa[i][morig] = 0;
    puts(mapa[i]);
  }
  return 0;
}