#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FORE(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

const int N = 200100;
int rows,cols,q,fu[2*N];

int fu_find(int x) { return fu[x] < 0 ? x : fu[x] = fu_find(fu[x]); }
void fu_join(int x, int y) {
  x = fu_find(x);
  y = fu_find(y);
  if (x != y) { fu[x] = y; }
}

int main() {
  scanf("%d%d%d",&rows,&cols,&q);
  REP(i,rows+cols) fu[i] = -1;
  REP(i,q) {
    int r,c; scanf("%d%d",&r,&c); --r; --c;
    fu_join(r, rows+c);
  }
  int ans = 0;
  REP(i,rows+cols) ans += fu[i] < 0;
  printf("%d\n", ans-1);
}