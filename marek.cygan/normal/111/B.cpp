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

const int N = 101 * 1001;
int last[N];

int main(){
  REP(i,N) last[i] = -N;
  int n;
  scanf("%d",&n);
  REP(j,n){
    int x, y;
    scanf("%d %d",&x,&y);
    int i = 1;
    int res = 0;
    while (i * i < x){
      if (x % i == 0){
        if (last[i] < j-y) res++;
        last[i] = j;

        int a = x/i;
        if (last[a] < j-y) res++;
        last[a] = j;
      }
      i++;
    }
    if (i * i == x){
      if (last[i] < j-y) res++;
      last[i] = j;
    }
    printf("%d\n", res);
  }
  return 0;
}