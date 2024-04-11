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

const int N = 101000;
const int NN = 5 * N;
const int K = 100;
const int EPS = 1E-13;

int ile[N];
int ogr[N];
long double t[N][K+1];
long double dobry[N];
long double pom[K+1];
long double nk[NN][10];

int main(){
  REP(i,NN) nk[i][0] = 1.0;
  FOR(i,1,NN-1) FOR(j,1,9) nk[i][j] = nk[i-1][j-1] + nk[i-1][j];
  int n;
  scanf("%d",&n);
  REP(i,n){
    scanf("%d",ile+i);
    ogr[i] = ile[i];
    t[i][ile[i]] = 1.0;
    dobry[i] = t[i][0];
  }
  int q;
  scanf("%d",&q);
  long double res = 0.0;
  REP(i,n) res += dobry[i];
  while (q--){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c); a--; b--;
    if (a == b){
      res -= dobry[a];
      int m = min(ogr[a], ile[a]);
      FOR(i,0,m) pom[i] = 0;
      FOR(i,0,m) {//if (t[a][i] > EPS){
        //para (i,ile[a]-i)
        for (int j = min(i, c); j >= 0; --j){
          pom[i-j] += t[a][i] * nk[i][j] * (long double)nk[ile[a]-i][c-j];
        }
      }
      FOR(i,0,m) t[a][i] = pom[i] / nk[ile[a]][c];
      dobry[a] = t[a][0];
      res += dobry[a];
    } else {
      res -= dobry[a];
      res -= dobry[b];

      //poprawiam b, rozklad sie nie zmienia
      ile[b] += c;

      //poprawiam a
      int m = min(ogr[a], ile[a]);
      FOR(i,0,m) pom[i] = 0;
      FOR(i,0,m){// if (t[a][i] > EPS){
        for (int j = min(i, c); j >= 0; --j){
          pom[i-j] += t[a][i] * nk[i][j] * (long double)nk[ile[a]-i][c-j];
        }
      }
      FOR(i,0,m) t[a][i] = pom[i] / nk[ile[a]][c];
      ile[a] -= c;

      dobry[a] = t[a][0]; dobry[b] = t[b][0];
      res += dobry[a];
      res += dobry[b];
    }

    /*
    REP(i,n){
      printf("i=%d\n",i);
      int m = min(ogr[a], ile[a]);
      FOR(j,0,m) printf("t[%d][%d]=%.6lf\n", i,j, t[i][j]);
    }
    */
    //REP(i,n) printf("ile[%d]=%d\n",i,ile[i]);

    printf("%.12lf\n", (double)res);
  }
  return 0;
}