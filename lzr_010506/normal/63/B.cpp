#include <bits/stdc++.h>
using namespace std;
int n, k, ans;
int a[110];
int main()
{
	cin >> n >> k;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	while(a[1] != k)
	{
		for(int j = 1; j <= n; j ++)
			if((j == n || a[j] != a[j + 1]) && a[j] < k)
				a[j] ++;
		ans ++;
	}
	cout << ans;
	return 0;
}