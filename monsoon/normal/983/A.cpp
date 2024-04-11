#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
typedef long long ll;

int _;
ll p,q,b;

int test(ll p, ll q, ll b) {
  if (p == 0) return 1;
  ll d = __gcd(p,q);
  q /= d;
  b = __gcd(q,b);
  while (b > 1) {
    q /= b;
    b = __gcd(q,b);
  }
  return q==1;
}

int main() {
  scanf("%d",&_);
  REP(__,_) {
    scanf("%lld%lld%lld",&p,&q,&b);
    puts(test(p,q,b) ? "Finite" : "Infinite");
  }
}