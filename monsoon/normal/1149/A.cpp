#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

const int N = 210000;
int n,c1,c2,a[N],k;

int main() {
  scanf("%d",&n);
  REP(i,n) {
    int c; scanf("%d",&c);
    if (c==1) ++c1; else ++c2;
  }
  if (c2) { a[k++] = 2; --c2; }
  if (c1) { a[k++] = 1; --c1; }
  while (c2) { a[k++] = 2; --c2; }
  while (c1) { a[k++] = 1; --c1; }

  REP(i,n) {
    printf("%d ",a[i]);
  }
  printf("\n");
}