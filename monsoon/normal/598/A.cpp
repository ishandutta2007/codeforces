#include <cstdio>
using namespace std;
typedef long long ll;

int _,n;

int main() {
  scanf("%d",&_);
  while (_--) {
    scanf("%d",&n);
    ll sum = ll(n)*(n+1)/2;
    ll pw = 1;
    while (2*pw <= n) pw*=2;
    sum -= 2*(2*pw-1);
    printf("%lld\n",sum);
  }
}