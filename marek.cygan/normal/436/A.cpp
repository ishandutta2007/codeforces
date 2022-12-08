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

VPII t[2];

int licz(int h, int a) {
  VI stos[2];
  VPII v[2];
  REP(i,2) FOREACH(it, t[i]) {
    if (it->ST <= h) stos[i].PB(it->ND);
    else v[i].PB(*it);
  }
  int res = 0;
  while (true) {
    if (stos[a].empty()) break;
    sort(ALL(stos[a]));
    res++;
    h += stos[a].back();
    stos[a].pop_back();

    REP(i,2) {
      int j = 0;
      while (j < SIZE(v[i])) {
        if (v[i][j].ST <= h) {
          stos[i].PB(v[i][j].ND);
          swap(v[i][j], v[i].back());
          v[i].pop_back();
        } else j++;
      }
    }
    a = 1-a;
  }
  return res;
}

int main(){
  int n,x;
  scanf("%d %d",&n,&x);
  REP(i,n) {
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    t[a].PB(MP(b,c));
  }
  printf("%d\n", max(licz(x,0), licz(x,1)));
  return 0;
}