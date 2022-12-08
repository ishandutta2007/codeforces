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

const int N = 2100;
const LL INF = 1000LL * 1000LL * 1000LL * 1000LL * 1000LL * 1000LL;
LL t[2*N];
LL nowy[2*N];

int main(){
  int n;
  scanf("%d",&n);
  REP(j,2*N) t[j] = INF;
  t[N] = 0;

  REP(i,n){
    int a,b;
    scanf("%d %d",&a,&b);
    REP(j, 2*N) nowy[j] = INF;
    REP(j, 2*N) if (t[j] < INF){
      //kradne
      nowy[j-1] = min(nowy[j-1], t[j]);
      //kupuje
      int czas = min(2*N-1, j + a);
      nowy[czas] = min(nowy[czas], t[j] + b);
    }
    REP(j, 2*N) t[j] = nowy[j];
  }
  LL res = INF;
  FOR(j,N,2*N-1) res = min(res, t[j]);
  cout << res << endl;
}