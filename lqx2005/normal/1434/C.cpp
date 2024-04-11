#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll t, a, b, c, d;
int main()
{
  scanf("%lld", &t);
  for(int amo = 1; amo <= t; amo++)
  {
    scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
    if(a - b * c > 0) printf("-1\n");
    else
    {
      if(d >= c) printf("%d\n", a);
      else 
      {
        ll mx = a;
        ll round = a / (b * d);
        mx = max(mx, (round + 1) * a - (round + 1) * round / 2 * b * d);
        printf("%lld\n", mx);
      }
    }
  }
  return 0;
}