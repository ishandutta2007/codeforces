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

const int N = 4100;

int parent[N];
VI kraw[N];

int licz(int x){
  int res = 1;
  FOREACH(it, kraw[x]) res = max(res, licz(*it)+1);
  return res;
}

int main(){
  int n;
  scanf("%d",&n);
  REP(i,n){
    scanf("%d",parent+i);
    parent[i]--;
    if (parent[i] >= 0) kraw[parent[i]].PB(i);
  }
  int res = 1;
  REP(i,n) if (parent[i] < 0) res = max(res, licz(i));
  printf("%d\n",res);
  return 0;
}