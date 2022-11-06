#include <bits/stdc++.h>
using namespace std;
int n, k, ans;
int a[100010];
int main()
{
	cin >> n >> k;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= k; i ++)
		ans += a[i];
	cout << ans;

	return 0;
}