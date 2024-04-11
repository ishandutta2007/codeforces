#include <bits/stdc++.h>
using namespace std;
int a[110];
int main()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	int ans = 0;
	for(int i = 1; i < n; i ++)
		ans += a[n] - a[i];
	cout << ans;
	return 0;
}