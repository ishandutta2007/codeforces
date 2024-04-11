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

const int N =510000;
const int MOD = 1000003;
vector<string> mapa;

char txt[N];
int wystaje[N];
int niewystaje[N];

LL licz(VI v){
  int n = SIZE(v);
  wystaje[0] = niewystaje[0] = 1;
  REP(i,n){
    wystaje[i+1]=niewystaje[i+1] = 0;
    if (v[i] >= 0){
      //idziemy w prawo
      wystaje[i+1] = (wystaje[i+1] + niewystaje[i]) % MOD;
    }
    if (v[i] <= 0){
      //w lewo
      niewystaje[i+1] = (niewystaje[i+1] + wystaje[i]) % MOD;
    }
  }
  return (wystaje[n] + niewystaje[n])%MOD;
}

int main(){
  int n,m;
  scanf("%d %d",&n,&m);

  REP(i,n){
    scanf("%s",txt);
    mapa.PB(string(txt));
  }

  int res = 1;
  REP(i,n){
    VI v;
    v.reserve(m);
    REP(j,m) if (mapa[i][j] == '.') v.PB(0);
    else if (mapa[i][j] == '1' || mapa[i][j] == '2') v.PB(-1);
    else v.PB(1);

    res = (LL)res * licz(v) % MOD;
  }

  REP(j,m){
    VI v;
    v.reserve(n);
    REP(i,n) if (mapa[i][j] == '.') v.PB(0);
    else if (mapa[i][j] == '1' || mapa[i][j] == '4') v.PB(-1);
    else v.PB(1);

    res = (LL)res * licz(v) % MOD;
  }

  printf("%d\n", res % MOD);
  return 0;
}