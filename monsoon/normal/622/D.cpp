#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

const int N = 500100;
int n,p[2*N];

int main() {
  scanf("%d",&n);
  REP(i,(n+1)/2-1) {
    p[(n+1)/2-2-i] = p[(n+1)/2+i] = 2*(n/2-i-1)+(n%2);
  }
  p[(n+1)/2-1] = n;
  int cent = (n+1)/2*2 + n/2;
  REP(i,(n+1)/2) {
    p[cent-1-i] = p[cent+i] = 2*(n/2-i)-1+(n%2);
  }
  p[(n+1)/2*2-1] = n;
  REP(i,2*n) printf("%d ",p[i]);
  printf("\n");
}