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

void no(){
  puts("NO");
  exit(0);
}

int ile_razy[1000];

int licz(int butle, int w,int osoby, int pisz){
  if (pisz)
    puts("YES");
    VI v(butle, w * osoby);
    int biore = w * butle;
    REP(i,butle) ile_razy[i] = 0;
    REP(i,osoby){
      int mam = 0;
      int bylo = 0;
      FOREACH(it,v){
        if (mam < biore && *it > 0){
          int chce = min(biore-mam,*it);
          *it -= chce; mam += chce;
          if (bylo++){
            if (pisz) printf(" ");
          }
          int pos = it-v.begin();
          if (++ile_razy[pos] > 2) return 0;
          if (pisz) printf("%d %.10lf", it-v.begin()+1, (double)chce/osoby);
        }
      }
      if (pisz) puts("");
    }
    return 1;
}

int main(){
  int osoby,w,butle;
  scanf("%d %d %d",&butle,&w,&osoby);
  if (2 * butle < osoby) no();
  /*
  if (osoby == butle){
    puts("YES");
    FOR(i,1,n) printf("%d %.10lf\n", i, w);
    return 0;
  }
  */
  if (licz(butle,w,osoby,0)) licz(butle,w,osoby,1);
  else no();
  return 0;
}