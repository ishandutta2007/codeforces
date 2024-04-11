#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int t;
ll p, q;
ll check(ll x, ll q)
{
  int k1 = 0, k2 = 0;
  while(q % x == 0) q /= x, k1++;
  k1--;
  ll r = p;
  while(r % x == 0) r /= x, k2++;
  k2 = min(k2, k1);
  for(int i = 1; i <= k2; i++) r = r * x;
  return r;
}
int main()
{
  scanf("%d", &t);
  for(int amo = 1; amo <= t; amo++)
  {
    scanf("%lld%lld", &p, &q);
    if(p % q != 0)
    {
      printf("%lld\n", p);
      continue;
    }
    ll ans = 0, s = q;
    for(ll i = 2; i * i <= q; i++)
    {
      if(q % i == 0)
      {
        while(q % i == 0) q /= i;
        ans = max(ans, check(i, s));
      }
    }
    if(q > 1) ans = max(ans, check(q, s)); 
    printf("%lld\n", ans);
  }
  return 0;
}