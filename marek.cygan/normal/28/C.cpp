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

const int N = 55;

int kabiny[N];
int limit[N];
int n,m;
long double t[N][N];
LL nk[N][N];

double licz(int q){
  REP(i,m) limit[i] = min(n, q * kabiny[i]);
  FOR(i,0,m) FOR(j,0,n) t[i][j] = 0.0;
  t[m][0] = 1.0;
  FORD(i,m-1,0) FOR(j,0,n){
    FOR(zostaja,0,min(j,limit[i])) t[i][j] += t[i+1][j-zostaja] * nk[j][zostaja];
  }
  return t[0][n] / pow(m,n);
}

int main(){
  REP(i,N) nk[i][0] = 1;
  FOR(i,1,N-1) FOR(j,1,N-1) nk[i][j] = nk[i-1][j-1] + nk[i-1][j];
  scanf("%d %d",&n,&m);
  REP(i,m) scanf("%d",kabiny+i);
  long double res = 0.0; 
  FOR(kol,1,n) res += (licz(kol)-licz(kol-1)) * kol;
  printf("%.12lf\n",(double)res);
  return 0;
}