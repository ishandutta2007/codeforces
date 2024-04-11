#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

const int N = 20100;
int n,a[2*N];

int main() {
  scanf("%d",&n);
  REP(i,2*n) { scanf("%d",&a[i]); }
  sort(a,a+2*n);
  int s1 = 0, s2 = 0; REP(i,n) { s1 += a[i]; s2 += a[n+i]; }
  if (s1 == s2) {
    puts("-1");
  } else {
    REP(i,2*n) printf("%d ",a[i]);
    printf("\n");
  }
}