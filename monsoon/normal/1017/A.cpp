#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

const int N = 1100;
int n,a[N][4],sum[N],idx[N];

bool cmp(int i, int j) {
  return sum[i] > sum[j];
}

int main() {
  scanf("%d",&n);
  REP(i,n) REP(j,4) { scanf("%d",&a[i][j]); sum[i] += a[i][j]; idx[i] = i; }
  stable_sort(idx,idx+n,cmp);
  REP(i,n) if (idx[i] == 0) printf("%d\n",i+1);
}