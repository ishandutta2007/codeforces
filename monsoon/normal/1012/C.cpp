#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FORE(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

const int N = 5100, infty = 1000000000;
int n,a[N],n2,dtak[N][N/2],dnie[N][N/2];

int main() {
  scanf("%d",&n);
  REP(i,n) scanf("%d",&a[i]);
  n2 = (n+1)/2;

  REP(k,n2+1) dtak[0][k] = dnie[0][k] = infty;
  dtak[0][1] = 0;
  dnie[0][0] = 0;

  
  for(int i=1; i<n; ++i) {
    REP(k,n2+1) {
      dtak[i][k] = dnie[i][k] = infty;
      if (i == 1) {
        dtak[1][1] = max(0, a[0] - (a[1]-1));
      } else if (k > 0) {
        dtak[i][k] = min(dtak[i-2][k-1] + max(0, a[i-1] - min(a[i]-1, a[i-2]-1)),
                         dnie[i-2][k-1] + max(0, a[i-1] - (a[i]-1)));
      }

      dnie[i][k] = min(dtak[i-1][k] + max(0, a[i] - (a[i-1]-1)),
                       dnie[i-1][k]);
    }
  }
  REP(k,n2) {
    int ans = min(dtak[n-1][k+1], dnie[n-1][k+1]);
    printf("%d ",ans);
  }
  printf("\n");
}