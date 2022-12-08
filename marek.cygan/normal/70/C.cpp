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

const int N = 110000;
const LL INF = (LL)N * (LL)N;
int mam[N][2];

map<PII,int> mapa;

inline int numer(const PII &p){
  if (mapa.count(p) == 0){
    int res = SIZE(mapa);
    return mapa[p]= res;
  }
  return mapa[p];
}

int rev(int x){
  int res = 0;
  while (x > 0){
    res = 10 * res + (x % 10);
    x /= 10;
  }
  return res;
}

int nwd(int a,int b){
  return b == 0 ? a : nwd(b,a%b);
}

PII popraw(int a,int b){
  int d = nwd(a,b);
  return MP(a/d,b/d);
}

int dajnumer(int x){
  return numer(popraw(x,rev(x)));
}

int dajnumerrev(int x){
  return numer(popraw(rev(x),x));
}

int main(){
  int maxx, maxy, w;
  LL suma = 0;
  LL best = INF; 
  int bestx = -1, besty=-1;
  scanf("%d %d %d",&maxx,&maxy,&w);
  FOR(i,1,maxx){
    int a = dajnumer(i);
    mam[a][0]++;
  }
  int akty = 0;
  FORD(i,maxx,1){
    while (akty < maxy && suma < w){
      akty++;
      int b = dajnumerrev(akty);
      suma -= (LL)mam[b][0] * (LL)mam[b][1];
      mam[b][1]++;
      suma += (LL)mam[b][0] * (LL)mam[b][1];
    }
    if (suma < w) break;
    if ((LL)i * (LL)akty < best){
      best = (LL)i * (LL)akty;
      bestx = i;
      besty = akty;
    }
    //na koniec wyjmuje i
    int a = dajnumer(i);
    suma -= (LL)mam[a][0] * (LL)mam[a][1];
    mam[a][0]--;
    suma += (LL)mam[a][0] * (LL)mam[a][1];
  }
  if (best == INF) puts("-1");
  else printf("%d %d\n", bestx, besty);
  return 0;
}