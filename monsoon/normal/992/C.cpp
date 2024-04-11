#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MOD = 1000000007;
ll x,k;

int modpow(int a, ll n) {
  int w = 1;
  while (n) {
    if (n&1) { w = ll(w)*a % MOD; }
    a = ll(a)*a % MOD;
    n /= 2;
  }
  return w;
}

int main() {
  scanf("%lld%lld",&x,&k);
  int wyn = x==0 ? 0 : (ll(x % MOD) * modpow(2, k+1) + (MOD - modpow(2, k)) + 1) % MOD;
  printf("%d\n", wyn);
}