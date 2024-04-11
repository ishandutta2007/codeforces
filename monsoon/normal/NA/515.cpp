#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPDN(i,n) for(int i=(n)-1;i>=0;--i)

const int N=5010;
int n,a[N][N],maks[N][N],q;


int main() {
  scanf("%d",&n);
  REP(i,n) {
    scanf("%d",&a[n-1][i]);
    maks[n-1][i] = a[n-1][i];
  }
  REPDN(i,n-1) {
    REP(j,i+1) {
      a[i][j] = a[i+1][j] ^ a[i+1][j+1];
      maks[i][j] = max(a[i][j], max(maks[i+1][j], maks[i+1][j+1]));
    }
  }
  scanf("%d",&q);
  REP(i,q) {
    int l,r; scanf("%d%d",&l,&r); --l; --r;
    printf("%d\n", maks[n-1-(r-l)][l]);
  }
}