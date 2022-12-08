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

int main(){
  int testy;
  scanf("%d",&testy);
  while (testy--){
    int n;
    scanf("%d",&n);
    vector<pair<PII,int> > v;
    LL s1 = 0, s2 = 0;
    REP(i,2*n-1){
      int a,b;
      scanf("%d %d",&a,&b);
      v.PB(MP(MP(a,b), i+1));
      s1 += a; s2 += b;
    }
    sort(ALL(v));
    LL x = 0;
    REP(i,n){
      x += v[2*i].ST.ND;
    }
    int r = (2 * x >= s2) ? 0 : 1;
    VI res;
    REP(i,n-1) res.PB(v[2*i+r].ND);
    res.PB(v.back().ND);
    puts("YES");
    FOREACH(it, res) printf("%d ",*it);
    puts("");
  }
  return 0;
}