#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

const int N = 55, infty = 1000000000;
int _,memo[N][N][N],inmemo[N][N][N];

int go(int n, int m, int k) {
  if (k == 0 || k == n*m) return 0;
  if (inmemo[n][m][k]) return memo[n][m][k];
  int best = infty;
  REP(i,n-1) REP(ki,k+1) {
    best = min(best, m*m + go(i+1, m, ki) + go(n-1-i, m, k-ki));
  }
  REP(i,m-1) REP(ki,k+1) {
    best = min(best, n*n + go(n, i+1, ki) + go(n, m-1-i, k-ki));
  }
  inmemo[n][m][k] = 1;
  return memo[n][m][k] = best;
}

int main() {
  scanf("%d",&_);
  while (_--) {
    int n,m,k; scanf("%d%d%d",&n,&m,&k);
    printf("%d\n",go(n,m,k));
  }
}