#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

const int N = 110;
int rows,cols,a[N][N],ans;

int main() {
  scanf("%d%d",&rows,&cols);
  REP(r,rows) REP(c,cols) scanf("%d",&a[r][c]);
  REP(r,rows) {
    ans = max(ans, *min_element(a[r],a[r]+cols));
  }
  printf("%d\n",ans);
}