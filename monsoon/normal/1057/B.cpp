#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

const int N = 5100;
int n,a[N];

int main() {
  scanf("%d",&n);
  REP(i,n) { scanf("%d",&a[i]); }
  int ans = 0;
  REP(i,n) {
    int sum=0;
    for(int j=i;j<n;++j) {
      sum += a[j];
      if (sum > 100*(j+1-i)) {
        ans = max(ans, j+1-i);
      }
    }
  }
  printf("%d\n", ans);
}