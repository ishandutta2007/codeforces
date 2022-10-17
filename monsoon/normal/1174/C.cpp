#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

const int N = 200100;
int n,k,comp[N],ans[N];

int main() {
  scanf("%d",&n);
  for(int i=2;i<=n;++i) if (!comp[i]) {
    ++k;
    comp[i] = 1;
    ans[i] = k;
    for (int j=i;j<=n;j+=i) if (!comp[j]) {
      comp[j] = 1;
      ans[j] = k;
    }
  }
  for(int i=2;i<=n;++i) { printf("%d ",ans[i]); }
  printf("\n");
}