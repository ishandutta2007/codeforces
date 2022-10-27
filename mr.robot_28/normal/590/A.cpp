#include<bits/stdc++.h>
using namespace std;
 
 
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector <int> a(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int ans = 0;
	for(int i = 0; i < n - 1; i++)
	{
		if(a[i] == 1)
		{
			if(a[i + 1] == a[i])
			{
				continue;
			}
			int j = i;
			while(j < n - 2 && a[j + 1] == 0 && a[j + 2] == 1)
			{
				j += 2;
			}
			if(j == i && i == 0)
			{
				continue;
			}
			for(int k = i; k <= j; k++)
			{
				
			if(i == 0 || a[i - 1] == 1)
			{
				if(j == n - 1 || a[j + 1] == 1)
				{
					ans = max(ans, (j - i) / 2);
					a[k] = 1;
				}
				else
				{
					ans = max(ans, (j - i) / 2);
					if(k <= (j + i) / 2)
					{
						a[k] = 1;
					}
					else
					{
						a[k] = 0;
					}
				}
			}
			else
			{
				if(j == n - 1 || a[j + 1] == 1)
				{
					ans = max(ans, (j - i) /2);
					if(k >= (j + i) / 2)
					{
						a[k] = 1;
					}
					else
					{
						a[k] = 0;
					}
				}
				else
				{
					ans = max(ans, (j - i + 2) / 2);
					a[k] = 0;
				}
			}
			}
			i = j;
		}
	}
	cout << ans << "\n";
	for(int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}