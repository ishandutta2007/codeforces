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

long double INF = 1E12;
long double res = INF;
long double EPS = 1E-15;
int vx,vy,vz;

inline long double sqr(long double x){
  return x*x;
}

inline long double dist(long double x1, long double y1, long double z1, long double x2, long double y2, long double z2){
  return sqrtl(sqr(x1-x2)+sqr(y1-y2)+sqr(z1-z2));
}

void licz(int ox,int oy,int oz,int r){
  //od teraz kula punkt
  long double lewy = 0.0, prawy = 1E6;
  long double d;
  REP(foo,200){
    long double m1 = lewy + (prawy-lewy) / 3.0;
    long double m2 = lewy + (prawy-lewy) * 2.0 / 3.0;
    long double f1 = dist(vx * m1, vy * m1, vz * m1, ox, oy, oz);
    long double f2 = dist(vx * m2, vy * m2, vz * m2, ox, oy, oz);
    d = f1;
    if (f1 <= f2) prawy = m2;
    else lewy = m1;
  }
//  printf("d=%.10Lf r=%.10Lf\n",d,(long double)r);
  if (d > r+EPS) return;
  lewy = 0.0;
  REP(foo,100){
    long double m = (lewy+prawy) / 2.0;
    long double f = dist(vx * m, vy * m, vz * m, ox, oy, oz);
    if (f > r+EPS) lewy = m;
    else prawy = m;
  }
  res = min(res, lewy);
}

int main(){
  int ax,ay,az,R;
  scanf("%d %d %d %d %d %d %d",&ax,&ay,&az,&vx,&vy,&vz,&R);

  int n;
  scanf("%d",&n);

  REP(i,n){
    int ox,oy,oz,r,m;
    scanf("%d %d %d %d %d",&ox,&oy,&oz,&r,&m);
    ox -= ax; oy -= ay; oz -= az;

    licz(ox,oy,oz,r+R);
    REP(j,m){
      int px,py,pz;
      scanf("%d %d %d",&px,&py,&pz);
      licz(ox+px,oy+py,oz+pz,R);
    }
  }

  if (res >= INF/2.0) printf("-1\n");
  else printf("%.10lf\n",(double)res);
  return 0;
}