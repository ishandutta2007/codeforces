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

const int N = 310;

int t[N][N];

int main(){
  int n;
  scanf("%d",&n);

  REP(i,n) REP(j,n){
    scanf("%d",t[i]+j);
  }

  int q, bylo=0;
  scanf("%d",&q);
  while (q--){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    a--; b--;
    if (t[a][b] > c){
      t[a][b] = t[b][a] = c;
      REP(foo,2){
        REP(i,n) REP(j,n) t[i][j] = min(t[i][j], t[i][a] + t[a][b] + t[b][j]);
        swap(a,b);
      }
    }
    LL suma = 0;
    REP(i,n) REP(j,n) suma += t[i][j];
    if (bylo++) cout << " ";
    cout << suma / 2; 
  }
  cout << endl;
  return 0;
}