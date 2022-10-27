#include<bits/stdc++.h>
using namespace std;

signed main()
{
	int n;
	cin >> n;
	vector <bool> used(n + 1, true);
	int j = n / 2;
	int k = j * 2;
	vector <int> ans;
	for(int i = n; i > 1; i--)
	{
		while(j > 1)
		{
			bool flag = false;
			while(k > j)
			{
				if(used[k])
				{
					flag = true;
					break;
				}
				k -= j;
			}
			if(flag)
			{
				break;
			}
			else
			{
				j--;
				k = (n / j) * j;
			}
		}
		ans.push_back(j);
		used[k] = false;
	}
	for(int i = ans.size() - 1; i >= 0; i--)
	{
		cout << ans[i] << " ";
	}
    return 0;
}