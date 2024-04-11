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

VI kraw[50];

const int WYMIAR=260;
int wymiar;

struct M{
  double t[WYMIAR][WYMIAR];
  M() {REP(i,WYMIAR) REP(j,WYMIAR) t[i][j]=0.0;}
};

M operator *(const M &a, const M &b){
  M res;
  REP(i,wymiar) REP(j,wymiar) REP(k,wymiar) res.t[i][j]+=a.t[i][k]*b.t[k][j];
  return res;
}

M potega(M x,LL n){
  M res = x;
  REP(i,n) res = res * res;
  return res;
}

int numer[50][50];
double p[50];

void init(int n){
  int x = n;
  FOR(a,0,n-1) FOR(b,a+1,n-1) numer[a][b] = x++;
  wymiar = x;
}

vector<pair<int,double > > daj_wektor(int x){
  vector<pair<int,double> > res;
  res.PB(MP(x,p[x]));
  int d = SIZE(kraw[x]);
  FOREACH(it, kraw[x]) res.PB(MP(*it, (1-p[x]) / d));
  return res;
}

M macierz_przejscia(int n){
  M res;
  REP(i,n) res.t[i][i] = 1.0;
  FOR(a,0,n-1) FOR(b,a+1,n-1){
    //jestem w (a,b)
    int i = numer[a][b];
    vector<pair<int,double> > va = daj_wektor(a);
    vector<pair<int,double> > vb = daj_wektor(b);
    FOREACH(it, va) FOREACH(it2, vb){
      double x = it->ND * it2->ND;
      if (it->ST == it2->ST) res.t[i][it->ST] += x;
      else res.t[i][numer[min(it->ST,it2->ST)][max(it->ST,it2->ST)]] += x;
    }
  }
  /*
  REP(i,wymiar){
    REP(j,wymiar) printf("%.5lf ", res.t[i][j]); puts("");
  }
  */
  return res;
}

int main(){
  int n,m,start,end;
  scanf("%d %d %d %d",&n,&m,&start,&end);
  start--; end--;
  REP(i,m){

    int a,b;
    scanf("%d %d",&a,&b);
    a--; b--;
    kraw[a].PB(b);
    kraw[b].PB(a);
  }
  REP(i,n) scanf("%lf",p+i);
  init(n);

  double suma = 0.0;

  {
    M m = macierz_przejscia(n);
    while (true){
      int zle = 0;
      REP(i,wymiar) FOR(j,n,wymiar-1) if (m.t[i][j] > 1E-8) zle = 1;
      if (zle == 0) break;
      m = m * m;
    }
    /*
    puts("spotegowana");
    REP(i,wymiar){
      REP(j,wymiar) printf("%.5lf ", m.t[i][j]); puts("");
    }
    */
    if (start > end) swap(start,end);
    int stan = start==end ? start :  numer[start][end];
    REP(j,n){
      double res = m.t[stan][j];
      suma += res;
      printf("%.10lf\n",res);
    }
  }
  //printf("suma = %.10lf\n", suma);
  return 0;
}