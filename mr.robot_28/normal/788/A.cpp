#include <bits/stdc++.h>
                  
using namespace std;
#define int long long
signed main(){
	int n;
	cin >> n;
	vector <int> a(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int ans = 0;
	int min1 = 0, min2 = 0;
	int sum1 = 0, sum2 = 0;
	for(int i = 0; i < n - 1; i++)
	{
		if(i % 2 == 0)
		{
			sum1 += abs(a[i] - a[i + 1]);
			sum2 -= abs(a[i] - a[i + 1]);
			min2 = min(min2, sum2);
		}
		else
		{
			sum1 -= abs(a[i] - a[i + 1]);
			sum2 += abs(a[i] - a[i + 1]);
			min1 = min(min1, sum1);
		}
		ans = max(ans, sum1 - min1);
		ans = max(ans, sum2 - min2);
	}
	cout << ans;
	return 0;
}