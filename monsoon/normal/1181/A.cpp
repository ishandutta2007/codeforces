#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

ll x,y,z;

int main() {
  scanf("%lld%lld%lld",&x,&y,&z);
  ll ans = (x+y)/z, ans2 = x/z + y/z, give = 0;
  if (ans != ans2) {
    give = min(z-x%z, z-y%z);
  }
  printf("%lld %lld\n",ans,give);
}