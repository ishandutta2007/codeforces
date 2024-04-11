#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FORE(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

int x[2][5],y[2][5];

int main() {
  REP(i,2) REP(j,4) {
    scanf("%d%d",&x[i][j],&y[i][j]);
    x[i][4] += x[i][j];
    y[i][4] += y[i][j];
    x[i][j] *= 4;
    y[i][j] *= 4;
  }
  int yes=0;
  REP(phase,2) {
    int minx = *min_element(x[0],x[0]+4);
    int maxx = *max_element(x[0],x[0]+4);
    int miny = *min_element(y[0],y[0]+4);
    int maxy = *max_element(y[0],y[0]+4);
    REP(j,5) if (minx <= x[1][j] && x[1][j] <= maxx
        && miny <= y[1][j] && y[1][j] <= maxy) yes = 1;
    REP(i,2) REP(j,5) {
      int tx = x[i][j]+y[i][j];
      int ty = x[i][j]-y[i][j];
      x[i][j] = tx;
      y[i][j] = ty;
    }
    REP(j,5) {
      swap(x[0][j],x[1][j]);
      swap(y[0][j],y[1][j]);
    }
  }
  puts(yes ? "YES" : "NO");
}