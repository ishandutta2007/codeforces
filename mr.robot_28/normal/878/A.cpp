#include<bits/stdc++.h>
using namespace std;

signed main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	int n;
	cin >> n;
	vector <int> type(10, 0);
	for(int i = 0; i < n; i++)
	{
		char t;
		cin >> t;
		int a;
		cin >> a;
		if(t == '|')
		{
			for(int j = 0; j < 10; j++)
			{
				if((1 << j) & a)
				{
					type[j] = 2;
				}
			}
		}
		else if(t == '&')
		{
			for(int j = 0; j < 10; j++)
			{
				if(((1 << j) & a) == 0)
				{
					type[j] = 3;
				}
			}
		}
		else
		{
			for(int j = 0; j < 10; j++)
			{
				if((1 << j) & a)
				{
					if(type[j] == 0)
					{
						type[j] = 1;
					}
					else if(type[j] == 1)
					{
						type[j] = 0;
					}
					else if(type[j] == 2)
					{
						type[j] = 3;
					}
					else
					{
						type[j] = 2;
					}
				}
			}
		}
	}
	vector <pair <int, int> > mass;
	int mask1 = 0, mask2 = 0, mask3 = 0;
	for(int j = 0; j < 10; j++)
	{
		if(type[j] == 1)
		{
			mask1 |= (1 << j);
		}
		else if(type[j] == 2)
		{
			mask2 |= (1 << j);
		}
		else if(type[j] == 3)
		{
			mask3 |= (1 << j);
		}
	}
	if(mask1 != 0)
	{
		mass.push_back({0, mask1});
	}
	if(mask2 != 0)
	{
		mass.push_back({1, mask2});
	}
	if(mask3 != 0)
	{
		mask3 = 1023 - mask3;
		mass.push_back({2, mask3});
	}
	cout << mass.size() << "\n";
	for(int i = 0; i < mass.size(); i++)
	{
		if(mass[i].first == 0)
		{
			cout << '^';
		}
		else if(mass[i].first == 1)
		{
			cout << '|';
		}
		else
		{
			cout << '&';
		}
		cout << " " << mass[i].second << "\n";
	}
	return 0;
}