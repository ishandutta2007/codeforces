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

const int N = 1001;
const int M = 110 * 1001;
const int MOD = 1000000007;
int t[2][N][N];

int licz(int n, int m, int x){
  if (n > m) return 0;
  int pos = 0, next = 1;
  t[pos][0][0] = 1;

  FOR(foo,1,m) {
    FOR(i,0,2*n) FOR(j,0,n) if (t[pos][i][j]) {
      //otworz
      t[next][i+1][j+1] = (t[next][i+1][j+1] + t[pos][i][j]) % MOD;

      if (j == 0) {
        //otworz-zamknij, singleton
        t[next][i+2][j] = (t[next][i+2][j] + t[pos][i][j]) % MOD;
      } else {
        //zamknij-otworz
        t[next][i+2][j] = (t[next][i+2][j] + t[pos][i][j]) % MOD;
      }

      if (foo != x) {
        //pomin
        t[next][i][j] = (t[next][i][j] + t[pos][i][j]) % MOD;

        if (j > 0) {
          //zamknij
          t[next][i+1][j-1] = (t[next][i+1][j-1] + t[pos][i][j]) % MOD;
        }
      }

      t[pos][i][j] = 0;
    }

//    FOR(i,0,2*n) FOR(j,0,n) printf("next[%d][%d]=%d\n",i,j,t[next][i][j]); puts("");

    swap(pos,next);
  }

  int res = t[pos][2*n][0];
  FOR(i,1,n) res = (LL) res * i % MOD;
  return res;
}

int main(){
  int n,m,x;
  scanf("%d %d %d",&n,&m,&x);
  printf("%d\n", licz(n,m,x));
  return 0;
}