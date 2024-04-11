#include<bits/stdc++.h>
using namespace std;

signed main() {	
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	int n;
	cin >> n;
	vector <pair <int, int> > a(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i].first >> a[i].second;
	}
	int ans = 1e9;
	for(int i = 1; i <= 1000; i++)
	{
		bool flag = 1;
		int sum = 0;
		for(int j = 0; j < n; j++)
		{
			if(a[j].first > i)
			{
				if(a[j].second > i)
				{
					flag = 0;
					break;
				}
				sum +=a[j].first;
			}
			else if(a[j].second > i)
			{
				sum += a[j].second;
			}
			else
			{
				sum += min(a[j].first, a[j].second);
			}
		}
		if(flag)
		{
			ans = min(ans, sum * i);
		}
	}
	cout << ans;
    return 0;
}