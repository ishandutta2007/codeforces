#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

const int N = 110000;
int n,a[N],sum,ans;

int main() {
  scanf("%d",&n);
  REP(i,n) { scanf("%d",&a[i]); sum += a[i]; }
  sort(a,a+n);
  REP(i,n) {
    ans += abs(a[i] - (sum+i)/n);
  }
  ans /= 2;
  printf("%d\n",ans);
}