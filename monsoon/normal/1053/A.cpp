#include <cstdio>
#include <algorithm>
using namespace std;

int n,m,k;

int main() {
  scanf("%d%d%d",&n,&m,&k);
  int d = __gcd(n, k);
  n /= d; k /= d;
  int d2 = __gcd(m, k);
  m /= d2; k /= d2;
  if (k == 1) {
    if (d >= 2) { n *= 2; k *= 2; }
    else if (d2 >= 2) { m *= 2; k *= 2; }
  }
  if (k == 2) {
    printf("YES\n0 0\n%d 0\n0 %d\n", n, m);
  } else {
    printf("NO\n");
  }
}