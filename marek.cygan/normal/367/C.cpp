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

int licz(int n){
  int res = 1;
  FOR(k,1,n) {
    if (k%2 == 0){
      if ((LL)k * (k-1LL) / 2 + (k-2) / 2 + 1 <= n) res = max(res, k);
    } else {
      if ((LL)k * (k-1LL) / 2 + 1 <= n) res = max(res, k);
    }
  }
  return res;
}

int main(){
  int n,m;
  scanf("%d %d",&n,&m);
  int x = licz(n);
  VI v;
  REP(i,m){
    int a,b;
    scanf("%d %d",&a,&b);
    v.PB(b);
  }
  sort(ALL(v)); reverse(ALL(v));
  LL res = 0;
  REP(i,min(SIZE(v),x)) res += v[i];
  cout << res << endl;
  return 0;
}