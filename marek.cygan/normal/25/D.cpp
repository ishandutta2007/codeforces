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
int fu[N];

int fufind(int x){
  return (fu[x] < 0) ? x : (fu[x] = fufind(fu[x]));
}

int main(){
  int n;
  scanf("%d",&n);
  REP(i,n) fu[i] = -1;
  VPII usun;
  REP(i,n-1){
    int a,b;
    scanf("%d %d",&a,&b);
    int olda = a, oldb = b;
    a--; b--;
    a = fufind(a);
    b = fufind(b);
    if (a != b){
      if (fu[a] < fu[b]) swap(a,b);
      fu[b] += fu[a];
      fu[a] = b;
    } else usun.PB(MP(olda,oldb));
  }
  VI v;
  REP(i,n) if (fu[i] < 0) v.PB(i);
  printf("%d\n", SIZE(v)-1);
  REP(i,SIZE(v)-1){
    printf("%d %d %d %d\n", usun[i].ST, usun[i].ND, v[i]+1, v[i+1]+1);
  }
  return 0;
}