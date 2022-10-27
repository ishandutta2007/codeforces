#include<bits/stdc++.h>
using namespace std;

signed main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, k;
		cin >> n >> k;
		vector <int> a(n);
		bool flag = false;
		bool flag1 = false;
		for(int i = 0; i < n; i++)
		{
			cin >> a[i];
			if(a[i] == k)
			{
				flag = true;
			}
			if(i > 0 && min(a[i - 1], a[i]) >= k)
			{
				flag1 = true;
			}
			if(i > 1 && min(a[i -2], a[i]) >= k)
			{
				flag1 = true;
			}
		}
		if((flag1 || n == 1) && flag)
		{
			cout << "yes\n";
		}
		else
		{
			cout << "no\n";
		}
	}
    return 0;
}