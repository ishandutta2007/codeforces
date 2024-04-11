#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

ll a,b,ab;

int main() {
  scanf("%lld%lld%lld",&a,&b,&ab);
  ll wsp = min(a,b);
  a -= wsp; b -= wsp;
  ll ans = 2*ab + 2*wsp + !!(a+b);
  printf("%lld\n",ans);
}