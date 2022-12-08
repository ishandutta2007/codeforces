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

const int N = 110 * 1010;

VI kraw[N];
int vis[N];
int parity[N];
int ccountc[N];
VI path;

int dfs(int x) {
  vis[x] = 1;
  path.PB(x);
  ccountc[x] = 1-ccountc[x];
  FOREACH(it, kraw[x]) if (!vis[*it]) {
    dfs(*it);
    path.PB(x);
    ccountc[x] = 1-ccountc[x];
    if (ccountc[*it] != parity[*it]) {
      path.PB(*it);
      path.PB(x);
      ccountc[x] = 1-ccountc[x];
      ccountc[*it] = 1-ccountc[*it];
    }
  }
  return 0;
}

int main(){
  int n, m;
  scanf("%d %d",&n,&m);
  REP(i,m) {
    int a,b;
    scanf("%d %d",&a,&b);
    a--; b--;
    kraw[a].PB(b);
    kraw[b].PB(a);
  }
  int start = -1;
  REP(i,n) {
    scanf("%d",parity+i);
    if (parity[i]) start = i;
  }
  if (start == -1) {
    puts("0");
    return 0;
  }
  dfs(start);
  if (parity[start] != ccountc[start]) {
    ccountc[start] = 1-ccountc[start];
    path.pop_back();
  }
  REP(i,n) if (ccountc[i] != parity[i]) {
    puts("-1");
    return 0;
  }
  printf("%d\n", SIZE(path));
  REP(i, SIZE(path)) {
    if (i) printf(" ");
    printf("%d", path[i]+1);
  }
  puts("");
  return 0;
}