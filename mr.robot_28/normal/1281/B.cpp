#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string a, b;
		cin >> a >> b;
		vector <int> cnt(26);
		for(int i = 0;i < a.size(); i++)
		{
			cnt[a[i] - 'A']++;
		}
		bool flag = false;
		for(int i = 0; i < a.size(); i++)
		{
			for(int j = 0; j < a[i] - 'A'; j++)
			{
				if(cnt[j] != 0)
				{
					for(int k = a.size() - 1; k > i; k--)
					{
						if(a[k] - 'A' == j)
						{
							swap(a[i], a[k]);
							break;
						}
					}
					flag = true;
					break;
				}
			}
			cnt[a[i] - 'A']--;
			if(flag)
			{
				break;
			}
		}
		int n = a.size();
		int m = b.size();
		flag = true;
		int i = 0;
		for(i = 0; i < min(n, m); i++)
		{
			if(b[i] < a[i])
			{
				flag = false;
				break;
			}
			if(a[i] < b[i])
			{
				break;
			}
		}
		if(i == n && i != m)
		{
			cout << a << "\n";
		}
		else if(i != m && flag)
		{
			cout << a << "\n";
		}
		else
		{
			cout << "---\n";
		}
	}
	return 0;
}