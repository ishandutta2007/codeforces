#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

const int N = 110;
int n,m,a[N];

int main() {
  scanf("%d%d",&n,&m);
  REP(i,n) { scanf("%d",&a[i]); }
  sort(a,a+n);
  for (int i=n-1; ; --i) {
    m -= a[i];
    if (m <= 0) {
      printf("%d\n",n-i);
      return 0;
    }
  }
}