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

const int N = 1100;

int x[N],y[N];

void shift(int *t, int n){
  int old = t[0];
  REP(i,n) t[i] = t[i+1];
  t[n-1] = old;
}

map<int,int> mapa;

VI mam[N*N];

int dist(int a,int b){
  return abs(x[a]-x[b])+abs(y[a]-y[b]);
}

int main(){
  int n,m;
  scanf("%d %d",&n,&m);
  REP(i,n) scanf("%d %d",x+i,y+i);
  REP(i,m){
    int a;
    scanf("%d",&a);
    mapa[a]++;
    mam[a].PB(i+1);
  }
  REP(foo,2){
    map<int,int> potrzeba;
    REP(i,n) if (i%2==0){
      int co = dist(i,(i+n-1)%n)+dist(i,(i+1)%n);
      potrzeba[co]++;
    }
    int ok = 1;
    FOREACH(it, potrzeba) if (mapa[it->ST] < it->ND){
      ok = 0;
      break;
    }
    if (ok){
      puts("YES");
      VI res;
      REP(i,n) if (i%2==0){
        int co = dist(i,(i+n-1)%n)+dist(i,(i+1)%n);
        res.PB(mam[co].back());
        mam[co].pop_back();
      } else res.PB(-1);
      if (foo){
        VI nowy;
        REP(i,n) nowy.PB(res[(n-1+i)%n]);
        res = nowy;
      }
      REP(i,n) {
        if (i) printf(" ");
        printf("%d", res[i]);
      }
      puts("");
      return 0;
    }
    shift(x,n);
    shift(y,n);
  }
  puts("NO");
  return 0;
}