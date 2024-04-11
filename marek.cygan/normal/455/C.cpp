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

const int N = 310 * 1010;

VI kraw[N];
int fu[N];
int diam[N];

inline int fufind(int x) {
  return fu[x] < 0 ? x : (fu[x] = fufind(fu[x]));
}

PII dfs(int x,int par) {
  PII res = MP(x, 0);
  FOREACH(it, kraw[x]) if (*it != par) {
    PII p = dfs(*it, x);
    p.ND++;
    if (p.ND > res.ND) res = p;
  }
  return res;
}

int main(){
  int n, m, q;
  scanf("%d %d %d",&n,&m,&q);
  REP(i,n) fu[i] = -1;

  REP(i,m) {
    int a,b;
    scanf("%d %d",&a,&b);
    a--; b--;
    kraw[a].PB(b);
    kraw[b].PB(a);
    a = fufind(a); b = fufind(b);
    if (a != b) {
      if (fu[a] < fu[b]) swap(a,b);
      fu[b] += fu[a];
      fu[a] = b;
    }
  }

  REP(i,n) if (fu[i] < 0) {
    PII p = dfs(i, -1);
    diam[i] = dfs(p.ST, -1).ND;
  }

//  REP(i,n) printf("fu[%d]=%d diam[%d]=%d\n", i, fu[i], i, diam[i]);

  REP(i,q) {
    int x;
    scanf("%d",&x);
    if (x == 2) {
      int a,b;
      scanf("%d %d",&a,&b);
      a--; b--;
      a = fufind(a);
      b = fufind(b);
      if (a == b) continue;
      else {
        int d1 = diam[a];
        int d2 = diam[b];
        if (fu[a] < fu[b]) swap(a,b);
        fu[b] += fu[a];
        fu[a] = b;
        diam[b] = max(max(d1,d2), 1 + (d1+1)/2 + (d2+1)/2);
      }
    } else {
      //x == 1
      int a;
      scanf("%d",&a);
      a--;
      a = fufind(a);
      printf("%d\n", diam[a]);
    }
  }
  return 0;
}