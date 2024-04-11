#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
const int N = 1e5 + 10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
int T, n, p, k, x, y;
int sum[N];
char s[N];
int main()
{
  scanf("%d", &T);
  for(int amo = 1; amo <= T; amo++)
  {
    scanf("%d%d%d", &n, &p, &k);
    scanf("%s", s + 1);
    for(int i = n; i >= 1; i--) 
    {
      sum[i] = (s[i] - '0') ^ 1;
      if(i + k <= n) sum[i] += sum[i + k];
    }
    ll ans = inf, cnt = 0;
    scanf("%d%d", &x, &y);
    for(int i = p; i <= n; i++) 
    {
      ans = min(ans, sum[i] * x + cnt);
      cnt += y;
    }
    printf("%lld\n", ans);
  }
	return 0;
}