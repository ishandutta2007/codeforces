#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	int n;
	cin >> n;
	vector <int> post(n + 1);
	int cnt1 = 0, cnt2 = 0;
	vector <int> a(n);
	for(int i = 0; i < n; i++)
	{
		int d;
		cin >> d;
		while(d > 0){
			a[i] += d % 2;
			d = d / 2;
		}
	}
	for(int i = n - 1; i >= 0; i--)
	{
		post[i] = post[i + 1] + a[i];
	}
	int ans = 0;
	for(int i = n - 1; i >= 0; i--)
	{
		if(i + 120 < n)
		{
			if(post[i + 120] % 2 == 0)
			{
				cnt1++;
			}
			else
			{
				cnt2++;
			}
		}
		int sum = 0, maxx = 0;
		for(int j = i; j < min(n, i + 119); j++)
		{
			maxx = max(maxx, a[j]);
			sum += a[j];
			if(maxx * 2 <= sum && sum %  2== 0)
			{
				ans++;
			}
		}
		if(post[i] % 2 == 0)
		{
			if(i + 120 <= n)
			{
				ans++;
			}
			ans += cnt1;
		}
		else
		{
			ans += cnt2;
		}
	}
	cout << ans;
	return 0;
}