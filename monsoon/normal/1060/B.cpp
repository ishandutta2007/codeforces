#include <cstdio>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
typedef long long ll;

ll n;

ll fast(ll n) {
  if (n <= 9) return n;
  ll other = (n-9) % 10;
  return 9 + other + fast((n-9)/10);
}

int main() {
  scanf("%lld",&n);
  printf("%lld\n",fast(n));
}