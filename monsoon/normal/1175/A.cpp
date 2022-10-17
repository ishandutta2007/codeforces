#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
typedef long long ll;

int _;
ll n,k,ans;

int main() {
  scanf("%d",&_);
  REP(__,_) {
    scanf("%lld%lld",&n,&k);
    ans = 0;
    while (n) {
      if (n % k == 0) { n /= k; ++ans; }
      else { ans += n % k; n -= n % k; }
    }
    printf("%lld\n",ans);
  }
}