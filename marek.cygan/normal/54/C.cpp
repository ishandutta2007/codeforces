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
typedef unsigned long long LL;
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

const int N = 1010;

long double p[N];
long double t[N][N];

//liczba liczb mniejszych od x majacych jedynke na poczatku
LL jedynki(LL x){
  LL pot = 1;
  LL res = 0;
  while (pot < x){
    //przedzial [pot,10*pot)
    if (x >= 2LL * pot){
      res += pot;
    } else{
      res += x - pot;
    }
    pot = 10LL * pot;
  }
  return res;
}

LD licz_prawd(LL l, LL r){
  LL jed = jedynki(r+1) - jedynki(l);
  return (LD)jed/(LD)(r-l+1);
}

int main(){
  int n;
  cin >> n;
  REP(i,n){
    LL l,r;
    cin >> l >> r;
    p[i] = licz_prawd(l,r);
  }
  int procenty;
  cin >> procenty;
  t[0][0] = 1.0;
  REP(i,n) FOR(j,0,i){
    t[i+1][j] += t[i][j] * (1.0 - p[i]);
    t[i+1][j+1] += t[i][j] * p[i];
  }
  LD res = 0.0;
  FOR(j,0,n) if (j * 100 >= procenty * n) res += t[n][j];
  cout.precision(12);
  cout << res << endl;
  return 0;
}