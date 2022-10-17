#include <cstdio>
#include <algorithm>
using namespace std;

int n;

int main() {
  scanf("%d",&n);
  int ans = n % 2 ? 0 : 1<<(n/2);
  printf("%d\n",ans);
}