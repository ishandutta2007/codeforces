#include<bits/stdc++.h>
using namespace std;
int a[200010];
long long sum[200010];
map<int, int> mp;
int main()
{
	long double ans = 0;
	int n;
	cin >> n;
	int i;
	for(i=1; i<=n; i++) cin >> a[i];
	sum[1] = a[1];
	for(i=2; i<=n; i++) sum[i] = sum[i-1] + a[i];
	for(i=1; i<=n; i++) ans -= (long double)(n - i) * a[i] - (sum[n] - sum[i]);
	for(i=n; i>=1; i--)
	{
		ans -= (long double)mp[a[i] + 1];
		ans += (long double)mp[a[i] - 1];
		mp[a[i]] ++;
	}
	printf("%.0Lf", ans);
	return 0;
}