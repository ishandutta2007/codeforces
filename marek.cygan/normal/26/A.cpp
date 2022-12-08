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

const int N = 3100;
int prime[N];
int dzielniki[N];

void init(){
  REP(i,N) prime[i] = 1;
  prime[0] = prime[1] = 0;

  FOR(i,2,N-1) if (prime[i]){
    for (int j = 2 * i; j < N; j += i){
      prime[j] = 0;
      dzielniki[j]++;
    }
  }
}

int main(){
  init();
  int n;
  scanf("%d",&n);
  int res = 0;
  FOR(i,2,n) if (!prime[i] && dzielniki[i] == 2){
//    printf("%d\n", i);
    res++;
  }
  printf("%d\n", res);
  return 0;
}