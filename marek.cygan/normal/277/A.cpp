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
int fu[N];
set<int> zna[N];

int fufind(int x){
  return fu[x] < 0 ? x : (fu[x] = fufind(fu[x]));
}

void fuunion(int a,int b){
  a = fufind(a);
  b = fufind(b);
  if (a != b){
    if (fu[a] < fu[b]) swap(a,b);
    fu[b] += fu[a];
    fu[a] = b;
  }
}

int main(){
  int n,m;
  scanf("%d %d",&n,&m);
  int zera = 1;
  REP(i,n){
    int k;
    scanf("%d",&k);
    REP(j,k){
      int x;
      scanf("%d",&x);
      zna[i].insert(x-1);
      zera = 0;
    }
  }
  if (zera){
    printf("%d\n", n);
    return 0;
  }
  REP(i,n) fu[i]=-1;
  REP(j,m){
    int last = -1;
    REP(i,n) if (zna[i].count(j)){
      if (last != -1) fuunion(last, i);
      last = i;
    }
  }
  int res = -1;
  REP(i,n) res += fu[i] < 0;
  printf("%d\n", res);
  return 0;
}