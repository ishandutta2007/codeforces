#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
ll n;
ll lob(ll x)
{
  ll cnt = 1;
  while(x % 3 == 0) x /= 3, cnt *= 3;
  return cnt;
}
int main()
{
  scanf("%lld", &n);
  ll k = lob(n);
  ll p = (n / k) % 3;
  ll m = 0;
  n -= (p - 1) * k;
  k *= 3;
  m += ((n + k - 1) / k);
  printf("%lld\n", m);
  return 0;
}