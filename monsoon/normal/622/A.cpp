#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

ll n;

int main() {
  scanf("%lld",&n);
  ll lb=0, ub=1e8;
  while (lb != ub) {
    ll mid = (lb+ub+1)/2;
    ll cnt = (1+mid)*mid/2;
    if (cnt < n) lb = mid;
    else ub = mid-1;
  }
  ll cnt = (1+lb)*lb/2;
  printf("%lld\n", n-cnt);
}