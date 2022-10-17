#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

const int N = 200100;
int n,m,a[N],b[N];

int main() {
  scanf("%d%d",&n,&m);
  REP(i,n) { scanf("%d",&a[i]); }
  REP(i,m) { scanf("%d",&b[i]); }
  sort(a,a+n);
  REP(i,m) {
    int pos = upper_bound(a,a+n,b[i]) - a;
    printf("%d ",pos);
  }
  printf("\n");
}