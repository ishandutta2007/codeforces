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

const int LEV = 1100;
const int N = 15;
char mapa[LEV][N][N];

VI kraw[LEV];
int fu[LEV];

vector<pair<int,PII> > v;

void dodaj(int a, int b) {
  kraw[a].PB(b);
  kraw[b].PB(a);
}

int fufind(int x) {
  return fu[x] < 0 ? x : fu[x] = fufind(fu[x]);
}

void mst(int k) {
  int res = 0;
  REP(i,k) fu[i] = -1;
  sort(ALL(v));
  FOREACH(it, v) {
    int a = fufind(it->ND.ST);
    int b = fufind(it->ND.ND);
    if (a != b) {
      res += it->ST;
      dodaj(it->ND.ST, it->ND.ND);
      if (fu[a] < fu[b]) swap(a,b);
      fu[b] += fu[a];
      fu[a] = b;
    }
  }
  printf("%d\n", res);
}

void dfs(int x, int par) {
  if (x != 0) {
    printf("%d %d\n", x, par);
  }
  FOREACH(it, kraw[x]) if (*it != par) {
    dfs(*it, x);
  }
}

int dist(int a,int b, int n, int m) {
  int res = 0;
  REP(i,n) REP(j,m) res += mapa[a][i][j] != mapa[b][i][j];
  return res;
}

int main(){
  int n,m,w,k;
  scanf("%d %d %d %d", &n, &m, &k, &w);
  REP(a,k) REP(i,n) scanf("%s",mapa[a][i]);

  FOR(a,1,k) v.PB(MP(n*m, MP(0,a)));
  FOR(a,1,k) FOR(b,a+1,k) v.PB(MP(w * dist(a-1,b-1, n, m), MP(a,b)));
  mst(k+1);
  dfs(0,-1);
  return 0;
}