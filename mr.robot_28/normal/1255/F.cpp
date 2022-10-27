#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	int n;
	cin >> n;
	vector <pair <int, int> > up, down;
	for(int i = 3; i <= n; i++)
	{
		cout << 2 << " " << 1 << " " << 2 << " " << i << endl;
		fflush(stdout);
		int t;
		cin >> t;
		cout << 1 << " " << 1 << " " << 2  << " " << i << endl;
		fflush(stdout);
		int s;
		cin >> s;
		if(t == -1)
		{
			down.push_back({s, i});
		}
		else
		{
			up.push_back({s, i});
		}
	}
	sort(up.begin(), up.end());
	sort(down.begin(), down.end());
	vector <int> upleft, upright, downleft, downright;
	for(int i = 0; i < up.size(); i++)
	{
		if(i < up.size() - 1 && up[i].first == up[i + 1].first)
		{
			cout << 2 << " " << 1 << " " << up[i].second << " " << up[i + 1].second << endl;
			fflush(stdout);
			int t;
			cin >> t;
			if(t == -1)
			{
				upleft.push_back(up[i].second);
				upright.push_back(up[i + 1].second);
			}
			else
			{
				upleft.push_back(up[i + 1].second);
				upright.push_back(up[i].second);
			}
			i++;
		}
		else
		{
			if(i == up.size() - 1)
			{
				upleft.push_back(up[i].second);
			}
			else
			{
				cout << 2 << " " << 1 << " " << up[i].second << " " << up[i + 1].second << endl;
				fflush(stdout);
				int t;
				cin >> t;
				if(t == -1)
				{
					upleft.push_back(up[i].second);
				}
				else
				{
					upright.push_back(up[i].second);
				}
			}
		}
	}
	for(int i = 0; i < down.size(); i++)
	{
		if(i < down.size() - 1 && down[i].first == down[i + 1].first)
		{
			cout << 2 << " " << 1 << " " << down[i].second << " " << down[i + 1].second << endl;
			fflush(stdout);
			int t;
			cin >> t;
			if(t == -1)
			{
				downright.push_back(down[i].second);
				downleft.push_back(down[i + 1].second);
			}
			else
			{
				downright.push_back(down[i + 1].second);
				downleft.push_back(down[i].second);
			}
		}
		else
		{
			if(i == down.size() - 1)
			{
				downleft.push_back(down[i].second);
			}
			else
			{
				cout << 2 << " " << 1 << " " << down[i].second << " " << down[i + 1].second << endl;
				fflush(stdout);
				int t;
				cin >> t;
				if(t == -1)
				{
					downright.push_back(down[i].second);
				}
				else
				{
					downleft.push_back(down[i].second);
				}
			}
		}
	}
	cout << 0 << " " << 1 << " ";
	for(int i = 0; i < downleft.size(); i++)
	{
		cout << downleft[i] << " ";
	 } 
	if(downright.size() != 0)
	{
	for(int i = downright.size() - 1; i >= 0; i--)
	{
		cout << downright[i] << " ";
	}
	}
	cout << 2 << " ";
	for(int i = 0; i < upright.size(); i++)
	{
		cout << upright[i] << " ";
	}
	if(upleft.size() != 0)
	{
	for(int i = upleft.size() - 1; i >= 0; i--)
	{
		cout << upleft[i] << " ";
	}
	}
	return 0;
}