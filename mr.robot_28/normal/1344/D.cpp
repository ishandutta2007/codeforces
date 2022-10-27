#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector <int> a(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int l = a[0] - 3 * a[0] * a[0] + a[0] - 2, r = a[0];
	for(int i = 0; i < n; i++)
	{
		r = max(r, a[i]);
		l = min(l, a[i] - 3 * a[i] * a[i] + a[i] - 2);
	}
	int calc = 0;
	vector <int> ans(n);
	while(r - l > 1)
	{
		int midd = (r + l) / 2;
		int sum = 0;
		vector <int> cnt(n);
		for(int i = 0; i < n; i++)
		{
			int l1 = 0, r1 = a[i] + 1;
			while(r1 - l1 > 1)
			{
				int midd1 = (l1 + r1) / 2;
				if(a[i] - 3 * midd1 * midd1 + 3 * midd1 - 1 >= midd)
				{
					l1 = midd1;
				}
				else
				{
					r1 = midd1;
				}
			}
			cnt[i] = l1;
			sum += l1;
		}
		if(sum > k)
		{
			l = midd;
		}
		else
		{
			for(int i = 0; i < n; i++){
				ans[i] = cnt[i];
			}
			calc = sum;
			r = midd;
		}
	}
	k -= calc;
	for(int i = 0; i < n; i++)
	{
		if(ans[i] != a[i] && a[i] - 3 * (ans[i] + 1) * (ans[i] + 1) + 3 * (ans[i] + 1) - 1 >= l && k > 0)
		{
			ans[i]++;
			k--;
		}
		cout << ans[i] << " ";
	}
	
	return 0; 
}