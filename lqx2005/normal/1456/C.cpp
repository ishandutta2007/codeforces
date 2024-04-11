#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef double db;
typedef long long ll;
const int N = 5e5 + 10;
int n, a[N], k;
int ans = 0;
vector<int> ps, ng;
int cnt[N];
signed main()
{
  scanf("%lld%lld", &n, &k);
  for(int i = 1; i <= n; i++)
  {
    scanf("%lld", &a[i]);
    if(a[i] >= 0) ps.push_back(a[i]);
    else ng.push_back(a[i]);
  }
  sort(ps.begin(), ps.end());
  int tot = ps.size();
  ll sum = 0;
  for(int i = tot - 1; i >= 0; i--)
  {
    ans += sum;
    sum += ps[i];
  }
  sort(ng.begin(), ng.end());
  tot = ng.size();
  for(int i = tot - 1; i >= 0; i--)
  {
    ans += sum;
    sum += ng[i];
    if(sum < 0) 
    {
      tot = i;
      break;
    }
  }
  if(sum >= 0) return printf("%lld\n", ans), 0;
  while(ng.size() > (int)tot) ng.pop_back();
  ng.push_back(sum);
  sort(ng.begin(), ng.end());
  tot = ng.size();
  for(int i = 0; i < tot; i++)
  {
    ans += 1ll * cnt[i % (k + 1)] * ng[i];
    cnt[i % (k + 1)]++;
  }
  printf("%lld\n", ans);
	return 0;
}